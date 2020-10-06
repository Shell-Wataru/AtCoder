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

ll BASE_NUM = 1000000007;

struct node
{
    ll x, y, k;
};

vector<vector<vector<ll>>> minimum_distances(vector<string> &G, ll K, ll x, ll y)
{
    vector<vector<vector<ll>>> answers(G.size(), vector<vector<ll>>(G[0].size(), vector<ll>(K + 1, BASE_NUM)));
    queue<node> q;
    q.push({x, y, 0});
    fill(answers[x][y].begin(), answers[x][y].end(), 0);
    vector<pair<ll, ll>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while (!q.empty())
    {
        node n = q.front();
        q.pop();
        for (auto p : directions)
        {
            ll next_x = n.x + p.first;
            ll next_y = n.y + p.second;
            ll next_distance = answers[n.x][n.y][n.k] + 1;
            if (0 <= next_x && next_x < G.size() && 0 <= next_y && next_y < G[0].size() && G[next_x][next_y] != 'T')
            {
                ll next_k = (G[next_x][next_y] == 'E') ? n.k + 1 : n.k;
                if (next_k == K + 1)
                {
                    continue;
                }
                if (answers[next_x][next_y][next_k] > next_distance)
                {
                    for (int i = next_k; i <= K; i++)
                    {
                        if (answers[next_x][next_y][i] > next_distance)
                        {
                            answers[next_x][next_y][i] = next_distance;
                        }
                        else
                        {
                            break;
                        }
                    }
                    q.push({next_x, next_y, next_k});
                }
            }
        }
    }
    return answers;
}

int main()
{
    // 整数の入力
    ll R, C, K;
    cin >> R >> C >> K;
    ll start_r, start_c, goal_r, goal_c, center_r, center_c;
    vector<string> G(R);
    for (int i = 0; i < R; i++)
    {
        cin >> G[i];
    }
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (G[i][j] == 'S')
            {
                start_r = i;
                start_c = j;
            }

            if (G[i][j] == 'G')
            {
                goal_r = i;
                goal_c = j;
            }

            if (G[i][j] == 'C')
            {
                center_r = i;
                center_c = j;
            }
        }
    }
    // cout << "==" << endl;
    vector<vector<vector<ll>>> minimum_distances_from_start = minimum_distances(G, K, start_r, start_c);
    vector<vector<vector<ll>>> minimum_distances_from_goal = minimum_distances(G, K, goal_r, goal_c);
    vector<vector<vector<ll>>> minimum_distances_from_center = minimum_distances(G, K, center_r, center_c);

    ll min_disntance = BASE_NUM;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            ll MaxK = (G[i][j] == 'E') ? K + 2 : K;
            for (int start_k = 0; start_k <= min(MaxK,K); start_k++)
            {
                for (int goal_k = 0; goal_k <= min(MaxK - start_k ,K); goal_k++)
                {
                    ll center_k = min(MaxK - (start_k + goal_k) ,K);
                    ll distance = minimum_distances_from_start[i][j][start_k] + minimum_distances_from_goal[i][j][goal_k] + 2 * minimum_distances_from_center[i][j][center_k];
                    if (distance < min_disntance)
                    {
                        min_disntance = distance;
                        // cout << i << "," << j << " " << distance << endl;
                    }
                }
            }
        }
    }

    if (min_disntance == BASE_NUM)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << min_disntance << endl;
    }
    return 0;
}