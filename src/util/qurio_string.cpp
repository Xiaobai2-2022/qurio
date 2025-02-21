//
// Created by xiaobai2-2025 on 2/21/25.
//

#include "qurio_string.h"

#include <regex>

bool Qurio_String::is_valid_number( const std::string & token ) {

    const std::regex int_regex{ R"(^[-+]?[0-9]([']?[0-9]+)*[lL]{0,2}$)" };
    const std::regex float_regex(R"(^[-+]?[0-9]([']?[0-9]+)*\.?[0-9]*([eE][-+]?[0-9]([']?[0-9]+)*)?[fFlL]?$)");
    const std::regex hex_regex(R"(^0[xX][0-9a-fA-F]([']?[0-9a-fA-F]+)*$)");
    const std::regex oct_regex(R"(^0[oO][0-7]([']?[0-7]+)*$)");
    const std::regex bin_regex(R"(^0[bB][01]([']?[01]+)*$)");

    return std::regex_match(token, int_regex) ||
           std::regex_match(token, float_regex) ||
           std::regex_match(token, hex_regex) ||
           std::regex_match(token, oct_regex) ||
           std::regex_match(token, bin_regex);

}
