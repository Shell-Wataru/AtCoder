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
    ll N,M,X,T,D;
    cin >> N >> M >> X >> T >> D;
    ll s;
    if ( N <= X){
        s = T - D*N;
    }else{
        s = T - D*X;
    }
    if (M >= X){
        cout << s + D*X << endl;
    }else{
        cout << s + D*M << endl;
    }
    return 0;
}