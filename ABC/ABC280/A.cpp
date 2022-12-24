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

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll H,W;
    cin >> H >> W;
    ll ans = 0;
    for(int i = 0;i < H;i++){
        string S;
        cin >> S;
        for(auto c:S){
            if (c == '#'){
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}