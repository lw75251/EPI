#include <vector>
#include "test_framework/generic_test.h"
using std::vector;

/* Goal: Update given array that represents integer D to represent the integer D+1 
   Example: <1,2,9> -> <1,3,0>
*/

// My First Attempt Algorithm (Correct solution)
// Time Complexity: O(n)
// IDEA: Start from end of array, and add. If its 10, then we continue to add 1 to the next
// digit place. If we successfully added without a carry, then we simply return the array.

vector<int> PlusOne(vector<int> A) {
  for ( int i = A.size()-1; i >= 0; --i ) {
    if ( A[i] + 1 == 10 ) {
      A[i] = 0;
    } else {
      A[i] += 1;
      return A;
    }
  }

  // If we reach the end without returning, means we need to add 1 more 
  A.emplace(A.begin(),1);
  return A;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "int_as_array_increment.cc",
                         "int_as_array_increment.tsv", &PlusOne,
                         DefaultComparator{}, param_names);
}
