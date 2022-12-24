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
    ll n,m;
    cin >> n >> m;
    vector<string> G(n);
    for(int i = 0;i < n;i++){
        cin >> G[i];
    }
    ll min_i = n;
    ll min_j = m;
    for(ll i = 0;i < n;i++){
        for(ll j = 0;j < m;j++){
            if (G[i][j] == 'R'){
                min_i = min(min_i,i);
                min_j = min(min_j,j);
            }
        }
    }
    if (G[min_i][min_j] == 'R'){
        cout << "YES";
    }else{
        cout << "NO";
    }
    cout << "\n";
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
    cout << flush;
    return 0;
}
