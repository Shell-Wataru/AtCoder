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
#include <stack>

using namespace std;
using ll = long long;

int solve(){
    ll N,M,X,Y;
    cin >> N >> M >> X >> Y;
    queue<ll> a;
    queue<ll> b;
    for(int i =0;i < N;i++){
        ll aa;
        cin >> aa;
        a.push(aa);
    }
    for(int i =0;i < M;i++){
        ll bb;
        cin >> bb;
        b.push(bb);
    }
    ll ans = 0;
    ll current = 0;
    while(true){
        while(!a.empty() && a.front() < current){
            a.pop();
        }
        if (a.empty()){
            break;
        }
        current = a.front() + X;
        a.pop();
        while(!b.empty() && b.front() < current){
            b.pop();
        }
        if (b.empty()){
            break;
        }
        current = b.front() + Y;
        b.pop();
        ans++;
    }
    cout << ans << endl;
    return 0;
}

int main()
{
    // 整数の入力
    // ll T;
    // cin >> T;
    // for (size_t i = 0; i < T; i++)
    // {
        solve();
    // }
    // cout << flush;
    return 0;
}