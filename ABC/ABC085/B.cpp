#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>

using namespace std;

int main()
{
    // 整数の入力
    long long N,i,tempD;
    set<long long> mochi;
    cin >> N;
    for (i=0;i<N;i++){
        cin >> tempD;
        mochi.insert(tempD);
    }
    cout << mochi.size() << endl;

    return 0;
}