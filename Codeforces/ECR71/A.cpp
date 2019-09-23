#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    long long T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        ll b, p, f, h, c, ans;
        cin >> b >> p >> f;
        cin >> h >> c;
        ans = 0;
        if (h > c)
        {
            if (b >= 2 * p)
            {
                ans += p * h;
                b -= 2 * p;
            }
            else
            {
                ans += b / 2 * h;
                b = 0;
            }

            if (b >= 2 * f)
            {
                ans += f* c;
                b -= 2 * f;
            }
            else
            {
                ans += b / 2 * c;
                b = 0;
            }
        }
        else
        {
            if (b >= 2 * f)
            {
                ans += c * f;
                b -= 2 * f;
            }
            else
            {
                ans += b / 2 * c;
                b = 0;
            }

            if (b >= 2 * p)
            {
                ans += p * h;
                b -= 2 * p;
            }
            else
            {
                ans += b / 2 * h;
                b = 0;
            }
        }

        cout << ans << endl;
    }

    return 0;
}