#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <ctime>

using namespace std;
int position(int x){
    int M = 8;
    return M - abs( abs(x)%(2*M) - M);
}

int main()
{
    // 整数の入力
    long long x,y,diffX,diffY;
    diffX = 0;
    diffY = 0;
    string W;
    string rows[10];
    cin >> x >> y >> W;
    for (int i = 0;i< 9;i++){
        cin >> rows[i];
    }

    if (W.find('R') != std::string::npos) {
        diffX = 1;
    }

    if (W.find('L') != std::string::npos) {
        diffX = -1;
    }

    if (W.find('U') != std::string::npos) {
        diffY = -1;
    }

    if (W.find('D') != std::string::npos) {
        diffY = 1;
    }

    for (int i = 0;i < 4 ;i++){
        cout << rows[position(y + i* diffY - 1)][position(x + i* diffX - 1)];
    }
    cout << endl;

    return 0;
}