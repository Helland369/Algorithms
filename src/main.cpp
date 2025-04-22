#include "include/BinarySearch.hpp"
#include "include/UniqueIntGen.hpp"
#include "include/BubbleSort.hpp"
#include "include/MergeSort.hpp"
#include "include/JumpSearch.hpp"
#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <vector>

int main(int argc, char* argv[])
{
  UniqueIntGen i;
  BubbleSort buble;
  MergeSort m;
  BinarySearch bin;
  JumpSearch jump;

  std::vector<uint16_t> vec = i.uint_10k_gen(false);

  int input, index;
  
  for (;;)
  {
    std::cout << "*** Algorithms ***\n" << "[1] Bubble sort\n" << "[2] Merge sort\n" << "[3] Binary search\n" << "[4] Jump search\n" << "[0] EXIT\n" << "\n";

    std::cin >> input;
    
    switch (input)
    {
    case 0:
      std::exit(0);
      break;
    case 1:
      buble.bubble_sort(vec, 10000);
      for (auto y : vec)
      {
        std::cout << y << "\n";
      }    
      break;
    case 2:
      m.merge_sort(vec, 0, vec.size() - 1);
      for (auto y : vec)
      {
        std::cout << y << "\n";
      }    
      break;
    case 3:
      bin.binary_search(vec, 333);
      break;
    case 4:
      std::vector<uint16_t> sorted_vec = vec;
      std::sort(sorted_vec.begin(), sorted_vec.end());
      index = jump.jump_search(sorted_vec, sorted_vec.size(), 333);
      if (index != -1)
      {
        std::cout << "333 was found at index: " << index << "\n";
      }
      else
      {
        std::cout << "333 was not found..,\n";
      }
      break;
    // default:
    //   std::cout << "Invalid input!" << "\n";
    //   break;
    }
  }


  return 0;
}    
