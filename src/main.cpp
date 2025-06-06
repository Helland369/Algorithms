#include "include/BinarySearch.hpp"
#include "include/UniqueIntGen.hpp"
#include "include/BubbleSort.hpp"
#include "include/MergeSort.hpp"
#include "include/JumpSearch.hpp"
#include "include/QuickSort.hpp"
#include "include/Kpm.hpp"
#include "include/RabinKarp.hpp"
#include "include/Sha256.hpp"
#include <chrono>
#include <climits>
#include <cstdint>
#include <ios>
#include <iostream>
#include <limits>
#include <string>
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
  QuickSort q;
  Kpm k;
  RabinKarp rk;
  Sha256 sha;
  
  std::vector<uint16_t> unsorted_vec = i.uint_10k_gen(false);
  std::vector<uint16_t> sorted_vec = i.uint_10k_gen(true);

  int input, index;
  uint16_t key;

  for (;;)
  {
    std::cout << "*** Algorithms ***\n" << "[1] Bubble sort\n" << "[2] Merge sort\n" << "[3] Quick sort\n" << "[4] Binary search\n" << "[5] Jump search\n" << "[6] Knuth-Morris-Pratt\n" << "[7] Rabin-karp\n" << "[8] Sha256\n" << "[0] EXIT\n" << "\n";

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
		auto vec_copy = unsorted_vec;
        auto duration = mesure_time([&]() {
          buble.bubble_sort(vec_copy, 9999);
        });
        for (auto y : vec_copy)
        {
          std::cout << y << "\n";
        }
        std::cout << "Microseconds: " << duration << "\n";
        break;
      }
    case 2:
      {
		auto vec_copy = unsorted_vec;
        auto duration = mesure_time([&]() {
          m.merge_sort(vec_copy, 0, vec_copy.size() - 1);
        });
        for (auto y : vec_copy)
        {
          std::cout << y << "\n";
        }
        std::cout << "Microseconds: " << duration << "\n";
        break;
      }
    case 3:
	  {
		auto vec_copy = unsorted_vec;
		auto duration = mesure_time([&]() {
          q.quick_sort(vec_copy, 0, vec_copy.size() - 1);
		});
		for (auto y : vec_copy)
		{
		  std::cout << y << "\n";
		}
		std::cout << "Microseconds: " << duration << "\n";
	    break;
	  }
    case 4:
      {
        key = input_option();
        auto duration = mesure_time([&]() {
          bin.binary_search(sorted_vec, key);
        });
        std::cout << "Microseconds: " << duration << "\n";
        key = 0;
        break;
      }
    case 5:
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
        std::cout << "Microseconds: " << duration << "\n";
        key = 0;
        break;
      }
    case 6:
      {
        std::string txt = "aabaacaadaabaaba";
        std::string pat = "aaba";
        std::vector<uint16_t> res;
        
        auto duration = mesure_time([&]() {
          res = k.kpm_search(pat, txt);
        });
        
        for (size_t i = 0; i < res.size(); i++)
        {
          std::cout << res[i] << "\n";
        }
        std::cout << "Microseconds: " << duration << "\n";
        break;
      }
    case 7:
      {
        std::string txt = "Emacs is the best editor";
        std::string pat = "Emacs";
        int q = INT_MAX;

        auto duration = mesure_time([&]() {
          rk.rabin_karp(pat, txt, q);
        });
        std::cout << "Microseconds: " << duration << "\n";
        break;
      }
    case 8:
      {
        std::string input;
        std::cout << "Enter text: " << "\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear buffer
        std::getline(std::cin, input);

        auto duration = mesure_time([&]() {
          std::string output = sha.sha256_algorithm(input);
          std::cout << "SHA256: " << output << "\n";
        });

        std::cout << "Microseconds: " << duration << "\n";
        break;
      }
    default:
      std::cout << "Invalid input!" << "\n";
      break;
    }
  }

  return 0;
}
