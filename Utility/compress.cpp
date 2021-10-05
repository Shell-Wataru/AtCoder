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

int main(){
    Compress<ll> compress;
    compress.add(1);
    compress.add(5);
    compress.add(10);
    compress.add(20);
    compress.build();
    cout << compress.get(1) << endl;
    cout << compress.get(5) << endl;
    cout << compress.get(10) << endl;
    cout << compress.get(20) << endl;
    return 0;

}