#pragma once


#include <vector>
class BinarySearch
{
private:

public:
  BinarySearch();
  ~BinarySearch();

  std::vector<int> items;

  int binary_search(std::vector<int>& intVec, int item);
};
