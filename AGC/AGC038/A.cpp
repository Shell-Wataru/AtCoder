#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

using ll = long long;
ll gcd(ll a, ll b)
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
    ll H, W, A, B;
    cin >> H >> W >> A >> B;
    if (A == 0)
    {
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                if (i < B)
                {
                    cout << 1;
                }
                else
                {
                    cout << 0;
                }
            }
            cout << endl;
        }
    }
    else if (2 * A == W)
    {
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                if ((j < A && i < B) || (j >= A && i >= B))
                {
                    cout << 1;
                }
                else
                {
                    cout << 0;
                }
            }
            cout << endl;
        }
    }
    else
    {
        ll wa_gcd = gcd(W, A);
        ll wa_lcm = W * A / wa_gcd;
        ll base_rows = wa_lcm / A;
        ll base_mins = wa_lcm / W;
        ll base_diff = wa_lcm / base_rows;
        // cout << base_rows << " " << base_mins << " " << base_diff << endl;

        if (2 * B == H)
        {
            for (int i = 0; i < H; i++)
            {
                for (int j = 0; j < W; j++)
                {
                    if ((j < A && i < B) || (j >= A && i >= B))
                    {
                        cout << 1;
                    }
                    else
                    {
                        cout << 0;
                    }
                }
                cout << endl;
            }
        }
        else if (B % base_mins != 0)
        {
            cout << "No" << endl;
        }
        else if (B == 0)
        {
            for (int i = 0; i < H; i++)
            {
                for (int j = 0; j < W; j++)
                {
                    if (j < A)
                    {
                        cout << 1;
                    }
                    else
                    {
                        cout << 0;
                    }
                }
                cout << endl;
            }
        }
        else if (H != (B / base_mins) * base_rows)
        {
            cout << "No" << endl;
        }
        else
        {

            for (int i = 0; i < H; i++)
            {
                for (int j = 0; j < W; j++)
                {
                    if ((j + base_diff * i) % W < A)
                    {
                        cout << 1;
                    }
                    else
                    {
                        cout << 0;
                    }
                }
                cout << endl;
            }
        }
    }
    return 0;
}