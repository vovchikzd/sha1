module;

#include <climits>
#include <sstream>
#include <string>

export module sha1;
using uint  = unsigned int;
using citer = std::string::const_iterator;

export struct sha1 {
private:
  size_t bmsl_;

  const uint h0_init_ = 0x67452301;
  const uint h1_init_ = 0xEFCDAB89;
  const uint h2_init_ = 0x98BADCFE;
  const uint h3_init_ = 0x10325476;
  const uint h4_init_ = 0xC3D2E1F0;

  uint h0_ = h0_init_;
  uint h1_ = h1_init_;
  uint h2_ = h2_init_;
  uint h3_ = h3_init_;
  uint h4_ = h4_init_;

  void pre_process_(citer begin, citer end) {}

  auto lrotate(uint value, uint count = 1) -> uint {
    const uint mask = CHAR_BIT * sizeof(value) - 1;
    count &= mask;
    return (value << count) | (value >> (-count & mask));
  }

public:
  sha1(const std::string& str = "")
      : bmsl_(CHAR_BIT * str.size()) {
    pre_process_(str.begin(), str.end());
  }

  auto hash() -> std::string {
    std::stringstream res;
    res << lrotate(h0_, 128) << lrotate(h1_, 96) << lrotate(h2_, 64)
        << lrotate(h3_, 32) << h4_;
    return res.str();
  }
};
