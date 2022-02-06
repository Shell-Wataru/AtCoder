
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>

using namespace std;
using ll = long long;

ll BASE_NUM = 1000000007;

int main()
{
    // 整数の入力
    ll A, B, C;
    cin >> A >> B >> C;
    cout << (A * B % BASE_NUM) * C % BASE_NUM << endl;

    return 0;
}