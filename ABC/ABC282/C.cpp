#define _USE_MATH_DEFINES
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
#include <unordered_map>
#include <unordered_set>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
  ll N;
  cin >> N;
  string S;
  cin >> S;
  bool is_in = false;
  for(int i = 0;i < N;i++){
    if (S[i] == '"'){
      is_in = !is_in;
      cout << S[i];
    }else{
      if (is_in){
        cout << S[i];
      }else if(S[i] == ','){
        cout << ".";
      }else{
        cout << S[i];
      }
    }
  }
  cout << endl;
  return 0;
}