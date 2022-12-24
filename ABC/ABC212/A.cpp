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
    ll A,B;
    cin >> A >> B;
    if (A == 0){
        cout << "Silver" << endl;
    }else if(B == 0){
        cout << "Gold" << endl;
    }else{
        cout << "Alloy" << endl;
    }
    return 0;
}