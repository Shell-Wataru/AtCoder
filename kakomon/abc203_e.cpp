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
    ll N,M;
    cin >> N >> M;
    map<ll,priority_queue<ll,vector<ll>,greater<ll>>> black_pones;
    for(int i = 0;i < M;i++){
        ll x,y;
        cin >> x >> y;
        black_pones[y].push(x);
    }
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
    q.push({0,N});
    set<ll> ans;
    while(!q.empty()){
        ll x = q.top().first;
        ll y = q.top().second;
        // cout << x << " " << y << endl;
        // cout << "s:" << black_pones[y].size() << endl;
        ll can_go_x;
        q.pop();
        if (black_pones[y].empty()){
            ans.insert(y);
            can_go_x = 2*N;
            // cout << y << endl;
        }else{
            can_go_x = black_pones[y].top();
        }

        if (y > 0){
            while(!black_pones[y-1].empty() && black_pones[y-1].top() <= x){
                black_pones[y-1].pop();
            }
            if (!black_pones[y-1].empty() && black_pones[y-1].top() <= can_go_x){
                q.push({black_pones[y-1].top(),y-1});
            }
            while(!black_pones[y-1].empty() && black_pones[y-1].top() <= can_go_x){
                black_pones[y-1].pop();
            }
        }
        if (y < 2*N){
            while(!black_pones[y+1].empty() && black_pones[y+1].top() <= x){
                black_pones[y+1].pop();
            }
            if (!black_pones[y+1].empty() && black_pones[y+1].top() <= can_go_x){
                q.push({black_pones[y+1].top(),y+1});
            }
            while(!black_pones[y+1].empty() && black_pones[y+1].top() <= can_go_x){
                black_pones[y+1].pop();
            }
        }
    }
    cout << ans.size() << endl;
    return 0;
}