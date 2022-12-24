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
#include <cmath>
using namespace std;
using ll = long long;

int solve()
{
    ll n;
    cin >> n;
    vector<ll> C(n);
    vector<set<ll>> G(n);
    queue<ll> q;
    for(int i = 0;i < n-1;i++){
        ll a,b;
        cin >> a >> b;
        a--;
        b--;
        G[a].insert(b);
        G[b].insert(a);
    }
    for(int i = 0;i < n;i++){
        cin >> C[i];
    }
    sort(C.rbegin(),C.rend());
    for(int i = 0;i < n;i++){
        if (G[i].size() == 1){
            q.push(i);
        }
    }
    ll ans = 0;
    vector<ll> weights(n);
    while(!q.empty()){
        ll current = q.front();
        q.pop();
        weights[current] = C.back();
        if (G[current].size() == 1){
            ans += C.back();
        }
        C.pop_back();
        for(auto to:G[current]){
            G[to].erase(current);
            if (G[to].size() == 1){
                q.push(to);
            }
        }
    }
    cout << ans << endl;
    for(int i = 0;i < n;i++){
        if (i != 0){
            cout << " ";
        }
        cout << weights[i];
    }
    cout << endl;
    return 0;
}

int main()
{
    // // 整数の入力
    //   ll t;
    //   cin >> t;
    //   for (size_t i = 0; i < t; i++)
    //   {
    solve();
    //   }
    //   cout << flush;
    return 0;
}
