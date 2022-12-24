#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
using namespace std;
using ll = long long;

vector<vector<ll>> numbers(ll N){
    vector<vector<ll>> Numbers(N,vector<ll>(N,0));
    pair<ll,ll> current_p = {0,0};
    ll current_num = 1;
    vector<pair<ll,ll>> directions = {
        {0,1},
        {-1,0},
        {0,-1},
        {1,0}
    };
    ll k = (N/2)*2;
    ll d_index = 0;
    auto d = directions[d_index];
    Numbers[0][0] = current_num;
    while(true){
        current_num++;
        auto next_p = current_p;
        next_p.first += d.first;
        next_p.second += d.second;
        while(!(0 <= next_p.first  && next_p.first < N  && 0 <= next_p.second && next_p.second< N &&  Numbers[next_p.first][next_p.second] == 0)){
            d_index = (d_index + 1) % 4;
            d = directions[d_index];
            next_p.first = current_p.first + d.first;
            next_p.second = current_p.second + d.second;
        }
        Numbers[next_p.first][next_p.second] = current_num;
        current_p = next_p;
        if (next_p.first == N/2 && next_p.second == N/2){
            break;
        }
    }
    return Numbers;
}

vector<pair<ll,ll>> number_positions(ll N){
    vector<vector<ll>> Numbers(N,vector<ll>(N,0));
    vector<pair<ll,ll>> positions(N*N+1);
    pair<ll,ll> current_p = {0,0};
    ll current_num = 1;
    vector<pair<ll,ll>> directions = {
        {0,1},
        {-1,0},
        {0,-1},
        {1,0}
    };
    ll k = (N/2)*2;
    ll d_index = 0;
    auto d = directions[d_index];
    Numbers[0][0] = current_num;
    positions[current_num] = {0,0};
    while(true){
        current_num++;
        auto next_p = current_p;
        next_p.first += d.first;
        next_p.second += d.second;
        while(!(0 <= next_p.first  && next_p.first < N  && 0 <= next_p.second && next_p.second< N &&  Numbers[next_p.first][next_p.second] == 0)){
            d_index = (d_index + 1) % 4;
            d = directions[d_index];
            next_p.first = current_p.first + d.first;
            next_p.second = current_p.second + d.second;
        }
        Numbers[next_p.first][next_p.second] = current_num;
        current_p = next_p;
        positions[current_num] = current_p;
        if (next_p.first == N/2 && next_p.second == N/2){
            break;
        }
    }
    return positions;
}
ll solve(){
    ll N,K;
    cin >> N >> K;
    if (K % 2 != 0 || K < (N/2)*2){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    vector<vector<ll>> G = numbers(N);
    vector<pair<ll,ll>> positions = number_positions(N);
    vector<pair<ll,ll>> shortcuts;
    vector<pair<ll,ll>> directions = {
        {0,1},
        {-1,0},
        {0,-1},
        {1,0}
    };
    ll k = (N/2)*2;
    pair<ll,ll> current_p = {0,0};
    while(true){
        if (k < K){
            pair<ll,ll> next_p = positions[G[current_p.first][current_p.second] + 1];
            if (abs(next_p.first - N/2) + abs(next_p.second - N/2) > abs(current_p.first - N/2) + abs(current_p.second - N/2)){
                k += 2;
            }
            current_p = next_p;
        }else{
            pair<ll,ll> next_p = current_p;
            if (current_p.first < N/2 && G[current_p.first][current_p.second] < G[current_p.first+1][current_p.second]){
                next_p.first++;
            }else if (current_p.second < N/2 && G[current_p.first][current_p.second] < G[current_p.first][current_p.second+1]){
                next_p.second++;
            }else if (current_p.first > N/2 && G[current_p.first][current_p.second] < G[current_p.first-1][current_p.second]){
                next_p.first--;
            }else if (current_p.second > N/2 && G[current_p.first][current_p.second] < G[current_p.first][current_p.second-1]){
                next_p.second--;
            }
            if (G[current_p.first][current_p.second] + 1 != G[next_p.first][next_p.second]){
                shortcuts.push_back({G[current_p.first][current_p.second],G[next_p.first][next_p.second]});
            }
            current_p = next_p;
        }
        if (current_p.first == N/2 && current_p.second == N/2){
            break;
        }
    }
    cout << shortcuts.size() << "\n";
    for(auto p:shortcuts){
        cout << p.first << " " << p.second << "\n";
    }
    return 0;
}
int main()
{
    // 整数の入力
    ll T;
    cin >> T;
    // cerr << T << endl;
    for (int i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    cout << flush;
    return 0;
}