#include <string>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <iomanip>
using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;
    vector<string> S(N);
    for(int i = 0;i < N;i++ ){
        cin >> S[i];
    }
    ll ans = 0;
    for(int a = 0;a < N;a++){
        bool is_ok = true;
        for(int i = 0;i < N;i++){
            for(int j = 0;j < N;j++){
                if (S[(i+a)% N][j] != S[(j+a)% N][i]){
                    // cout << i << " " << j << endl;
                    // cout << a <<  ":" << S[(i+a)% N][j]  << "," << S[(j+a)% N][i] << endl;
                    is_ok = false;
                    break;
                }
            }
            if (!is_ok){
                break;
            }
        }
        if (is_ok){
            ans += N;
        }
    }
    cout << ans << endl;

    return 0;
}