#include "third_party/catch.hpp"
#include "algorithm/searching/quick_search.hpp"

TEST_CASE("Base cases", "[searching][quick_search]") {
    REQUIRE(quick_search(std::vector<int>(), 0, 0, 0) == -1);
    REQUIRE(quick_search(std::vector<int>({0, 6, 3, 1, 2}), 3, 0, 5) == 4);
    REQUIRE(quick_search(std::vector<int>({0, 1, 2, 3, 4, 5, 6, 7}), 8, 0, 8) == 8);
    REQUIRE(quick_search(std::vector<int>({0, 1, 2, 3, 4, 5, 6, 7}), 1, 0, 8) == 0);
}