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
#include <set>
using namespace std;
using ll = long long;

int main()
{
  string S;
  cin >> S;
  ll N = S.size();
  if (N % 2 == 1){
      if (S.front() == S.back()){
          cout << "Second" << endl;
      }else{
          cout << "First" << endl;
      }
  }else{
      if (S.front() == S.back()){
          cout << "First" << endl;
      }else{
          cout << "Second" << endl;
      }
  }
  return 0;
}
