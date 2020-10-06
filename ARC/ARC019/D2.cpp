#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
ll BASE_NUM = 1000000007;

int diag(ll n, vector<string> &answer){
  for(int i = 0;i< 150;i++){
    if (0 <= i+ n && i + n < 150){
      answer[i+n][i] = 'o';
    }
  }
  return 0;
}

int main()
{
  vector<string> answer(150, "......................................................................................................................................................");
  diag(0,answer);
  diag(1,answer);
  diag(-2,answer);
  diag(5,answer);
  diag(-8,answer);
  diag(15,answer);
  diag(-20,answer);
  diag(31,answer);
  diag(42,answer);
  diag(-48,answer);
  diag(-67,answer);
  diag(76,answer);
  diag(100,answer);
  diag(119,answer);
  diag(-125,answer);
  diag(-136,answer);
  //1605
  // vector<ll> used_rows({0});
  // ll lower = 0;
  // ll upper = 0;
  // for(int i = 0; i< 20;i++){
  //   set<ll> diffs({0});
  //   for(int j = 0;j < used_rows.size();j++){
  //     for(int k = j+1; k < used_rows.size();k++){
  //       ll diff = abs(used_rows[j] - used_rows[k]);
  //       diffs.insert(diff);
  //     }
  //   }
  //   ll new_row = -151;
  //   for(int j = -150; j <= 150;j++){
  //     bool is_clear = true;
  //     for(int k = 0; k < used_rows.size();k++){
  //       ll diff = abs(j - used_rows[k]);
  //       if(diffs.find(diff) != diffs.end()){
  //         is_clear = false;
  //         break;
  //       }
  //     }
  //     if(is_clear && abs(j) < abs(new_row)){
  //         new_row = j;
  //     }
  //   }
  //   if (new_row != -151){
  //     cout << "new_row" << new_row << endl;
  //     used_rows.push_back(new_row);
  //   }
  // }
  // for(auto r:used_rows){
  //   if (abs(r) <= 150){
  //     diag(r,answer);
  //   }
  // }
  cout << 150 << endl;
  for (auto s : answer)
  {
    cout << s << endl;
  }
  return 0;
}