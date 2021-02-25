#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>

using namespace std;
using ll = long long;
const int BASE_NUM = 1000000007;

int solve()
{
    ll L,R;
    cin >> L >> R;
    ll width = R - L + 1;
    ll needs = 0;
    while(width >  1<<needs){
        needs++;
    }
    cout << needs << endl;
    // cout << "YES" << endl;
    // for(int i = 0;i < 10;i++){
    //     cout << 2*i+1 << " " << 2*i + 2 << " " << 1 << "\n";
    //     cout << 2*i+2 << " " << 2*i + 3 << " " << (1<<i) << "\n";
    //     cout << 2*i+1 << " " << 2*i + 3 << " " << 1 << "\n";
    // }
    return 0;
}
int main()
{
    // 整数の入力
    // int t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
        solve();
        // }
    cout << flush;
    return 0;
}
