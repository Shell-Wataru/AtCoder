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

int main()
{
    // 整数の入力
    long long N;
    map<ll, ll> A;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        ll a;
        cin >> a;
        A[a]++;
    }
    if (A.size() == 3)
    {
        vector<pair<ll, ll>> pairs;
        for (auto p : A)
        {

            pairs.push_back(p);
        }
        if ((pairs[0].first ^ pairs[1].first ^ pairs[2].first) == 0 &&
            pairs[0].second == N / 3 && pairs[1].second == N / 3 && pairs[2].second == N / 3)
        {
            cout << "Yes" << endl;

        }else{
            cout << "No" << endl;
        }
    }
    else if (A.size() == 2)
    {
        ll zero_count = A[0];
        ll nonzero_count;
        for (auto p : A)
        {
            if (p.first != 0)
            {
                nonzero_count = p.second;
            }
        }
        if (zero_count == N / 3 && nonzero_count == 2 * N / 3)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    else if (A.size() == 1)
    {
        if (A[0] == N)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}