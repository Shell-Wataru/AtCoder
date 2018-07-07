#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>

using namespace std;

int main()
{
        // 整数の入力
    long long N,ai,i,total;
    cin >> N;
    total = 0;
    for (i=0;i<N;i++){
        cin >> ai;
        while (ai % 2 == 0){
            ai = ai/2;
            total++;
        }
    }

    cout << total << endl;
    return 0;
}