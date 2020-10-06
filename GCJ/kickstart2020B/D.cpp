#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
using namespace std;
using ll = long long;

ll BASE_NUM = 1000000000;

string solve()
{
    ll W,H,L,R,U,D;
    cin >> W >> H >> L >> R >> U >> D;
    vector<vector<double>> probs(H,vector<double>(W,0));
    probs[0][0] = 1;
    for(int i = 1;i< W;i++){
        probs[0][i] = 0.5 * probs[0][i-1];
    }
    for(int i = 1;i< H;i++){
        probs[i][0] = 0.5 * probs[i-1][0];
    }
    for(int i = 1;i< H;i++){
        for(int j = 1;j < W;j++){
            probs[i][j] = 0.5 * probs[i-1][j] + 0.5 * probs[i][j-1];
        };
    }
    return "A";
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