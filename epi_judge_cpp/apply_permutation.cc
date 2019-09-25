#include <vector>
#include "test_framework/generic_test.h"

using namespace std;

/* Optimized Algorithm
Time Complexity: O(n)
Space Complexity: O(1)
IDEA: Iterate through permutation vector. We continue to swap at 
an index until we return to the "original index position". As we swap
the permutation one, we also swap the corresponding positions in A.

Example: permutation A = <a,b,c,d> and perm = <2,0,1,3>

perm = <1,0,2,3>            // swapped perm[0] and perm[2]
perm = <0,1,2,3>            // swapped perm[0] and perm[1]

Now that 0 is in the correct spot we go to the next index. Turns out,
as we swapped, 1,2 and 3 are all now in the correct positions. So we are done.
*/
void ApplyPermutation(vector<int>* perm_ptr, vector<int>* A_ptr) {
  for ( int i = 0, e = A_ptr->size(); i < e; ++i ) {
    while ( (*perm_ptr)[i] != i ) {
      swap((*A_ptr)[i], (*A_ptr)[(*perm_ptr)[i]]);
      swap((*perm_ptr)[i], (*perm_ptr)[(*perm_ptr)[i]]);
    }
  }

  // vector<int> perm = *perm_ptr;
  // vector<int> A = *A_ptr; 
  // for ( int i = 0, e = A.size(); i < e; ++i ) {
  //   while ( perm[i] != i ) {
  //     swap(A[i], A[perm[i]]);
  //     swap(perm[i], perm[perm[i]]);
  //   }
  // }
}

/* First Attempt Algorithm
Time Complexity: O(n)
Space Complexity: O(n)
IDEA: Create a new array of the same size. Iterate through the permutation vector and place
the value of A[i] into the desired placement given by the permutation vector. */
void FirstAttemptApplyPermutation(vector<int>* perm_ptr, vector<int>* A_ptr) {
  int size = perm_ptr->size();
  vector<int> perm = *perm_ptr;
  vector<int> A = *A_ptr;
  vector<int> permutated(size);

  for ( int i = 0; i < size; ++i ) {
    permutated[perm[i]] = A[i];
  }

  for ( int i = 0; i < size; ++i ) {
    (*A_ptr)[i] = permutated[i];
  }
  return;
}
vector<int> ApplyPermutationWrapper(vector<int> perm, vector<int> A) {
  ApplyPermutation(&perm, &A);
  return A;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"perm", "A"};
  return GenericTestMain(args, "apply_permutation.cc", "apply_permutation.tsv",
                         &ApplyPermutationWrapper, DefaultComparator{},
                         param_names);
}
