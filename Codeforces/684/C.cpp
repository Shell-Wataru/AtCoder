#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>

using namespace std;
using ll = long long;
const ll BASE_NUM = 1000000007;

void push_moves2(vector<vector<ll>> &moves, pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c, pair<ll, ll> d)
{
    moves.push_back({a.first, a.second, c.first, c.second, d.first, d.second});
    moves.push_back({b.first, b.second, c.first, c.second, d.first, d.second});
}

void push_moves1(vector<vector<ll>> &moves, pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c, pair<ll, ll> d)
{
    moves.push_back({a.first, a.second, b.first, b.second, c.first, c.second});
    push_moves2(moves, b, c, d, a);
}

void push_moves3(vector<vector<ll>> &moves, pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c, pair<ll, ll> d)
{
    moves.push_back({a.first, a.second, b.first, b.second, c.first, c.second});
}

void push_moves4(vector<vector<ll>> &moves, pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c, pair<ll, ll> d)
{
    moves.push_back({a.first, a.second, b.first, b.second, c.first, c.second});
    push_moves1(moves, d, a, b, c);
}

void push_moves(vector<string> &G, vector<vector<ll>> &moves, ll i, ll j)
{
    vector<pair<ll, ll>> a;
    ll one_count = 0;
    for (int k = 0; k < 2; k++)
    {
        for (int l = 0; l < 2; l++)
        {
            if (G[i + k][j + l] == '1')
            {
                one_count++;
                a.insert(a.begin(), {i + k, j + l});
            }
            else
            {
                a.push_back({i + k, j + l});
            }
            G[i + k][j + l] = '0';
        }
    }

    if (one_count == 0)
    {
    }
    else if (one_count == 1)
    {
        push_moves1(moves, a[0], a[1], a[2], a[3]);
    }
    else if (one_count == 2)
    {
        push_moves2(moves, a[0], a[1], a[2], a[3]);
    }
    else if (one_count == 3)
    {
        push_moves3(moves, a[0], a[1], a[2], a[3]);
    }
    else
    {
        push_moves4(moves, a[0], a[1], a[2], a[3]);
    }
}
void apply(vector<string> &G, vector<ll> &move)
{
    G[move[0]][move[1]] = (G[move[0]][move[1]] == '0') ? '1' : '0';
    G[move[2]][move[3]] = (G[move[2]][move[3]] == '0') ? '1' : '0';
    G[move[4]][move[5]] = (G[move[4]][move[5]] == '0') ? '1' : '0';
}
int solve()
{
    ll n, m;
    cin >> n >> m;
    vector<string> G(n);
    vector<vector<ll>> moves;
    for (int i = 0; i < n; i++)
    {
        cin >> G[i];
    }
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j < m - 1)
            {
                if (G[i][j] == '1')
                {
                    moves.push_back({i, j, i + 1, j, i + 1, j + 1});
                    apply(G, moves.back());
                }
            }
            else
            {
                if (G[i][j] == '1')
                {
                    moves.push_back({i, j, i + 1, j, i + 1, j - 1});
                    apply(G, moves.back());
                }
            }
        }
    }
    // cout << moves.size() << endl;
    ll last_row = n - 2;
    for (ll j = 0; j < m - 2; j++)
    {
        // cout << "!!" << endl;
        if (G[last_row][j] == '0' && G[last_row + 1][j] == '0')
        {
        }
        else if (G[last_row][j] == '0' && G[last_row + 1][j] == '1')
        {
            moves.push_back({last_row + 1, j, last_row, j + 1, last_row + 1, j + 1});
            apply(G, moves.back());
        }
        else if (G[last_row][j] == '1' && G[last_row + 1][j] == '0')
        {
            moves.push_back({last_row, j, last_row, j + 1, last_row + 1, j + 1});
            apply(G, moves.back());
        }
        else if (G[last_row][j] == '1' && G[last_row + 1][j] == '1')
        {
            moves.push_back({last_row, j, last_row + 1, j, last_row, j + 1});
            apply(G, moves.back());
        }

    }

    push_moves(G, moves, n - 2, m - 2);

    // for (int i = 0; i < n; i++)
    // {
    //     cout << G[i] << endl;
    // }
    cout << moves.size() << "\n";
    for (size_t i = 0; i < moves.size(); i++)
    {
        cout << moves[i][0] + 1 << " " << moves[i][1] + 1 << " " << moves[i][2] + 1 << " " << moves[i][3] + 1 << " " << moves[i][4] + 1 << " " << moves[i][5] + 1 << "\n";
    }
    cout << flush;
    return 0;
}

int main()
{
    // 整数の入力
    ll t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        solve();
    }
    cout << flush;
    return 0;
}
