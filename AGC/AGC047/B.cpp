#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>
#include <list>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<vector<vector<ll>>> A(N);
    for (size_t i = 0; i < N; i++)
    {
      cin >> A[i];
      reverse(A[i].begin(),A[i].end());
    }
    return 0;
}