#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
using namespace std;
using ll = long long;

ll pow(ll x, ll y, ll modulo)
{
    if (y == 0)
    {
        return 1LL;
    }
    else
    {
        ll y_2 = pow(x, y / 2, modulo) % modulo;
        ll yy = (y_2 * y_2) % modulo;
        if (y % 2 == 0)
        {
            return yy;
        }
        else
        {
            return (yy * x) % modulo;
        }
    }
}

ll repunit(ll ones, ll width, ll M)
{
    if (ones == 1)
    {
        return 1;
    }
    else
    {
        ll half = repunit(ones / 2, width, M);
        if (ones % 2 == 0)
        {
            return (half * pow(10, ones / 2 * width, M) % M + half) % M;
        }
        else
        {
            return (half * pow(10, (ones / 2 + 1) * width, M) % M + (half * pow(10,width,M)) % M + 1) % M;
        }
    }
}

int solve()
{
    ll A, B, M;
    scanf("%lld", &A);
    scanf("%lld", &B);
    scanf("%lld", &M);
    cout << repunit(A,1,M) * repunit(B/gcd(A,B),gcd(A,B),M) % M << endl;
    return 0;
}

int main()
{
    // // 整数の入力
    //   ll t;
    //   cin >> t;
    //   for (size_t i = 0; i < t; i++)
    //   {
    solve();
    //   }
    //   cout << flush;
    return 0;
}
