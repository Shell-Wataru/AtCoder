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

namespace mp = boost::multiprecision;
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
    ll N;
    scanf("%lld", &N);
    vector<pair<ll,ll>> AB(N);
    Compress<ll> C;
    for(int i = 0;i < N;i++){
        cin >>  AB[i].first >> AB[i].second;
        C.add(AB[i].first);
        C.add(AB[i].second);
    }
    C.build();
    for(int i = 0;i < N;i++){
        AB[i].first = C.get(AB[i].first);
        AB[i].second = C.get(AB[i].second);
    }
    ll M = C.size();
    priority_queue<pair<ll,ll>> bad_q;
    priority_queue<pair<ll,ll>> good_q;
    for(int i = 0;i < N;i++){
        if (AB[i].first > AB[i].second){
            good_q.push(AB[i]);
        }else if (AB[i].first < AB[i].second){
            bad_q.push(AB[i]);
        }
    }
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> can_use_q;
    while(!bad_q.empty()){
        if(!good_q.empty() && good_q.top().first >= bad_q.top().first){
            auto p = good_q.top();
            swap(p.first,p.second);
            can_use_q.push(p);
            good_q.pop();
        }else if (!can_use_q.empty()){
            auto bad = bad_q.top();
            auto good = can_use_q.top();
            swap(good.first,good.second);
            bad_q.pop();
            can_use_q.pop();
            if (good.first > bad.first){
                good_q.
            }
            if ()
        }else{

        }
    }
    return 0;
}