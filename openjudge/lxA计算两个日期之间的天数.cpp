#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int month_[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool run(int year){
    if(year % 400 == 0)
        return true;
    else if(year % 100 == 0)
        return false;
    else if(year % 4 == 0)
        return true;
    return false;
}

int main(){
    int sy, sm, sd;
    int ey, em, ed;
    cin >> sy >> sm >> sd;
    cin >> ey >> em >> ed;

    int sum = 0;
    for(int i = sy + 1; i < ey; i++){
        if(run(i))
            sum += 366;
        else
            sum += 365;
    }

    int* m_ = month;
    if(run(sy))
        m_ = month_;
    int sum_s = 0;
    for(int i = sm + 1; i <= 12; i++){
        sum_s += m_[i];
    }
    sum_s += m_[sm] - sd + 1;

    m_ = month;
    if(run(ey))
        m_ = month_;
    int sum_e = 0;
    for(int i = 1; i < em; i++){
        sum_e += m_[i];
    }
    sum_e += ed;

    if(sy == ey){
        sum = sum_s + sum_e;
        if(run(sy))
            sum -= 366;
        else
            sum -= 365;
    }
    else{
        sum += sum_s + sum_e;
    }
    cout << sum - 1 << endl;
}