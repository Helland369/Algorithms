#include "include/QuickSort.hpp"
#include <cstddef>
#include <cstdint>

QuickSort::QuickSort() {}

QuickSort::~QuickSort() {}

size_t QuickSort::partition(std::vector<uint16_t>& vec, size_t low, size_t high)
{
  // selecting last element as the pivot
  uint16_t pivot = vec[high];

  // index of element just before the last element. It is used for swaping
  size_t i = (low - 1);

  for (size_t j = low; j <= high - 1; j++)
  {
	// if current element is smaller to or equal to pivot
	if (vec[j] <= pivot)
	{
	  i++;
	  std::swap(vec[i], vec[j]);
	}
  }
	
  // put pivot to its position
  std::swap(vec[i + 1], vec[high]);

  return i + 1;
}

void QuickSort::quick_sort(std::vector<uint16_t>& vec, size_t low, size_t high)
{
  // base case: This part will be executed till the starting index low is lesser than the ending index high
  if (low < high)
  {
	// if pi is partitioning index, vec[p] is now at the right place
	size_t pi = partition(vec, low, high);

	// sepparately sort elements before and after the partition index pi
	quick_sort(vec, low, pi - 1);
	quick_sort(vec, pi + 1, high);
  }
}
