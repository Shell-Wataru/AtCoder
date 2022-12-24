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
  // 整数の入力
  ll N,M,K;
  cin >> N;
  vector<ll> A(N);
  vector<ll> revA(N);
  for(int i = 0; i < N;i++){
    cin >> A[i];
    A[i]--;
    revA[A[i]] = i;
  }
  string ans(N,'-');
  ll maximum_next_v = -2;
  ll current = 0;
  for(int i = 0;i < N;i++){
    ll index = A[i];
    ll next_v = -1;
    if (index + 1 < N){
        next_v = revA[index+1];
    }
    if (next_v > maximum_next_v){
        ans[index] = 'A' + current;
        maximum_next_v = next_v;
    }else{
        current++;
        ans[index] = 'A' + current;
        maximum_next_v = next_v;
    }
  }
  if (current >= 26){
    cout << -1 << endl;
  }else{
    cout << ans << endl;
  }

  return 0;
}
