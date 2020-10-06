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

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> B(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for (size_t i = 0; i < N; i++)
    {
        cin >> B[i];
    }

    ll total = 0;
    vector<ll> diffs(N);
    for (size_t i = 0; i < N; i++)
    {
        diffs[i] = B[i] - A[i];
        total += B[i] - A[i];
    }
    if (N == 2)
    {
        if (total == 0)
        {
            ll positive_sum = 0;
            for (int i = 0; i < N; i++)
            {
                if (diffs[i] > 0)
                {
                    positive_sum += diffs[i];
                }
            }
            cout << positive_sum << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    else
    {
        // cout << total % (N-2) << endl;
        if (total % (N - 2) != 0)
        {
            cout << -1 << endl;
        }
        else
        {
            bool can_make = true;
            for (int i = 0; i < N; i++)
            {
                diffs[i] = diffs[i] + total / (N - 2);
                if (diffs[i] > 0 || abs(diffs[i]) % 2 != 0)
                {
                    can_make = false;
                }
            }
            if (can_make)
            {
                cout << -total / (N - 2) << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}