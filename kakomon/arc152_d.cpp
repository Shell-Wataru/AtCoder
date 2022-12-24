#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
#include <unordered_map>
using namespace std;
using ll = long long;

struct UnionFind
{
  vector<int> data;

  UnionFind(int sz)
  {
    data.assign(sz, -1);
  }

  bool unite(int x, int y)
  {
    x = find(x), y = find(y);
    if (x == y)
      return (false);
    if (data[x] > data[y])
      swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  bool same(int x, int y)
  {
    x = find(x), y = find(y);
    return x == y;
  }
  int find(int k)
  {
    if (data[k] < 0)
      return (k);
    return (data[k] = find(data[k]));
  }

  int size(int k)
  {
    return (-data[find(k)]);
  }
};

int solve()
{
  ll N, K;
  cin >> N >> K;
  if (N % 2 == 0)
  {
    cout << -1 << endl;
  }
  else
  {
    cout << (N - 1) / 2 << endl;
    if (gcd(N,K) == 1)
    {
      ll current = 0;
      for (int i = 0; i < N / 2; i++)
      {
        cout << current << " " << (current + K) % N << endl;
        current = (current+ 2*K)%N;
      }
    }else{

      bool is_reverse = false;
      if (K > N-K){
        K = N-K;
        is_reverse = true;
      }
      ll lines = N/K;
      vector<pair<ll,ll>> answers;
      for(int i = 0;i < K;i++){
        ll current = i;
        for(int j = 0;j < lines/2;j++){
          answers.push_back({current,current+1});
          current += 2*K;
        }
      }
      ll remain = (N % (2* K));
      for(int i = 1;i <= remain/2;i++){
        answers.push_back({N -remain + remain/2 +i - K ,N - remain +i});
      }
      if (is_reverse){
        for(auto p:answers){
          cout << (p.first + K) % N <<" " << (p.second+K) % N << endl;
        }
      }else{
        for(auto p:answers){
          cout << p.first <<" " << p.second << endl;
        }
      }
    }
  }
  return 0;
}

int main()
{
  // int t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
  solve();
  // }
  cout << flush;
  return 0;
}