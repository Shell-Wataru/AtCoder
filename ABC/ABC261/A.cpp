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
    ll L1,R1;
    ll L2,R2;
    cin >> L1 >> R1;
    cin >> L2 >> R2;
    cout <<  max(min(R1,R2) - max(L1,L2),0ll) << endl;

    return 0;
}