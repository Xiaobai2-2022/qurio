//
// Created by xiaobai2-2025 on 2/18/25.
//

#include "main.h"

int main() {

    std::queue< Token * > tokens;

    Qurio_Lexer::tokenizer( "/home/xiaobai2-2025/proj-q/qurio/test/debug_test.qc", tokens );

    const std::string user_defined_type = "x";
    const auto udt = new Token_Identifier{ 0, 0, user_defined_type, user_defined_type };

    Token_List::user_defined_type_map.emplace( user_defined_type, udt );

    const auto program = Qurio_Parser::form_tree( tokens );

    // for(const auto it : * program) PRINT_DEBUG_IT( *it );
    //
    // delete program;

    //
    // const auto program = new Token_Protocol{ 0, 0, PROGRAM, "PROGRAM" };
    // const auto const_ = new Token_Keyword{ 0, 0, KEY_DATATYPE_CONSTANT, "const" };
    // const auto unsigned_ = new Token_Keyword{ 0, 5, KEY_DATATYPE_UNSIGNED, "unsigned" };
    // // const auto int_ = new Token_Keyword{ 0, 5, KEY_DATATYPE_INTEGER, "int" };
    // // const auto my_type = new Token_Identifier{ 0, 10, user_defined_type };
    // // const auto not_a_type = new Token_Operator{ 0, 10, OPERATOR_ARTH_ADDITION };
    // const auto val = new Token_Number{ 0, 10, "0x34", "0x34" };
    //
    // auto node_prog = new AST_Node{ program };
    // auto node_const = new AST_Node{ const_ };
    // auto node_unsigned = new AST_Node{ unsigned_ };
    // // auto node_int = new AST_Node{ int_ };
    // // auto node_my_type = new AST_Node{ my_type };
    // auto node_val = new AST_Node{ val };
    //
    // node_prog->set_child( node_const );
    // node_prog->set_child( node_unsigned );
    // // node_prog->set_child( node_int );
    // node_prog->set_child( node_val );
    //
    // Token_List::user_defined_type_set.insert( user_defined_type );
    //
    // try {
    //     auto func = node_prog->get_child();
    //     Qurio_Parser::scan_function( node_prog );
    // } catch( Compile_Time_Exception & cte ) {
    //     PRINT_ERROR( cte.what() );
    //     cte.free_node();
    //     delete node_prog;
    //     return -1;
    // }

    if( program ) for( const auto it : * program ) PRINT_DEBUG_IT( *it );

    delete program;

    delete udt;

} // main
