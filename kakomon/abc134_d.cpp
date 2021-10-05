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

using namespace std;
using ll = long long;

int main()
{
  // 整数の入力
  ll N;
  cin >> N;
  vector<ll> A(N+1);
  for (size_t i = 1; i <= N; i++)
  {
    cin >> A[i];
  }
  vector<ll> ans(N+1);
  for(int i = N;i >= 1;i--){
      ll total = 0;
      for(int j = 2; i*j <= N;j++){
          total = total + ans[i*j];
          total %= 2;
      }
    //   cout << i << ":" << total << endl;
      if (total != A[i]){
          ans[i] = 1;
      }else{
          ans[i] = 0;
      }
  }
  vector<ll> b;
  for(int i = 1;i <= N;i++){
      if (ans[i] == 1){
          b.push_back(i);
      }
  }
  cout << b.size() << endl;
  if (b.size() != 0){
    for(int i = 0;i < b.size();i++){
        if (i != 0){
            cout << " ";
        }
        cout << b[i];
    }
    cout << endl;
  }
  return 0;
}
