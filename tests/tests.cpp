#include <cstdint>
#include <vector>
#define CATCH_CONFIG_MAIN

#include "../external/catch_amalgamated.hpp"
#include "../src/include/UniqueIntGen.hpp"
#include "../src/include/BinarySearch.hpp"

TEST_CASE("Binary Search works", "BinarySearch")
{
	UniqueIntGen u;
	std::vector<uint16_t> vec = u.uint_10k_gen(true);

	BinarySearch b;
	REQUIRE(b.binary_search(vec, 333) == 332);
}
