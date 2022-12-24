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

using namespace std;
using ll = long long;

int main()
{
    ll N;
    cin >> N;
    vector<ll> S(N);
    for (int i = 0; i < N; i++)
    {
        cin >> S[i];
    }
    ll zero_minimum = 0;
    ll zero_current = 0;
    ll one_minimum = 0;
    ll one_current = 0;
    ll two_minimum = 0;
    ll two_current = 0;
    for (int i = 0; i < N - 1; i++)
    {
        if (i % 3 == 0)
        {
            zero_current += S[i + 1] - S[i];
            zero_minimum = min(zero_minimum, zero_current);
        }
        else if (i % 3 == 1)
        {
            one_current += S[i + 1] - S[i];
            one_minimum = min(one_minimum, one_current);
        }
        else
        {
            two_current += S[i + 1] - S[i];
            two_minimum = min(two_minimum, two_current);
        }
    }
    if (S[0] >= -(zero_minimum + one_minimum + two_minimum))
    {
        cout << "Yes" << endl;
        cout << -zero_minimum << " " << -one_minimum << " " << S[0] + zero_minimum + one_minimum;
        zero_current = -zero_minimum;
        one_current = -one_minimum;
        two_current = S[0] + zero_minimum + one_minimum;
        for (int i = 0; i < N - 1; i++)
        {
            if (i % 3 == 0)
            {
                zero_current += S[i + 1] - S[i];
                cout << " " << zero_current;
            }
            else if (i % 3 == 1)
            {
                one_current += S[i + 1] - S[i];
                cout << " " << one_current;
            }
            else
            {
                two_current += S[i + 1] - S[i];
                cout << " " << two_current;
            }
        }
        cout << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}