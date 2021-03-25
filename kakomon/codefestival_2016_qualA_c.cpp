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

ll my_pow(ll x, ll y)
{
    if (y == 0)
    {
        return 1LL;
    }
    else
    {
        ll y_2 = my_pow(x, y / 2);
        ll yy = y_2 * y_2;
        if (y % 2 == 0)
        {
            return yy;
        }
        else
        {
            return yy * x;
        }
    }
}

int main()
{
    // 整数の入力
    string s;
    ll K;
    cin >> s;
    cin >> K;
    for(int i = 0;i < s.size();i++){
        ll change = (26 - (s[i] - 'a')) % 26;
        if ( change <= K){
            K -= change;
            s[i] = 'a';
        }
    }
    K = K % 26;
    for(int i = s.size() - 1;i >= 0;i--){
        ll change = min((ll)('z' - s[i]),K);
        K -= change;
        s[i] = s[i] + change;
    }
    cout << s << endl;
    return 0;
}