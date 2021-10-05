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
    // 整数の入力
    ll X, Y, Z, K;
    cin >> X >> Y >> Z >> K;
    vector<ll> A(X);
    vector<ll> B(Y);
    vector<ll> C(Z);
    for (int i = 0; i < X; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < Y; i++)
    {
        cin >> B[i];
    }

    for (int i = 0; i < Z; i++)
    {
        cin >> C[i];
    }
    vector<ll> ab_candidates;
    vector<ll> abc_candidates;
    for (int i = 0; i < X; i++)
    {
        for (size_t j = 0; j < Y; j++)
        {
            ab_candidates.push_back(A[i] + B[j]);
        }
    }
    sort(ab_candidates.begin(), ab_candidates.end(), greater<ll>());
    for (int i = 0; i < min(K,X*Y); i++)
    {
        for (size_t j = 0; j < Z; j++)
        {
            abc_candidates.push_back(ab_candidates[i] + C[j]);
        }
    }

    sort(abc_candidates.begin(), abc_candidates.end(), greater<ll>());
    for (int i = 0; i < K; i++)
    {
        cout << abc_candidates[i] << "\n";
    }
    cout << flush;
    return 0;
}