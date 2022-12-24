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
    ll X;
    cin >> X;
    if (0 <= X  && X < 40){
        cout << 40 - X << endl;
    }else if(X < 70){
        cout << 70 - X << endl;
    }else if(X < 90){
        cout << 90 - X << endl;
    }else{
        cout <<"expert" << endl;
    }
    return 0;
}