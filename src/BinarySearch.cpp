#include "include/BinarySearch.hpp"
#include <cstdint>
#include <iostream>


BinarySearch::BinarySearch() {}

BinarySearch::~BinarySearch() {}

uint16_t BinarySearch::binary_search(std::vector<uint16_t>& intVec, uint16_t item)
{
  int low = 0, high = intVec.size() -1;

  while (low <= high)
  {
    int mid = (low + high) / 2, guess = intVec[mid];

    if (guess == item)
    {
      std::cout << "Item found at index: " << mid << "\n";
      return mid;
    }
    else if (guess > item)
    {
      high = mid -1;
    }
    else
    {
      low = mid + 1;
    }
  }

  std::cout << "Item not found!" << "\n";

  return 0;
}    
