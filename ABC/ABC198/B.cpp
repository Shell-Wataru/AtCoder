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

int main()
{
  // 整数の入力
  string A;
  cin >> A;
  for(int i = A.size()-1;i >= 0;i--){
    if (A[i] == '0'){
      A.pop_back();
    }else{
      break;
    }
  }
  bool is_paridrome = true;
  for(int i = 0;i < A.size();i++){
    if (A[i] != A[A.size() - 1 - i]){
      is_paridrome = false;
      break;
    }
  }
  if (is_paridrome){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}