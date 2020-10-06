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
    ll n;
    cin >> n;
    vector<ll> E(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> E[i];
    }

    sort(E.begin(),E.end());
    ll index = 0;
    ll groups = 0;
    ll current_group_required = -1;
    ll current_group_total = 0;
    for(int i = 0;i < n;i++){
        if(current_group_required == -1){
            current_group_total = 1;
            current_group_required = E[i];
        }else{
            current_group_total++;
            current_group_required = E[i];
        }

        if(current_group_total >= current_group_required){
            current_group_total = 0;
            current_group_required = -1;
            // cout << i << endl;
            groups++;
        }
    }
    cout << groups << endl;
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
