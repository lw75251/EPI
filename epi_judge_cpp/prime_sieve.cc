#include <vector>
#include <math.h>
#include "test_framework/generic_test.h"
using namespace std;

vector<int> GeneratePrimes(int n) {
  if ( n < 2 ) {
    return {};
  }

  const int size = floor(0.5 * (n-3)) + 1;
  vector<int> primes;
  deque<bool> is_prime(size,true);
  primes.emplace_back(2);

  // is_prime[i] represents whether (2i+3) is prime or not
  // is_prime[0] -> 3
  // is_prime[1] -> 5
  for ( int i = 0; i < size; ++i ) {
    if ( is_prime[i] ) {
      int p = (i * 2) + 3;
      primes.emplace_back(p);

      for ( long long j = 2LL * i * i + 6 * i + 3; j < size; j += p ) {
        is_prime[j] = false;
      }
    }
  }

  return primes;
}


// Prime Sieving
// Given n, return all primes up to and including n.
vector<int> EfficientGeneratePrimes(int n) {
  if ( n < 2 ) {
    return {};
  }

  vector<int> primes;
  deque<bool> is_prime(n+1,true);
  is_prime[0] = is_prime[1] = false;
  for ( int p = 2; p <= n; ++p ) {
    if ( is_prime[p] ) {
      primes.emplace_back(p);
    }
    for ( int i = p*2; i <= n; i += p ) {
      is_prime[i] = false;
    }
  }

  return primes;
}



// Given n, return all primes up to and including n.
// vector<int> GeneratePrimes(int n) {
//   // TODO - you fill in here.
//   return {};
// }

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n"};
  return GenericTestMain(args, "prime_sieve.cc", "prime_sieve.tsv",
                         &GeneratePrimes, DefaultComparator{}, param_names);
}
