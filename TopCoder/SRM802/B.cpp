#include <string>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
using namespace std;
using ll = long long;

class TheQuestForGold
{
public:
    vector<pair<ll, ll>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool dfs(vector<string> &G, ll x,ll y, vector<vector<ll>> &visited){
        ll n = G.size();
        ll m = G[0].size();
        if (visited[x][y]){
            return false;
        }
        visited[x][y] = true;
        if (G[x][y] == 'T'){
            return true;
        }else if (G[x][y] == 'M'){
            return false;
        }
        for(auto &d:directions){
            ll next_x = x + d.first;
            ll next_y = y + d.second;
            if (0 <= next_x && next_x < n && 0 <= next_y && next_y < m){
                if (dfs(G,next_x,next_y,visited)){
                    return true;
                }
            }
        }
        return false;
    }
    string explore(vector<string> G)
    {
        ll n = G.size();
        ll m = G[0].size();
        ll start_x = -1;
        ll start_y = -1;
        vector<vector<ll>> visited(n,vector<ll>(m,false));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (G[i][j] == 'S')
                {
                    start_x = i;
                    start_y = j;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (G[i][j] == 'P'){
                    for(auto &d:directions){
                        ll next_i = i + d.first;
                        ll next_j = j + d.second;
                        if (0 <= next_i && next_i < n && 0 <= next_j && next_j < m){
                            if (G[next_i][next_j] == '.' || G[next_i][next_j] == 'S'){
                                G[next_i][next_j] = 'M';
                            }
                        }
                    }
                }
            }
        }
        // for(auto l:G){
        //     cout << l << endl;
        // }
        if (dfs(G,start_x,start_y,visited)){
            return "gold";
        }else{
            return "no gold";
        }
    }
};

// int main(){
//     // vector<string> G{"S....",".....","PPP..",".....",".....",".....","..PPP","..T.."};
//     vector<string> G{
//         "S....",
//         "P....",
//         "...T.",
//         "....."};
//     TheQuestForGold m;
//     cout << m.explore(G) << endl;
//     return 0;
// }