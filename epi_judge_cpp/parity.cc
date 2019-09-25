#include "test_framework/generic_test.h"

// DEFINITION: Parity of a binary word is 1 if the number of 
// 1s in the word is odd; otherwise it is 0.

// BRUTE-FORCE Algorithm
// Time complexity: O(n) where n is the word size (number of bits)

short BruteForce_Parity(unsigned long long x) {
  short result = 0;
  while (x) {
//    result++;   // Drawback is that if the number is large enough, then
                  // we could potentially reach the int_max. A better way
                  // would be the following:

    result ^= ( x & 1 ); // This acts as %2. Since we only care about evens
                         // and odds, the value alternates between 1 and 0.
                         // This is much better since we won't ever have to
                         // worry about hitting the max.
    x >>= 1;
  }
  
  return result;
}

// More Optimized Algorithm
// Time complexity: O(k) where k is the number of 1s

short Faster_Parity(unsigned long long x) {
  short result = 0;
  while (x) {
    result ^= 1;
    x &= (x-1);         // Drops lowest set bit of x
  }
  
  return result;
}

// Optimized Algorithm
// Time Complexity: O(log n) where n is the length of the word
// TODO: Review HOW this works

short Parity(unsigned long long x) {
  x ^= x >> 32;
  x ^= x >> 16;
  x ^= x >> 8;
  x ^= x >> 4;
  x ^= x >> 2;
  x ^= x >> 1;
  return x & 0x1;
}


int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "parity.cc", "parity.tsv", &Parity,
                         DefaultComparator{}, param_names);
}
