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
using namespace std;
using ll = long long;

vector<int> prime_numbers(int n){
    if (n <= 1){
        return vector<int>(0);
    }
    vector<int> ans = {2};
    for(int i = 3;i <= n;i++){
        bool is_prime = true;
        for(int j = 0; ans[j] * ans[j] <= i;j++){
            if (i % ans[j] == 0){
                is_prime = false;
                break;
            }
        }
        if (is_prime){
            ans.push_back(i);
        }
    }
    return ans;
}
vector<int> primes = prime_numbers(1100);
void decomposite(int N, map<int,int> &factors,int p_index = 0){
    if (N == 1){
        return;
    }

    while (primes[p_index] * primes[p_index] <= N ) {
        if (N % primes[p_index] == 0) {
            factors[primes[p_index]] += 1;
            decomposite(N/primes[p_index],factors,p_index);
            return;
        } else {
            p_index++;
        }
    }
    factors[N] += 1;
}

struct Mo
{
  using ADD = function<void(int)>;
  using DEL = function<void(int)>;
  using REM = function<void(int)>;

  int width;
  vector<int> left, right, order;
  vector<bool> v;

  Mo(int N, int Q) : width((int)sqrt(N)), order(Q), v(N)
  {
    iota(begin(order), end(order), 0);
  }

  void add(int l, int r)
  { /* [l, r) */
    left.emplace_back(l);
    right.emplace_back(r);
  }

  int run(const ADD &add, const DEL &del, const REM &rem)
  {
    // assert(left.size() == order.size());
    sort(begin(order), end(order), [&](int a, int b)
         {
      int ablock = left[a] / width, bblock = left[b] / width;
      if(ablock != bblock) return ablock < bblock;
      if(ablock & 1) return right[a] < right[b];
      return right[a] > right[b]; });
    int nl = 0, nr = 0;
    auto push = [&](int idx)
    {
      v[idx].flip();
      if (v[idx])
        add(idx);
      else
        del(idx);
    };
    for (auto idx : order)
    {
      while (nl > left[idx])
        push(--nl);
      while (nr < right[idx])
        push(nr++);
      while (nl < left[idx])
        push(nl++);
      while (nr > right[idx])
        push(--nr);
      rem(idx);
    }
    return 0;
  }
};

int main()
{
  int N, Q;
  cin >> N;
  cin >> Q;

  vector<int> A(N);
  vector<map<int,int>> decomposited(N);
  for (int i = 0; i < N; i++)
  {
    scanf("%d",&A[i]);
    decomposite(A[i],decomposited[i]);
    vector<ll> remove_keys;
    for(auto p:decomposited[i]){
      if(p.second % 3 == 0){
        remove_keys.push_back(p.first);
      }
    }
    for(auto key:remove_keys){
      decomposited[i].erase(key);
    }
  }
  Mo mo(N, Q);
  for (int i = 0; i < Q; i++)
  {
    int l, r;
    scanf("%d",&l);
    scanf("%d",&r);

    mo.add(--l, r);
  }
  vector<ll> ret(1000001);
  ll count = 0;
  auto add = [&](int idx)
  {
    for(auto &p:decomposited[idx]){
      bool before = ret[p.first] % 3 == 0;
      ret[p.first] += p.second;
      bool after = ret[p.first] % 3 == 0;
      if (before && !after){
        count++;
      }else if (!before && after){
        count--;
      }
    }
  };
  auto del = [&](int idx)
  {
    for(auto &p:decomposited[idx]){
      bool before = ret[p.first] % 3 == 0;
      ret[p.first] -= p.second;
      bool after = ret[p.first] % 3 == 0;
      if (before && !after){
        count++;
      }else if (!before && after){
        count--;
      }
    }
  };
  vector<bool> ans(Q);
  auto rem = [&](int idx)
  {
    ans[idx] = count == 0;
  };
  mo.run(add, del, rem);
  for (int i = 0; i < Q; i++)
  {
    if (ans[i]){
      cout << "Yes\n";
    }else{
      cout << "No\n";
    }
  }
  cout << flush;
  return 0;
}
