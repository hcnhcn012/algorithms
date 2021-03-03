//
//  main.cpp
//  Singleton
//
//  Created by ChengnanHu on 2/27/21.
//

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

class Singleton
{
protected:
    static Singleton *__obj;
    static mutex mtx;
    Singleton(int i);
    
public:
    int __i;
    static Singleton &get_obj();
    Singleton(const Singleton &__other) = delete;
    Singleton &operator=(const Singleton &__other) = delete;
    
};

Singleton *Singleton::__obj = nullptr;
mutex Singleton::mtx;

Singleton::Singleton(int i)
{
    this->__i = i;
}

Singleton &Singleton::get_obj()
{
    mtx.lock();
    if (Singleton::__obj == nullptr)
    {
        cout << "Now creating singleton" << endl;
        Singleton::__obj = new Singleton(5);
    }
    mtx.unlock();
    return *Singleton::__obj;
}

void t1_handler()
{
    cout << "[Thread1]Now getting the singleton object" << endl;
    cout << Singleton::get_obj().__i << endl;
}

void t2_handler()
{
    cout << "[Thread2]Now getting the singleton object" << endl;
    cout << Singleton::get_obj().__i << endl;
}


int main(int argc, const char * argv[])
{
    thread t1 = thread(t1_handler);
    thread t2 = thread(t2_handler);
    t1.join();
    t2.join();
}
