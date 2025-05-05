#include <string>


class Sha256
{
public:
  Sha256();
  ~Sha256();
  std::string sha256_algorithm(const std::string& str);
};
