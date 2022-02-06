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

int main()
{
  string X;
  cin >> X;
  reverse(X.begin(),X.end());
  vector<ll> ans;
  vector<ll> digitSum(X.size()+1);
  for(ll i= 0;i < X.size();i++){
    digitSum[i+1] = digitSum[i] + (X[i] - '0');
  }
  ll remain = 0;
  for(int i = 0;i < X.size();i++){
    ll current = remain + digitSum[X.size()] - digitSum[i];
    // cout << current << endl;
    ans.push_back(current % 10);
    remain = current/10;
  }
  reverse(ans.begin(),ans.end());
  if (remain){
    cout << remain;
  }

  for(auto r:ans){
    cout << r;
  }
  cout << endl;
  return 0;
}
