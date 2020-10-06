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
ll BASE_NUM = 2000000007;

int main()
{
  // 整数の入力
  ll N;
  cin >> N;
  vector<ll> A(N);
  ll all_xor = 0;
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
    all_xor ^=  A[i];
  }
  for(int i = 0;i < N;i++){
    if (i != 0){
      cout << " ";
    }
    cout << (all_xor ^ A[i]);
  }
  cout << endl;
  return 0;
}
