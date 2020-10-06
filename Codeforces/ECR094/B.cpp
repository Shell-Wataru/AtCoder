#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <bitset>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int solve()
{
    ll p,f,s_cnt,w_cnt,s,w;
    cin >> p >> f;
    cin >> w_cnt >> s_cnt >> w >> s;
    if (s > w){
        swap(s,w);
        swap(s_cnt,w_cnt);
    }
    ll ans = 0;
    for(int i = 0;i <= s_cnt;i++){
        if (p - s * i  < 0){
            continue;
        }
        ll p_w_cnt =  min(w_cnt,(p - s * i)/w);
        ll f_s_cnt = min(s_cnt - i, f/s);
        if (f - s * f_s_cnt < 0){
            continue;
        }
        ll f_w_cnt = min(w_cnt - p_w_cnt, (f - s * f_s_cnt)/w);
        if (p_w_cnt >= 0 && f_s_cnt >= 0 && f_w_cnt >= 0){
            ans = max(ans,i+p_w_cnt+f_s_cnt+f_w_cnt);
        }
    }
    cout << ans << endl;
    return 0;
}
int main()
{
    ll t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}
