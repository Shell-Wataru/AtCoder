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

ll BASE_NUM = 1000000007;


int main()
{
    // 整数の入力
    ll N,X,Y;
    cin >> N >> X >> Y;
    vector<vector<ll>> G(403,vector<ll>(403,BASE_NUM));
    queue<
        pair<ll,pair<ll,ll>>
    > q;
    vector<pair<ll,ll>>directions = {
        {1,1},
        {0,1},
        {-1,1},
        {1,0},
        {-1,0},
        {0,-1}
    };
    ll center = 201;
    for(int i = 0;i < N;i++){
        ll x,y;
        cin >> x >> y;
        x += center;
        y += center;
        G[x][y] = -1;
    }
    q.push({0,{center,center}});
    while(!q.empty()){
        auto p = q.front();
        // cout << p.first << ":" << p.second.first << "," << p.second.second << endl;

        q.pop();
        ll x = p.second.first;
        ll y = p.second.second;
        if (p.first < G[x][y]){
            G[x][y] = p.first;
            for(auto &d:directions){
                if (0 <= x + d.first && x+ d.first < 403 && 0 <= y + d.second &&  y + d.second < 403){
                    q.push({p.first + 1,{x+d.first,y + d.second}});
                }
            }
        }
    }
    if (G[X+center][Y+center] == BASE_NUM){
        cout << -1 << endl;
    }else{
        cout << G[X+center][Y+center] << endl;
    }
    return 0;
}