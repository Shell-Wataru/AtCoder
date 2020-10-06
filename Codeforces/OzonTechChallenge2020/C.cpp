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
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>> counts(26,vector<ll>(n,0));
    string s;
    cin >> s;
    for(int i = 0;i< n;i++){
        counts[s[i] - 'a'][i]++;
    }

    for(int i = 0;i< 26;i++){
        for(int j = 1;j < n;j++){
            counts[i][j] += counts[i][j-1];
        }
    }
    vector<ll> used_counts(26,0);
    for(int i = 0;i< m;i++){
        ll p;
        cin >> p;
        p--;
        for(int j = 0;j< 26;j++){
            used_counts[j] += counts[j][p];
        }
    }
    //last
    for(int j = 0;j< 26;j++){
        used_counts[j] += counts[j][n-1];
    }
    for(int j = 0;j< 26;j++){
        if (j != 0){
            cout << " ";
        }
        cout << used_counts[j];
    }
    cout << endl;
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
    return 0;
}
