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
    ll N,C,K;
    cin >> N >> C >> K;
    vector<ll> T(N);
    for(int i = 0;i < N;i++){
        cin >> T[i];
    }
    sort(T.begin(),T.end());
    ll waitings = 0;
    ll wait_start = 0;
    ll ans = 0;
    for(int i =0 ;i < N;i++){
        if (waitings == C){
            ans++;
            waitings = 0;
        }else if (waitings > 0 && T[i] - wait_start > K){
            ans++;
            waitings = 0;
        }
        if (waitings == 0){
            waitings++;
            wait_start = T[i];
        }else{
            waitings++;
        }
    }
    ans++;
    cout << ans << endl;
    return 0;
}