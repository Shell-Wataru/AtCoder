#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <ctime>
#include <map>
#include <boost/multiprecision/cpp_int.hpp>
#include <string>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
    // 整数の入力
    ll n, a, b;
    cin >> a >> b;
    cin >> n;
    if (a < b)
    {
        swap(a, b);
    }
    double eps = 0.001;
    for (int i = 0; i < n; i++)
    {
        ll c, d;
        cin >> c >> d;
        if (c < d)
        {
            swap(c, d);
        }
        if (a <= c + eps && b <= d + eps)
        {
            cout << "YES" << endl;
        }
        else if (a > c && b > d)
        {
            cout << "NO" << endl;
        }
        else
        {
            double alpha = atan(1.0 * b / a);
            double theta = acos(1.0 * d / sqrt(a * a + b * b));
            double height = max(sqrt(a * a + b * b) * sin(theta), sqrt(a * a + b * b) * sin(theta + 2 * alpha));
            double width = max(abs(sqrt(a * a + b * b) * cos(theta)), abs(sqrt(a * a + b * b) * cos(theta + 2 * alpha)));
            // cout << "alpha" <<alpha << endl;
            // cout << "theta" << theta << endl;
            // cout << height << endl;
            // cout << sqrt(a * a + b * b) * cos(theta) << endl;
            if (height <= c + eps && width <= d+eps)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}