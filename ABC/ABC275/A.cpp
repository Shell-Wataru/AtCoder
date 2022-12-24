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
    ll N;
    cin >> N;
    ll max_h = 0;
    ll max_index = -1;
    for(int i = 0;i < N;i++){
        ll h;
        cin >> h;
        if (h > max_h){
            max_h = h;
            max_index = i;
        }
    }
    cout << max_index + 1 << endl;
    return 0;
}