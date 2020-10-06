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
ll BASE_NUM = 1000000007;

struct UnionFind
{
    vector<int> data;

    UnionFind(int sz)
    {
        data.assign(sz, -1);
    }

    bool unite(int x, int y)
    {
        x = find(x), y = find(y);
        if (x == y)
            return (false);
        if (data[x] > data[y])
            swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return (true);
    }

    bool same(int x, int y)
    {
        x = find(x), y = find(y);
        return x == y;
    }
    int find(int k)
    {
        if (data[k] < 0)
            return (k);
        return (data[k] = find(data[k]));
    }

    int size(int k)
    {
        return (-data[find(k)]);
    }
};

ll rev(ll a)
{
    ll ans = 0;
    for (int i = 0; i < 20; i++)
    {
        if (a & 1 << i)
        {
            ans += 1 << (19 - i);
        }

    }
    return ans;
}
void print(ll a)
{
    for (int i = 0; i < 20; i++)
    {
        if (a & 1 << i)
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
    }
    cout << endl;
}
void output_answer(vector<ll> &streak, vector<ll> &answer, ll parent, ll current)
{
    streak.push_back(current);
    if (current % 2 == 0)
    {
        ll pair = current + 1;
        if (parent != pair)
        {
            output_answer(streak, answer, current, pair);
        }
        else if (answer[current] != -1)
        {
            output_answer(streak, answer, current, answer[current]);
        }
    }
    else
    {
        ll pair = current - 1;
        if (parent != pair)
        {
            output_answer(streak, answer, current, pair);
        }
        else if (answer[current] != -1)
        {
            output_answer(streak, answer, current, answer[current]);
        }
    }
}

ll score(ll a, ll b)
{
    ll c = a ^ b;
    ll k = 0;
    cout << c << endl;
    for (int i = 0; i < 20; i++)
    {
        if (c & 1ll << i)
        {
            break;
        }
        k++;
    }
    return k;
}
int solve()
{
    // cout << "==" << endl;
    ll n;
    scanf("%lld", &n);
    UnionFind uf(2 * n);
    vector<pair<ll, ll>> parts;
    vector<ll> colors(2 * n, -1);
    vector<ll> answer(2 * n, -1);
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        scanf("%lld%lld", &a, &b);
        colors[2 * i] = a;
        colors[2 * i + 1] = b;
        parts.push_back({rev(a), 2 * i});
        parts.push_back({rev(b), 2 * i + 1});
        uf.unite(2 * i, 2 * i + 1);
    }
    sort(parts.begin(), parts.end(), greater<pair<ll, ll>>());
    vector<pair<ll, ll>> remains;
    for (auto &p : parts)
    {
        // print(p.first);
        if (remains.empty())
        {
            remains.push_back(p);
        }
        else
        {
            bool united = false;
            for (int i = 0; i < remains.size(); i++)
            {
                if (!uf.same(p.second, remains[i].second))
                {
                    cout << "==" << endl;
                    cout << p.second << ":";
                    print(p.first);
                    cout << remains[i].second << ":";
                    print(remains[i].first);
                    uf.unite(p.second, remains[i].second);
                    answer[p.second] = remains[i].second;
                    answer[remains[i].second] = p.second;
                    remains.erase(remains.begin() + i);
                    united = true;
                    break;
                }
            }
            if (!united)
            {
                remains.push_back(p);
            }
        }
    }
    ll start;
    for (int i = 0; i < 2 * n; i++)
    {
        if (answer[i] == -1)
        {
            start = i;
            break;
        }
    }
    vector<ll> streak;
    streak.push_back(start);
    if (start % 2 == 0)
    {
        output_answer(streak, answer, start, start + 1);
    }
    else
    {
        output_answer(streak, answer, start, start - 1);
    }
    ll min_score = BASE_NUM;
    for (int i = 0; i < n; i++)
    {
        min_score = min(score(colors[streak[(2 * i + 2) % (2 * n)]], colors[streak[(2 * i + 1) % (2 * n)]]), min_score);
    }
    cout << min_score << endl;
    for (int i = 0; i < 2 * n; i++)
    {
        if (i != 0)
        {
            cout << " ";
        }
        cout << streak[i];
    }
    cout << endl;
    return 0;
}
int main()
{
    // 整数の入力
    // ll t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
    solve();
    // }
    // cout << flush;
    return 0;
}
