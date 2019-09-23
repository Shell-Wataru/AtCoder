#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> A, B;

    for (int i = 0; i < n; i++)
    {
        vector<ll> row;
        for (int j = 0; j < m; j++)
        {
            ll a;
            cin >> a;
            row.push_back(a);
        }
        A.push_back(row);
    }

    for (int i = 0; i < n; i++)
    {
        vector<ll> row(m,0);
        B.push_back(row);
    }

    vector<pair<ll,ll>> tejun;
    for(int i = 0;i<n-1;i++){
        for(int j= 0;j<m-1;j++){
            if(A[i][j] == 1 &&
               A[i][j+1] == 1 &&
               A[i+1][j] == 1 &&
               A[i+1][j+1] == 1){
                   tejun.push_back(make_pair(i,j));
                   B[i][j] = 1;
                   B[i+1][j] = 1;
                   B[i][j+1] = 1;
                   B[i+1][j+1] = 1;
               }
        }
    }
    bool clear = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(A[i][j] != B[i][j]){
                clear = false;
            }
        }
    }

    if(clear){
        cout << tejun.size() << endl;
        for(auto te:tejun){
            cout << te.first + 1 <<  " " <<te.second + 1 << endl;
        }
    }else{
        cout << -1 << endl;
    }
    return 0;
}