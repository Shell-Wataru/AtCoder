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

vector<pair<ll,ll>> directions = {
    {0,1},
    {0,-1},
    {1,0},
    {-1,0}
};
int main()
{
    // 整数の入力
    ll N,M;
    cin >> N >> M;
    vector<string> G(N);
    for(int i = 0;i < N;i++){
        cin >> G[i];
    }
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            if (G[i][j] != '.'){
                continue;
            }else{
                set<ll> unused = {'1','2','3','4','5'};
                for(auto d:directions){
                    ll next_x = i + d.first;
                    ll next_y = j + d.second;
                    if (0 <= next_x && next_x < N && 0 <= next_y && next_y < M){
                        unused.erase(G[next_x][next_y]);
                    }
                }
                G[i][j] = *unused.begin();
            }
        }
    }
    for(int i = 0;i < N;i++){
        cout << G[i] << "\n";
    }
    cout << flush;
    return 0;
}