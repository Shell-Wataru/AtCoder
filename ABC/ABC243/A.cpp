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
    ll v,a,b,c;
    cin >> v >> a >> b >> c;
    while( v >= 0){
        v -= a;
        if (v < 0){
            cout << "F" << endl;
            return 0;
        }
        v -= b;
        if (v < 0){
            cout << "M" << endl;
            return 0;
        }
        v -= c;
        if (v < 0){
            cout << "T" << endl;
            return 0;
        }
    }
    return 0;
}