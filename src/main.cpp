//
// Created by xiaobai2-2025 on 2/18/25.
//

#include "main.h"

int main() {

    const auto prog = new Token_Protocol{ 0, 0, PROGRAM };

    auto head = new AST_Node{ prog };

    const auto func = new Token_Protocol{ 0, 0, FUNCTION };
    const auto func_rtn = new Token_Protocol{ 0, 0, RETURN_TYPE };
    const auto func_name = new Token_Protocol{ 0, 0, FUNCTION_NAME };
    const auto func_args = new Token_Protocol{0, 0, ARGUMENT };
    const auto func_body = new Token_Protocol{0, 0, SCOPE };

    const auto node_func = new AST_Node{ func };
    const auto node_func_rtn = new AST_Node{ func_rtn };
    const auto node_func_name = new AST_Node{ func_name };
    const auto node_func_args = new AST_Node{ func_args };
    const auto node_func_body = new AST_Node{ func_body };

    head->set_child( node_func );
    head->set_child( node_func_rtn );
    head->set_child( node_func_name );
    head->set_child( node_func_args );
    head->set_child( node_func_body );

    for(const auto it : *head) PRINT_DEBUG_IT( *it );

    delete head;

    delete prog;
    delete func;
    delete func_rtn;
    delete func_name;
    delete func_args;
    delete func_body;

} // main
