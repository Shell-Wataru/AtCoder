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
    string S,ans;
    cin >> S;
    for(auto &c:S){
      if (ans.empty()){
        ans += c;
      }else if (ans.back() == 'S' && c == 'T'){
        ans.pop_back();
      }else{
        ans += c;
      }
    }
    cout << ans.length() << endl;
    return 0;
}