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

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<ll> a(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    vector<ll> DP(N,numeric_limits<ll>::max());
    DP[0] = 0;
    for(int i = 1;i < N;i++){
        DP[i] = min(DP[i], DP[i-1] + abs(a[i] - a[i-1]));
        if (i - 2 >= 0){
            DP[i] = min(DP[i], DP[i-2] + abs(a[i] - a[i-2]));
        }
    }
    cout << DP[N-1] << endl;
    return 0;
}