/*
 * PARSER
 * Some parsers
 */

#ifndef __PARSER_HPP
#define __PARSER_HPP

#include <utility>

// another example using integer_sequence 
template <char...characters> using stream = std::integer_sequence<char, characters...>;

//template <typename T, T... characters> constexpr stream<characters...> operator""_stream()
//{
//    return { };
//}

template <typename T, T... characters> constexpr auto operator""_stream() 
{
    return stream<characters...>{};
}

// Printing functions 
//template <char... characters, typename... Args> void pcprintf(stream<characters...>, Args&&... args) { ... };


// Where we are in a stream
template <size_t i> struct Position
{
    static const size_t index = i;
    using next = Position<i + 1>;
};

// print positions 
template <typename> struct Printer;

template <size_t index> struct Printer<Position<index>>
{
    static std::ostream& Print(std::ostream& output)
    {
        return output << "Position: " << index;
    }
};


// parser state is now just a stream and a position 
template <typename i, typename pos> struct State
{
    using input = i;
    using position = pos;
};

enum class ResultType
{
    PC_SUCCESS,
    PC_FAILURE,
    PC_ERROR
};

template <ResultType rt, typename X, typename S> struct Result
{
    static const ResultType success = rt;       // default here is SUCCESS
    using value = X;
    using state = S;
};

template <typename pos, typename expected, typename found> struct ExpectError {};

//printer for expect errors 
template <typename pos, typename expected, typename found> 
struct Printer<ExpectError<pos, expected, found>>
{
    static std::ostream& Print(std::ostream& output)
    {
        output << "At: ";
        Printer<pos>::Print(output) << " ";
        output << "Expected: ";
        Printer<expected>::Print(output) << " ";
        output << "Found: ";

        return Printer<found>::Print(output);
    }
};


/*
 * ALWAYS PARSER
 * This parser doesn't alter the input and never fails
 */
template <typename T> struct Always
{
    template <typename state> struct apply
    {
        using type = Result<ResultType>::Success, T, state>;
    };
};





// Some Value that fell out of a parser
//template <typename T, T x> struct Value {} 
//
//template <typename T, T x> struct Printer<Value<T, x>>
//{
//    static std::ostream& Print(std::ostream& output)
//    {
//        return output << std::boolalpha << x;
//    }
//};


#endif /*__PARSER_HPP*/
