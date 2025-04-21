#pragma once

#include <cstdint>
#include <vector>


class BinarySearch
{
private:

public:
  BinarySearch();
  ~BinarySearch();

  uint16_t binary_search(std::vector<uint16_t>& intVec, uint16_t item);
};
