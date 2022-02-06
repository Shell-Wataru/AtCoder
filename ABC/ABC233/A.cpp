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
    ll X,Y;
    cin >> X >> Y;
    if (X >= Y){
        cout << 0 << endl;
    }else{
        cout << (Y-X+9)/10 << endl;
    }
    return 0;
}