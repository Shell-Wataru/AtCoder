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

ll BASE_NUM = 1000000007;

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<ll> S(N);
    vector<ll> T(N);
    vector<ll> U(N);
    vector<ll> V(N);
    for (int i = 0; i < N; i++)
    {
        cin >> S[i];
    }

    for (int i = 0; i < N; i++)
    {
        cin >> T[i];
    }

    for (int i = 0; i < N; i++)
    {
        cin >> U[i];
    }

    for (int i = 0; i < N; i++)
    {
        cin >> V[i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (j != 0)
            {
                cout << " ";
            }
            if (S[i] == 0 && T[j] == 0)
            {
                cout << (U[i] | V[j]);
            }
            else if (S[i] == 1 && T[j] == 0)
            {
                cout << V[i];
            }
            else if (S[i] == 0 && T[j] == 1)
            {
                cout << U[i];
            }
            else if (S[i] == 1 && T[j] == 1)
            {
                cout << (U[i] ^ V[j]);
            }

        }
        cout << endl;
    }
    return 0;
}