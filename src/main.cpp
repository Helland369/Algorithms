#include "include/BinarySearch.hpp"
#include "include/UniqueIntGen.hpp"
#include <cstdint>
#include <vector>

int main(int argc, char* argv[])
{
  UniqueIntGen i;

  std::vector<uint16_t> x = i.uint_10k_gen(true);

  BinarySearch b;

  b.binary_search(x, 333);

  
  return 0;
}    
