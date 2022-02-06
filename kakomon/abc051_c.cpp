#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>
#include <boost/multiprecision/cpp_int.hpp>
#include <regex>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
    ll sx,sy,tx,ty;
    cin >> sx >>sy >> tx >> ty;
    for(int i = 0;i < tx - sx;i++){
        cout << "R";
    }
    for(int i = 0;i < ty - sy;i++){
        cout << "U";
    }
    for(int i = 0;i < tx - sx;i++){
        cout << "L";
    }
    for(int i = 0;i <= ty - sy;i++){
        cout << "D";
    }
    for(int i = 0;i <= tx - sx;i++){
        cout << "R";
    }
    for(int i = 0;i <= ty - sy;i++){
        cout << "U";
    }
    cout << "L";
    cout << "U";
    for(int i = 0;i <= tx - sx;i++){
        cout << "L";
    }
    for(int i = 0;i <= ty - sy;i++){
        cout << "D";
    }
    cout << "R" << endl;
    return 0;
}