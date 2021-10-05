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
    ll A,B;
    cin >>  A >> B;
    if (A + B>=  15 && B >= 8){
        cout << 1 << endl;
    }else if(A+B >= 10 && B >= 3){
        cout << 2 << endl;
    }else if (A+B >= 3){
        cout << 3 << endl;
    }else{
        cout << 4 <<endl;
    }
    return 0;
}