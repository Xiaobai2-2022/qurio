//
// Created by xiaobai2-2025 on 3/10/25.
//

#pragma once

#include "ast_node.h"

#include <queue>

class Qurio_Parser {

    public:
        Qurio_Parser() = delete;

    public:
        static AST_Node * form_tree( std::queue< Token * > & tokens );
        static void parse_fun_global_var( AST_Node * );

}; // class Qurio_Parser <- static
