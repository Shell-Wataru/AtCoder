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
    ll H,W,R,C;
    cin >> H >> W>>R >> C;
    ll ans = 0;
    vector<pair<ll,ll>> directions = {
        {0,1},
        {0,-1},
        {1,0},
        {-1,0}
    };
    for(auto d:directions){
        ll r = R+d.first;
        ll c = C+ d.second;
        if (1 <= r && r <= H && 1 <= c && c <= W){
            ans += 1;
        }
    }
    cout << ans << endl;
    return 0;
}