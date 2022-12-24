#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <iomanip>
#include <cmath>
#include <cmath>
#include <set>
#include <numeric>
#include <climits>
#include <unordered_map>
using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll h1, h2, h3, w1, w2, w3;
    cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;
    ll ans = 0;
    for (int a11 = 1; a11 <= 28; a11++)
    {
        for (int a12 = 1; a12 <= 28; a12++)
        {
            for (int a21 = 1; a21 <= 28; a21++)
            {
                for (int a22 = 1; a22 <= 28; a22++)
                {
                    int a31 = h1 - a21 - a11;
                    int a32 = h2 - a22 - a12;
                    int a13 = w1 - a12 - a11;
                    int a23 = w2 - a22 - a21;
                    int a33 = h3 - a13 - a23;
                    if (a31 + a32 + a33 == w3 && 1 <= a31 && 1 <= a32 && 1 <= a13 && 1 <= a23 && 1 <= a33)
                    {
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
