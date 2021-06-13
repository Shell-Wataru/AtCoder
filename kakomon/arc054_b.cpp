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
#include <cmath>

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    double P;
    cin >> P;
    double x= max(0.0, -1.5/log(2) * log(1.5/(log(2) *P)));
    cout << fixed << setprecision(12) << x + P/pow(2.0,x/1.5) << endl;
    return 0;
}
