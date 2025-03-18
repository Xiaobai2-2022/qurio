//
// Created by xiaobai2-2025 on 2/23/25.
//

# pragma once

#include "token_enums.h"

#include <string>
#include <unordered_map>
#include <unordered_set>

#include "token.h"

class Token_List {

    public:
        Token_List() = delete;

    public:
        static std::unordered_set< char > symbol_list;

    public:
        static std::unordered_map< char, QURIO_Delimiter > delimiter_list;
        static std::unordered_map< std::string, QURIO_Operator > operator_list;
        static std::unordered_map< std::string, QURIO_Keyword > keyword_list;

    public:
        static std::unordered_map< QURIO_Keyword, QURIO_BUILT_IN_Type > keyword_to_built_in_type;

    public:
        static std::unordered_map< std::string, Token * > user_defined_type_map;
        static std::unordered_map< std::string, Token * > function_decl_map;
        static std::unordered_map< std::string, Token * > function_def_map;
        static std::unordered_map< std::string, Token * > var_name_map;

}; // class Token_List <- static
