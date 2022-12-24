#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <numeric>

using namespace std;
using ll = long long;

void sort(vector<ll> &A){
    ll N = A.size();
    for(int i = 0;i < N-2;i++){
        ll minimum = numeric_limits<ll>::max();
        ll minimum_index = numeric_limits<ll>::max();
        for(int j = i;j < N;j++){
            if (A[j] < minimum){
                minimum = A[j];
                minimum_index = j;
            }
        }
        if (minimum_index == N-1){
            swap(A[N-3],A[N-2]);
            swap(A[N-2],A[N-1]);
            minimum_index--;
        }
        for(;minimum_index > i;){
            swap(A[minimum_index-1],A[minimum_index]);
            swap(A[minimum_index],A[minimum_index+1]);
            minimum_index--;
        }
    }
}

int solve()
{
    ll N,K;
    cin >> N;
    vector<ll> A(N);
    vector<ll> B(N);
    for(int i = 0;i < N;i++){
        cin >> A[i];
    }
    for(int i = 0;i < N;i++){
        cin >> B[i];
    }
    vector<ll> sortedA(A);
    vector<ll> sortedB(B);
    sort(sortedA.begin(),sortedA.end());
    sort(sortedB.begin(),sortedB.end());
    if (sortedA != sortedB){
        cout << "No" << endl;
        return 0;
    }
    bool containsDuplicate = false;
    for(int i = 0;i < N-1;i++){
        if (sortedA[i] == sortedA[i+1]){
            containsDuplicate = true;
        }
    }
    if (containsDuplicate){
        cout << "Yes" << endl;
        return 0;
    }
    sort(A);
    sort(B);
    // for(int i = 0;i < N;i++){
    //     cout << A[i] << ",";
    // }
    // cout << endl;
    // for(int i = 0;i < N;i++){
    //     cout << B[i] << ",";
    // }
    // cout << endl;
    if (A == B){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}

int main()
{
    //   ll t;
    //   cin >> t;

    //   for (int i = 1; i <= t; i++)
    //   {
    solve();
    //   }
    cout << flush;
    return 0;
}