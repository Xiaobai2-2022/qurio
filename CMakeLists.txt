cmake_minimum_required( VERSION 3.16 )
project( qurio )

set( CMAKE_CXX_STANDARD 23 )

# Ensure CMake uses modern C++
set( CMAKE_CXX_STANDARD_REQUIRED ON )

# Set the output directory for binaries
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )

# Automatically find all .cpp files in src/ and subdirectories
file( GLOB_RECURSE SOURCES "src/*.cpp" )

# Define the executable
add_executable( qurio_executable ${SOURCES} )

# Include directories (for header files)
include_directories(

        inc
            inc/compiler
                inc/compiler/lexer
                inc/compiler/parser
            inc/constant
                inc/constant/output_msg
            inc/entity
                inc/entity/abstract_syntax_tree
                inc/entity/parsed_object
                inc/entity/parsed_object/lex_object
                inc/entity/parsed_object/lex_object/concrete_lex_object
            inc/exception
            inc/util

)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
endif()

