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
  ll N,A,B;
  cin >> N >> A >> B;
  for(int i = 0;i < N* A;i++){
    for(int j = 0;j < N*B;j++){
      bool a = i % (2*A) < A;
      bool b = j % (2*B) < B;
      if (a ^ b){
        cout << '#';
      }else{
        cout << '.';
      }
    }
    cout << "\n";
  }
  cout << flush;
  return 0;
}