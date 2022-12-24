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
    ll M,K;
    cin >> M >> K;
    if (M < 2){
        if (K == 0){
            for(int i = 0;i < 1ll<<M;i++){
                if (i != 0){
                    cout << " ";
                }
                cout << i << " " << i;
            }
            cout << endl;
        }else{
            cout << -1 << endl;
        }
    }else if (K <= (1ll<<M)-1){
        vector<ll> a;
        vector<ll> b;
        for(int i = 0;i < 1ll<<M;i++){
            if (__builtin_popcountll(i) == 1 && (K & i)){
                b.push_back(i);
            }else{
                a.push_back(i);
            }
        }
        for(int i = 0;i < a.size();i++){
            if (i!= 0){
                cout << " ";
            }
            cout << a[i];
        }
        for(int i = 0;i < b.size();i++){
            cout << " ";
            cout << b[i];
        }
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        for(int i = 0;i < a.size();i++){
            cout << " ";
            cout << a[i];
        }
        for(int i = 0;i < b.size();i++){
            cout << " ";
            cout << b[i];
        }
        cout << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}