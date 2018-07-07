#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>

using namespace std;

int main()
{
    // 整数の入力
    string N;
    cin >> N;
    if (N[0] ==N[1] && N[1] == N[2] ||  N[1] == N[2]  && N[2] ==N[3] ){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}