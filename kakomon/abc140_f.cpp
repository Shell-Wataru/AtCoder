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

int clz(unsigned long long N)
{
    return N ? 64 - __builtin_clzll(N) : 0;
}

int solve()
{
    ll N;
    cin >> N;
    vector<ll> S(1ll<<N);
    for(ll i = 0;i < 1ll<<N;i++){
        cin >> S[i];
    }
    sort(S.rbegin(),S.rend());
    vector<priority_queue<ll>> qs(N+1);
    qs[N].push(numeric_limits<ll>::max());
    for(ll i = 0;i < 1ll<<N;i++){
        bool pushed = false;
        for(int j = N;j>=0;j--){
            if (!qs[j].empty() && qs[j].top() > S[i]){
                qs[j].pop();
                for(int k = 0;k < j;k++){
                    qs[k].push(S[i]);
                }
                pushed = true;
                break;
            }
        }
        if (!pushed){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

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
    // cout << flush;
    return 0;
}
