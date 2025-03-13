//
// Created by xiaobai2-2025 on 3/10/25.
//

#include "qurio_parser.h"

#include <compile_time_exception.h>
#include <token_keyword.h>

#include "parser_msg.h"
#include "token_protocol.h"

AST_Node * Qurio_Parser::form_tree( std::queue< Token * > & tokens ) {

    PARSER_DEBUG( PARSER_BEGIN );

    const auto prog = new Token_Protocol{ 0, 0, PROGRAM };
    auto program = new AST_Node{ prog };

    while( !tokens.empty() ) {
        Token * current = tokens.front();
        tokens.pop();

        const auto cur_node = new AST_Node{ current };

        program->set_child( cur_node );

    }

    PARSER_DEBUG( TREE_GEN );

    try {
        scan_function( program );
    } catch ( Compile_Time_Exception & cte ) {
        cte.free_node();
    }

    return program;

}

void Qurio_Parser::scan_function( AST_Node *& program ) {

    AST_Node * func_head = program->get_child();

    scan_function_head( func_head );

}

void Qurio_Parser::scan_function_head( AST_Node *& function_head ) {

    AST_Node * scan = function_head;



}

void Qurio_Parser::scan_type( AST_Node *& type_start, const QURIO_Protocol & protocol ) {

    const Token * type = type_start->get_token();

    unsigned int row = type->get_row();
    unsigned int col = type->get_col();

    PARSER_DEBUG( SCAN_TYPE, row, ":", col );

    auto type_head = new AST_Node{ new Token_Protocol{ row, col, protocol } };

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
                        ) ) ) throw Compile_Time_Exception{ SYNTAX_ERROR_UNEXPECTED, row, col, type_head };

                }

                type_start = type_start->get_next();
                if( type_start ) type_start->unlink_this();

                parent->set_child( type_head );
                parent->set_child( type_start );

                return;

            }

        } catch( std::bad_any_cast & ) {
            PARSER_ERROR( COMPILE_TIME_ERROR( row, col ) );
            throw Compile_Time_Exception{ SYNTAX_ERROR_UNEXPECTED, row, col, type_head };
        } catch( Compile_Time_Exception & cte ) {
            PARSER_ERROR( COMPILE_TIME_ERROR( cte.get_row(), cte.get_col() ) );
            throw;
        }

    }
    if( type->get_type() == IDENTIFIER ) {

        try {

            if( const auto value = std::any_cast< std::string >( type->get_value() );
                ! Token_List::user_defined_type.contains( value ) )
                throw Compile_Time_Exception{ SYNTAX_ERROR_UNEXPECTED, row, col, type_head };

            type_start = type_start->get_next();
            if( type_start ) type_start->unlink_this();

            parent->set_child( type_head );
            parent->set_child( type_start );

        } catch( std::bad_any_cast & ) {
            PARSER_ERROR( COMPILE_TIME_ERROR( row, col ) );
            throw Compile_Time_Exception{ SYNTAX_ERROR_UNEXPECTED, row, col, type_head };
        } catch( Compile_Time_Exception & cte ) {
            PARSER_ERROR( COMPILE_TIME_ERROR( cte.get_row(), cte.get_col() ) );
            throw;
        }

    } else throw Compile_Time_Exception{ SYNTAX_ERROR_UNEXPECTED, row, col, type_head };

}

