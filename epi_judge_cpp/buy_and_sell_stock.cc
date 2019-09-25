#include <vector>
#include "test_framework/generic_test.h"

using namespace std;

/* Given an array of stock prices, you are allowed to buy and sell once.
You must find the maximum profit you can get within the timeframe. 

  Example: <310, 315, 275, 295, 260, 270, 290, 230, 255, 250>
  The maximum profit is buying on 260 and selling on 290 for a profit of 30

*/

double BuyAndSellStockOnce(const vector<double>& prices) {

  if ( prices.empty() ) return 0;

  double profit = 0;
  double min_price = prices[0];
  for ( int i = 1, e = prices.size(); i < e; ++i ) {
    min_price = min(min_price,prices[i]);
    profit = max(profit,prices[i]-min_price);
  }

  return profit;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"prices"};
  return GenericTestMain(args, "buy_and_sell_stock.cc",
                         "buy_and_sell_stock.tsv", &BuyAndSellStockOnce,
                         DefaultComparator{}, param_names);
}
