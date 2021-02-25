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
const int BASE_NUM = 1000000007;

void update_pasts(vector<pair<ll,ll>> &pasts,ll current_continues,ll &past_total){
    if (!pasts.empty() && pasts.back().first < current_continues){
        past_total += (current_continues - pasts.back().first)* pasts.back().second;
        pasts.back().first = current_continues;
    }
    while(pasts.size() > 1){
        if (pasts[pasts.size() -1].first > pasts[pasts.size() -2].first){
            ll continues = pasts[pasts.size() -1].first;
            ll indexes = pasts[pasts.size() -1].second;
            past_total += (pasts[pasts.size() -1].first - pasts[pasts.size() -2].first)* pasts[pasts.size() -2].second;
            pasts.pop_back();
            pasts.back().first = continues;
            pasts.back().second += indexes;
        }else{
            break;
        }
    }
}
int solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll total = 0;
    vector<pair<ll,ll>> pasts;
    ll pasts_total = 0;
    ll current_continues = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (s[i] == '1'){
            current_continues++;
            update_pasts(pasts,current_continues,pasts_total);
            total += (current_continues + 1) * current_continues /2 + pasts_total;
        }else{
            for(int i =  current_continues; i >= 0;i--){
                pasts.push_back({i,1});
            }
            pasts_total += (current_continues + 1) * current_continues /2;
            current_continues = 0;
            total += pasts_total;
        }
    }
    cout << total << endl;
    return 0;
}
int main()
{
    // 整数の入力
    // int t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
        solve();
        // }
    // cout << flush;
    return 0;
}
