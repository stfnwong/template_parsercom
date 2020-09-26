/*
 * Unit tests for parser stuff 
 *
 */


#define CATCH_CONFIG_MAIN
#include "catch/catch.hpp"

// unit(s) under test 
#include "parser.hpp"

TEST_CASE("test_print", "[classic]")
{
    pcprintf("testint=%d"_stream, 5);
}

//TEST_CASE("test_init_parser", "[classic]")
//{
//    using hello_word = decltype("Does this work?"_stream);
//}
