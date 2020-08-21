//
// Created by linjliang on 2020/8/21.
//

/*
 * 单例模式：
 * - 类只能实例化一个对象
 * - 提供一个能访问该对象的全局访问方式
 */

#include <iostream>
using namespace std;

// 饿汉式
class Singleton{
private:
    Singleton() {};
    Singleton(const Singleton&) {};
    Singleton& operator= (const Singleton&) {};
    static Singleton* p_singleton;
public:
    static Singleton* getInstance(){
        return p_singleton;
    }
};
Singleton* Singleton::p_singleton;    // 静态成员变量 类外初始化

// 懒汉式
class Singleton1{
private:
    Singleton1() {};
    Singleton1(const Singleton1&) {};
    Singleton1& operator=(const Singleton1&) {};
    static Singleton1* p_singleton1;
    static mutex mux;
public:
    static Singleton1* getInstance(){
        if (p_singleton1 == nullptr){
            lock_guard<mutex> lock(mux);    // 使懒汉模式可以在多线程下运行
            if (p_singleton1 == nullptr) {
                p_singleton1 = new Singleton1();
            }
        }
        return p_singleton1;
    }
};
Singleton1* Singleton1::p_singleton1;    // 静态成员变量 类外初始化
mutex Singleton1::mux;

int main(){
    Singleton* p1 = Singleton::getInstance();
    Singleton* p2 = Singleton::getInstance();
    cout<< (p1==p2) <<endl;

    Singleton1* p3 = Singleton1::getInstance();
    Singleton1* p4 = Singleton1::getInstance();
    cout<< (p3==p4) <<endl;
}

/*
 * Note:
 *
 * 饿汉模式：能够在多线程下运行，但由于其一开始就初始化了实例对象，如果从未调用则造成资源浪费
 * 懒汉模式：需要通过加锁来确保线程安全，在加锁前后都判断对象指针是否为空，是为了减少加锁次数（只需一次），
 *         提高运行效率（加锁是耗时操作）
 */