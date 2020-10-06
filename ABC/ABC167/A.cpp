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
    string S,T;
    cin >> S;
    cin >> T;
    if( S == T.substr(0,S.size()) ){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
   return 0;
}