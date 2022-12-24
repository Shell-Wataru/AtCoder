#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <numeric>
using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<vector<ll>> DP(1001,vector<ll>(1001,0));
    vector<ll> counts(N+1);
    for(int i = 0;i < N;i++){
        ll lx,ly,rx,ry;
        cin >> lx >> ly >> rx >> ry;
        // rx++;ry++;
        DP[lx][ly]++;
        DP[lx][ry]--;
        DP[rx][ly]--;
        DP[rx][ry]++;
    }
    // for(int i = 0;i < 10;i++){
    //     for(int j = 0;j < 10;j++){
    //         cout << DP[i][j];
    //     }
    //     cout << endl;
    // }
    for(int i = 0;i <= 1000;i++){
        for(int j = 0;j < 1000;j++){
            DP[i][j+1] += DP[i][j];
        }
    }
    // cout << endl;
    // for(int i = 0;i < 10;i++){
    //     for(int j = 0;j < 10;j++){
    //         cout << DP[i][j];
    //     }
    //     cout << endl;
    // }
    for(int i = 0;i <= 1000;i++){
        for(int j = 0;j < 1000;j++){
            DP[j+1][i] += DP[j][i];
        }
    }
    for(int i = 0;i < 1000;i++){
        for(int j = 0;j < 1000;j++){
            counts[DP[i][j]]++;
        }
    }
    // cout << endl;
    // for(int i = 0;i < 10;i++){
    //     for(int j = 0;j < 10;j++){
    //         cout << DP[i][j];
    //     }
    //     cout << endl;
    // }
    for(int i = 1;i <= N;i++){
        cout << counts[i] << endl;
    }
    return 0;
}