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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<pair<ll,ll>> s(k),f(k);
    for(int i = 0;i < k;i++){
        cin >> s[i].first >> s[i].second;
    }

    for(int i = 0;i < k;i++){
        cin >> f[i].first >> f[i].second;
    }

    cout << n - 1 + m - 1 + n * (m - 1) + n - 1 << endl;
    for(int i = 0; i < n -1;i++){
        cout << "U";
    }
    for(int i = 0; i < m - 1;i++){
        cout << "L";
    }

    for(int i = 0;i < n;i++){
        if(i != 0){
            cout << "D";
        }
        for(int j= 0;j < m - 1;j++){
            if(i % 2 ==0){
                cout <<  "R";
            }else{
                cout << "L";
            }
        }
    }
    cout << endl;
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
    return 0;
}
