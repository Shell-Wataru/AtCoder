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
#include <atcoder/mincostflow>
using namespace std;
using ll = long long;
using namespace atcoder;

int solve()
{
    ll H, W,N;
    cin >> H >> W >> N;
    vector<vector<ll>> G(W);
    for(int i = 0;i < N;i++){
        ll x,y;
        cin >> x >> y;
        x--;
        y--;
        G[y].push_back(x);
    }
    for(int i = 0;i < W;i++){
        G[i].push_back(H);
        sort(G[i].begin(),G[i].end());
    }
    ll current_x = 0;
    ll current_y = 0;
    ll ans = numeric_limits<ll>::max();
    while(true){
        ll next_obstacle_x = *upper_bound(G[current_y].begin(),G[current_y].end(),current_x);
        // cout << current_x << "," << current_y << endl;
        ans = min(ans,next_obstacle_x);
        if (current_x+1 == next_obstacle_x){
            break;
        }
        current_x++;
        if (current_y + 1 < W && !binary_search(G[current_y+1].begin(),G[current_y+1].end(),current_x)){
            current_y++;
        }
    }
    cout << ans << endl;
    return 0;
}

int main()
{
    // ll T;
    // cin >> T;
    // for (int i = 0; i < T; i++)
    // {
    solve();
    // }
    cout << flush;
    return 0;
}
