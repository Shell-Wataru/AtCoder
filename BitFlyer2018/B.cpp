#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>

using namespace std;
int main()
{
    // 整数の入力
    long long A,B,N,i;
    string S;
    cin >> A >> B >> N;
    cin >> S;

    for (i= 0;i<N;i++){
        if (S[i] == 'S'){
            if (A > 0){
                A += -1;
            }
        }else if (S[i] == 'C'){
            if (B > 0){
                B += -1;
            }
        }else{
            if (A > B){
                A += -1;
            }else if(B > A){
                B += -1;
            }else{
                if (A > 0){
                    A += -1;
                }
            }
        }
    }
    cout << A << endl;
    cout << B << endl;
    return 0;
}