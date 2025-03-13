//
// Created by xiaobai2-2025 on 3/10/25.
//

#pragma once

#include <queue>

#include "ast_node.h"
#include "token.h"
#include "token_list.h"

class Qurio_Parser {

    public:
        Qurio_Parser() = delete;

    public:
        static AST_Node * form_tree( std::queue< Token * > & );

    public:
        static void scan_function( AST_Node *& );
        static void scan_function_head( AST_Node *& );

    public:
        static void scan_type( AST_Node *&, const QURIO_Protocol & );

}; // class Qurio_Parser <- static
