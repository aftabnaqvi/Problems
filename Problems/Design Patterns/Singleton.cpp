//
//  Singleton.cpp
//  Problems
//
//  Created by Syed Naqvi on 3/31/23.
//

#include "Singleton.hpp"

std::mutex Singleton::_mutex;

std::mutex Singleton1::_mutex;
Singleton1* Singleton1::_singleton = nullptr;;

//// Usage example
//int main() {
//    Singleton& mySingleton = Singleton::getInstance();
//    mySingleton.doSomething();
//    
//    Singleton1* pSingleton = Singleton1::getInstance();
//    pSingleton->doSomething();
//}

