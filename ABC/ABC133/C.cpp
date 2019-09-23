#include<iostream>
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
namespace mp = boost::multiprecision;
ll BASE_NUM =  1000000007;
int main()
{
    // 整数の入力
    ll L,R,minimum,realL,diff,BASE;
    minimum = 2020;
    BASE = 2019;
    cin >> L >> R;
    realL = L % BASE;
    diff = min(R - L,2020LL);
    for (int i = realL;i < realL + diff;i++){
        for(int j = i + 1; j <= realL + diff;j++){
            // cout << i << " " << j<<endl;
            minimum = min(minimum,(i * j) % BASE);
        }
    }
    cout << minimum << endl;
    return 0;
}