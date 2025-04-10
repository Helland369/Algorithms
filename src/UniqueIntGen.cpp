#include "include/UniqueIntGen.hpp"
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <random>


UniqueIntGen::UniqueIntGen() {}

UniqueIntGen::~UniqueIntGen() {}

std::vector<uint16_t> UniqueIntGen::uint_10k_gen(bool sorted)
{
  std::vector<uint16_t> vec;

  for (size_t i = 1; i < 10000; i++)
  {
    vec.push_back(i);
  }

  if (!sorted)
  {
    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(vec), std::end(vec), rng);
  }

  for (auto &x : vec)
  {
    std::cout << vec[x] << "\n";
  }    
  
  return vec;
}    
