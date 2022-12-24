#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <numeric>

using namespace std;
using ll = long long;

int solve()
{
  ll n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> answers_odd(n,0);
  vector<ll> answers_even(n,0);
  for(int i = 0;i < n;i++){
    scanf("%lld",&a[i]);
    a[i]--;
    if (i % 2 == 0){
      answers_even[a[i]] = max(answers_even[a[i]],answers_odd[a[i]]+1);
    }else{
      answers_odd[a[i]] = max(answers_odd[a[i]],answers_even[a[i]]+1);
    }
  }
  for(int i = 0;i < n;i++){
    if (i != 0){
      cout << " ";
    }
    cout << max(answers_even[i],answers_odd[i]);
  }
  cout << "\n";
  return 0;
}

int main()
{
  ll t;
  cin >> t;

  for (int i = 1; i <= t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}