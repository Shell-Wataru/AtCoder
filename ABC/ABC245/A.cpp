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
    ll A,B,C,D;
    cin >> A >> B >> C >> D;
    if (60*A + B <= 60*C + D){
        cout << "Takahashi" << endl;
    }else{
        cout << "Aoki" << endl;
    }
    return 0;
}