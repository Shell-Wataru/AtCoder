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
namespace mp = boost::multiprecision;
ll BASE_NUM = 1000000007;

int main()
{
    // 整数の入力
    ll N, M;
    cin >> N >> M;
    vector<ll> answer(N, -1);
    bool can_make = true;
    for (int i = 0; i < M; i++)
    {
        ll s, c;
        cin >> s >> c;
        s--;
        if (answer[s] == -1 || answer[s] == c)
        {
            answer[s] = c;
        }
        else
        {
            can_make = false;
        }
    }
    if (!can_make || (answer[0] == 0 && N != 1))
    {
        cout << -1 << endl;
    }
    else
    {
        if (N == 1)
        {
            if (answer[0] == -1)
            {
                cout << 0 << endl;
            }
            else
            {
                cout << answer[0] << endl;
            }
        }
        else
        {
            for (int i = 0; i < N; i++)
            {
                if (i == 0)
                {
                    if (answer[i] == -1)
                    {
                        cout << 1;
                    }
                    else
                    {
                        cout << answer[i];
                    }
                }
                else
                {
                    if (answer[i] == -1)
                    {
                        cout << 0;
                    }
                    else
                    {
                        cout << answer[i];
                    }
                }
            }
            cout << endl;
        }
    }
    return 0;
}