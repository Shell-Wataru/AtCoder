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
    ll n, k;
    cin >> n >> k;
    set<ll> used;
    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        used.insert(a);
    }
    if (used.size() > k){
        cout << -1 << endl;
    }else{
        vector<ll> ans;
        for (int i = 0; i < n; i++)
        {
            for(auto i:used){
                ans.push_back(i);
            }
            for(int j = used.size(); j < k;j++){
                ans.push_back(1);
            }
        }
        cout << ans.size() << endl;
        for(int i = 0;i < ans.size();i++){
            if(i != 0){
                cout << " ";
            }
            cout << ans[i];
        }

        cout << endl;
    }
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
