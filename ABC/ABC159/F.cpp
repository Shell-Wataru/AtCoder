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
#include <set>
using namespace std;
using ll = long long;

ll BASE_NUM = 998244353;


int main()
{
    // 整数の入力
    ll N,S;
    cin >> N >> S;
    vector<ll> A(N);
    for(int i = 0;i < N;i++){
        cin >> A[i];
    }
    vector<vector<map<ll,ll>>> DP(N,vector<map<ll,ll>>(N+1));
    for(int i = 0;i < N;i++){
        DP[i][i][0] = 1;
        for(int j = i+1;j<N+1;j++){
            DP[i][j] = map<ll,ll>(DP[i][j-1]);
            for(auto p:DP[i][j-1]){
                ll value = p.first + A[j-1];
                if (value <= S){
                    DP[i][j][value] = (DP[i][j-1][value] + p.second) % BASE_NUM;
                    // cout << "[" <<i << ","<< j << ")" << value << ":" <<DP[i][j][value] << endl;
                }
            };
        }
    }

    ll count = 0;
    for(int i = 0;i<N;i++){
        for(int j = i+1;j<N+1;j++){
            count = (count + DP[i][j][S]) % BASE_NUM;
        }
    }
    cout << count << endl;
    return 0;
}