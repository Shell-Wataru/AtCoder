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

int solve()
{
    ll n;
    cin >> n;
    vector<bool> used(n+1,false);
    cout << 2 << "\n";
    // cout << 1 << " " << 2;
    for(int i = 1;i <= n;i++){
        ll x = i;
        while(x <= n && !used[x]){
            if (x != 1){
                cout << " ";
            }
            cout <<  x;
            used[x] = true;
            x *= 2;
        }
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
