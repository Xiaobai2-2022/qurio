//
// Created by xiaobai2-2025 on 2/28/25.
//

#pragma once

#include <string>

#include "token.h"

class AST_Node final {

    private:
        AST_Node * _parent;
        AST_Node * _prev;
        AST_Node * _next;
        AST_Node * _first_child;

        Token * _cur;

        unsigned long _level;

    public:
        explicit AST_Node( Token * ) noexcept;
        ~AST_Node() noexcept;

    public:
        [[nodiscard]] Token * get_token() const noexcept;

    public:
        void set_next( AST_Node * ) noexcept;
        void set_child( AST_Node * ) noexcept;

        [[nodiscard]] AST_Node * get_next() const noexcept;
        [[nodiscard]] AST_Node * get_child() const noexcept;

        AST_Node * unlink_this() noexcept;

    public:

        class PreorderIterator {

            private:
                AST_Node * _cur_node;

            public:
                explicit PreorderIterator( AST_Node * ) noexcept;

            public:
                PreorderIterator & operator++() noexcept;
                PreorderIterator & operator--() noexcept;

                AST_Node * operator*() const noexcept;

                bool operator!=( const PreorderIterator & other ) const noexcept;

        };

        PreorderIterator begin();
        PreorderIterator end();

    friend std::ostream & operator<<( std::ostream & os, const AST_Node & node ) noexcept;

};
