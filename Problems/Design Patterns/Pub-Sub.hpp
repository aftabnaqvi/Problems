//
//  Pub-Sub.hpp
//  Problems
//
//  Created by Syed Naqvi on 4/1/23.
//

#ifndef Pub_Sub_hpp
#define Pub_Sub_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <memory>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <vector>

// Forward declaration of Subscriber class
#include <iostream>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <memory>

// Abstract subscriber interface
class Subscriber {
public:
    virtual ~Subscriber() {}
    virtual void update() = 0;
};

// Publisher class
class Publisher {
private:
    std::vector<std::shared_ptr<Subscriber>> subscribers_;
    std::mutex mutex_;
    std::condition_variable cv_;
    bool data_available_ = false;
public:
    void subscribe(std::shared_ptr<Subscriber> subscriber) {
        std::unique_lock<std::mutex> lock(mutex_);
        subscribers_.push_back(subscriber);
    }
    void setDataAvailable(bool data_available) {
        std::unique_lock<std::mutex> lock(mutex_);
        data_available_ = data_available;
        cv_.notify_all();
    }
    void notifySubscribers() {
//        std::cout << "notifySubscribers - try tp acquire lock" << std::endl;
        std::unique_lock<std::mutex> lock(mutex_);
//        std::cout << "notifySubscribers - acquired lock" << std::endl;
        cv_.wait(lock, [this]{ return data_available_; });
        for (auto& subscriber : subscribers_) {
            subscriber->update();
        }
        data_available_ = false;
//        std::cout << "data_available_ == false" << std::endl;
    }
};

// Concrete subscriber classes
class ConcreteSubscriber1 : public Subscriber {
public:
    void update() override {
        std::cout << "ConcreteSubscriber1 received update" << std::endl;
    }
};

class ConcreteSubscriber2 : public Subscriber {
public:
    void update() override {
        std::cout << "ConcreteSubscriber2 received update\n" << std::endl;
    }
};

// Client code
//int main() {
//    Publisher publisher;
//    
//    // Create subscribers
//    std::shared_ptr<Subscriber> subscriber1 = std::make_shared<ConcreteSubscriber1>();
//    std::shared_ptr<Subscriber> subscriber2 = std::make_shared<ConcreteSubscriber2>();
//    
//    // Subscribe subscribers to publisher
//    publisher.subscribe(subscriber1);
//    publisher.subscribe(subscriber2);
//    
//    // Create a thread to notify subscribers
//    std::thread notification_thread([&]{
//        while (true) {
////            std::cout << "going to call notifySubscribers().\n" << std::endl;
//            publisher.notifySubscribers();
//            std::this_thread::sleep_for(std::chrono::seconds(3));
//        }
//    });
//    
//    // Set data available and sleep
//    for (int i = 0; i < 10; ++i) {
//        publisher.setDataAvailable(true);
////        std::cout << "main thread is sleeping for two seconds.\n" << std::endl;
//        std::this_thread::sleep_for(std::chrono::seconds(2));
//    }
//    
//    // Stop the notification thread
//    notification_thread.join();
//    
//    return 0;
//}

#endif /* Pub_Sub_hpp */
