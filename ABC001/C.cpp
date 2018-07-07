#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <iomanip>

using namespace std;
using ll = long long;
int main()
{
    // 整数の入力
    ll Deg,Dis,DisOut;
    string DegOut;
    cin >> Deg >> Dis;


    if (Deg < 112.5){
        DegOut = "N";
    }else if(Deg < 337.5){
        DegOut = "NNE";
    }else if (Deg < 562.5){
        DegOut = "NE";
    }else if(Deg < 787.5){
        DegOut = "ENE";
    }else if(Deg < 1012.5){
        DegOut = "E";
    }else if(Deg < 1237.5){
        DegOut = "ESE";
    }else if(Deg < 1462.5){
        DegOut = "SE";
    }else if(Deg < 1687.5){
        DegOut = "SSE";
    }else if(Deg < 1912.5){
        DegOut = "S";
    }else if(Deg < 2137.5){
        DegOut = "SSW";
    }else if(Deg < 2362.5){
        DegOut = "SW";
    }else if(Deg < 2587.5){
        DegOut = "WSW";
    }else if(Deg < 2812.5){
        DegOut = "W";
    }else if(Deg < 3037.5){
        DegOut = "WNW";
    }else if(Deg < 3262.5){
        DegOut = "NW";
    }else if(Deg < 3487.5){
        DegOut = "NNW";
    }else{
        DegOut = "N";
    }

    if (Dis < 0.2 * 60 + 3){
        DisOut = 0;
    }else if(Dis < 1.5 * 60+ 3) {
        DisOut = 1;
    }else if(Dis < 3.3 * 60+ 3) {
        DisOut = 2;
    }else if(Dis < 5.4 * 60+ 3) {
        DisOut = 3;
    }else if(Dis < 7.9 * 60+ 3) {
        DisOut = 4;
    }else if(Dis < 10.7 * 60+ 3) {
        DisOut = 5;
    }else if(Dis < 13.8 * 60+ 3) {
        DisOut = 6;
    }else if(Dis < 17.1 * 60+ 3) {
        DisOut = 7;
    }else if(Dis < 20.7 * 60+ 3) {
        DisOut = 8;
    }else if(Dis < 24.4 * 60+ 3) {
        DisOut = 9;
    }else if(Dis < 28.4 * 60+ 3) {
        DisOut = 10;
    }else if(Dis < 32.6 * 60 + 3) {
        DisOut = 11;
    }else{
        DisOut = 12;
    }

    if (DisOut == 0){
        cout << "C 0"  << endl;
    }else{
        cout << DegOut << " " << DisOut << endl;
    }
    return 0;
}