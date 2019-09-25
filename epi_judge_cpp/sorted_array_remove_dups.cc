#include <vector>
#include "test_framework/generic_test.h"
#include "test_framework/timed_executor.h"
using namespace std;

/* Given a sorted array remove all duplicate entries */

// Returns the number of valid entries after deletion.
int DeleteDuplicates(vector<int>* A_ptr) {
  vector<int>& A = *A_ptr;
  if ( A.size() == 0 ) return 0;

  int i = 0;
  // Optimized Algorithm
  // IDEA: We have a slow and fast pointer. While A[slow] == A[fast] that means
  // we are on a duplicate run, and only increment j. When A[slow] != A[fast] that
  // means the duplicate run has ended. We must place the next non-duplicate value
  // in A[slow+1].
  // Time Complexity: O(n)
  // Space Complexity: O(1)
  for (int j = 1, e = A.size(); j < e; ++j ) {
    if ( A[i] != A[j] ) {
      A[++i] = A[j];
    }
  }

  return i+1;
}
vector<int> DeleteDuplicatesWrapper(TimedExecutor& executor, vector<int> A) {
  int end = executor.Run([&] { return DeleteDuplicates(&A); });
  A.resize(end);
  return A;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "A"};
  return GenericTestMain(
      args, "sorted_array_remove_dups.cc", "sorted_array_remove_dups.tsv",
      &DeleteDuplicatesWrapper, DefaultComparator{}, param_names);
}
