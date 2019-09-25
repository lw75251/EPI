#include <algorithm>
#include <vector>
#include "test_framework/generic_test.h"
using namespace std;


// My First Attempt
vector<int> Multiply(vector<int> num1, vector<int> num2) {

  vector<int> ans( num1.size()+ num2.size() );
  const int sign = (num1.front() < 0) ^ (num2.front() < 0) ? -1 : 1;
  num1.front() = abs(num1.front()), num2.front() = abs(num2.front());

  for ( int i = num1.size()-1; i >= 0; --i ) {
    for ( int j = num2.size()-1; j >= 0; --j ) {
      ans[i+j+1] += num1[i]*num2[j];
      ans[i+j] += ans[i+j+1]/10;
      ans[i+j+1] %= 10;
    }
  }

  ans = {
      find_if_not( begin(ans), end(ans), [](int a) { return a == 0; }),
      end(ans)};

  if (ans.empty()) {
    return {0};
  }

  ans.front() *= sign;
  return ans;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"num1", "num2"};
  return GenericTestMain(args, "int_as_array_multiply.cc",
                         "int_as_array_multiply.tsv", &Multiply,
                         DefaultComparator{}, param_names);
}
