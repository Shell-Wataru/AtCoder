#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>

using namespace std;

int main()
{
        // 整数の入力
    long long N,Y,i,j;
    cin >> N;
    cin >> Y;
    for (i=0;i<=N;i++){
        for (j=0;i+j<=N;j++){
            if(1000 * i + 5000 * j + 10000*(N- i-j) == Y){
                cout << (N- i-j) << " " << j << " " << i << endl;
                return 0;
            }
        }
    }


    cout << "-1 -1 -1" << endl;
    return 0;
}