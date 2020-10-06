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

int solve()
{
  ll n;
  scanf("%lld", &n);
  string S;
  cin >> S;
  ll total = 0;
  vector<ll> ones;
  vector<ll> zeros;
  vector<ll> answers;
  for(int i = 0;i < n;i++){
    if (S[i] == '1'){
      if (zeros.size() == 0){
        total++;
        ones.push_back(total);
        answers.push_back(total);
      }else{
        ll a = zeros.back();
        zeros.pop_back();
        ones.push_back(a);
        answers.push_back(a);
      }
    }else{
      if (ones.size() == 0){
        total++;
        zeros.push_back(total);
        answers.push_back(total);
      }else{
        ll a = ones.back();
        ones.pop_back();
        zeros.push_back(a);
        answers.push_back(a);
      }
    }
  }
  cout << total << endl;
  for(int i = 0;i < n;i++){
    if (i != 0){
      cout << " ";
    }
    cout << answers[i];
  }
  cout << endl;
  return 0;
}

int main()
{
  int t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  // cout << flush;
  return 0;
}