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
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

long long gcd(long long a, long long b)
{
    if (a == 0)
    {
        return b;
    }
    else if (b == 0)
    {
        return a;
    }

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
    ll A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    ll lcm_ab = A * B / gcd(A, B);
    ll lcm_cd = C * D / gcd(C, D);
    pair<ll, ll> maixmum_pair = {100 * A, 0};
    for (int a = 0; a < lcm_ab / A; a++)
    {
        if (100 * A * a > F)
        {
            break;
        }
        for (int b = 0; b < lcm_ab / B; b++)
        {
            if (100 * (A * a + B * b) > F)
            {
                break;
            }
            for (int i = 0; 100 * (A * a + B * b + lcm_ab * i) <= F; i++)
            {
                for (int c = 0; c < lcm_cd / C; c++)
                {
                    if (100 * (A * a + B * b + lcm_ab * i) + C * c > F || C * c > E * (A * a + B * b + lcm_ab * i))
                    {
                        break;
                    }
                    for (int d = 0; d < lcm_cd / D; d++)
                    {
                        // cout << "!!!" << endl;
                        if (100 * (A * a + B * b + lcm_ab * i) + C * c + D * d > F ||
                            C * c + D * d > E * (A * a + B * b + lcm_ab * i))
                        {
                            break;
                        }
                        for (int j = 0; 100 * (A * a + B * b + lcm_ab * i) + C * c + D * d + lcm_cd * j <= F &&
                                        C * c + D * d + lcm_cd * j <= E * (A * a + B * b + lcm_ab * i);
                             j++)
                        {
                            // cout << "!" << endl;
                            if (100 * (A * a + B * b + lcm_ab * i) > 0)
                            {
                                if (maixmum_pair.second * (100 * (A * a + B * b + lcm_ab * i) + C * c + D * d + lcm_cd * j) < (C * c + D * d + lcm_cd * j) * maixmum_pair.first)
                                {
                                    maixmum_pair = {(100 * (A * a + B * b + lcm_ab * i) + C * c + D * d + lcm_cd * j), (C * c + D * d + lcm_cd * j)};
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << maixmum_pair.first << " " << maixmum_pair.second << endl;
    return 0;
}