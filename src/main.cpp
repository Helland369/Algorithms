#include "include/BinarySearch.hpp"
#include "include/UniqueIntGen.hpp"
#include "include/BubbleSort.hpp"
#include "include/MergeSort.hpp"
#include <cstdint>
#include <iostream>
#include <vector>

int main(int argc, char* argv[])
{
  UniqueIntGen i;
  BubbleSort buble;
  MergeSort m;

  std::vector<uint16_t> vec = i.uint_10k_gen(false);

  m.merge_sort(vec, 0, vec.size() - 1);
  
  // buble.bubble_sort(x, 10000);
  
  // BinarySearch bin;

  // bin.binary_search(x, 333);

  for (auto y : vec)
  {
    std::cout << y << "\n";
  }    

  return 0;
}    
