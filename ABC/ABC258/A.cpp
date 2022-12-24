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
    ll K;
    cin >> K;
    cout << 21+ K/60 << ":";
    if (K % 60 < 10){
        cout << 0;
    }
    cout << K % 60 << endl;
    return 0;
}