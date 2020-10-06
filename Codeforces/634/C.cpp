#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int solve()
{
    vector<string> S(9);
    for(int i = 0;i < 9;i++){
        cin >> S[i];
    }
    S[0][0] = S[0][1];
    S[3][1] = S[3][0];
    S[6][2] = S[6][1];
    S[1][3] = S[1][2];
    S[4][4] = S[4][3];
    S[7][5] = S[7][4];
    S[2][6] = S[2][5];
    S[5][7] = S[5][6];
    S[8][8] = S[8][7];
    for(auto s:S){
        cout << s << endl;
    }
    return 0;
}
int main()
{
    // 整数の入力
    ll t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}
