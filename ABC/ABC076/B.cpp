#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>

using namespace std;

int main()
{
    // 整数の入力
    long long N,K,now,i;
    now = 1;
    cin >> N >> K;
    for (i=0;i<N;i++){
        if (now + K < 2 * now){
            now = now + K;
        }else{
            now = 2 * now;
        }
    }
    cout << now << endl;

    return 0;
}