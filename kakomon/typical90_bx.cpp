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
#include <stack>

using namespace std;
using ll = long long;

int main()
{
  // 整数の入力
  ll N;
  cin >> N;
  vector<ll> A(N);
  ll total = 0;
  for(int i = 0;i < N;i++){
      cin >> A[i];
      total += A[i];
  }
  if (total % 10 != 0){
      cout << "No" << endl;
      return 0;
  }
  ll target = total/10;
  ll r = 0;
  ll current = A[N-1];
  ll ans = 0;
  for(int i = 0;i < N;i++){
      current -= A[(N+i-1)%N];
      while(current < target){
          current += A[r];
          r =  (r + 1) % N;
          if (r == i){
              break;
          }
      }
      if (current == target){
        //   cout << i << "," << r << endl;
        //   cout << current << endl;
          ans++;
      }
  }
  if (ans > 0){
      cout << "Yes" << endl;
  }else{
      cout << "No" << endl;
  }
//   cout << ans << endl;
  return 0;
}
