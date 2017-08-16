#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

void convert(string& S){
    int N,i,start,Slength,Count;
    while (i!=S.length()){
        Count = 0;
        for (i=0;i<S.length() ;i++){
            if (Count ==0 ){
                start = i;
            }
            if (S[i] == '('){
                Count += 1;
            }else{
                Count += -1;
            }

            if (Count < 0){
                break;
            }
        }
        if (Count < 0){
            S.insert(S.begin(),'(');
        }
    }

    Count = 0;
    for (i=0;i<S.length() ;i++){
        if (S[i] == '('){
            Count += 1;
        }else{
            Count += -1;
        }
    }

    for (i= 0; i< Count ; i++){
        S.insert(S.end(),')');
    }

}

int main()
{
    // 整数の入力
    int N,i,start,Slength,Count;
    string S;
    cin >> N;
    cin >> S;
    convert(S);
    cout << S << endl;
    return 0;
}