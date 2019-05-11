#include<iostream>
#include <algorithm>
using namespace std;

long long Move(int *A,int N,int remain){
    long long i,sum = 0,moveCount = 0;
    for (i=0;i<N;i++){
        if (i%2==remain){
            if (sum + A[i] > 0){
                sum += A[i];
            }else{
                moveCount+=  - sum - A[i] + 1;
                sum = 1;
            }
        }else{
            if (sum + A[i] < 0){
                sum += A[i];
            }else{
                moveCount += sum + A[i] + 1;
                sum = - 1;
            }
        }
    }
    return moveCount;
}

int main()
{
    // 整数の入力
    int N,i=0;
    cin >> N;
    int* A = new int[N];
    // スペース区切りの整数の入力
    for (i=0;i<N;i++){
        cin >> A[i];
    }

    cout << min(Move(A,N,0),Move(A,N,1)) << endl;

    return 0;
}