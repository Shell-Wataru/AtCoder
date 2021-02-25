#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <ctime>
#include <map>
#include <boost/multiprecision/cpp_int.hpp>
#include <string>
#include <numeric>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

const long long BASE_NUM = 1000000007;

int main()
{
  ll N;
  string s;
  cin >> N;
  cin >> s;
  string checker = "";
  ll count = 0;
  for(auto &c:s){
    checker.push_back(c);
    ll size = checker.size();
    if (size >= 3 && checker[size-3] == 'f' && checker[size-2] == 'o' && checker[size-1] == 'x'){
      checker.pop_back();
      checker.pop_back();
      checker.pop_back();
    }
  }
  cout << checker.size() << endl;
  return 0;
}