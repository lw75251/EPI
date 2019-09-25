#include <iostream>
#include <vector>
#include "test_framework/generic_test.h"
using namespace std;
using std::vector;

// Definition: H-Index is the largest number "h" such that the researcher has published
// "h" papers that have each been cited at least "h" times. 

// Example: Carl has produced the following Papers
// Papers:           [ A,  B, C,  D, E, F, G,  H,  I]
// # of Times Cited: [ 1, *4, 1, *4, 2, 1, 3, *5, *6]
// H-Index: 4

// Optimized Algorithm
// Time Complexity: O(n*log n)
// IDEA: Sort the list, and since all papers to the right of
// current index is greater or equal to current paper, we know
// the h_index is the remaining entries
int HIndex( vector<int> citations ) {
  sort(citations.begin(),citations.end());
  for (int i = 0, e = citations.size(); i < e; ++i ) {
    if ( citations[i] >= e-i ) {
      return e-i;
    }
  }

  return 0;
}

// Brute-Force Algorithm
// Time Complexity: O(n^2)
int BruteForce_HIndex(vector<int> citations) {

  bool next = true;
  int h_index = 0;

  while ( next ) {
    next = false;
    int count = 0;
    for ( int i = 0, e = citations.size(); i != e; ++i ) {
      if ( citations[i] >= h_index ) {
        ++count;
      }
    }

    if ( count >= h_index ) {
      next = true;
      ++h_index;
    }
  }

  return --h_index;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"citations"};
  return GenericTestMain(args, "h_index.cc", "h_index.tsv", &HIndex,
                         DefaultComparator{}, param_names);
}
