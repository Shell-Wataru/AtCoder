#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
using namespace std;
using ll = long long;

int solve()
{
    ll n;
    scanf("%lld", &n);
    set<pair<ll, ll>> ranges;
    for (int i = 0; i < n; i++)
    {
        ll s, c;
        cin >> s >> c;
        auto iter = ranges.upper_bound({s,numeric_limits<ll>::max()});
        if (iter == ranges.end()){
            cout << s + c - 1 << "\n";
            ranges.insert({s+c,s});
        }else{
            vector<pair<ll,ll>> removes;

            // cout << iter->second << "~" << iter->first << endl;
            while(iter != ranges.end()){
                // cout <<"s:" << s << ",c:" << c << endl;
                ll l = iter->second;
                ll r = iter->first;
                if (s + c <= l){
                    break;
                }else{
                    s = min(s,l);
                    c = c + r - l;
                    removes.push_back({r,l});
                    iter++;
                }
            }
            cout << s + c - 1 << "\n";
            ranges.insert({s+c,s});
            for(auto r:removes){
                ranges.erase(r);
            }
        }
    }
    return 0;
}

int main()
{
    // // 整数の入力
    // ll t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
    solve();
    // }
    // cout << flush;
    return 0;
}
