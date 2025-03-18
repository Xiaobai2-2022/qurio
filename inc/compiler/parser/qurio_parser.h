//
// Created by xiaobai2-2025 on 3/10/25.
//

#pragma once

#include <queue>

#include "ast_node.h"

#include "token_list.h"

#include "token.h"
#include "token_identifier.h"

class Qurio_Parser {

    public:
        Qurio_Parser() = delete;

    public:
        static AST_Node * form_tree( std::queue< Token * > & );

    public:
        static Token * is_free_identifier( const std::string & );

    public:
        static void scan_program( AST_Node *& );
        static void scan_from_head( AST_Node *& );

    public:
        static void scan_type( AST_Node *&, const QURIO_Protocol & );
        static Token_Identifier * scan_identifier( AST_Node *&, const QURIO_Protocol & );

}; // class Qurio_Parser <- static
