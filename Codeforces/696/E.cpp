#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>

using namespace std;
using ll = long long;
const int BASE_NUM = 1000000007;

int solve()
{
    int n;
    scanf("%d", &n);
    unsigned long long ab,ac,bc;
    cout << "OR 1 2" << endl;
    cin >> ab;
    cout << "OR 1 3" << endl;
    cin >> ac;
    cout << "AND 2 3" << endl;
    cin >> bc;
    cout << ab << endl;
    cout << ac << endl;
    cout << bc << endl;
    cout << ((ab&ac&~bc) | (ab&ac&bc)) << endl;
    return 0;
}
int main()
{
    // 整数の入力
    // int t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
        solve();
        // }
    // cout << flush;
    return 0;
}
