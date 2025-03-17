//
// Created by xiaobai2-2025 on 2/23/25.
//

# pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>

#include "token_enums.h"

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
        static std::unordered_set< std::string > user_defined_type_set;
        static std::unordered_set< std::string > function_decl_set;
        static std::unordered_set< std::string > function_def_set;
        static std::unordered_set< std::string > var_name_set;

}; // class Token_List <- static
