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
  string S,T;
  cin >> S >> T;
  if (S == T){
    cout << "Yes" << endl;
    return 0;
  }
  for(int i = 0;i < S.length()-1;i++){
    swap(S[i],S[i+1]);
    if (S == T){
      cout << "Yes" << endl;
      return 0;
    }
    swap(S[i],S[i+1]);
  }
  cout << "No" << endl;
  return 0;
}