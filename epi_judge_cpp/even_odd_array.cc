#include <set>
#include <vector>
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"
using namespace std;

// Efficient Algorithm
// Time-Complexity: O(n)

void EvenOdd(vector<int>* A_ptr) {
  // Idea: We partition the array into three groups: EVEN, UNCLASSIFIED, ODD.
  // As we go through, we swap positions to he end (ODD partition). The 
  // UNCLASSIFIED portion shrinks as we iterate through the array.

  vector<int>& A = *A_ptr;
  int left = 0; int right = A.size()-1;
  while ( left < right ) {
    if ( A[left] % 2 == 0 ) {
      ++left;
    } else {
      swap(A[left], A[right--]);
    }
  }

  return;
}
void EvenOddWrapper(TimedExecutor& executor, vector<int> A) {
  std::multiset<int> before(begin(A), end(A));

  executor.Run([&] { EvenOdd(&A); });

  bool in_odd = false;
  for (int a : A) {
    if (a % 2 == 0) {
      if (in_odd) {
        throw TestFailure("Even elements appear in odd part");
      }
    } else {
      in_odd = true;
    }
  }

  std::multiset<int> after(begin(A), end(A));
  if (before != after) {
    throw TestFailure("Elements mismatch");
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "A"};
  return GenericTestMain(args, "even_odd_array.cc", "even_odd_array.tsv",
                         &EvenOddWrapper, DefaultComparator{}, param_names);
}
