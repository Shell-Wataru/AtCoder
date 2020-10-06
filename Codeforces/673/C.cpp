#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>

using namespace std;
using ll = long long;
const ll BASE_NUM = 1000000007;

int solve()
{
    ll n;
    scanf("%lld", &n);
    vector<vector<ll>> number_occurs(n+1);
    vector<ll> number_sukima(n+1,n+1);
    for (size_t i = 0; i < n; i++)
    {
        ll a;
        scanf("%lld",&a);
        number_occurs[a].push_back(i);
    }

    for(int i = 0;i <= n;i++){
        ll last = -1;
        ll max_sukima = 0;
        for(int j = 0; j < number_occurs[i].size();j++){
            max_sukima = max(max_sukima, number_occurs[i][j] - last - 1);
            last = number_occurs[i][j];
        }
        max_sukima = max(max_sukima, n - last - 1);
        number_sukima[i] = max_sukima;
    }
    // for(int i = 0;i <= n;i++){
    //     cout << i << " "<<number_sukima[i] << endl;
    // }
    vector<ll> ans(n+1);

    ll current = 0;
    for(int i = n;i >= 0;i--){
        while(current <= n && number_sukima[current] >= i){
            current++;
        }
        if (current == n+1){
            ans[i] = -1;
        }else{
            ans[i] = current;
        }
    }
    for(int i = 1;i <= n;i++){
        if (i != 1){
            cout << " ";
        }
        cout << ans[i];
    }
    cout << endl;
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
    // cout << flush;
    return 0;
}
