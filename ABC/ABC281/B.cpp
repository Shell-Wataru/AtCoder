

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
    string S;
    cin >> S;
    if (S.size() != 8){
      cout << "No" << endl;
    }else{
      bool is_ok = true;
      is_ok = is_ok && 0<= (S[0]-'A') && (S[0]-'A') < 26;
      is_ok = is_ok && 1<= (S[1]-'0') && (S[1]-'0') < 10;
      is_ok = is_ok && 0<= (S[2]-'0') && (S[2]-'0') < 10;
      is_ok = is_ok && 0<= (S[3]-'0') && (S[3]-'0') < 10;
      is_ok = is_ok && 0<= (S[4]-'0') && (S[4]-'0') < 10;
      is_ok = is_ok && 0<= (S[5]-'0') && (S[5]-'0') < 10;
      is_ok = is_ok && 0<= (S[6]-'0') && (S[6]-'0') < 10;
      is_ok = is_ok && 0<= (S[7]-'A') && (S[7]-'A') < 26;
      if (is_ok){
        cout << "Yes" << endl;
      }else{
        cout << "No" << endl;
      }
    }
    return 0;
}