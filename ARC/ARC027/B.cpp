#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <ctime>
#include <map>
#include <boost/multiprecision/cpp_int.hpp>
#include <string>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

ll my_pow(ll x,ll y){
    if (y == 0){
        return 1LL;
    }else{
        ll y_2 =my_pow(x,y/2);
        ll yy = (y_2 * y_2);
        if (y % 2 == 0){
            return yy;
        }else{
            return yy * x;
        }
    }
}

int main()
{
    // 整数の入力
    ll n;
    string S1, S2;
    cin >> n;
    cin >> S1 >> S2;
    for (int i = 0; i < n; i++)
    {
        if (S1[i] == S2[i])
        {
            continue;
        }
        else
        {
            char s1c = S1[i];
            char s2c = S2[i];
            if (S1[i] - '0' > 9 && S2[i] - '0' > 9)
            {
                replace(S1.begin(), S1.end(), s1c, s2c);
                replace(S2.begin(), S2.end(), s1c, s2c);
            }
            else if (S1[i] - '0' > 9 && S2[i] - '0' <= 9)
            {
                replace(S1.begin(), S1.end(), s1c, s2c);
                replace(S2.begin(), S2.end(), s1c, s2c);
            }
            else if (S1[i] - '0' <= 9 && S2[i] - '0' > 9)
            {
                replace(S1.begin(), S1.end(), s2c, s1c);
                replace(S2.begin(), S2.end(), s2c, s1c);
            }
            // cout << S1 << endl;
            // cout << S2 << endl;
        }
    }
    // cout << S1 << endl;
    // cout << S2 << endl;
    set<char> using_chars;
    for (int i = 0; i < n; i++)
    {
        if (S1[i] - '0' > 9)
        {
            using_chars.insert(S1[i]);
        }
    }
    if (S1[0] - '0' > 9){
        cout << 9ll * my_pow(10ll,using_chars.size() - 1) << endl;
    }else{
        cout << my_pow(10ll,using_chars.size()) << endl;
    }
    return 0;
}