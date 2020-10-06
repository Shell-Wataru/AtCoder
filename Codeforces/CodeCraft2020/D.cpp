#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
using namespace std;
using ll = long long;
ll BASE_NUM = 998244353;

int solve(){
  ll a,b,c;
  cin >> a >> b >> c;
  ll minA,minB,minC;
  ll min_move = BASE_NUM;
  for(int A  = 1; A < 20000;A++ ){
    for(int b_a = 1; A * b_a <= 20000;b_a++){
      int B = A * b_a;
      for(int c_b = 1; B * c_b <= 20000;c_b++){
        int C = B * c_b;
        ll move_count = abs(C - c) + abs(B - b) + abs(A - a);
        if (move_count < min_move){
          min_move = move_count;
          minA = A;
          minB = B;
          minC = C;
        }
      }
    }
  }
  cout << min_move << endl;
  cout << minA << " " << minB << " " << minC << endl;

  return 0;
}

int main()
{
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
      solve();
  }
 return 0;
}