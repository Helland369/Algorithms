#include <cstddef>
#include <cstdint>
#include <vector>


class QuickSort
{
private:
  size_t partition(std::vector<uint16_t>& vec, size_t low, size_t high);

public:
  QuickSort();
  ~QuickSort();

  void quick_sort(std::vector<uint16_t>& vec, size_t low, size_t high);
};
