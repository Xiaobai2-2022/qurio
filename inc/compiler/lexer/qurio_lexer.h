//
// Created by xiaobai2-2025 on 2/21/25.
//

#pragma once

#include <fstream>
#include <vector>

#include "file_not_found_exception.h"

#include "token.h"

class Qurio_Lexer {

    public:
        static std::vector< Token * >tokenizer( const std::string & );

};
