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
    double A,B;
    cin >> A >> B;
    cout << fixed << setprecision(12) << (A -B)/3 + B << endl;
    return 0;
}