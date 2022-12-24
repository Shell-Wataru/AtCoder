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
    ll a,b,c,x;
    cin >> a >> b >> c >> x;
    if ( x <= a){
        cout << 1 << endl;
    }else if (x <= b){
        cout << fixed << setprecision(12) << 1.0*c/(b-a) << endl;
    }else{
        cout << 0 << endl;
    }
    return 0;
}