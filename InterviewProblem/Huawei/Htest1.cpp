//
// Created by linjliang on 2020/9/12.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> mon_days = {31,28,31,30,31,30,31,31,30,31,30,31};
vector<int> mon_days2 = {31,29,31,30,31,30,31,31,30,31,30,31};

int cnt_date(string date){
    int j = -1;
    int cnt = 0;
    string year, mon, day;
    for (int i = 0; i < date.size(); ++i) {
        if (date[i] == '-' && cnt==0){
            year = date.substr(0,i);

            j = i+1;
            mon = date.substr(j,2);

            j += 3;
            day = date.substr(j,2);
            break;
        }
    }

    int m_year = stoi(year);
    bool run = false;
    int m_mon = stoi(mon);
    int m_day = stoi(day);

    int sum = 0;
    for (int i = 0; i < m_mon - 1; i++) {
        sum += mon_days[i];
        if (i+1==2){
            if (m_year%400==0 || (m_year%4==0 && m_year%100!=0)) sum += 1;
        }
    }
    sum += m_day;

    return sum;
}

int main(){
    cout<<cnt_date("2020-03-01")<<endl;
}