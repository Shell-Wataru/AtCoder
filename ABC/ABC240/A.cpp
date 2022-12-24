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
    ll a,b;
    cin >> a >> b;
    if (a > b){
        swap(a,b);
    }
    if (a + 1 == b || (a== 1 && b == 10)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;

    }
    return 0;
}