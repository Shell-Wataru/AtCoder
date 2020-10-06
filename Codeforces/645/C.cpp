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
    ll n,x;
    cin >> n >> x;
    x--;
    vector<vector<ll>> G(n);
    for(int i = 0;i < n-1;i++){
        ll a,b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    if(G[x].size() == 1 || G[x].size() == 0){
        cout << "Ayush" << endl;
    }else{
        if (n % 2 == 0){
            cout << "Ayush" << endl;
        }else{
            cout << "Ashish" << endl;
        }
    }
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
