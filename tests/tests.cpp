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
#include "../src/include/Kpm.hpp"
#include "../src/include/RabinKarp.hpp"
#include "../src/include/Sha256.hpp"

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

TEST_CASE("Knuth-Morris-Pratt", "KPM")
{
  Kpm k;
  std::string txt = "aabaacaadaabaaba";
  std::string pat = "aaba";
  std::vector<uint16_t> res = k.kpm_search(pat, txt);

  std::vector<uint16_t> expected = {0, 9, 12};

  REQUIRE(res == expected);
}

TEST_CASE("Rabin karp", "RK")
{
  RabinKarp rk;
  std::string txt = "Emacs is the best editor";
  std::string pat = "Emacs";
  int q = INT_MAX;

  rk.rabin_karp(pat, txt, q);
}

TEST_CASE("Sha256", "SHA")
{
  Sha256 sha;
  std::string input = "Hei Hei Hallo";
  sha.sha256_algorithm(input);
}
