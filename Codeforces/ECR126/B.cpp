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
#include <numeric>
using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

vector<ll> answers(32768,numeric_limits<ll>::max()/2);

int solve()
{
    ll n;
    cin >> n;
    for(int i = 0;i < n;i++){
        ll a;
        cin >> a;
        if (i != 0){
            cout << " ";
        }
        cout << answers[a];
    }
    cout << "\n";

    return 0;
}
int main()
{
    queue<pair<ll,ll>> q;
    answers[0] = 0;
    q.emplace(0,0);
    while(!q.empty()){
        auto current = q.front().first;
        // cout << current << endl;
        auto d = q.front().second;
        q.pop();
        if (d + 1 < answers[(current  - 1 + 32768) % 32768]){
            answers[(current - 1 + 32768) % 32768] = d + 1;
            q.emplace((current - 1 + 32768) % 32768, d+1);
        }
        if (d + 1 < answers[current/ 2]){
            answers[current/2] = d + 1;
            q.emplace(current/2, d + 1);
        }
        if (d + 1 < answers[(current/ 2 + (1ll<<14)) % 32768]){
            answers[(current/ 2 + (1ll<<14)) % 32768] = d + 1;
            q.emplace((current/ 2 + (1ll<<14)) % 32768, d + 1);
        }
    }
    // ll t;
    // cin >> t;
    // for (int i = 1; i <= t; i++)
    // {
        solve();
    // }
    cout << flush;
    return 0;
}
