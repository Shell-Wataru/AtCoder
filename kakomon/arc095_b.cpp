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
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    ll a_j = A.back();
    ll a_i = -1;
    for (int i = 0; i < N - 1; i++)
    {
        if (min(a_i, a_j - a_i) < min(A[i], a_j - A[i]))
        {
            a_i = A[i];
        }
    }
    cout << a_j << " " << a_i << endl;
    return 0;
}