
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>
#include <map>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
    // 整数の入力
    ll H,W;
    cin >> H >> W;
    ll minSize = min(H,W);
    ll maxSize = max(H,W);
    vector<vector<ll>> answer(minSize,vector<ll>(maxSize,0));
    if (minSize == 1){
        ll amari = maxSize % 7;
        if (amari == 2 || amari == 0){
            for(int i = 0;i< maxSize;i++){
                if (i % 7 < 2){
                    answer[0][i] = 2;
                }else{
                    answer[0][i] = 5;
                }
            }
        }else if (amari == 5){
            for(int i = 0;i< maxSize;i++){
                if (i % 7 < 5){
                    answer[0][i] = 5;
                }else{
                    answer[0][i] = 2;
                }
            }
        }else{
            cout << "No" <<  endl;
            return 0;
        }
    }else if (minSize == 2){
        ll amari = maxSize % 7;
        vector<pair<ll,ll>> inputs{
            {2,2},
            {5,5},
            {5,5},
            {2,5},
            {5,2},
            {5,5},
            {5,5}
        };
        if (amari == 1 || amari == 0){
            for(int i = 0;i< maxSize;i++){
                answer[0][i] = inputs[i % 7].first;
                answer[1][i] = inputs[i % 7].second;
            }
        }else if (amari == 6){
            for(int i = 0;i< maxSize;i++){
                answer[0][i] = inputs[(i+1) % 7].first;
                answer[1][i] = inputs[(i+1) % 7].second;
            }
        }else{
            cout << "No" <<  endl;
            return 0;
        }
    }else if (minSize == 3){
        if (maxSize == 3){
            answer = {{2,2,5},{5,5,5},{5,2,2}};
        }else{
            cout << "No" <<  endl;
            return 0;
        }
    }else{
        cout << "No" <<  endl;
        return 0;
    }

    cout << "Yes" << endl;
    if (minSize == H){
        for(int i = 0;i< H;i++){
            for(int j =0; j< W;j++){
                cout << answer[i][j];
            }
            cout << endl;
        }
    }else{
        for(int i = 0;i< H;i++){
            for(int j =0; j< W;j++){
                cout << answer[j][i];
            }
            cout << endl;
        }
    }
    return 0;
}