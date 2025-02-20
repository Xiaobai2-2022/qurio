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
            inc/constant
            inc/entity
                inc/entity/parsed_objects
                    inc/entity/parsed_objects/lex_objects
                        inc/entity/parsed_objects/lex_objects/concrete_lex_objects
            inc/util

)
