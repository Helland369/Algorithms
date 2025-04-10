#include <cstdint>
#include <vector>


class UniqueIntGen
{
private:
public:
  UniqueIntGen();
  ~UniqueIntGen();

  std::vector<uint16_t> uint_10k_gen(bool sorted);
};
