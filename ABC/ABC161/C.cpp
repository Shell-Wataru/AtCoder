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
    ll max_diff = 0;
    ll N,K;
    cin >> N >> K;
    cout << min(abs(N % K), K - abs(N % K)) << endl;
   return 0;
}