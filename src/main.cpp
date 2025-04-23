#include "include/BinarySearch.hpp"
#include "include/UniqueIntGen.hpp"
#include "include/BubbleSort.hpp"
#include "include/MergeSort.hpp"
#include "include/JumpSearch.hpp"
#include <chrono>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <vector>

uint16_t input_option()
{
  uint16_t input;
  std::cout << "Write a number between 0 & 10000\n";
  std::cin >> input;
  return input;
}

int main(int argc, char* argv[])
{
  UniqueIntGen i;
  BubbleSort buble;
  MergeSort m;
  BinarySearch bin;
  JumpSearch jump;

  std::vector<uint16_t> vec = i.uint_10k_gen(false);
  std::vector<uint16_t> sorted_vec = i.uint_10k_gen(true);

  int input, index;
  uint16_t key;

  for (;;)
  {
    std::cout << "*** Algorithms ***\n" << "[1] Bubble sort\n" << "[2] Merge sort\n" << "[3] Binary search\n" << "[4] Jump search\n" << "[0] EXIT\n" << "\n";

    std::cin >> input;

    // timing helpe
    auto mesure_time = [](auto&& func) {
      auto start = std::chrono::high_resolution_clock::now();
      func();
      auto stop = std::chrono::high_resolution_clock::now();
      return std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
    };
    
    switch (input)
    {
    case 0:
      return 0;
    case 1:
      {
        auto duration = mesure_time([&]() {
          buble.bubble_sort(vec, 10000);
        });
        for (auto y : vec)
        {
          std::cout << y << "\n";
        }
        std::cout << "Microseconds: " << duration << "\n";
        break;
      }
    case 2:
      {
        auto duration = mesure_time([&]() {
          m.merge_sort(vec, 0, vec.size() - 1);
        });
        for (auto y : vec)
        {
          std::cout << y << "\n";
        }
        std::cout << "Microseconds: " << duration << "\n";
        break;
      }
    case 3:
      {
        key = input_option();
        auto duration = mesure_time([&]() {
          bin.binary_search(sorted_vec, key);
        });
        std::cout << "Microseconds: " << duration << "\n";
        key = 0;
        break;
      }
    case 4:
      {
        key = input_option();
        auto duration = mesure_time([&]() {
          index = jump.jump_search(sorted_vec, sorted_vec.size(), key);
        });
        if (index != -1)
        {
          std::cout << key << " was found at index: " << index << "\n";
        }
        else
        {
          std::cout << key << " was not found..,\n";
        }
        std::cout << "Millisedconds: " << duration << "\n";
        key = 0;
        break;
      }
    default:
      std::cout << "Invalid input!" << "\n";
      break;
    }
  }

  return 0;
}    
