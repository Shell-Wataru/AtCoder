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
map<pair<ll,ll>,ll> cache;

//zero indexed and vector
template< typename T>
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

    void show(){
        for (auto v:data){
            cout << v << endl;
        }
    }
};

ll inversion_number(vector<ll> &A){
    BIT<ll> bit(A.size());
    ll ans = 0;
    ll n = A.size();
    for (int i = 0; i < n; i++) {
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
  ll N,M,v;
  cin >> N >> M >> v;
  v--;
  vector<vector<pair<ll,ll>>> G(2*N);
  vector<vector<pair<ll,ll>>> revG(2*N);
  vector<ll> decided(2*N);

  for(int i = 0;i < M;i++){
    ll a,b,c;
    cin >> a >> b >> c;
    a--;b--;
    G[2*a].push_back({2*b+1,c});
    G[2*a+1].push_back({2*b,c});
    revG[2*b].push_back({2*a+1,c});
    revG[2*b+1].push_back({2*a,c});
  }
  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
  vector<ll> answers(2*N,numeric_limits<ll>::max());
  for(int i = 0;i < 2*N;i++){
    if (G[i].size() == 0){
        answers[i] = 0;
        for(auto p:revG[i]){
            decided[p.first]++;
            if (p.first % 2 == 0){
                if (decided[p.first] == G[p.first].size()){
                    ll maximum = 0;
                    for(auto p2:G[p.first]){
                        maximum = max(maximum,answers[p2.first]+p2.second);
                    }
                    q.push({maximum,p.first});
                }
            }else{
                q.push({p.second,p.first});
            }
        }
    }
  }
  while(!q.empty()){
    ll current = q.top().second;
    ll cost = q.top().first;
    q.pop();
    if (cost >= answers[current]){
        continue;
    }
    answers[current] = cost;
    for(auto p:revG[current]){
        decided[p.first]++;

        if (p.first % 2 == 0){
            if (decided[p.first] == G[p.first].size()){
                ll maximum = 0;
                for(auto p2:G[p.first]){
                    maximum = max(maximum,answers[p2.first]+p2.second);
                }
                q.push({maximum,p.first});
            }
        }else{
            q.push({cost+p.second,p.first});
        }
    }
  }
//   for(int i = 0;i < 2*N;i++){
//     cout << i << ":" << answers[i] << endl;
//   }
  if (answers[2*v+1] == numeric_limits<ll>::max()){
    cout << "INFINITY" << endl;
  }else{
    cout << answers[2*v+1] << endl;
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
