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
  ll N;
  cin >> N;
  ll continueation = 0;
  ll max_continueation = 0;
  for(int i = 0;i < N;i++){
    ll d1, d2;
    cin >> d1 >> d2;
    if (d1 == d2){
      continueation++;
    }else{
      continueation = 0;
    }
    max_continueation = max(max_continueation,continueation);
  }
  if (max_continueation >= 3){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
 return 0;
}