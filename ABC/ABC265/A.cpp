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
    ll X,Y,N;
    ll L,R;
    cin >> X >> Y >> N;
    if (3*X <= Y){
        cout << N*X << endl;
    }else{
        cout << N/3 * Y + (N%3)*X << endl;
    }

    return 0;
}