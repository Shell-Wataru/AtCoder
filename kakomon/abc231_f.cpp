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

//zero indexed and vector
template< typename T>
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
    T sum(int index)
    {
        T retValue = 0;
        for (int i = index - 1; i >= 0; i = (i & (i + 1)) - 1)
        {
            retValue += data[i];
        }
        return retValue;
    }

    // [l,r)の和
    T sum(int l,int r)
    {
        return sum(r) - sum(l);
    }

    void show(){
        for (auto v:data){
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

int main()
{
    ll N;
    cin >> N;
    vector<pair<ll,ll>> AB(N);
    Compress<ll> c;
    map<pair<ll,ll>,ll> duplicates;
    for(int i = 0;i < N;i++){
        cin >> AB[i].first;
    }
    for(int i = 0;i < N;i++){
        cin >> AB[i].second;
        c.add(AB[i].second);
        AB[i].second *= -1;
    }
    for(int i = 0;i < N;i++){
        duplicates[AB[i]]++;
    }

    c.build();
    sort(AB.begin(),AB.end());
    ll ans = 0;
    for(auto p:duplicates){

        ans += p.second*p.second - p.second*(p.second+1)/2;
    }
    BIT<ll> bit(c.size());
    for(int i = 0;i < N;i++){
        ll a = AB[i].first;
        ll b = -AB[i].second;
        bit.add(c.get(b),1);
        ans +=  bit.sum(c.get(b),c.size());
    }
    cout << ans << endl;
    return 0;
}