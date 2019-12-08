#include<iostream>
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
    set<int> a = {1,2,3};
    set<int> &b = a;
    b.insert(4);
    a = {1,2,3};
    for(auto i: a){
        cout << i << " ";
    }
    cout << endl;
    for(auto i: b){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}