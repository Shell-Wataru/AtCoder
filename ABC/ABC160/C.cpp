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
    cin >> K >> N;
    vector<ll> A(N);
    for(int i = 0;i < N;i++){

        cin >> A[i];
    }
    for(int i = 0;i < N;i++){
        max_diff = max(max_diff,(K + A[(i+ 1)% N] - A[i]) % K);
    }

    cout << K - max_diff << endl;
   return 0;
}