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
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll a,b;
    cin >> a >> b;
    if (a < b){
        for(int i = 0;i< b;i++){
            cout << a;
        }
        cout << endl;
    }else{
        for(int i = 0;i< a;i++){
            cout << b;
        }
        cout << endl;
    }
   return 0;
}