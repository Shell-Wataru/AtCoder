#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>
#include <unordered_map>
using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    string S;
    cin >> S;
    ll N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        ll l, r;
        cin >> l >> r;
        reverse(S.begin() + l - 1, S.begin() + r);
    }
    cout << S << endl;
    return 0;
}