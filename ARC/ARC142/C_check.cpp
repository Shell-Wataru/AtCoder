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

int main()
{
    string S;
    cin >> S;
    ll ans = 0;
    for (int i = 0; i < S.size(); i++)
    {
        for (int j = 0; i + j < S.size(); j++)
        {
            ll total = 0;
            for (int k = i; k <= i + j; k++)
            {
                total = (total * 10 + (S[k] - '0')) % 7;
            }
            if (total == 0)
            {
                // cout << i  << ","  << j << endl;
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
