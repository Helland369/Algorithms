#include "include/Kpm.hpp"

// Knuth-Morris-Pratt

void Kpm::construct_lps(std::string& pat, std::vector<uint16_t>& lps)
{
  // len stores the length of longet prefix which is also a suffix for the previous index
  int len = 0;

  // lps[0] is always 0
  lps[0] = 0;

  int i = 1;
  while (i < pat.length())
  {
    // if character match increment the size of lps
    if (pat[i] == pat[len])
    {
      len++;
      lps[i] = len;
      i++;
    }

    // if there is a mismatch
    else
    {
      if (len != 0)
      {
        // update len to the previous lps value to avoid redundant comarisons
        len = lps[len -1];
      }
      else
      {
        // if no matching prefix found, set lps[i] to 0
        lps[i] = 0;
        i++;
      }
    }
  }
}

std::vector<uint16_t> Kpm::kpm_search(std::string &pat, std::string &txt)
{
  int n = txt.length();
  int m = pat.length();

  std::vector<uint16_t> lps(m);
  std::vector<uint16_t> res;

  construct_lps(pat, lps);

  int i = 0, j = 0;

  while (i < n)
  {
    // if character match move both pointers forward
    if (txt[i] == pat[j])
    {
      i++;
      j++;

      // if the entire pattern is matched sotre the start index in result
      if (j == m)
      {
        res.push_back(i - j);

        // use LPS of previous index to skip unnecessary comparisons
        j = lps[j - 1];
      }
    }
      // if there is a mismatch
    else
    {
      // use lps value of previous index to avoid redundant comarisons
      if (j != 0)
      {
        j = lps[j - 1];
      }
      else
      {
        i++;
      }
    }
  }
  return res;
}
