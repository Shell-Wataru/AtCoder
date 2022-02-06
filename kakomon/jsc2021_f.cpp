#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <climits>
using namespace std;
using ll = long long;

//zero indexed and vector
template <typename T>
class BIT
{
public:
    vector<T> data;
    BIT(long long n) : data(n) {}
    //　indexに足す
    void add(int index, T v)
    {
        int N = data.size();
        for (int i = index; i < N; i |= i + 1)
        {
            data[i] += v;
        }
    }

    // [0,index)の和
    long long sum(int index)
    {
        T retValue = 0;
        for (int i = index - 1; i >= 0; i = (i & (i + 1)) - 1)
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
    ll N, M, Q;
    cin >> N >> M >> Q;
    vector<ll> a(N, 0);
    vector<ll> b(M, 0);
    Compress<ll> compress;
    compress.add(0);
    vector<vector<ll>> queries(Q);
    for (int i = 0; i < Q; i++)
    {
        ll t, x, y;
        cin >> t >> x >> y;
        x--;
        compress.add(y);
        queries[i] = {t, x, y};
    }
    compress.build();
    BIT<ll> bit_a_count(compress.size());
    BIT<ll> bit_b_count(compress.size());
    BIT<ll> bit_a_sum(compress.size());
    BIT<ll> bit_b_sum(compress.size());
    bit_a_count.add(compress.get(0), N);
    bit_b_count.add(compress.get(0), M);
    ll ans = 0;
    for (size_t i = 0; i < Q; i++)
    {
        ll t = queries[i][0];
        ll x = queries[i][1];
        ll y = queries[i][2];
        if (t == 1)
        {
            ll before_y = a[x];
            ll before_y_index = compress.get(before_y);
            ll after_y_index = compress.get(y);
            ll before_point = bit_b_count.sum(before_y_index) * before_y + bit_b_sum.sum(compress.size()) - bit_b_sum.sum(before_y_index);
            ll after_point = bit_b_count.sum(after_y_index) * y + bit_b_sum.sum(compress.size()) - bit_b_sum.sum(after_y_index);
            ans += after_point - before_point;
            a[x] = y;
            bit_a_count.add(compress.get(before_y), -1);
            bit_a_count.add(compress.get(y), 1);
            bit_a_sum.add(compress.get(before_y), -before_y);
            bit_a_sum.add(compress.get(y), y);
        }
        else
        {
            ll before_y = b[x];
            ll before_y_index = compress.get(before_y);
            ll after_y_index = compress.get(y);
            ll before_point = bit_a_count.sum(before_y_index) * before_y + bit_a_sum.sum(compress.size()) - bit_a_sum.sum(before_y_index);
            ll after_point = bit_a_count.sum(after_y_index) * y + bit_a_sum.sum(compress.size()) - bit_a_sum.sum(after_y_index);
            ans += after_point - before_point;
            b[x] = y;
            bit_b_count.add(compress.get(before_y), -1);
            bit_b_count.add(compress.get(y), 1);
            bit_b_sum.add(compress.get(before_y), -before_y);
            bit_b_sum.add(compress.get(y), y);
        }
        cout << ans << endl;
    }
    return 0;
}
int main()
{
    // // 整数の入力
    //   ll t;
    //   cin >> t;
    //   for (size_t i = 0; i < t; i++)
    //   {
    solve();
    //   }
    //   cout << flush;
    return 0;
}
