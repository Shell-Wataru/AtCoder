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
#include <atcoder/string>
#include <unordered_map>
using namespace std;
using ll = long long;
using namespace atcoder;

// 区間加算　一点取得
//zero indexed and vector
template< typename T>
class DualBIT
{
public:
    vector<T> data;
    DualBIT(long long n) : data(n) {}
    // [0,index)に足す
    void add(int index, T v)
    {
        for (int i = index - 1; i >= 0; i = (i & (i + 1)) - 1)
        {
            data[i] += v;;
        }
    }

    // indexを取得
    T get(int index)
    {
        T retValue = 0;
        int N = data.size();
        for (int i = index; i < N; i |= i + 1)
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
  ll N,A;
  cin >> N >> A;
  vector<vector<ll>> fishes(N);
  for(int i = 0;i < N;i++){
    ll w,x,v;
    cin >> w >> x >>v;
    fishes[i] = {w,x,v};
  }
  ll ans = 0;

  for(int i = 0;i < N;i++){
    // cout << "a" << endl;
    Compress<double> C;
    // cout << "!" << endl;
    for(int j = 0;j < N;j++){

      ll relative_v = fishes[j][2] - fishes[i][2];
      ll relative_x = fishes[j][1] - fishes[i][1];
      // cout << relative_x << " " << relative_v << endl;
      if (relative_v == 0){
        if (0 <= relative_x && relative_x <= A){
          C.add(0);
        }
      }else{
        double t1 = 1.0 *(A - relative_x)/relative_v;
        double t2 = -1.0 *relative_x/relative_v;
        if (t1 > t2){
          swap(t1,t2);
        }
        if (t2 >= 0){
          t1 = max(t1,0.0);
          C.add(t1);
          C.add(t2);
        }

      }
    }
    // cout << "!" << endl;
    C.build();
    DualBIT<ll> bit(C.size());
    for(int j = 0;j < N;j++){
      ll relative_v = fishes[j][2] - fishes[i][2];
      ll relative_x = fishes[j][1] - fishes[i][1];
      if (relative_v == 0){
        if (0 <= relative_x && relative_x <= A){
          bit.add(C.size(),fishes[j][0]);
        }
      }else{
        double t1 = 1.0 *(A - relative_x)/relative_v;
        double t2 = -1.0 *relative_x/relative_v;
        if (t1 > t2){
          swap(t1,t2);
        }
        // cout << i << "," << j << endl;
        // cout << t1 << "~" << t2 << endl;
        if (t2 >= 0){
          t1 = max(t1,0.0);
          bit.add(C.get(t2)+1,fishes[j][0]);
          bit.add(C.get(t1),-fishes[j][0]);
        }
      }
    }
    // cout << "c" << endl;
    for(int j = 0;j < C.size();j++){
      ans = max(ans,bit.get(j));
    }
    // cout << "d" << endl;
  }
  cout << ans << endl;
  return 0;
}
