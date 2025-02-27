//
// Created by xiaobai2-2025 on 2/21/25.
//

#pragma once

#include <exception>
#include <string>

class File_Failure_Exception final : public std::exception {

    private:
        std::string _msg;
        std::string _f_name;

    public:
        explicit File_Failure_Exception( const std::string &, const std::string & ) noexcept;

    public:
        [[nodiscard]] const char * what() const noexcept override;

    public:
        [[nodiscard]] std::string get_f_name() const noexcept;

}; // class File_Failure_Exception <- Exception
