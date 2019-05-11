#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

int main()
{
    // 整数の入力
    int i,N,maxA,minA,a;
    maxA = -1;
    minA = 1001;
    cin >> N;
    for (i=0;i<N;i++){
        cin >> a;
        if (a < minA){
            minA = a;
        }
        if (a > maxA){
            maxA = a;
        }
    }
    cout << maxA - minA << endl;

    return 0;
}