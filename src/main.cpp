#include "include/BinarySearch.hpp"
#include "include/UniqueIntGen.hpp"
#include "include/BubbleSort.hpp"
#include <cstdint>
#include <iostream>
#include <vector>

int main(int argc, char* argv[])
{
  UniqueIntGen i;
  BubbleSort buble;

  std::vector<uint16_t> x = i.uint_10k_gen(false);

  buble.sort(x, 10000);
  
  // BinarySearch bin;

  // bin.binary_search(x, 333);

  for (auto y : x)
  {
    std::cout << y << "\n";
  }    

  return 0;
}    
