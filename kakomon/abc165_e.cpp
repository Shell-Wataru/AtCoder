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
    string S;
    ll N,M;
    cin >> N >> M;
    if (N % 4 == 0){
        for(int i = 0;i < min(M,N/4);i++){
            cout << (i+N) % N +1 << " " << (-1-i+N) % N +1 << endl;
        }
        for(int i = min(M,N/4);i < M;i++){
            cout << (i+N) % N +1 << " " << (-2-i+N) % N +1 << endl;
        }
    }else if (N % 4 == 2){
        for(int i = 0;i < min(M,N/4);i++){
            cout << (i+N) % N +1 << " " << (-1-i+N) % N +1 << endl;
        }
        for(int i = min(M,N/4);i < M;i++){
            cout << (i+N) % N +1 << " " << (-2-i+N) % N +1 << endl;
        }
    }else{
        for(int i = 0;i < M;i++){
            cout << (i+N) % N +1 << " " << (-1-i+N) % N +1 << endl;
        }
    }
    return 0;
}