#include <vector>
#include <queue>
#include "test_framework/generic_test.h"
using namespace std;


/* Dynamic Programming Approach 
  Let A[i,j] denote that you purchase on the ith day and sell on the jth day.
  
*/
double BuyAndSellStockTwice(const vector<double>& prices) {
  priority_queue<double> profits;

}

int main(int argc, char* argv[]) {
  vector<string> args{argv + 1, argv + argc};
  vector<string> param_names{"prices"};
  return GenericTestMain(args, "buy_and_sell_stock_twice.cc",
                         "buy_and_sell_stock_twice.tsv", &BuyAndSellStockTwice,
                         DefaultComparator{}, param_names);
}
