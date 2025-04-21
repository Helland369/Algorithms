#include "include/MergeSort.hpp"
#include <cstddef>


MergeSort::MergeSort() {}

MergeSort::~MergeSort() {}

void MergeSort::merge(std::vector<uint16_t>& vec, int left, int mid, int right)
{
  int n1 = mid - left + 1;
  int n2 = right - mid;

  // temp vector
  std::vector<uint16_t> L(n1), R(n2);

  // copy data to temp vectors
  for (size_t i = 0; i < n1; ++i)
  {
    L[i] = vec[left + i];
  }
  for (size_t j = 0; j < n2; ++j)
  {
    R[j] = vec[mid + 1 + j];
  }

  int i = 0, j = 0;
  int k = left;

  // merge the temp vectors back into vec
  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      vec[k] = L[i];
      i++;
    }
    else
    {
      vec[k] = R[j];
      j++;
    }
    k++;
  }

  // copy the remaining elements of L[]
  while (i < n1)
  {
    vec[k] = L[i];
    i++;
    k++;
  }

  // copy the remaining elements of R[]
  while (j < n2)
  {
    vec[k] = R[j];
    j++;
    k++;
  }
}

void MergeSort::merge_sort(std::vector<uint16_t>& vec, int left, int right)
{
  if (left >= right)
    return;
  
  int mid = left + (right - left) / 2;

  merge_sort(vec, left, mid);
  merge_sort(vec, mid + 1, right);
  merge(vec, left, mid, right);
}
