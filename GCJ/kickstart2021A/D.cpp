#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <queue>

using namespace std;
using ll = long long;

ll BASE_NUM = 1000000000;

void erase_remain_question(vector<set<ll>> &a_questions, vector<set<ll>> &b_questions, ll i)
{
    ll j = *(a_questions[i].begin());
    a_questions[i].erase(j);
    b_questions[j].erase(i);
    if (b_questions[j].size() == 1)
    {
        erase_remain_question(b_questions, a_questions, j);
    }
}
string solve()
{
    ll N;
    cin >> N;
    vector<vector<ll>> A(N, vector<ll>(N));
    vector<vector<ll>> B(N, vector<ll>(N));
    vector<ll> R(N);
    vector<ll> C(N);
    vector<set<ll>> row_qustions(N);
    vector<set<ll>> column_qustions(N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> B[i][j];
        }
    }
    for (size_t i = 0; i < N; i++)
    {
        cin >> R[i];
    }
    for (size_t i = 0; i < N; i++)
    {
        cin >> C[i];
    }
    // cout << "!!" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (A[i][j] == -1)
            {
                row_qustions[i].insert(j);
                column_qustions[j].insert(i);
            }
        }
    }
    // cout << "!!" << endl;
    for (size_t i = 0; i < N; i++)
    {
        if (row_qustions[i].size() == 1)
        {
            erase_remain_question(row_qustions, column_qustions, i);
        }
    }
    for (size_t i = 0; i < N; i++)
    {
        if (column_qustions[i].size() == 1)
        {
            erase_remain_question(column_qustions, row_qustions, i);
        }
    }
    priority_queue<pair<ll, ll>> q;
    for (size_t i = 0; i < N; i++)
    {
        for (auto j : row_qustions[i])
        {
            q.emplace(-B[i][j], i * N + j);
        }
    }
    ll ans = 0;
    while (!q.empty())
    {
        auto p = q.top();
        q.pop();
        ll i = p.second / N;
        ll j = p.second % N;
        if (row_qustions[i].find(j) != row_qustions[i].end())
        {
            ans += -p.first;
            row_qustions[i].erase(j);
            column_qustions[j].erase(i);
            if (row_qustions[i].size() == 1)
            {
                erase_remain_question(row_qustions, column_qustions, i);
            }
            if (column_qustions[j].size() == 1)
            {
                erase_remain_question(column_qustions, row_qustions, j);
            }
        }
    }
    return to_string(ans);
}
int main()
{
    // 整数の入力
    ll T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        string ans = solve();
        cout << "Case #" << i << ": " << ans << endl;
    }

    return 0;
}