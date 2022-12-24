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
    string S;
    cin >> S;
    ll ans = 0;
    for(auto c:S){
        if (c == 'w'){
            ans+= 2;
        }else{
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}