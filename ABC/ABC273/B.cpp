

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
    ll X,K;
    cin >> X >> K;
    ll base = 10;
    for(int i = 0;i < K;i++){
        ll current = X - X % base;
        if (X % base >= base/2){
            current += base;
        }
        base *= 10;
        X = current;
    }

    cout << X << endl;
    return 0;
}