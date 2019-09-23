#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    long long N;
    vector<ll> A;
    map<ll,ll> diffs;
    set<ll> nums;
    cin >> N;
    for (int i =0 ;i<N;i++){
        ll a;
        cin >> a;
        A.push_back(a);
        nums.insert(a);
    }
    sort(A.begin(),A.end());
    for (int i =1 ;i<N;i++){
       diffs[A[i]-A[i-1]]++;
    }

    ll diff;
    if (diffs.size() > 3){
        cout << -1 << endl;
    }else if (diffs.size() == 1){
        cout << 1 << endl;
    }else if (diffs.size() == 2){
        for (auto d:diffs){
            bool is_clear_forward = true;
            for (int i =0 ;i<N-1;i++){
                if (nums.find(A[0]+d*i) == nums.end()){
                    is_clear_farward = false;
                };
            }

            bool is_clear_backward = true;
            for (int i =0 ;i<N-1;i++){
                if (nums.find(A[N-1]-d*i) == nums.end()){
                    is_clear_backward = false;
                };
            }

        }
    }

    for (int i =1 ;i<N;i++){
        if (A[i]-A[i-1] == d){

        }
    }

    return 0;
}