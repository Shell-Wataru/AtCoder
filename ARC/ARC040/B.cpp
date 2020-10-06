#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <ctime>
#include <map>
#include <boost/multiprecision/cpp_int.hpp>
#include <string>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
  // 整数の入力
  ll N, R;
  string S;
  cin >> N >> R;
  cin >> S;
  ll shots = 0;
  ll moves = 0;
  ll current = S.length() - 1;
  while(current >= 0){
    if(S[current] == '.'){
      shots++;
      if (moves == 0){
        moves = max(0ll,current - R + 1);
      }
      current -= R;
    }else{
      current--;
    }
  }
  // cout << shots << endl;
  // cout << moves << endl;
  cout << shots + moves << endl;
  return 0;
}