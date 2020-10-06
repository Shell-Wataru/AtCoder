#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <iterator> // std::rbegin, std::rend
#include <functional>

using namespace std;
using ll = long long;

int solve()
{
    ll n;
    cin >> n;
    ll a = 0;
    ll b = 0;
    a += 1<<n;
    for(int i = 1;i <n/2;i++){
      a += 1<<i;
    }

    for(int i = n/2;i <n;i++){
      b += 1<<i;
    }
    // cout << a << " " << b << endl;
    cout << a - b << endl;
    return 0;
}

int main()
{
    // 整数の入力
    ll t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}