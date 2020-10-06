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
ll BASE_NUM = 998244353;

vector< int > manacher(const string &s) {
  vector< int > radius(s.size());
  int i = 0, j = 0;
  while(i < s.size()) {
    while(i - j >= 0 && i + j < s.size() && s[i - j] == s[i + j]) {
      ++j;
    }
    radius[i] = j;
    int k = 1;
    while(i - k >= 0 && i + k < s.size() && k + radius[i - k] < j) {
      radius[i + k] = radius[i - k];
      ++k;
    }
    i += k;
    j -= k;
  }
  return radius;
}

int solve(){
  string s;
  cin >> s;
  ll n = s.size();
  string longest;
  ll i = 0;
  ll j = n-1;
  string a,b;
  a = "";
  b = "";
  bool found = true;
  while(found && i < j){
    found = false;
    if (s[i] == s[j]){
      a += s[i];
      b += s[j];
      found = true;
      i++;
      j--;
    }
  }
  string remain = "";
  for(int j = i; j < n - i;j++){
    if (i != j){
      remain += "-";
    }
    remain += s[j];
  }
  // s.substr(i,n - 2 * i);

  // cout << remain << endl;
  vector<int> mana = manacher(remain);
  ll front_max = 0;
  ll back_max = 0;
  for(int i = 0; i < (remain.size() + 1)/2;i++){
    if (mana[i] == i+1){
      front_max = i;
    }
  }

  for(int i = 0; i < (remain.size() + 1)/2;i++){
    if (mana[mana.size()- i - 1] == i+1){
      back_max = i;
    }
  }
  // cout << front_max << " " << back_max << endl;
  reverse(b.begin(),b.end());
  if (front_max > back_max){
    cout << a;
    for(int i = 0;i < 2*front_max + 1;i++){
      if (remain[i] != '-'){
        cout << remain[i];
      }
    }
    cout << b << endl;
  }else{
    cout << a;
    for(int i = remain.size() - (2 * back_max + 1);i < remain.size();i++){
      if (remain[i] != '-'){
        cout << remain[i];
      }
    }
    cout << b << endl;
  }
  // cout << longest << endl;
  return 0;
}

int main()
{
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
      solve();
  }
 return 0;
}