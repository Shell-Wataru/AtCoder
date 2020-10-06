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
ll BASE_NUM = 1000000007;


int solve()
{
    // cout << "==" << endl;
    string S;
    ll n,k;
    scanf("%lld", &n);
    scanf("%lld", &k);
    cin >> S;
    vector<ll> nextOne(n,-1);
    ll last = BASE_NUM;
    for(int i = n -1;i >= 0;i--){
        if (S[i] == '1'){
            last = i;
        }
        nextOne[i] = last;
    }
    last = - BASE_NUM;
    ll ans = 0;
    for(int i = 0;i < n;i++){
        if (S[i] == '1'){
            last = i;
        }else{
            if (i - last > k && nextOne[i] - i > k){
                last = i;
                ans++;
            }
        }
    }
    cout << ans << endl;
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
