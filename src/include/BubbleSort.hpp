#pragma once    

#include <cstdint>
#include <vector>


class BubbleSort
{
private:
public:
  BubbleSort();
  ~BubbleSort();

  void sort(std::vector<uint16_t>& vec, int n);
};
