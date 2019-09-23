#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <ctime>
#include <map>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
    // 整数の入力
    long long N,X,D,c;
    cin >> N >> X;
    D = 0;
    c = 1;
    for(int i = 0;i<N;i++){
        ll L;
        cin >> L;
        D += L;
        if(D <= X){
            c++;
        }
    }
    cout << c << endl;
    return 0;
}