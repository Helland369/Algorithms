#include "include/JumpSearch.hpp"
#include <algorithm>
#include <cmath>
#include <cstddef>


JumpSearch::JumpSearch() {}

JumpSearch::~JumpSearch() {}

int JumpSearch::jump_search(std::vector<uint16_t> vec, int size, int key)
{
  // ensure vec is not empty and size is valid
  if (size <= 0 || vec.empty())
  {
    return -1;
  }

  // calculate the jump step size
  int step = std::sqrt(size);

  // find the block where the key might be
  int prev = 0;
  while (step < size && vec[step] < key)
  {
    prev = step;
    step += std::sqrt(size);
  }

  // preform linear search in the indentified block
  int end = std::min(step, size);
  for (int i = prev; i < end; ++i)
  {
    if (vec[i] == key)
      return -1;
  }
  
  return -1;
}
