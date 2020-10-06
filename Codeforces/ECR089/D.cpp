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
int BASE_NUM = 998244353;

map<int,int> decomposite(int N, map<int,int> & primes,int next_p = 2){
    if (N == 1){
        return primes;
    }

    while (next_p * next_p <= N ) {
        if (N % next_p == 0) {
            primes[next_p] += 1;
            return decomposite(N/next_p,primes,next_p);
        } else {
            next_p++;
        }
    }
    primes[N] += 1;
    return primes;
}

int solve()
{
  int n;
  scanf("%d",&n);
  vector<int> A(n);
  vector<int> ans1(n);
  vector<int> ans2(n);
  for (size_t i = 0; i < n; i++)
  {
    scanf("%d",&A[i]);
  }
  for(int i = 0;i < n;i++){
    map<int,int> dec;
    decomposite(A[i],dec);
    if (dec.size() <= 1){
      ans1[i] = -1;
      ans2[i] = -1;
    }else{
      int product = 1;
      for(auto &p:dec){
        product *= p.first;
      }
      ans1[i] = product/(*dec.begin()).first;
      ans2[i] = (*dec.begin()).first;
    }
  }
  for (size_t i = 0; i < n; i++)
  {
    if (i != 0){
      cout << " ";
    }
    cout << ans1[i];
  }
  cout << "\n";
  for (size_t i = 0; i < n; i++)
  {
    if (i != 0){
      cout << " ";
    }
    cout << ans2[i];
  }
  cout << "\n";
  cout << flush;
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
  // cout << flush;
  return 0;
}