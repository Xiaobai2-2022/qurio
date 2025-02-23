//
// Created by xiaobai2-2025 on 2/23/25.
//

# pragma once

#include <unordered_map>
#include <unordered_set>

#include "token_enums.h"

class Token_List {

    private:
        Token_List();

    public:
        static std::unordered_set< char > symbol_list;

    public:
        static std::unordered_map< char, QURIO_Delimiter > delimiter_list;

}; // class Token_List <- static
