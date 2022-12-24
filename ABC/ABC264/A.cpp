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
    string S = "atcoder";
    ll L,R;
    cin >> L >> R;
    cout << S.substr(L-1,R-L+1) << endl;
    return 0;
}