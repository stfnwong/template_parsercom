/*
 * Unit tests for parser stuff 
 *
 */

#define CATCH_CONFIG_MAIN
#include "catch/catch.hpp"

#include <iostream>

// unit(s) under test 
#include "parser.hpp"

//TEST_CASE("test_print", "[classic]")
//{
//    pcprintf("testint=%d"_stream, 5);
//}

//TEST_CASE("test_init_parser", "[classic]")
//{
//    using hello_word = decltype("Does this work?"_stream);
//}

TEST_CASE("test_parse", "[classic]")
{
    using p = Always<Value<int, 3>>;
    using result = run_parser<p, decltype("Does this work?"_stream)>;

    std::cout << std::endl;
    Printer<result>::Print(std::cout);     // should print 3?
    std::cout << std::endl;
}
