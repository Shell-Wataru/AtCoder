#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>

using namespace std;


int main()
{
    // 整数の入力
    long long N,maxindex,minindex,maxNumber,minNumber,i,inputNumber;
    maxNumber = -10000000;
    minNumber = 10000000;
    cin >> N;
    for (i= 1;i<= N;i++){
        cin >> inputNumber;
        if (inputNumber < minNumber){
            minNumber = inputNumber;
            minindex = i;
        }

        if(inputNumber > maxNumber){
            maxNumber = inputNumber;
            maxindex = i;
        }
    }

    if (maxNumber > - minNumber){
        cout << 2 * N << endl;
        cout << maxindex << " " << 1 << endl;
        cout << maxindex << " " << 1 << endl;
        for (i = 1;i<N;i++){
            cout << i << " " << i+1 << endl;
            cout << i << " " << i+1 << endl;
        }
    }else{
        cout << 2 * N << endl;
        cout << minindex << " " << N << endl;
        cout << minindex << " " << N << endl;
        for (i = N;i>1;i--){
            cout << i << " " << i-1 << endl;
            cout << i << " " << i-1 << endl;
        }
    }

    return 0;
}