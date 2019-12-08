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

long long gcd(long long a, long long b)
{
    if (a % b == 0)
    {
        return b;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int main()
{
    // 整数の入力
    ll a, b;
    ll N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        ll g = gcd(a, b);
        if (g == 1)
        {
            cout << "finite" << endl;
        }
        else
        {
            cout << "Infinite" << endl;
        }
    }
    return 0;
}