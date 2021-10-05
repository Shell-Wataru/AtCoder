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

class SoFarAway
{
public:
    int distance(vector<string> G)
    {
        ll n = G.size();
        ll m = G[0].size();
        ll start_x = -1;
        ll start_y = -1;
        ll destination_x = -1;
        ll destination_y = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (G[i][j] == 'S')
                {
                    start_x = i;
                    start_y = j;
                }
                if (G[i][j] == 'D')
                {
                    destination_x = i;
                    destination_y = j;
                }
            }
        }
        queue<pair<ll, ll>> q;
        vector<vector<ll>> min_distance(n, vector<ll>(m, numeric_limits<int>::max()));
        q.emplace(start_x, start_y);
        vector<pair<ll, ll>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        min_distance[start_x][start_y] = 0;
        while (!q.empty())
        {
            auto current = q.front();
            // cout << current.first << " " << current.second << endl;
            // cout << min_distance[current.first][current.second] << endl;
            q.pop();
            for (auto &p : directions)
            {
                ll next_x = current.first + p.first;
                ll next_y = current.second + p.second;

                if (0 <= next_x && next_x < n &&
                    0 <= next_y && next_y < m &&
                    G[next_x][next_y] != 'X' &&
                    min_distance[next_x][next_y] == numeric_limits<int>::max())
                {
                    min_distance[next_x][next_y] = min_distance[current.first][current.second] + 1;
                    q.emplace(next_x, next_y);
                }
            }
        }
        if (min_distance[destination_x][destination_y] == numeric_limits<int>::max())
        {
            return -1;
        }
        else
        {
            return min_distance[destination_x][destination_y];
        }
    }
};

int main(){
    map<ll,ll>a;
    a.;
    a.erase(1);
    if (a.find(1) == a.end()){
        cout << "!" << endl;
    }
    return 0;
}