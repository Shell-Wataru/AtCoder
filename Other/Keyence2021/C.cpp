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

template <int mod>
struct ModInt
{
    int x;

    ModInt() : x(0) {}

    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    ModInt &operator+=(const ModInt &p)
    {
        if ((x += p.x) >= mod)
            x -= mod;
        return *this;
    }

    ModInt &operator-=(const ModInt &p)
    {
        if ((x += mod - p.x) >= mod)
            x -= mod;
        return *this;
    }

    ModInt &operator*=(const ModInt &p)
    {
        x = (int)(1LL * x * p.x % mod);
        return *this;
    }

    ModInt &operator/=(const ModInt &p)
    {
        *this *= p.inverse();
        return *this;
    }

    ModInt operator-() const { return ModInt(-x); }

    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

    bool operator==(const ModInt &p) const { return x == p.x; }

    bool operator!=(const ModInt &p) const { return x != p.x; }

    ModInt inverse() const
    {
        int a = x, b = mod, u = 1, v = 0, t;
        while (b > 0)
        {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ModInt(u);
    }

    ModInt pow(int64_t n) const
    {
        ModInt ret(1), mul(x);
        while (n > 0)
        {
            if (n & 1)
                ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend ostream &operator<<(ostream &os, const ModInt &p)
    {
        return os << p.x;
    }

    friend istream &operator>>(istream &is, ModInt &a)
    {
        int64_t t;
        is >> t;
        a = ModInt<mod>(t);
        return (is);
    }

    static int get_mod() { return mod; }
};

using modint = ModInt<998244353>;

int main()
{
    // 整数の入力
    ll H, W, K;
    cin >> H >> W >> K;
    vector<vector<modint>> DP(H, vector<modint>(W, 0));
    vector<ll> free_chars(H * W + 1, 0);
    vector<vector<char>> G(H, vector<char>(W, '*'));
    DP[0][0] = 1;
    for (int i = 0; i < K; i++)
    {
        ll h, w;
        char c;
        cin >> h >> w >> c;
        h--;
        w--;
        G[h][w] = c;
    }
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (G[i][j] == '*')
            {
                free_chars[W * i + j + 1] = free_chars[W * i + j] + 1;
            }
            else
            {
                free_chars[W * i + j + 1] = free_chars[W * i + j];
            }
        }
    }
    // cout << "!!!!" << endl;
    for (int i = 0; i < H; i++)
    {
        if (i != 0){
            for (int j = 0; j < W; j++)
            {
                // cout << free_chars[W * i + j] - free_chars[W * i + j - W + 1] << endl;
                DP[i][j] *= modint(3).pow(free_chars[W * i + j] - free_chars[W * i + j - W + 1]);
            }
        }
        // cout << "!!!" << endl;
        for (int j = 0; j < W; j++)
        {
            if (G[i][j] == '*')
            {
                if (j + 1 < W)
                {
                    DP[i][j + 1] += DP[i][j] * 2;
                }
                if (i + 1 < H)
                {
                    DP[i + 1][j] += DP[i][j] * 2;
                }
            }
            if (G[i][j] == 'R')
            {
                if (j + 1 < W)
                {
                    DP[i][j + 1] += DP[i][j];
                }
            }

            if (G[i][j] == 'D')
            {
                if (i + 1 < H)
                {
                    DP[i + 1][j] += DP[i][j];
                }
            }

            if (G[i][j] == 'X')
            {
                if (j + 1 < W)
                {
                    DP[i][j + 1] += DP[i][j];
                }
                if (i + 1 < H)
                {
                    DP[i + 1][j] += DP[i][j];
                }
            }
        }
    }
    // for (int i = 0; i < H; i++)
    // {
    //     for (int j = 0; j < W; j++)
    //     {
    //         cout << DP[i][j] << ",";
    //     }
    //     cout << endl;
    // }
    if (G[H-1][W-1] == '*'){
        cout << DP[H - 1][W - 1]*3 << endl;
    }else{
        cout << DP[H - 1][W - 1] << endl;
    }
    return 0;
}