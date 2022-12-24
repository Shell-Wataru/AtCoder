

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll N,M;
    cin >> N >> M;
    vector<vector<bool>> shares(N,vector<bool>(N,false));
    for(int i = 0;i < M;i++){
        ll k;
        cin >> k;
        vector<ll> xs(k);
        for(int j = 0;j < k;j++){
            cin >> xs[j];
            xs[j]--;
        }
        for(int j = 0;j < k;j++){
            for(int l = j;l < k;l++){
                shares[xs[j]][xs[l]] = true;
                shares[xs[l]][xs[j]] = true;
            }
        }
    }
    bool is_ok = true;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            if (!shares[i][j]){
                is_ok = false;
            }
        }
    }
    if (is_ok){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}