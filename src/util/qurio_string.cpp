//
// Created by xiaobai2-2025 on 2/21/25.
//

#include "qurio_string.h"

#include <regex>
#include <string>

#include "log.h"

bool Qurio_String::is_valid_number( const std::string & token ) {

    const std::regex int_regex{ R"(^[-+]?[0-9]([']?[0-9]+)*[lL]{0,2}$)" };
    const std::regex float_regex{ R"(^[-+]?[0-9]([']?[0-9]+)*\.?[0-9]*([eE][-+]?[0-9]([']?[0-9]+)*)?[fFlL]?$)" };
    const std::regex hex_regex{ R"(^0[xX][0-9a-fA-F]([']?[0-9a-fA-F]+)*$)" };
    const std::regex oct_regex{ R"(^0[oO][0-7]([']?[0-7]+)*$)" };
    const std::regex bin_regex{ R"(^0[bB][01]([']?[01]+)*$)" };

    return std::regex_match(token, int_regex) ||
           std::regex_match(token, float_regex) ||
           std::regex_match(token, hex_regex) ||
           std::regex_match(token, oct_regex) ||
           std::regex_match(token, bin_regex);

}

bool Qurio_String::is_valid_char( const std::string & token ) {

    const unsigned long length = token.size();

    if( token.at( 0 ) != '\'' || token.at( length - 1 ) != '\'' ) return false;

    if( length == 3 ) {
        if ( token.at( 1 ) != '\'' && token.at( 1 ) != '\\' ) return true;
        return false;
    }

    if( token.at( 1 ) != '\\' ) return false;

    // Oct
    if ( token.at( 2 ) >= '0' && token.at( 2 ) <= '7' ) {
        if( length == 4 ) return true;

        if ( token.at( 3 ) >= '0' && token.at( 3 ) <= '7' ) {
            if( length == 5 ) return true;

            if ( token.at( 4 ) >= '0' && token.at( 4 ) <= '7' ) {
                if( length == 6 ) return true;
            }
        }

        return false;

    }

    if( token.at( 2 ) == 'x' ) {
        if( length != 6 ) return false;
        if ( (
            ( token.at( 3 ) >= '0' && token.at( 3 ) <= '9' ) ||
            ( token.at( 3 ) >= 'a' && token.at( 3 ) <= 'f' ) ||
            ( token.at( 3 ) >= 'A' && token.at( 3 ) <= 'F' ) ) && (
            ( token.at( 4 ) >= '0' && token.at( 4 ) <= '9' ) ||
            ( token.at( 4 ) >= 'a' && token.at( 4 ) <= 'f' ) ||
            ( token.at( 4 ) >= 'A' && token.at( 4 ) <= 'F' )
            ) ) return true;
        return false;
    }

    if( length == 4 ) {
        return
            token.at( 2 ) == 'n' ||
            token.at( 2 ) == 't' ||
            token.at( 2 ) == 'r' ||
            token.at( 2 ) == 'b' ||
            token.at( 2 ) == 'f' ||
            token.at( 2 ) == 'v' ||
            token.at( 2 ) == 'a' ||
            token.at( 2 ) == '\'' ||
            token.at( 2 ) == '\"' ||
            token.at( 2 ) == '\\';
    }

    return false;

}

bool Qurio_String::is_valid_string( const std::string & token) {

    if( token.at( 0 ) != '\"' || token.at( token.size() - 1 ) != '\"' ) return false;
    for( auto c = token.begin(); c != token.end(); ++c ) {
        if( *c == '\\' ) {
            if( ++c == token.end() ) return false;
            if( *c == 'x')
            {
                if( ++c == token.end() ) return false;
                const char hex_1st = *c;
                if( ++c == token.end() ) return false;
                const char hex_2nd = *c;
                if ( ! (
                    ( hex_1st >= '0' && hex_1st <= '9' ) ||
                    ( hex_1st >= 'a' && hex_1st <= 'f' ) ||
                    ( hex_1st >= 'A' && hex_1st <= 'F' ) ) && (
                    ( hex_2nd >= '0' && hex_2nd <= '9' ) ||
                    ( hex_2nd >= 'a' && hex_2nd <= 'f' ) ||
                    ( hex_2nd >= 'A' && hex_2nd <= 'F' )
                    ) ) return false;
            } else if ( const char escaped = *c; ! (
                escaped == 'n' ||
                escaped == 't' ||
                escaped == 'r' ||
                escaped == 'b' ||
                escaped == 'f' ||
                escaped == 'v' ||
                escaped == 'a' ||
                escaped == '\'' ||
                escaped == '\"' ||
                escaped == '\\' || (
                escaped >= '0' && escaped <= '7'
                ) ) ) return false;
        }
    }

    return true;

}


bool Qurio_String::is_last_quote( const std::string & token ) {

    if( token.size() == 1 ) return false;

    unsigned long last = token.size() - 1;

    if( token.at( last ) != token.at( 0 ) ) return false;

    unsigned long count = 0;

    // check if still in range, and if the value is an escape;
    while( last != 0 && token.at( last - 1 ) == '\\' ) {
        ++count;
        --last;
    }

    return !( count % 2 );

}