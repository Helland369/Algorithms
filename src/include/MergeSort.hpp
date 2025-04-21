#pragma once

#include <cstdint>
#include <vector>


class MergeSort
{
private:
public:
  MergeSort();
  ~MergeSort();

  void merge(std::vector<uint16_t>& vec, int left, int mid, int right);
  void merge_sort(std::vector<uint16_t>& vec, int left, int right);
};
