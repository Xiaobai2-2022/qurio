//
// Created by xiaobai2-2025 on 2/28/25.
//

#include "ast_node.h"

AST_Node::AST_Node( Token * token ) noexcept :
    _parent{ nullptr }, _prev{ nullptr }, _next{ nullptr },
    _first_child{ nullptr }, _cur{ token }, _level{ 0 } {}

AST_Node::~AST_Node() noexcept {

    this->_parent = nullptr;
    this->_prev = nullptr;

    delete this->_first_child;
    delete this->_next;

    delete this->_cur;

}

Token * AST_Node::get_token() const noexcept {
    return this->_cur;
}

void AST_Node::set_next( AST_Node * next ) noexcept {

    if( !next ) return;

    next->_parent = this->_parent;
    next->_level = this->_level;

    auto prev = this;
    while( prev->_next ) prev = prev->_next;

    next->_prev = prev;
    prev->_next = next;

}

void AST_Node::set_child( AST_Node * child ) noexcept {

    if( ! this->_first_child ) {
        child->_parent = this;
        child->_level = this->_level + 1;
        this->_first_child = child;
        return;
    }

    this->_first_child->set_next( child );

}

AST_Node * AST_Node::get_next() const noexcept {
    return this->_next;
}

AST_Node * AST_Node::get_child() const noexcept {
    return this->_first_child;
}

// unlink the current node and return parent
AST_Node * AST_Node::unlink_this() noexcept {

    AST_Node * parent = this->_parent;

    if( this->_prev ) {
        this->_prev->_next = nullptr;
    } else if( this->_parent ) {
        this->_parent->_first_child = nullptr;
    }

    this->_prev = nullptr;
    this->_parent = nullptr;

    return parent;

}

AST_Node::PreorderIterator::PreorderIterator( AST_Node * cur_node ) noexcept :
    _cur_node{ cur_node } {}

AST_Node::PreorderIterator & AST_Node::PreorderIterator::operator++() noexcept {

    if( !_cur_node ) return *this;

    if( _cur_node->_first_child ) _cur_node = _cur_node->_first_child;
    else if( _cur_node->_next ) _cur_node = _cur_node->_next;
    else {
        while( _cur_node->_parent && !_cur_node->_parent->_next ) _cur_node = _cur_node->_parent;
        _cur_node = _cur_node->_parent ? _cur_node->_parent->_next : nullptr;
    }

    return *this;

}

AST_Node::PreorderIterator & AST_Node::PreorderIterator::operator--() noexcept {

    if( !_cur_node ) return *this;

    if( _cur_node->_prev ) {
        _cur_node = _cur_node->_prev;
        while( _cur_node->_first_child ) {
            _cur_node = _cur_node->_first_child;
            while( _cur_node->_next ) _cur_node = _cur_node->_next;
        }
    } else _cur_node = _cur_node->_parent;

    return *this;

}

AST_Node * AST_Node::PreorderIterator::operator*() const noexcept {
    return _cur_node;
}

bool AST_Node::PreorderIterator::operator!=( const PreorderIterator& other ) const noexcept {
    return _cur_node != other._cur_node;
}

AST_Node::PreorderIterator AST_Node::begin() {
    return PreorderIterator{ this };
}

AST_Node::PreorderIterator AST_Node::end() {
    return PreorderIterator{ nullptr };
}

std::ostream & operator<<( std::ostream& os, const AST_Node & node ) noexcept {
    if( node._next ) node._next->_level = node._level;
    if( node._first_child ) node._first_child->_level = node._level + 1;
    os << "Level: " << node._level << "\t";
    for( unsigned long i{0}; i < node._level; ++i ) os << '\t';
    Token::print_token( os, node._cur );
    return os;
}
