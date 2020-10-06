#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <cmath>
#include <iterator> // std::rbegin, std::rend
#include <functional>

using namespace std;
using ll = long long;

int solve()
{
  ll n;
  cin >> n;
  vector<ll> A(n);
  for (int i = 0; i < n; i++)
  {
    cin >> A[i];
  }
  string current = "";
  for(int i = 0;i < 200;i++){
    current += "a";
  }
  cout << current << endl;
  for(int i = 0;i < n;i++){
    string next = "";
    for(int j = 0;j < 200;j++){
      if (j < A[i]){
        next += current[j];
      }else{
        if (current[j] == 'a'){
          next += 'b';
        }else{
          next += 'a';
        }
      }
    }
    cout << next << endl;
    current = next;
  }
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
  return 0;
}