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
    ll n;
    cin >> n;
    if (n >= 10 || 1ll<<n > n*n){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}