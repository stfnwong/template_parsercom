/*
 * PARSER
 * Some parsers
 */

#ifndef __PARSER_HPP
#define __PARSER_HPP

#include <utility>

// another example using integer_sequence 
template <char...characters> using stream = std::integer_sequence<char, characters...>;

template <typename T, T... characters> constexpr stream<characters...> operator""_stream()
{
    return { };
}


// Printing functions 
template <char... characters, typename... Args> void pcprintf(stream<characters...>, Args&&... args) { ... };


// Where we are in a stream
template <size_t i> struct Position
{
    static const size_t index = i;
    using next = Position<i + 1>;
};


#endif /*__PARSER_HPP*/
