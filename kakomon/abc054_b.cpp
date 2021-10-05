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

int main(){
    ll N,M;
    cin >> N >> M;
    vector<string> A(N);
    vector<string> B(M);
    for(int i = 0;i<N;i++){
        cin >> A[i];
    }
    for(int i = 0;i<M;i++){
        cin >> B[i];
    }
    bool found = false;
    for(int i = 0;i + M - 1< N;i++){
        for(int j = 0;j + M- 1< N;j++){
            bool all_ok = true;
            for(int k = 0;k < M;k++){
                for(int l = 0;l < M;l++){
                    if (A[i+k][j+l] != B[k][l]){
                        all_ok = false;
                        break;
                    }
                }
                if (!all_ok){
                    break;
                }
            }
            if (all_ok){
                found = true;
                break;
            }
        }
        if (found){
            break;
        }
    }
    if (found){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;

}