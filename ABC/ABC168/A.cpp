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
    string S;
    cin >> S;
    if( S.back() == '2' || S.back() == '4' ||S.back() == '5' ||S.back() == '7' ||S.back() == '9'){
        cout << "hon" << endl;
    }else if(S.back() == '0' ||S.back() == '1' ||S.back() == '6' ||S.back() == '8'){
        cout << "pon" << endl;
    }
    else{
        cout << "bon" << endl;
    }
   return 0;
}