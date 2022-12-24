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
    string S,T;
    cin >> S >> T;
    if ( S < T){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}