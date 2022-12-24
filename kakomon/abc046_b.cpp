#define _USE_MATH_DEFINES
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
    ll N, K;
    cin >> N >> K;
    ll ans = K;
    for (int i = 1; i < N; i++)
    {
        ans *= K - 1;
    }
    cout << ans << endl;
    return 0;
}