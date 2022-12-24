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
    ll N;
    cin >> N;
    string S;
    string T;
    cin >> S >> T;
    for (int i = 0; i <= N; i++)
    {
        string ans = S.substr(0, i) + T;
        if (ans.substr(0, N) == S)
        {
            cout << ans.size() << endl;
            return 0;
        }
    }
    return 0;
}
