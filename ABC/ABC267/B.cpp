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
  string S;
  cin >> S;
  vector<vector<ll>> rows = {
    {6},
    {3},
    {1,7},
    {0,4},
    {2,8},
    {5},
    {9}
  };
  if (S[0] == '1'){
    cout << "No" << endl;
    return 0;
  }else{
    vector<bool> pins(7,false);
    for(int i = 0;i < rows.size();i++){
      for(auto r:rows[i]){
        if (S[r] == '1'){
          pins[i] = true;
        }
      }
    }
    bool found_a = false;
    bool found_b = false;
    bool found_c = false;
    for(int i = 0;i <rows.size();i++){
      if (!found_a){
        if (pins[i]){
          found_a = true;
        }
      }else if (!found_b){
        if (!pins[i]){
          found_b = true;
        }
      }else if (!found_c){
        if (pins[i]){
          found_c = true;
        }
      }
    }
    if (found_c){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }
  return 0;
}