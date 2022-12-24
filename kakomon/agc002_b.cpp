#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
using namespace std;
using ll = long long;

int solve()
{
    ll N,M;
    cin >> N >> M;
    vector<ll> ball_count(N,1);
    vector<ll> red(N,false);
    red[0] = true;
    for(int i = 0;i < M;i++){
        ll x,y;
        cin >> x >> y;
        x--;y--;
        if (red[x]){
            ball_count[y]++;
            red[y] = true;
            ball_count[x]--;
            if (ball_count[x]== 0){
                red[x] = false;
            }
        }else{
            ball_count[y]++;
            ball_count[x]--;
        }
    }
    ll ans = 0;
    for(int i = 0;i < N;i++){
        if (red[i]){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

int main()
{
    // // 整数の入力
    // ll t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
    solve();
    // }
    cout << flush;
    return 0;
}
