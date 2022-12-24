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
  ll N,K;
  cin >> N >> K;
  double ans = 0;
  for(int i = 0;i < N;i++){
    double current_ans = 0;
    for(int j = i;j < N;j++){
        current_ans += 1.0/N *  C(j-i,K-1)*(K-1)!*(j-k)! /(j-1)!);
    }
    ans = max(ans,current_ans);
  }
  cout << ans << endl;
  return 0;
}
