#pragma once

#include <string>
class RabinKarp
{
public:
  RabinKarp();
  ~RabinKarp();

  void rabin_karp(std::string pat, std::string txt, int q);
};
