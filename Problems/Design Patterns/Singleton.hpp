//
//  Singleton.hpp
//  Problems
//
//  Created by Syed Naqvi on 3/31/23.
//

#ifndef Singleton_hpp
#define Singleton_hpp

#include <mutex>
#include <iostream>

class Singleton {
public:
    static Singleton& getInstance() {
        std::unique_lock<std::mutex> lock(_mutex);
        static Singleton instance;
        return instance;
    }
    void doSomething() {
        std::cout << "Singleton - doSomething\n";
    }
    // Other public member functions and data members.
private:
    // Private constructor and destructor to prevent creating instances from outside the class.
    Singleton() {}
    ~Singleton() {}
    // Disable copy constructor and assignment operator to prevent cloning of objects.
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    // Private data members.
    static std::mutex _mutex;
};


class Singleton1 {
public:
    static Singleton1* getInstance() {
        
        if(_singleton) {
            return _singleton;
        }
        
        std::unique_lock<std::mutex> lock(_mutex);
        if (!_singleton) {
            _singleton = new Singleton1();
        }
        
        return _singleton;
    }
    void doSomething() {
        std::cout << "Singleton1 - doSomething\n";
    }
    // Other public member functions and data members.
private:
    // Private constructor and destructor to prevent creating instances from outside the class.
    Singleton1() {}
    ~Singleton1() {}
    // Disable copy constructor and assignment operator to prevent cloning of objects.
    Singleton1(const Singleton1&) = delete;
    Singleton1& operator=(const Singleton1&) = delete;
    
    // Private data members.
    static std::mutex _mutex;
    static Singleton1* _singleton;
};
#endif /* Singleton_hpp */
