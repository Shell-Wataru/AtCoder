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
#include <set>
#include <atcoder/mincostflow>
using namespace std;
using ll = long long;
using namespace atcoder;

const long long BASE_NUM = 1000000007;
map<pair<ll, ll>, ll> cache;

// zero indexed and vector
template <typename T>
class BIT
{
public:
    vector<T> data;
    BIT(long long n) : data(n) {}
    void add(int index, T v)
    {
        int N = data.size();
        for (int i = index; i < N; i |= i + 1)
        {
            data[i] += v;
        }
    }

    long long sum(int index)
    {
        T retValue = 0;
        for (int i = index; i >= 0; i = (i & (i + 1)) - 1)
        {
            retValue += data[i];
        }
        return retValue;
    }

    void show()
    {
        for (auto v : data)
        {
            cout << v << endl;
        }
    }
};

ll inversion_number(vector<ll> &A)
{
    BIT<ll> bit(A.size());
    ll ans = 0;
    ll n = A.size();
    for (int i = 0; i < n; i++)
    {
        ans += i - bit.sum(A[i]);
        bit.add(A[i], 1);
    }
    return ans;
}

template <typename T>
struct Compress
{
    vector<T> xs;

    Compress() = default;

    Compress(const vector<T> &vs)
    {
        add(vs);
    }

    Compress(const initializer_list<vector<T>> &vs)
    {
        for (auto &p : vs)
            add(p);
    }

    void add(const vector<T> &vs)
    {
        copy(begin(vs), end(vs), back_inserter(xs));
    }

    void add(const T &x)
    {
        xs.emplace_back(x);
    }

    void build()
    {
        sort(begin(xs), end(xs));
        xs.erase(unique(begin(xs), end(xs)), end(xs));
    }

    vector<int> get(const vector<T> &vs) const
    {
        vector<int> ret;
        transform(begin(vs), end(vs), back_inserter(ret), [&](const T &x)
                  { return lower_bound(begin(xs), end(xs), x) - begin(xs); });
        return ret;
    }

    int get(const T &x) const
    {
        return lower_bound(begin(xs), end(xs), x) - begin(xs);
    }

    size_t size() const
    {
        return xs.size();
    }
    const T &operator[](int k) const
    {
        return xs[k];
    }
};

int solve()
{
    ll N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++)
    {
        cin >> S[i];
    }
    vector<string> heads;
    for (int i = 0; i < N; i++)
    {
        heads.push_back(S[i].substr(0, 3));
        heads.push_back(S[i].substr(S[i].size() - 3, 3));
    }
    sort(heads.begin(), heads.end());
    auto iter = unique(heads.begin(), heads.end());
    heads.erase(iter, heads.end());
    // for(auto h:heads){
    //     cout << h << endl;
    // }
    map<string, ll> indices;
    for (int i = 0; i < heads.size(); i++)
    {
        indices[heads[i]] = S.size() + i;
    }
    vector<vector<ll>> G(S.size() + heads.size());
    vector<vector<ll>> revG(S.size() + heads.size());
    for (int i = 0; i < N; i++)
    {
        G[i].push_back(indices[S[i].substr(S[i].size() - 3, 3)]);
        revG[indices[S[i].substr(S[i].size() - 3, 3)]].push_back(i);
        G[indices[S[i].substr(0, 3)]].push_back(i);
        revG[i].push_back(indices[S[i].substr(0, 3)]);
    }
    ll UNKNOWN = -1;
    ll DRAW = 0;
    ll WIN = 1;
    ll LOSE = 2;
    vector<ll> results(S.size() + heads.size(), -1);
    vector<ll> dicided(S.size() + heads.size(), 0);
    deque<pair<ll, ll>> q;
    for (int i = S.size(); i < S.size() + heads.size(); i++)
    {
        if (G[i].size() == 0)
        {
            q.push_back({i, LOSE});
            results[i] = LOSE;
        }
    }
    while (!q.empty())
    {
        ll current = q.front().first;
        ll result = q.front().second;
        q.pop_front();
        if (result == LOSE)
        {
            for (auto from : revG[current])
            {
                results[from] = WIN;
                ll fromfrom = revG[from][0];
                dicided[fromfrom]++;
                if (results[fromfrom] == UNKNOWN)
                {
                    results[fromfrom] = LOSE;
                    q.push_front({fromfrom, WIN});
                }
            }
        }
        else
        {
            for (auto from : revG[current])
            {
                results[from] = LOSE;
                ll fromfrom = revG[from][0];
                dicided[fromfrom]++;
                if (G[fromfrom].size() == dicided[fromfrom] && results[fromfrom] == UNKNOWN)
                {
                    results[fromfrom] = WIN;
                    q.push_back({fromfrom, LOSE});
                }
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (results[i] == UNKNOWN)
        {
            cout << "Draw\n";
        }
        else if (results[i] == LOSE)
        {
            cout << "Aoki\n";
        }
        else
        {
            cout << "Takahashi\n";
        }
    }
    return 0;
}

int main()
{
    // ll T;
    // cin >> T;
    // for (int i = 0; i < T; i++)
    // {
    solve();
    // }
    cout << flush;
    return 0;
}
