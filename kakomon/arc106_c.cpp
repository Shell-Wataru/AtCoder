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
    ll N,M;
    cin >> N >> M;
    if (M == 0){
        for(int i = 1; i<= N;i++){
            cout << 4*i << " " << 4*i + 2 << "\n";
        }
        cout << flush;
    }else if (N - 1<= M || M < 0){
        cout << -1 << endl;
    }else{
        for(int i = 1; i<= M+1;i++){
            cout << 4*i << " " << 4*i + 2 << "\n";
        }
        cout << "1 " <<  4*(M+1) + 3 << "\n";
        for(int i = M+3; i<= N;i++){
            cout << 4*i + 10000000 << " " << 4*i + 2 + 10000000 << "\n";
        }
        cout << flush;
    }
    return 0;
}