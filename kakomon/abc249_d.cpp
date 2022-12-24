#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

int solve()
{
    ll N;
    cin >> N;
    vector<ll> A(200001,0);
    for(int i = 0;i < N;i++){
        ll a;
        cin >> a;
        A[a]++;
    }
    // cout << "!" << endl;
    ll ans = 0;
    for(ll i =1;i <= 200000;i++){
        for(ll j = 1;i*j<=200000;j++){
            ans += A[i]*A[j]*A[i*j];
        }
    }
    cout << ans  << "\n";
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
    cout << flush;
    return 0;
}
