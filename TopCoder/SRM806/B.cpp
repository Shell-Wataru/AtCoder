#include <string>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
using namespace std;
using ll = long long;

const long long BASE_NUM = 1000000007;
//https://scrapbox.io/pocala-kyopro/%E6%8B%A1%E5%BC%B5%E3%83%A6%E3%83%BC%E3%82%AF%E3%83%AA%E3%83%83%E3%83%89%E3%81%AE%E4%BA%92%E9%99%A4%E6%B3%95
// https://ei1333.github.io/luzhiled/snippets/math/combination.html
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
using modint = ModInt<BASE_NUM>;

class MostSubstrings
{
public:
    int count(string S, int L)
    {

        vector<bool> zurashi(S.size());
        ll min_zurashi = -1;
        for(int i = 1;i <= S.size();i++){
            cout << S.substr(i) << ":" << S.substr(0,S.size() - i)<< endl;
            if (S.substr(i) == S.substr(0,S.size() - i)){
                zurashi[i] = true;
                cout << "!!" << endl;
                if (min_zurashi == -1){
                    min_zurashi = i;
                }
            }
        }
        modint twentysix = 26;
        if (L < S.size()){
            return twentysix.pow(L).x;
        }
        ll remain = (L - S.size()) % min_zurashi;
        if (remain == 0){
            return 1;
        }
        vector<vector<modint>> DP(remain+1,vector<modint>(S.size()+1));
        DP[0][0] = 1;
        return 0;
    }

};

int main()
{
    MostSubstrings m;
    // cout << m.count("helloworld",7) << endl;
    // cout << m.count("aaaa",13) << endl;
    // cout << m.count("dogecoin",17) << endl;
    cout << m.count("decode",11) << endl;
    return 0;
}