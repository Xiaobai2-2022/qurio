//
// Created by xiaobai2-2025 on 3/10/25.
//

#include "qurio_parser.h"

#include <token_delimiter.h>

#include "compile_time_exception.h"

#include "parser_msg.h"

#include "token_list.h"
#include "token_protocol.h"

AST_Node * Qurio_Parser::form_tree( std::queue< Token * > & tokens ) {

    if( tokens.empty() ) return nullptr;

    PARSER_DEBUG( PARSER_BEGIN );

    const auto prog = new Token_Protocol{ 0, 0, PROGRAM, "PROGRAM" };
    auto program = new AST_Node{ prog };

    while( !tokens.empty() ) {
        Token * current = tokens.front();
        tokens.pop();

        const auto cur_node = new AST_Node{ current };

        program->set_child( cur_node );

    }

    PARSER_DEBUG( TREE_GEN );

    try {
        Qurio_Parser::scan_program( program );
    } catch ( Compile_Time_Exception & cte ) {
        cte.free_node();
        PARSER_ERROR( cte.what());
        delete program;
        program = nullptr;
    }

    return program;

}

Token * Qurio_Parser::is_free_identifier( const std::string & id ) {

    if( Token_List::user_defined_type_map.contains( id ) )
        return Token_List::user_defined_type_map.at( id );

    if( Token_List::function_decl_map.contains( id ) )
        return Token_List::function_decl_map.at( id );

    if( Token_List::function_def_map.contains( id ) )
        return Token_List::function_def_map.at( id );

    if( Token_List::var_name_map.contains( id ) )
        return Token_List::var_name_map.at( id );

    return nullptr;

}


void Qurio_Parser::scan_program( AST_Node *& program ) {

    AST_Node * head = program->get_child();

    Qurio_Parser::scan_from_head( head );

}

void Qurio_Parser::scan_from_head( AST_Node *& head ) {

    const Token * type = head->get_token();

    const auto head_token = new Token_Protocol{ type->get_row(), type->get_col(), DECL_DEF, "FUNCTION" };

    const auto type_head = new AST_Node{ head_token };

    const auto parent = head->unlink_this();

    parent->set_child( type_head );
    type_head->set_child( head );

    try {

        Qurio_Parser::scan_type( head, TYPE );

        auto token = head->get_token();

        auto id = Qurio_Parser::scan_identifier( head, NAME );

        token = head->get_token();

        if ( const auto token_type = token->get_type(); token_type == DELIMITER ) {

            if (const auto value =
                std::any_cast< QURIO_Delimiter >( token->get_value() );
                value == DELIMITER_SEMICOLON ) {

                // Logic for Variable Declaration

                head_token->set_protocol( VARIABLE_DECL, "VARIABLE_DECL" );

                const auto is_free_id = Qurio_Parser::is_free_identifier(
                    std::any_cast< std::string >( id->get_value() ) ) ;

                // Check if the identifier is defined previously
                if( is_free_id ) {

                    head->unlink_this();

                    throw Compile_Time_Exception { SYNTAX_ERROR_REDEFINE(
                        std::any_cast< std::string >( id->get_value() ),
                        id->get_row(), id->get_col(),
                        is_free_id->get_row(), is_free_id->get_col() ),
                        id->get_row(), id->get_col(), head };

                }

                // Add variable to the list
                Token_List::var_name_map.emplace(
                    std::pair< std::string, Token * > {
                        std::any_cast< std::string >( id->get_value() ),
                        id } );

                // Remove the unused delimiter
                const auto last = head->unlink_this();
                if ( head->get_next() ) {
                    const auto next = head->get_next();
                    next->unlink_this();
                    last->set_next( next );
                    delete head;
                    head = next;
                }

            } else if( value == DELIMITER_LSQRBR ) {
                head_token->set_protocol( ARRAY, "ARRAY_DECL" );

                // Logic for Array here

            } else if( value == DELIMITER_LPAREN )
                head_token->set_protocol( FUNCTION, "FUNCTION" ); {

                // Logic for Function here

            }
        } else if( token_type == OPERATOR ) {

        }


    } catch( Compile_Time_Exception & ) {
        throw;
    }

    head = head->get_next();
    if( head ) head->unlink_this();
    parent->set_child( head );

}

