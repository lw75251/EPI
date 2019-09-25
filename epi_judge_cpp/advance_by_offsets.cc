#include <vector>
#include "test_framework/generic_test.h"
using namespace std;
using std::vector;

/* Given an array, the player's goal is to reach the end of the array.
   Each position has an integer associated to it that represents the
   max you can advance in one move */

// First Attempt Algorithm
// IDEA: Greedy-Alg -> If we see a spot that has more moves than what
// we currently have, then we stop there and grab the most moves possible.
// Time Complexity: O(n)
// Space Complexity: O(1)
bool CanReachEnd(const vector<int>& max_advance_steps) {
  int moves = 0;
  for ( int i = 0, e = max_advance_steps.size(); i < e; ++i, --moves) {
    moves = max(max_advance_steps[i], moves);
    if ( moves == 0 && i+1 != e) return false;
  }
  return true;
}

// Variant: Write a program to compute the minimum number of steps needed to
// advance to the last location

// First Attempt Algorithm
// IDEA: Start from the end. The index difference will tell us how many
// steps a spot must have. If we find multiple valid spots to step, then
// we take the min of the two.

// Note: size - index = distance needed for us to restart to one step
// Example-> Board: 3,3,1,0,2,0,1
//                  ^   ^   ^   ^
//                  4   3   2   1

int minSteps( const vector<int>& board ) {
  int steps = 1;
  int e = board.size()-1;
  int count = 0;
  for ( int i = e; i >= 0; --i, ++count ) {
    if ( board[i] >= count ) {
      ++steps;
    }
    else if ( board[i] >=  e-i ) {
      steps = 1;
    }
  }

  return steps;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"max_advance_steps"};
  return GenericTestMain(args, "advance_by_offsets.cc",
                         "advance_by_offsets.tsv", &CanReachEnd,
                         DefaultComparator{}, param_names);
}
