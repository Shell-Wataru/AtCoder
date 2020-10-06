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
  ll K;
  cin >> K;
  vector<vector<string>> RunRun(30,vector<string>());
  for(int i = 0;i< 10;i++){
    RunRun[0].push_back(to_string(i));
  }
  for(int i = 1;i<=10;i++){
    for(auto r:RunRun[i-1]){
      ll head = r[0] - '0';
      if (0 <= head + 1 && head + 1 <= 9 ){
        RunRun[i].push_back(to_string(head + 1) + r);
      }
      RunRun[i].push_back(to_string(head) + r);
      if (0 <= head - 1 && head - 1 <= 9 ){
        RunRun[i].push_back(to_string(head - 1) + r);
      }
    }
  }
  vector<ll> Numbers;
  for(int i = 0;i<=10;i++){
    for(auto r: RunRun[i]){
      if(r[0] != '0'){
        Numbers.push_back(stoll(r));
      }
    }
  }
  sort(Numbers.begin(),Numbers.end());
  cout << Numbers[K-1]<< endl;
  return 0;
}