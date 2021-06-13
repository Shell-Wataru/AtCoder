#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

ll BASE_NUM = 1000000007;

int main()
{
    // 整数の入力
    ll N, D, H;
    vector<ll> X;
    cin >> N >> D >> H;
    double ans = 0;
    for (int i = 0; i < N; i++)
    {
        ll h, d;
        cin >> d >> h;
        ans = max(ans, -1.0 * (H - h) / (D - d) * d + h);
    }
    cout << fixed << setprecision(12)<< ans << endl;
    return 0;
}