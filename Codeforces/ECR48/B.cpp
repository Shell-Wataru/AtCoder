#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int solve()
{
    ll n,m,q;
    string a,b;
    cin >> n >> m >> q;
    cin >> a >> b;
    vector<ll> occurences(n,0);
    for(int i = 0;i + m< n;i++){
        // cout << (a.substr(i, m) == b) << endl;
        if (a.substr(i, m) == b){
            // cout << "i" << i << endl;
            occurences[i + m - 1]++;
        }
    }

    map<pair<ll,ll>,ll> counts;
    for(int i = 0;i< n;i++){
        for(int j = i + m - 1;j < n;j++){

        }
    }

    for(int i = 0 ;i < q;i++){
        ll l,r;
        cin >> l >> r;
        l--;
        // cout << "r" << occurences[r] << "l" << occurences[l] << endl;
        cout << occurences[r] - occurences[l] << endl;
    }
    return 0;
}
int main()
{
    // ll t;
    // cin >> t;
    // for (int i = 1; i <= t; i++)
    // {
        solve();
    // }
    return 0;
}
