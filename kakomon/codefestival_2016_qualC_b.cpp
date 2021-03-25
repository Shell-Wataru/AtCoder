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
    ll K, T;
    cin >> K >> T;
    vector<ll> a(T);
    for(int i = 0;i < T;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end(),greater<ll>());
    cout << max(a[0] - (K - a[0]) - 1,0ll) << endl;
    return 0;
}