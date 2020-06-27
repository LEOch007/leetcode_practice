//
// Created by linjliang on 2020/6/27.
//

#include <iostream>
using namespace std;

int main(){
    string s1 = "aaa";
    string s2 = "abaa";
    cout<<"s1:"<<s1.length()<<" "<<typeid(s1.length()).name()<<endl;
    cout<<"s2:"<<s2.length()<<" "<<typeid(s2.length()).name()<<endl;
    cout<<s1.length()-s2.length()<<endl;
    int len_s1 = s1.length();
    int len_s2 = s2.length();
    cout<<len_s1-len_s2<<endl;
}