#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

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
    long long get(int index)
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

int solve()
{
  ll n;
  scanf("%lld", &n);
  DualBIT<ll> bit(n);
  vector<ll> c(n);
  vector<ll> a(n);
  for(int i = 0;i < n;i++){
    cin >> c[i];
  }
  for(int i = 0;i < n;i++){
    bit.add(i+1,c[i]);
    bit.add(i,-c[i]);
  }
  ll total = 0;
  for(int i = 0;i < n;i++){
    total += c[i];
  }
  ll one_count = total/n;
  ll zero_count = n - one_count;
  for(int i = n-1;i >= 0;i--){
      bit.add(i+1,-1);
      bit.add(zero_count,1);
    //   for(int j = 0;j < n;j++){
    //       cout << bit.get(j);
    //   }
    //   cout << endl;
      if (bit.get(i) > 0){
          one_count--;
          a[i] = 1;
      }else{
          zero_count--;
          a[i] = 0;
      }
  }
  if (c[0] > 0){
      a[0] = 1;
  }
  for(int i = 0;i < n;i++){
      if (i != 0){
          cout << " ";
      }
      cout << a[i];
  }
  cout << "\n";
  return 0;
}

int main()
{
  // 整数の入力
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}
