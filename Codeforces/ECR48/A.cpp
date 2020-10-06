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
    ll n,m;
    cin >> n >> m;
    vector<ll> A(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    ll total = 0;
    for(int i = 0;i < n;i++){
        ll start = total;
        ll end = total + A[i];
        if (i != 0){
            cout << " ";
        }
        cout << (end/m - start/m);
        total = end;
    }
    cout << endl;
    return 0;
}

int main()
{
    // 整数の入力
    // ll t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
        solve();
    // }
    return 0;
}