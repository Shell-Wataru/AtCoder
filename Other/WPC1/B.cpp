#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;

ll BASE_NUM = 1000000007;

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> B(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        B[i] = A[i];
    }
    sort(A.begin(), A.end());
    ll median_1 = A[N / 2 - 1];
    ll median_2 = A[N / 2];

    for (int i = 0; i < N; i++)
    {
        if (B[i] < median_2)
        {
            cout << median_2 << endl;
        }
        else
        {
            cout << median_1 << endl;
        }
    }
    return 0;
}