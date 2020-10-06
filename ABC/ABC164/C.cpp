#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
ll BASE_NUM = 1000000007;

int main()
{
    // 整数の入力

    ll N;
    cin >>  N;
    set<string> sss;
    for(int i = 0;i < N;i++){
        string s;
        cin >> s;
        sss.insert(s);
    }
    cout << sss.size() << endl;
  return 0;
}