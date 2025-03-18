//
// Created by xiaobai2-2025 on 3/10/25.
//

#include "qurio_parser.h"

#include <queue>

#include "compile_time_exception.h"
#include "parser_msg.h"
#include "token_protocol.h"

AST_Node * Qurio_Parser::form_tree( std::queue< Token * > & tokens ) {

    if( tokens.empty() ) return nullptr;

    PARSER_DEBUG( PARSER_BEGIN );

    const auto prog = new Token_Protocol{ 0, 0, PROGRAM, "PROGRAM" };


    const auto program = new AST_Node{ prog };

    while( !tokens.empty() ) {

        Token * current = tokens.front();
        tokens.pop();
        const auto cur_node = new AST_Node{ current };
        program->set_child( cur_node );

    }

    PARSER_DEBUG( TREE_GEN );

    return program;

}

void Qurio_Parser::parse_fun_global_var( AST_Node * head_node ) {

    if( !head_node ) return;

    unsigned int level = 0;
    bool complete = false;
    unsigned int row = 1;
    unsigned int col = 1;

    const auto parent_node = head_node->unlink_this();

    if( !parent_node ) return;

    auto cur_head_node = head_node;
    auto cur_node = head_node;

    while( cur_node ) {

        const auto cur_token = cur_node->get_token();
        row = cur_token->get_row();
        col = cur_token->get_col();

        if ( complete ) {
            const auto fun_var_node = new AST_Node{
                new Token_Protocol{
                    row, col,
                    DEV_DEF,
                    "DEV_DEF"
                }
            };
            complete = false;

            parent_node->set_child( fun_var_node );
            fun_var_node->set_child( cur_head_node );
            cur_head_node = cur_node;
            cur_head_node->unlink_this();
        }

        if( cur_node->get_token()->get_type() == DELIMITER ) {
            if(const auto delimiter = std::any_cast< QURIO_Delimiter >( cur_node->get_token()->get_value() );
                level == 0 && delimiter == DELIMITER_SEMICOLON ) {
                complete = true;
            } else if( delimiter == DELIMITER_LBRACE ) {
                ++level;
            } else if( delimiter == DELIMITER_RBRACE ) {
                if( level == 1) {
                    --level;
                    complete = true;
                } else if( level == 0 ) {
                    const std::string msg = "{";
                    throw Compile_Time_Exception{ SYNTAX_ERROR_UNEXPECTED( msg, row, col ), cur_head_node };
                } else {
                    --level;
                }
            }
        }

        cur_node = cur_node->get_next();

    }

    if ( complete ) {
        const auto fun_var_node = new AST_Node{
            new Token_Protocol{
                row, col,
                DEV_DEF,
                "DEV_DEF"
            }
        };
        fun_var_node->set_child( cur_head_node );
        parent_node->set_child( fun_var_node );
    }

}

