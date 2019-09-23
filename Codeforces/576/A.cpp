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
    long long N,x,y,K,total,remain;
    vector<ll> A;
    cin >> N >> x >> y;
    for(int i = 0;i<N;i++){
        ll a;
        cin >> a;
        A.push_back(a);
    }


    for(int i = 0;i<N;i++){
        bool is_clear  = true;
        for(int j = max(i - x,0LL);j <= min(i+y,N-1);j++){
            if (j < i){
                if (A[j] < A[i]){
                    is_clear = false;
                }
            }else if (i < j){
                if (A[i] > A[j]){
                    is_clear = false;
                }
            }
            if (!is_clear){
                break;
            }
        }

        if (is_clear){
            cout << i + 1 << endl;
            break;
        }
    }
    return 0;
}