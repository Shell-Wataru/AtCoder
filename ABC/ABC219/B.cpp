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
  string S1,S2,S3,S;
  cin >> S1 >> S2 >> S3 >> S;
  for(auto c:S){
    if (c == '1'){
      cout << S1;
    }else if(c == '2'){
      cout << S2;
    }else{
      cout << S3;
    }
  }
  cout << endl;
  return 0;
}