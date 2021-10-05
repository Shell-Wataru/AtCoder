#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>

using namespace std;
using ll = long long;
const ll BASE_NUM = 1000000007;

int solve()
{
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>> G(n,vector<ll>(m,0));
    vector<vector<ll>> values;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            scanf("%lld",&G[i][j]);
        }
    }

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if (j != 0){
                cout << " ";
            }
            if ((i + j) % 2 == 0){
                if (G[i][j] % 2 == 0){
                    cout << G[i][j];
                }else{
                    cout << G[i][j] + 1;
                }
            }else{
                if (G[i][j] % 2 == 0){
                    cout << G[i][j] + 1;
                }else{
                    cout << G[i][j];
                }
            }
        }
        cout << "\n";
    }
    cout << flush;
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
    cout << flush;
    return 0;
}
