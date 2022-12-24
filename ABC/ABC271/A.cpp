

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
    ll a;
    cin >> a;
    ll b= a/16;
    ll c= a%16;

    if (b > 10){
        cout  << (char)('A' + b - 10);
    }else{
        cout << b;
    }
    if (c > 10){
        cout  << (char)('A' + c - 10);
    }else{
        cout << c;
    }
    cout<< endl;
    return 0;
}