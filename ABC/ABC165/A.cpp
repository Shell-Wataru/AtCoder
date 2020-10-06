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
    ll A,B,K;
    cin >> K;
    cin >> A >> B;
    if( ( (A + K - 1)/K)* K <= B ){
        cout << "OK" << endl;
    }else{
        cout << "NG" << endl;
    }
   return 0;
}