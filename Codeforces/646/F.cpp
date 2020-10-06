#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;

int dfs(ll x, ll y, vector<string> &G)
{
    if (0 <= x && x < G.size() && 0 <= y && y < G.size())
    {
        if (G[x][y] == '1')
        {
            G[x][y] = '0';
            dfs(x - 1, y, G);
            dfs(x, y - 1, G);
        }
    }
    return 0;
}

int solve()
{

    ll N, M;
    cin >> N >> M;
    vector<string> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    vector<set<char>> used(M);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            used[j].insert(A[i][j]);
        }
    }
    string global_ans;
    bool all_same = true;
    bool can_make = false;
    for (int i = 0; i < M; i++)
    {
        if (used[i].size() > 1)
        {
            all_same = false;
        }
    }
    if (all_same)
    {
        global_ans = A[0];
        can_make = true;
    }
    else
    {

        for (int i = 0; i < M; i++)
        {
            if (used[i].size() == 1)
            {
                continue;
            }
            for (auto c : used[i])
            {
                string ans;
                for (int j = 0; j < N; j++)
                {
                    if (A[j][i] != c)
                    {
                        ans = A[j];
                        ans[i] = c;
                        break;
                    }
                }
                bool is_ok = true;
                for (int j = 0; j < N; j++)
                {
                    ll diffs = 0;
                    for (int k = 0; k < M; k++)
                    {
                        if (A[j][k] != ans[k])
                        {
                            diffs++;
                        }
                    }
                    if (diffs > 1)
                    {
                        is_ok = false;
                        break;
                    }
                }
                if (is_ok)
                {
                    global_ans = ans;
                    can_make = true;
                }
            }
        }
    }

    if (can_make)
    {
        cout << global_ans << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}
int main()
{
    int t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}