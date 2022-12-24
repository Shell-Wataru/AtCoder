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
    // 整数の入力
    ll N;
    cin >> N;
    vector<ll> A(N);
    Compress<ll> compress;
    for(int i = 0;i < N;i++){
        cin >> A[i];
        compress.add(A[i]);
    }
    compress.build();
    // 最長増加部分列
    vector<ll> DP(N,numeric_limits<ll>::max());
    ll ans = 0;
    for(int i =0;i < N;i++){
        *lower_bound(DP.begin(),DP.end(),A[i]) = A[i];
    }
    ll longest = lower_bound(DP.begin(),DP.end(),numeric_limits<ll>::max()) - DP.begin();
    cout << N- longest << endl;
    return 0;
}