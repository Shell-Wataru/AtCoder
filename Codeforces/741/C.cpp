#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
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
  ll k;
  scanf("%lld", &k);
  string n;
  cin >> n;
  ll zero_index = -1;
  for(int i =0 ;i < k;i++){
    if (n[i] == '0'){
      zero_index = i;
      break;
    }
  }
  if(zero_index == -1){
    cout << 1 << " " << k-1 << " " << 2 << " " << k  << "\n";
  }else if (zero_index < k/2){
    cout << zero_index + 1 << " " << k << " " << zero_index + 2 << " " << k << "\n";
  }else{
    cout << 1 << " " << zero_index + 1 << " " << 1 << " " << zero_index << "\n";
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
  cout << flush;
  return 0;
}
