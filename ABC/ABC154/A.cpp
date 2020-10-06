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
    string S,T,U;
    ll A,B;
    cin >> S >> T >> A >> B >> U;
    if (S == U){
        A--;
    }else{
        B--;
    }

    cout << A << " " << B << endl;
    return 0;
}