void Qurio_Parser::scan_type( AST_Node *& type_start, const QURIO_Protocol & protocol ) {

    const Token * type = type_start->get_token();

    unsigned int row = type->get_row();
    unsigned int col = type->get_col();

    PARSER_DEBUG( SCAN_TYPE, row, ":", col );

    auto type_head = new AST_Node{ new Token_Protocol{ row, col, protocol, "TYPE" } };

    const auto parent = type_start->unlink_this();

    type_head->set_child( type_start );

    if ( type->get_type() == KEYWORD ) {

        try {

            auto value = std::any_cast< QURIO_Keyword >( type->get_value() );

            if( value == KEY_DATATYPE_CONSTANT ) {

                PARSER_DEBUG( "const", row, ":", col );

                type_start = type_start->get_next();
                if( !type_start ) throw Compile_Time_Exception{ SYNTAX_ERROR_MISSING, row, col, type_head };
                type_start->unlink_this();
                type = type_start->get_token();
                row = type->get_row();
                col = type->get_col();
                type_head->set_child( type_start );

            }

            if( type->get_type() == KEYWORD ) {

                value = std::any_cast< QURIO_Keyword >( type->get_value() );

                if( value == KEY_DATATYPE_UNSIGNED ) {

                    PARSER_DEBUG( "unsigned", row, ":", col );

                    type_start = type_start->get_next();
                    if( !type_start ) throw Compile_Time_Exception{ SYNTAX_ERROR_MISSING, row, col, type_head };
                    type_start->unlink_this();
                    type = type_start->get_token();
                    row = type->get_row();
                    col = type->get_col();
                    type_head->set_child( type_start );

                    value = std::any_cast< QURIO_Keyword >( type->get_value() );

                    if( !( Token_List::keyword_to_built_in_type.contains( value ) && (
                            value == KEY_DATATYPE_DOUBLE_FLOAT ||
                            value == KEY_DATATYPE_FLOAT ||
                            value == KEY_DATATYPE_INTEGER ||
                            value == KEY_DATATYPE_LONG_INTEGER
                        ) ) ) throw Compile_Time_Exception{ SYNTAX_ERROR_UNEXPECTED( type->to_string(), row, col ),
                            row, col, type_head };

                }

                type_start = type_start->get_next();
                if( type_start ) type_start->unlink_this();

                parent->set_child( type_head );
                parent->set_child( type_start );

                return;

            }

        } catch( std::bad_any_cast & ) {
            throw Compile_Time_Exception{ SYNTAX_ERROR_UNEXPECTED( type->to_string(), row, col ),
                row, col, type_head };
        } catch( Compile_Time_Exception & ) {
            throw;
        }

    }

    if( type->get_type() == IDENTIFIER ) {

        try {

            if( const auto value = std::any_cast< std::string >( type->get_value() );
                ! Token_List::user_defined_type_map.contains( value ) )
                throw Compile_Time_Exception{ SYNTAX_ERROR_UNEXPECTED( type->to_string(), row, col ),
                    row, col, type_head };

            type_start = type_start->get_next();
            if( type_start ) type_start->unlink_this();

            parent->set_child( type_head );
            parent->set_child( type_start );

        } catch( std::bad_any_cast & ) {
            throw Compile_Time_Exception{ SYNTAX_ERROR_UNEXPECTED( type->to_string(), row, col ),
                row, col, type_head };
        } catch( Compile_Time_Exception & ) {
            throw;
        }

        return;

    }

    throw Compile_Time_Exception{ SYNTAX_ERROR_UNEXPECTED( type->to_string(), row, col ), row, col, type_head };

}

Token_Identifier * Qurio_Parser::scan_identifier( AST_Node *& type_start, const QURIO_Protocol & protocol ) {

    Token * type = type_start->get_token();

    const unsigned int row = type->get_row();
    const unsigned int col = type->get_col();

    PARSER_DEBUG( SCAN_IDENTIFIER, row, ":", col );

    auto type_head = new AST_Node{ new Token_Protocol{ row, col, protocol, "NAME" } };

    const auto parent = type_start->unlink_this();

    type_head->set_child( type_start );

    if( type->get_type() != IDENTIFIER )
        throw Compile_Time_Exception{ SYNTAX_ERROR_UNEXPECTED( type->to_string(), row, col ), row, col, type_head };

    const auto id = dynamic_cast< Token_Identifier * >( type );

    type_start = type_start->get_next();
    if( type_start ) type_start->unlink_this();

    parent->set_child( type_head );
    parent->set_child( type_start );

    return id;

}
