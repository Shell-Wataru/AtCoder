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
#include <set>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
ll BASE_NUM = 1000000007;

int main()
{
    // 整数の入力
    ll H,W;
    cin >> H >> W;
    vector<vector<ll>> A(H,vector<ll>(W));
    vector<vector<ll>> B(H,vector<ll>(W));
    vector<vector<set<ll>>> patternsFromStart(H,vector<set<ll>>(W));
    vector<vector<set<ll>>> patternsFromGoal(H,vector<set<ll>>(W));
    for(int i = 0;i< H;i++){
        for(int j = 0;j< W;j++){
            ll a;
            cin >> a;
            A[i][j] = a;
        }
    }

    for(int i = 0;i< H;i++){
        for(int j = 0;j< W;j++){
            ll a;
            cin >> a;
            B[i][j] = a;
        }
    }
    for(int i = 0;i< H;i++){
        for(int j = 0; i+j < (H+W)/2;j++){
            if (i == 0 && j == 0){
                patternsFromStart[i][j].insert(A[i][j] -  B[i][j]);
                patternsFromStart[i][j].insert(B[i][j] -  A[i][j]);
            }else{
                if (j > 0){
                    for(auto p: patternsFromStart[i][j-1]){
                        patternsFromStart[i][j].insert(p + A[i][j] -  B[i][j]);
                        patternsFromStart[i][j].insert(p + B[i][j] -  A[i][j]);
                    }
                }
                if (i > 0){
                    for(auto p: patternsFromStart[i-1][j]){
                        patternsFromStart[i][j].insert(p + A[i][j] -  B[i][j]);
                        patternsFromStart[i][j].insert(p + B[i][j] -  A[i][j]);
                    }
                }
            }
        }
    }

    cout << "========" << endl;
    for(int i = H -1;i>= 0;i--){
        for(int j = W - 1;i+j >= (H+W)/2 - 1;j--){
            if (i == H -1 && j == W - 1){
                patternsFromGoal[i][j].insert(A[i][j] -  B[i][j]);
                patternsFromGoal[i][j].insert(B[i][j] -  A[i][j]);
            }else{
                if (j < W - 1){
                    for(auto p: patternsFromGoal[i][j+1]){
                        patternsFromGoal[i][j].insert(p + A[i][j] -  B[i][j]);
                        patternsFromGoal[i][j].insert(p + B[i][j] -  A[i][j]);
                    }
                }
                if (i <  H - 1){
                    for(auto p: patternsFromGoal[i+1][j]){
                        patternsFromGoal[i][j].insert(p + A[i][j] -  B[i][j]);
                        patternsFromGoal[i][j].insert(p + B[i][j] -  A[i][j]);
                    }
                }
            }
        }
    }

    for(int i = 0;i< H;i++){
        for(int j = 0;j< W;j++){
            cout << patternsFromStart[i][j].size() << ",";
        }
        cout << endl;
    }

    for(int i = 0;i< H;i++){
        int j = (H+W)/2 - 1 - i;
        if (j >= 0 && j < W){
            cout << endl;
        }
    }
    return 0;
}