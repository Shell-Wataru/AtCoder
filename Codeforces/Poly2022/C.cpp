#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

int solve()
{
  ll n;
  scanf("%lld", &n);
  string S;
  cin >> S;
  ll lasts = 0;
  for(int i = 0;i < n-1;i++){
    if(i > 0 && S[i] == S[i-1]){
      lasts++;
    }else{
      lasts = 1;
    }
    if (i != 0){
      cout << " ";
    }
    cout << i+2 - lasts;
  }
  cout << "\n";
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
  cout << flush;
  return 0;
}
