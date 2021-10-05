#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <bitset>
#include <numeric>

using namespace std;
using ll = long long;

int main()
{
    ll K;
    cin >> K;
    vector<ll> A(K);
    for (size_t i = 0; i < K; i++)
    {
        cin >> A[i];
    }
    reverse(A.begin(), A.end());
    ll min_ans = 2;
    ll max_ans = 2;
    for (size_t i = 0; i < A.size(); i++)
    {
        // cout << min_ans << " " << max_ans << endl;
        ll min_times = (min_ans + A[i] - 1) / A[i];
        ll next_min = min_times * A[i];
        ll max_times = max_ans / A[i];
        ll next_max = max_times * A[i] + A[i] - 1;
        // cout << next_min << "~" << next_max << endl;
        if (next_min > next_max)
        {
            cout << -1 << endl;
            return 0;
        }
        min_ans = next_min;
        max_ans = next_max;
    }
    cout << min_ans << " " << max_ans << endl;
    return 0;
}