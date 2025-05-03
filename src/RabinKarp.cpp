#include "include/RabinKarp.hpp"
#include <iostream>

RabinKarp::RabinKarp() {}

RabinKarp::~RabinKarp() {}

void RabinKarp::rabin_karp(std::string pat, std::string txt, int q)
{
  int m = pat.size();
  int n = txt.size();
  int i, j;
  int p = 0; // hash value for pattern
  int t = 0; // hash vaue for txt
  int h = 1;
  int d = 256; // d is the number of characters in the input alphabet

  for (i = 0; i < m; i++)
    h = (h * d) % q;

  // calculate the hash value of pattern and first window of text
  for (i = 0; i < m; i++)
  {
    p = (d * p + pat[i]) % q;
    t = (d * t + txt[i]) % q;
  }

  // slide the pattern over text one by one
  for (i = 0; i <= n - m; i++)
  {
    // check the hash values for current window of text and pattern.
    // if the hash values match then only check for chatacters one by one
    if (p == t)
    {
      // check for characters one by one
      for (j = 0; j < m; j++)
      {
        if (txt[i + j] != pat[j])
        {
          break;
        }
      }

      // if p == t and pat[0...m-1] = txt[i, i+1, ...i+m-1]
      if (j == m)
        std::cout << "Pattern found at index " << i << "\n";
    }

    // calculate hash value for next window of text:
    // remove leading digit, add trailing digit
    if (i < n - m)
    {
      t = (d * (t - txt[i] * h) + txt[i + m]) % q;

      // we might get negaitve value of t, converting it to positive
      if (t < 0)
        t = (t + q);
    }
  }
}    

