#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <ctime>
#include <map>
#include <boost/multiprecision/cpp_int.hpp>
#include <string>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

map<char,ll> codes{
    {'b',1},
    {'c',1},
    {'d',2},
    {'w',2},
    {'t',3},
    {'j',3},
    {'f',4},
    {'q',4},
    {'l',5},
    {'v',5},
    {'s',6},
    {'x',6},
    {'p',7},
    {'m',7},
    {'h',8},
    {'k',8},
    {'n',9},
    {'g',9},
    {'z',0},
    {'r',0},
};

int main()
{
    // 整数の入力
    long long N;
    double va,vb,L;
    cin >> N >> va >> vb >> L;
    double rate = vb/va;
    for(int i = 0;i < N;i++){
        L = L* rate;
    }
    cout << fixed << setprecision(14)<< L << endl;
    return 0;
}