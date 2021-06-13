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
    ll x,y;
    cin >> x >> y;
    if (x == y){
        cout << x << endl;
    }else if ((x == 1 && y == 2)  || (x == 2 && y == 1) ){
        cout << 0 << endl;
    }else if ( (x == 2 && y == 0)  || (x == 0 && y == 2)){
        cout << 1 << endl;
    }else{
        cout << 2 << endl;
    }
    return 0;
}