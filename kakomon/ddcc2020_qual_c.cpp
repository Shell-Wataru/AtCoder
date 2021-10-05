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

ll ruiseki(vector<vector<ll>> &ruisekiWa, ll from_x, ll from_y, ll to_x, ll to_y)
{
    return ruisekiWa[to_x][to_y] - ruisekiWa[to_x][from_y] - ruisekiWa[from_x][to_y] + ruisekiWa[from_x][from_y];
}

int main()
{
    ll H, W, K;
    cin >> H >> W >> K;
    vector<string> G(H);
    for (size_t i = 0; i < H; i++)
    {
        cin >> G[i];
    }

    vector<vector<ll>> ruisekiWa(H + 1, vector<ll>(W + 1, 0));
    for (int i = 0; i < H; i++)
    {
        for (size_t j = 0; j < W; j++)
        {
            if (G[i][j] == '#')
            {
                ruisekiWa[i + 1][j + 1] = ruisekiWa[i + 1][j] + ruisekiWa[i][j + 1] - ruisekiWa[i][j] + 1;
            }
            else
            {
                ruisekiWa[i + 1][j + 1] = ruisekiWa[i + 1][j] + ruisekiWa[i][j + 1] - ruisekiWa[i][j];
            }
        }
    }
    // for(int i = 0;i <= H;i++){
    //     for (size_t j = 0; j <= W; j++)
    //     {
    //         cout << ruisekiWa[i][j] << ",";
    //     }
    //     cout << endl;
    // }
    vector<ll> visited(H, 0);
    vector<vector<ll>> results(H, vector<ll>(W, 0));
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.push({0, 0});
    ll counts = 1;
    while (!q.empty())
    {
        auto p = q.top();
        q.pop();
        ll start_i = p.first;
        ll start_j = p.second;
        if (start_i == H || start_j == W || results[start_i][start_j] != 0)
        {
            continue;
        }
        ll end_j = -1;
        ll end_i = -1;
        for (int i = start_i + 1; i <= H; i++)
        {
            for (int j = start_j + 1; j <= W; j++)
            {
                if (ruiseki(ruisekiWa, start_i, start_j, i, j) == 1 &&
                (i == H || ruiseki(ruisekiWa, start_i, start_j, i+1, j) >= 2) &&
                (j == W || ruiseki(ruisekiWa, start_i, start_j, i, j+1) >= 2)){
                    end_i = i;
                    end_j = j;
                    break;
                }
            }
            if (end_i != -1){
                break;
            }
        }
        // cout << start_i << "," << start_j << "~" << end_i << "," << end_j << endl;
        // cout << ruiseki(ruisekiWa,start_i,start_j,end_i,end_j) << endl;
        for (int i = start_i; i < end_i; i++)
        {
            for (int j = start_j; j < end_j; j++)
            {
                results[i][j] = counts;
            }
        }
        counts++;
        q.push({start_i, end_j});
        q.push({end_i, start_j});
    }

    for (int i = 0; i < H; i++)
    {
        for (size_t j = 0; j < W; j++)
        {
            if (j != 0)
            {
                cout << " ";
            }
            cout << results[i][j];
        }
        cout << "\n";
    }
    cout << flush;
    return 0;
}