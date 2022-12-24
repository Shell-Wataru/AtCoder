#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>
#include <list>

using namespace std;
using ll = long long;

void get_sorted(string &s)
{
  ll n = s.size();
  for(int i = 2;i < n;i++){
    if (s[i-2] == 'C' && s[i-1] == 'A' && s[i] == 'B'){
      swap(s[i-2],s[i-1]);
      swap(s[i-1],s[i]);
    }
  }
  for(int i = 2;i < n;i++){
    if (s[i-2] == 'B' && s[i-1] == 'C' && s[i] == 'A'){
      swap(s[i],s[i-1]);
      swap(s[i-1],s[i-2]);
    }
  }
}


int main()
{
  // 整数の入力
  ll N;
  cin >> N;
  string S, T;
  cin >> S;
  cin >> T;
  get_sorted(S);
  get_sorted(T);
  if (S == T){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
  return 0;
}