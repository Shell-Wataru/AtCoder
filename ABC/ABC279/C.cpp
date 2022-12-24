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
  ll H,W;
  cin >> H >> W;
  vector<string> S(H);
  vector<string> T(H);
  vector<string> tS(W,string(H,'-'));
  vector<string> tT(W,string(H,'-'));
  for(int i = 0;i < H;i++){
    cin >> S[i];
  }
  for(int i = 0;i < H;i++){
    cin >> T[i];
  }
  for(int i = 0;i < H;i++){
    for(int j = 0;j < W;j++){
      tS[j][i] = S[i][j];
      tT[j][i] = T[i][j];
    }
  }
  sort(tS.begin(),tS.end());
  sort(tT.begin(),tT.end());
  if (tS == tT){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}