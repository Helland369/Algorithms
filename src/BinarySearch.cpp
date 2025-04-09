#include "include/BinarySearch.hpp"
#include <iostream>


BinarySearch::BinarySearch()
{
  items = { 1, 2, 3, 4, 5, 6, 7 , 8 , 9 , 10 , 11 , 12 , 13};
}

BinarySearch::~BinarySearch() {}

int BinarySearch::binary_search(std::vector<int>& intVec, int item)
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
