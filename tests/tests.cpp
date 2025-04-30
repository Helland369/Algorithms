#define CATCH_CONFIG_MAIN

#include <cstdint>
#include <vector>

#include "../external/catch_amalgamated.hpp"
#include "../src/include/UniqueIntGen.hpp"
#include "../src/include/BinarySearch.hpp"
#include "../src/include//JumpSearch.hpp"
#include "../src/include/BubbleSort.hpp"
#include "../src/include/MergeSort.hpp"
#include "../src/include/QuickSort.hpp"

UniqueIntGen u;
std::vector<uint16_t> vec_sorted = u.uint_10k_gen(true);
std::vector<uint16_t> vec_unsorted = u.uint_10k_gen(false);

TEST_CASE("Binary Search works", "Binary Search")
{
  BinarySearch b;
  std::vector<uint16_t> vec = vec_sorted;
  REQUIRE(b.binary_search(vec, 333) == 332);
}

TEST_CASE("Jump search works", "Jump Search")
{
  JumpSearch j;
  std::vector<uint16_t> vec = vec_sorted;
  REQUIRE(j.jump_search(vec, vec.size(), 333) == 332);
}

TEST_CASE("Bubble sort works", "Bubble Sort")
{
  BubbleSort b;
  std::vector<uint16_t> vec = vec_unsorted;
  b.bubble_sort(vec, 9999);
}

TEST_CASE("Merge sort works", "Merge Sort")
{
  MergeSort m;
  std::vector<uint16_t> vec = vec_unsorted;
  m.merge_sort(vec, 0, vec.size() - 1);
}

TEST_CASE("Quick sort works", "Quick Sort")
{
  QuickSort q;
  std::vector<uint16_t> vec = vec_unsorted;
  q.quick_sort(vec, 0, vec.size() - 1);
}
