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
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
  // 整数の入力
  ll N,K;
  cin >> N >> K;
  vector<ll> A(N);
  vector<ll> visited(N, -1);
  for(int i = 0 ;i < N;i++){
    cin >> A[i];
    A[i]--;
  }
  ll current = 0;
  ll turn = 0;
  map<ll,ll> ikisaki;
  while(visited[current] == -1){
    visited[current] = turn;
    ikisaki[turn] = current;
    // cout << turn << " " << current << endl;
    turn++;
    current = A[current];
  }
  ll base = visited[current];
  ll shuuki = turn - visited[current];
  // cout << base << " " << shuuki << endl;
  if (K < base){
    cout << ikisaki[K] + 1 << endl;
  }else{
    // cout << (K - base) % shuuki + base << endl;
    cout << ikisaki[(K - base) % shuuki + base] + 1<< endl;
  }
  return 0;
}