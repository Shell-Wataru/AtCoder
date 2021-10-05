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
const long long BASE_NUM = 1000000007;

int main()
{
    ll N, M;
    cin >> N >> M;
    vector<bool> used(N + 1, false);
    vector<ll> writes(M);
    for (size_t i = 0; i < M; i++)
    {
        cin >> writes[i];
    }

    reverse(writes.begin(), writes.end());
    vector<ll> answers;
    for (int i = 0; i < M; i++)
    {
        //   cout << writes[i] << endl;
        if (!used[writes[i]])
        {
            used[writes[i]] = true;
            answers.push_back(writes[i]);
        }
    }
    for (int i = 1; i <= N; i++)
    {
        if (!used[i])
        {
            answers.push_back(i);
        }
    }
    for (int i = 0; i < N; i++)
    {
        cout << answers[i] << endl;
    }
    return 0;
}