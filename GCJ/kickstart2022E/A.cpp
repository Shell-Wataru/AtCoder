#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
using namespace std;
using ll = long long;

string solve()
{
    ll N;
    cin >> N;
    N = (N/5)*2 + (N%5+4)/5 + (N%5+3)/5;
    N = (N+1)/2;
    return to_string(N);
}
int main()
{
    // 整数の入力
    ll T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        string ans = solve();
        cout << "Case #" << i << ": " << ans << endl;
    }

    return 0;
}