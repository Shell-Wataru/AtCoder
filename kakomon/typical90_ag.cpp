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
    ll H,W;
    cin >> H >> W;
    if (H == 1){
        cout << W << endl;
    }else if (W == 1){
        cout << H << endl;
    }else{
        cout << ((H+1)/ 2) * ((W + 1)/2) << endl;
    }

    return 0;
}