//
// Created by xiaobai2-2025 on 2/18/25.
//

#include "main.h"

int main() {

    Parsed_Lex_Object * lex = new Parsed_Lex_Number{ 33, 14, NUMBER, "0x21" };

    try {

        PRINT_INFO( *dynamic_cast< Parsed_Lex_Number * >( lex ) );

        const std::string number = "-245.34";

        lex->set_value( number );

        PRINT_INFO( *dynamic_cast< Parsed_Lex_Number * >( lex ) );

        lex->set_row( 150 );

        PRINT_INFO( *dynamic_cast< Parsed_Lex_Number * >( lex ) );

        PRINT_WARN( "Illegal Change Here" );

        const std::string not_number = "0xp";

        lex->set_value( not_number );

        PRINT_INFO( *dynamic_cast< Parsed_Lex_Number * >( lex ) );

    } catch( const Type_Missmatch_Exception & tme ) {
        PRINT_ERROR( tme.what(), "At:", tme.get_parsed_object());
    } // try

    delete lex;

} // main
