#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
using namespace std;
using ll = long long;
ll BASE_NUM = 998244353;

int solve()
{
    ll n, l, r;
    cin >> n >> l >> r;
    l--;
    r--;
    vector<ll> indexes;
    indexes.push_back(0);
    for (ll i = 0; i < n - 1; i++)
    {
        indexes.push_back(indexes.back() + (n - i - 1) * 2);
    }

    for (ll i = l; i <= r; i++)
    {
        if (i != l)
        {
            cout << " ";
        }
        ll index = lower_bound(indexes.begin(), indexes.end(), i, [](ll a, ll b) {
                       return a <= b;
                   }) - indexes.begin();
        ll a = i - indexes[index-1];
        if (index == n){
            cout << 1;
        }else if(a % 2 == 0){
            cout << index;
        }else{
            cout << index + (a+1)/2;
        }
    }
    cout << endl;
    return 0;
}

int main()
{
    ll t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}