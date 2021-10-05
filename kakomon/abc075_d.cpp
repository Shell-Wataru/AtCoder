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

int main()
{
    ll N, K;
    cin >> N >> K;
    Compress<ll> compress_x;
    Compress<ll> compress_y;
    vector<pair<ll, ll>> points(N);
    for (int i = 0; i < N; i++)
    {
        ll x, y;
        cin >> x >> y;
        points[i].first = x;
        points[i].second = y;
        compress_x.add(x);
        compress_y.add(y);
    }
    compress_x.build();
    compress_y.build();
    vector<vector<ll>> ruisekiwa(compress_x.size()+1, vector<ll>(compress_y.size() + 1));
    for (auto p : points)
    {
        ruisekiwa[compress_x.get(p.first)+1][compress_y.get(p.second)+1] += 1;
    }
    for (int i = 1; i <= compress_x.size(); i++)
    {
        for (int j = 1; j <= compress_y.size(); j++)
        {
            ruisekiwa[i][j] += ruisekiwa[i - 1][j] + ruisekiwa[i][j - 1] - ruisekiwa[i - 1][j - 1];
        }
    }
    // for (int i = 0; i <= compress_x.size(); i++)
    // {
    //     for (int j = 0; j <= compress_y.size(); j++)
    //     {
    //         cout << ruisekiwa[i][j]<< ",";
    //     }
    //     cout << endl;
    // }
    ll min_s = numeric_limits<ll>::max();
    for (int x_from = 0; x_from < compress_x.size(); x_from++)
    {
        for (int x_to = x_from; x_to < compress_x.size(); x_to++)
        {
            for (int y_from = 0; y_from < compress_y.size(); y_from++)
            {
                for (int y_to = y_from; y_to < compress_y.size(); y_to++)
                {
                    if (ruisekiwa[x_to+1][y_to+1] - ruisekiwa[x_from][y_to+1] - ruisekiwa[x_to+1][y_from] + ruisekiwa[x_from][y_from] >= K){
                        min_s = min(min_s, (compress_x[x_to] - compress_x[x_from])* (compress_y[y_to] - compress_y[y_from]));
                    }
                }
            }
        }
    }
    cout << min_s << endl;
    return 0;
}