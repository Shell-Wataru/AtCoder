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
#include <set>
using namespace std;
using ll = long long;

ll BASE_NUM = 1000000007;

bool find_same_char(vector<char> &l,vector<char> &r, char &new_char){
    ll l_index = 0;
    ll r_index = 0;
    bool found = false;
    while(l_index < l.size() && r_index < r.size()){
        if (l[l_index] == r[r_index]){
            found = true;
            new_char = l[l_index];
            break;
        }else if(l[l_index] > r[r_index]){
            r_index++;
        }else{
            l_index++;
        }
    }
    return found;
}

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<vector<char>> A(N,vector<char>(N));
    vector<char> ans(N);

    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            cin >> A[i][j];
        }
    }
    for(int i = 0;i < N;i++){
        sort(A[i].begin(),A[i].end());
    }
    bool can_make = true;
    for(int i = 0; i < (N+1)/2;i++){
        char new_char;
        if (find_same_char(A[i],A[N-i-1],new_char)){
            ans[i] = new_char;
            ans[N-i-1] = new_char;
        }else{
            can_make = false;
            break;
        }
    }
    if (can_make){
        for(auto &c: ans){
            cout << c;
        }
        cout << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}