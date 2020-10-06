#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <iterator> // std::rbegin, std::rend

using namespace std;
using ll = long long;

int solve()
{
    ll n,k;
    cin >> n >> k;
    ll min_sum = k * k;
    if (n < min_sum){
        cout << "NO" << endl;
    }else if (n % 2 != k % 2){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
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