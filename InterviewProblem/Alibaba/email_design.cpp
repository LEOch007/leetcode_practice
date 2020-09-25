/**
评测题目:
写一个邮件查找算法，可以根据发件人+标题关键字+时间区间中的任意一个或者几个进行搜索，
返回符合查找条件的邮件列表
备注：
1、纯内存操作即可
2、对概念进行建模【类】，查询对象和业务对象分开定义
3、需具备一定的扩展性，满足将来查询条件变化时快速响应，满足开闭原则
*/

//
// Created by linjliang on 2020/9/25.
//

#include <string>
#include <vector>
#include "stdarg.h"
using namespace std;


// 邮件
class emailMeta{
public:
    string sender;      // 发件人
    string receiver;    // 收件人
    string head;        // 邮件标题
    string content;     // 邮件内容
    int send_time;		// 发件时间
    int time_zone;      // 邮件时区
    bool has_attachment;// 有无附件
    // ...
};


/* ********************************************** */
/*          搜索条件可按需增加                       */

// 搜索条件
class SearchCondition{
public:
    virtual bool condition(emailMeta e) = 0;
};

// 条件一：发件人
class Condition_sender : public SearchCondition{
private:
    string target_sender;
public:
    Condition_sender(string s):target_sender(s){}
    bool condition(emailMeta e){
        if (e.sender == target_sender) return true;
        else return false;
    }
};

// 条件二：标题关键字
class Condition_keyword_head: public SearchCondition{
private:
    string keyword;
    vector<int> getNext(string p)
    {
        vector<int> next(p.length());
        next[0] = -1;
        int j = 0;
        int k = -1;
        while (j < (int)p.length() - 1)
        {
            if (k == -1 || p[j] == p[k])
            {
                j++;
                k++;
                next[j] = k;
            }
            else
            {
                k = next[k];
            }
        }
        return next;
    }
    int KMP(string T,string p)
    {
        int i=0; int j=0;
        vector<int> next = getNext(T);
        while (i < (int)T.length() && j < (int)p.length())
        {
            if (j == -1 || T[i] == p[j])
            {
                i++;
                j++;
            }
            else
            {
                j=next[j];
            }
        }
        if (j == (int)p.length())
        {
            return i-j;
        }
        return -1;
    }
public:
    Condition_keyword_head(string k):keyword(k){}
    bool condition(emailMeta e){
        if ( KMP(e.head,keyword) != -1 ) return true;
        else return false;
    }
};

// 条件三：时区
class Condition_timezone: public SearchCondition{
private:
    int target_timezone;
public:
    Condition_timezone(int t):target_timezone(t){}
    bool condition(emailMeta e){
        if (e.time_zone == target_timezone) return true;
        else return false;
    }
};

// 条件四：发件时间
class Condition_sendtime: public SearchCondition{
private:
    int begin;
    int end;
public:
    Condition_sendtime(int b, int e):begin(b),end(e){}
    bool condition(emailMeta e){
        if (e.send_time>=begin && e.send_time<=end) return true;
        else return false;
    }
}

// 若还有新的条件需求 增加子类继承抽象类SearchCondition 重写condition函数即可

/* ********************************************** */

// 邮件搜索
class emailSearch{
private:
    vector<emailMeta> emails;
public:
    emailSearch(){}
    emailSearch(vector<emailMeta>& E):emails(E){}
    emailSearch(const emailSearch & eS){ emails = eS.emails; }
    // 根据条件查找相应邮件 条件个数可变
    vector<int> findEmails(int count, ...){
        if(count<=0) return {};
        va_list arg_ptr;
        va_start(arg_ptr,count);

        vector<SearchCondition*> sC(count); // 条件个数
        for (int i = 0; i < count; ++i) {
            sC[i] = va_arg(arg_ptr,SearchCondition*);
        }

        vector<int> ans;
        for (int i=0; i<emails.size(); i++){
            bool satisfied = true;
            for (auto C:sC){                // 遍历每个条件
                if (C->condition(emails[i]) == false){
                    satisfied = false;
                    break;
                }
            }
            if (satisfied){                 // 满足这些条件
                ans.push_back(i);
            }
        }

        va_end(arg_ptr);
        return ans;
    }
};


// 邮件业务
class emailFunction{
private:
    vector<emailMeta> emails;
public:
    emailFunction(){}
    emailFunction(vector<emailMeta>& E):emails(E){}
    emailFunction(const emailFunction & eF){ emails = eF.emails; }
    // ... 业务逻辑
};


// 邮件整体服务
class emailService{
private:
    vector<emailMeta> emails;
    emailFunction eFunction;
    emailSearch eSearch;
public:
    emailService(){
        emailFunction eFunction(emails);
        emailSearch eSearch(emails);
    }
};