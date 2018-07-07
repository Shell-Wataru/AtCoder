#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <ctime>

using namespace std;
int main()
{
    // 整数の入力
    string YMD;
    char outputYMD[100];
    tm today;
    cin >> YMD;
    today.tm_isdst = 0;
    today.tm_hour = 0;
    today.tm_min = 0;
    today.tm_sec = 0;
    today.tm_wday = 0;
    today.tm_yday = 0;
    today.tm_isdst = 0;
    strptime(YMD.c_str(),"%Y/%m/%d",&today);
    mktime(&today);
    while((today.tm_year + 1900) % ((today.tm_mon+1) * today.tm_mday)!= 0){
        today.tm_mday += 1;
        mktime(&today);
    }
    strftime( outputYMD, 100,"%Y/%m/%d",&today);
    string returnString(outputYMD);

    cout << returnString <<  endl;


    return 0;
}