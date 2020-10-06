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
#include <set>
using namespace std;
using ll = long long;

using namespace std;

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> B(N);
    vector<ll> ans(N, -1);
    map<ll, ll> a_counts;
    map<ll, ll> b_counts;
    for (size_t i = 0; i < N; i++)
    {
        cin >> A[i];
        a_counts[A[i]]++;
    }
    for (size_t i = 0; i < N; i++)
    {
        cin >> B[i];
        b_counts[B[i]]++;
    }

    vector<bool> can_move(N, true);
    ll from = -1;
    ll to = -1;
    ll last_b = -1;
    for (int i = 0; i < N; i++)
    {
        if (last_b != B[i])
        {
            from = lower_bound(A.begin(), A.end(), B[i]) - A.begin();
            to = upper_bound(A.begin(), A.end(), B[i]) - A.begin();
            // cout << from << "~" << to - 1<< endl;
            for (int j = from; j < to; j++)
            {
                can_move[(N + j - i) % N] = false;
            }
        }
        else if(from != -1 && to != -1 && from < to)
        {
            // cout << "111" << endl;
            can_move[(N + to - 1 - i) % N] = false;
            can_move[(N + from - i) % N] = false;
        }
        last_b = B[i];
    }

    // for (int i = 0; i < N; i++)
    // {
    //     cout << can_move[i] << ",";
    // }
    // cout << endl;

    ll diff = -1;
    for (int i = 0; i < N; i++)
    {
        if (can_move[i])
        {
            diff = i;
            break;
        }
    }
    // cout << diff << endl;
    if (diff == -1)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
        for (size_t i = 0; i < N; i++)
        {
            if (i != 0)
            {
                cout << " ";
            }
            cout << B[(N + i - diff) % N];
        }
        cout << endl;
    }
    return 0;
}