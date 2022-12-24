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

ll solve()
{
  ll N,L,R;
  scanf("%lld",&N);
  scanf("%lld",&L);
  scanf("%lld",&R);
  L--;
  deque<ll> q;
  vector<ll> A;
  for(int i = 1;i <= N;i++){
    q.push_back(i);
  }
  ll s = 0;
  ll e = 0;
  for(ll i = 0;i < N;i++){
    s = e;
    e += N-1-i;
    // cout << s << "~" << e << endl;
    if (L <= s && e <= R){
      ll last = q.back();
      q.push_front(last);
      q.pop_back();
    }else{
      ll from = max(L,s);
      ll to = min(e,R);
      // cout << "f" << from << "~t" <<  to << endl;
      // cout << q.size() << endl;
      for(ll j = from - s;j < to - s;j++){
        // cout << "j" << j << endl;
        swap(q[0],q[j+1]);
      }
    }
    A.push_back(q.front());
    q.pop_front();
  }
  for(int i = 0;i < N;i++){
    if (i != 0){
      cout << " ";
    }
    cout << A[i];
  }
  cout << endl;
  return 0;
}

int main()
{
  // ll N;
  // cin >> N;
  // for(int i = 1; i <= N;i++){
  solve();
  // }
  cout << flush;
  return 0;
}
