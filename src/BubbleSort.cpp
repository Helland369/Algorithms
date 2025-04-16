#include "include/BubbleSort.hpp"
#include <cstddef>
#include <cstdint>


BubbleSort::BubbleSort() {}

BubbleSort::~BubbleSort() {}

void BubbleSort::sort(std::vector<uint16_t>& vec, int n)
{
  for (size_t i = 0; i < n; ++i)
  {
    for (size_t j = 0; j < n - i- 1; ++j)
    {
      if (vec[j] > vec[j+1])
      {
        uint16_t temp = vec[j];
        vec[j] = vec[j+1];
        vec[j+1] = temp;
      }
    }
  }
}    
