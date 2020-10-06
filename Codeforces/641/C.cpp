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

int solve()
{
    // cout << "==" << endl;
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> reverseG(n);
    StronglyConnectedComponents G(n);
    for(int i = 0;i < m;i++){
        ll a,b;
        cin >> a >> b;
        a--;
        b--;
        G.addEdge(a,b);
        reverseG[b].push_back(a);
    }
    vector<vector<ll>> scc = G.scc();
    bool can_make = true;
    for(auto v:scc){
        if(v.size() > 1){
            can_make = false;
        }
    }
    if (can_make){
        string ans = "";
        ll counter = 0;
        for(int i = 0;i < n;i++){
            if (reverseG[i].size() == 0){
                ans+= 'A';
                counter++;
            }else{
                ans+='E';
            }
        }
        cout << counter << endl;
        cout << ans;
        cout << "\n";
    }else{
        cout << -1 << "\n";
    }
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
    cout << flush;
    return 0;
}
