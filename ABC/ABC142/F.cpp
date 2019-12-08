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
#include <set>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
ll BASE_NUM = 1000000007;

class StronglyConnectedComponents {
public:
    StronglyConnectedComponents(ll n) :
        n_(n),
        edges_(n),
        reverse_edges_(n),
        order_(n),
        num_(0) {}

    void addEdge(ll from, ll to) {
        edges_[from].push_back(to);
        reverse_edges_[to].push_back(from);
    }

    vector<vector<ll>> scc() {
        visit.assign(n_, false);
        for (ll i = 0; i < n_; i++) {
            dfsForward(i);
        }
        sort(order_.begin(), order_.end(), [](const Order& lhs, const Order& rhs) {
            return lhs.order > rhs.order;
        });
        visit.assign(n_, false);
        for (ll i = 0; i < n_; i++) {
            auto curr_result = dfsBackward(order_[i].index);
            if (curr_result.size() == 0) {
                continue;
            }
            result_.push_back(curr_result);
        }
        return result_;
    }

    vector<vector<ll>> sccEdges() {
        vector<vector<ll>> scc_edges(result_.size());
        vector<ll> indexToScc(n_);
        for (ll i = 0; i < (ll)result_.size(); i++) {
            for (ll j : result_[i]) {
                indexToScc[j] = i;
            }
        }

        for (ll i = 0; i < (ll)result_.size(); i++) {
            for (ll from : result_[i]) {
                for (ll to : edges_[from]) {
                    if (indexToScc[to] == i) {
                        continue;
                    }
                    scc_edges[i].push_back(indexToScc[to]);
                }
            }
        }
        return scc_edges;
    }
private:
    void dfsForward(ll curr) {
        if (visit[curr]) {
            return;
        }
        visit[curr] = true;
        for (ll next : edges_[curr]) {
            dfsForward(next);
        }
        order_[curr] = { curr, num_++ };
        return;
    }

    vector<ll> dfsBackward(ll curr) {
        vector<ll> curr_result;
        if (visit[curr]) {
            return curr_result;
        }
        visit[curr] = true;
        curr_result.push_back(curr);
        for (ll next : reverse_edges_[curr]) {
            auto members = dfsBackward(next);
            for (ll m : members) {
                curr_result.push_back(m);
            }
        }
        return curr_result;
    }

    ll n_;
    vector<vector<ll>> edges_;
    vector<vector<ll>> reverse_edges_;
    struct Order {
        ll index, order;
    };
    vector<Order> order_;
    vector<bool> visit;
    vector<vector<ll>> result_;
    ll num_;
};

vector<ll> smallest_cycle(map<ll,set<ll>> G,vector<ll> candidates){
    map<pair<ll,ll>,ll> d;
    ll n = candidates.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(G[candidates[i]].find(candidates[j]) != G[candidates[i]].end()){
                d[make_pair(candidates[i],candidates[i])] = 1;
            }else{
                d[]
            }
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}
int main()
{
    // 整数の入力
    ll N, M;
    cin >> N >> M;
    map<ll,vector<ll>> G;
    StronglyConnectedComponents scc(N);
    for(int i = 0;i<M;i++){
        ll a,b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        scc.addEdge(a, b);
    }
    auto scc_result = scc.scc();
    for(auto sc: scc_result){
        if (sc.size() > 1){

            return 0;
        }
    }
    cout << -1 << endl;
  return 0;
}