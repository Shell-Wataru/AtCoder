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

namespace mp = boost::multiprecision;
using namespace std;

using ll = long long;

const long long BASE_NUM = 1000000007;

int main()
{
    ll N;
    scanf("%lld", &N);
    vector<ll> A(N + 1, 0);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &A[i]);
    }
    ll inner = 0;
    ll outer = 1;
    for (int i = 0; i < N; i++)
    {
        ll next_inner = outer * min(A[i],A[i+1]) + inner * A[i] * B[i];
        ll next_outer = outer * 1;
        inner = next_inner;
        outer = next_outer;
    }
    cout << inner + outer << endl;
    return 0;
}