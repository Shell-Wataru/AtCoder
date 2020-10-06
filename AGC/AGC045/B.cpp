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
#include <list>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
ll BASE_NUM = 2;

vector<ll> two_powers(int n)
{
    vector<ll> ret(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        ll p = 0;
        while ((i >> p) % 2 == 0)
        {
            p++;
        }
        // cout << i << ":" << p << endl;
        ret[i] = p;
    }
    return ret;
}
ll combination(vector<ll> &factorial, ll n, ll m)
{
    if (factorial[n] - factorial[m] - factorial[n - m] > 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

string next_x(string &s)
{
    if (s.size() == 1)
    {
        return s;
    }
    else
    {
        string ret;
        for (int i = 0; i < s.size() - 1; i++)
        {
            ret += (char)'0' + abs(s[i + 1] - s[i]);
        }
        return ret;
    }
}
int main()
{
    // 整数の入力
    ll N;
    string S;
    cin >> N;
    cin >> S;

    vector<ll> twos = two_powers(N);
    vector<ll> factorial(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        factorial[i] = factorial[i - 1] + twos[i];
        // cout << i << ":" << factorial[i] << endl;
    }

    string x = next_x(S);
    // cout << x << endl;
    map<ll, ll> elementary_counts{{0, 0}, {1, 0}, {2, 0}};
    map<ll, ll> counts{{0, 0}, {1, 0}, {2, 0}};
    for (int i = 0; i < x.length(); i++)
    {
        ll c = combination(factorial, x.size() - 1, i);
        // cout << x.size() -1 << "C" << i   << endl;
        // cout << (x[i] - '0') << " " << c << endl;
        elementary_counts[x[i] - '0']++;
        counts[x[i] - '0'] = (counts[x[i] - '0'] + c) % 2;
    }
    // for(auto p:counts){
    //     cout << p.first << " " << p.second << endl;
    // }
    if (elementary_counts[1] > 0){
        counts[2] = 0;
    }
    if (counts[1] == 0 && counts[2] == 0)
    {
        cout << 0 << endl;
    }
    else if (counts[1] == 0 && counts[2] == 1)
    {
        cout << 2 << endl;
    }
    else if (counts[1] == 1 && counts[2] == 0)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 1 << endl;
    }

    // cout << x << endl;
    // while(x.size() != 1){
    //     x = next_x(x);
    //     cout << x << endl;
    // }
    // cout << x << endl;
    return 0;
}