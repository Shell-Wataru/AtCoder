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

int solve()
{
    string A,B;
    cin >> A >> B;
    vector<ll> countsA(10,0);
    vector<ll> countsB(10,0);
    for(auto a:A){
        countsA[a-'0']++;
    }
    for(auto a:B){
        countsB[a-'0']++;
    }
    if (A.size() > B.size()){
        countsB[0] = A.size() - B.size();
    }else{
        countsA[0] = B.size() - A.size();
    }
    ll maximum_kuriage = 0;
    ll maximum_i = -1;
    ll maximum_j= -1;
    for(int i = 1;i < 10;i++){
        for(int j = 10-i;j < 10;j++){
            vector<ll> currentA(countsA);
            vector<ll> currentB(countsB);
            if (currentA[i] > 0 && currentB[j] > 0){
                ll kuriage = 1;
                currentA[i]--;
                currentB[j]--;
                for(int k = 0;k < 10;k++){
                    for(int l = 9-k;l < 10;l++){
                        ll current_kuriage = min(currentA[k],currentB[l]);
                        kuriage += current_kuriage;
                        currentA[k] -= current_kuriage;
                        currentB[l] -= current_kuriage;
                    }
                }
                if (maximum_kuriage < kuriage){
                    maximum_kuriage = kuriage;
                    maximum_i = i;
                    maximum_j = j;
                }
            }
        }
    }
    // cout << maximum_kuriage << endl;
    // cout << maximum_i << endl;
    // cout << maximum_j << endl;
    if (maximum_kuriage == 0){
        cout << A << endl;
        cout << B << endl;
    }else{
        deque<char> ans_a;
        deque<char> ans_b;
        ans_a.push_back('0' + maximum_i);
        ans_b.push_back('0' + maximum_j);
        vector<ll> currentA(countsA);
        vector<ll> currentB(countsB);
        ll kuriage = 1;
        currentA[maximum_i]--;
        currentB[maximum_j]--;
        ll zero_nine = 0;
        ll nine_zero = 0;
        for(int k = 0;k < 10;k++){
            for(int l = 9-k;l < 10;l++){
                ll current_kuriage = min(currentA[k],currentB[l]);
                kuriage += current_kuriage;
                currentA[k] -= current_kuriage;
                currentB[l] -= current_kuriage;
                if (k == 0){
                    zero_nine += current_kuriage;
                }else if (l == 0){
                    nine_zero += current_kuriage;
                }else{
                    for(int m = 0;m < current_kuriage;m++){
                        ans_a.push_front('0'+k);
                        ans_b.push_front('0'+l);
                    }
                }
            }
        }
        for(int i = 0;i < nine_zero;i++){
            ans_a.push_front('9');
        }
        for(int i = 0;i < zero_nine;i++){
            ans_b.push_front('9');
        }
        ll remain_a = 0;
        ll remain_b = 0;
        for(int i = 1;i < 10;i++){
            remain_a += currentA[i];
            remain_b += currentB[i];
        }
        ll tail_a = min(remain_a,remain_b);
        ll tail_b = min(remain_a,remain_b);
        for(int i = 1; i < 10;i++){
            for(int j = 0;j < currentA[i];j++){
                if (tail_a > 0){
                    ans_a.push_back('0'+i);
                    tail_a--;
                }else{
                    ans_a.push_front('0'+i);
                }
            }
        }
        for(int i = 1; i < 10;i++){
            for(int j = 0;j < currentB[i];j++){
                if (tail_b > 0){
                    ans_b.push_back('0'+i);
                    tail_b--;
                }else{
                    ans_b.push_front('0'+i);
                }
            }
        }
        for(auto a:ans_a){
            cout << a;
        }
        cout << endl;
        for(auto a:ans_b){
            cout << a;
        }
        cout << endl;
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