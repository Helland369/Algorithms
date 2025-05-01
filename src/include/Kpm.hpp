#include <cstdint>
#include <string>
#include <vector>

// Knuth-Morris-Pratt

class Kpm
{
private:
  void construct_lps(std::string& pat, std::vector<uint16_t>& lps);
public:
  std::vector<uint16_t> kpm_search(std::string& pat, std::string& txt);
};
