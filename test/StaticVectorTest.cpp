#include "catch.hpp"
#include "StaticVector.hpp"
#include "rand.hpp"
#include <iostream>
#define RND randinrange(-100,100)
TEST_CASE("Vector Products", "[Static Vector]")
{
    StaticVector<float, 3> a({1, 0, 0});
    StaticVector<float, 3> b({0, 1, 0});
    StaticVector<float, 3> c({0, 0, 1});
    REQUIRE((a.cross(b)) == c);
    REQUIRE(a * c == 0);
    REQUIRE(b * c == 0);
    int tests = randinrange(1000,2000);
    for (size_t i = 0; i < tests; i++)
    {
        StaticVector<float, 3> a({RND, RND, RND});
        StaticVector<float, 3> b({RND, RND, RND});
        StaticVector<float, 3> c(a.cross(b));

        REQUIRE((a.cross(b)) == c);
        REQUIRE((int)(a * c) == 0);
        REQUIRE((int)(b * c) == 0);
    }
}