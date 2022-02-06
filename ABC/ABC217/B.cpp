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
  set<string > s = {
    "ABC","ARC","AGC","AHC"
  };
  string S;
  cin >> S;
  s.erase(S);
  cin >> S;
  s.erase(S);
  cin >> S;
  s.erase(S);
  cout << *s.begin() << endl;
  return 0;
}