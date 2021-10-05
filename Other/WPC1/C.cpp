#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

ll BASE_NUM = 1000000007;

int main()
{
    // 整数の入力
    ll N, K;
    cin >> N;
    vector<pair<ll, ll>> A(N);
    for (size_t i = 0; i < N; i++)
    {
        ll a;
        cin >> a;
        A[i] = {a, i};
    }
    sort(A.begin(), A.end(), greater<pair<ll, ll>>());
    for (int i = 0; i < N; i++)
    {
        cout << A[i].second + 1 << endl;
    }
    return 0;
}