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
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll N,M,Q;
    cin >> N >> M >> Q;
    vector<vector<ll>> ruisekiWa(N+1,vector<ll>(N+1));
    for(int i = 0;i < M;i++){
        ll l,r;
        cin >> l >> r;
        l--;
        r--;
        ruisekiWa[0][r]+= 1;
        ruisekiWa[l+1][r] += -1;
    }

    for(int i = 0; i <= N;i++){
        for(int j = 0; j <= N;j++){
            if (i == 0 && j == 0){
                continue;
            }else if(i == 0){
                ruisekiWa[i][j] += ruisekiWa[i][j-1];
            }else if (j == 0){
                ruisekiWa[i][j] += ruisekiWa[i-1][j];
            }else{
                ruisekiWa[i][j] += ruisekiWa[i-1][j] + ruisekiWa[i][j-1] - ruisekiWa[i-1][j-1];
            }

        }
    }

    for(int i = 0;i < Q;i++){
        ll p,q;
        cin >> p >> q;
        p--;
        q--;
        cout << ruisekiWa[p][q] << "\n";
    }
    cout << flush;
    return 0;
}