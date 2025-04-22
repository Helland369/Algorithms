#pragma once

#include <cstdint>
#include <vector>


class JumpSearch
{
private:
public:
  JumpSearch();
  ~JumpSearch();

  int jump_search(std::vector<uint16_t> vec, int size, int key);
};
