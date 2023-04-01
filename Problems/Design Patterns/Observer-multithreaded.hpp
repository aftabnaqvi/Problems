//
//  Observer-multithreaded.hpp
//  Problems
//
//  Created by Syed Naqvi on 4/1/23.
//

#ifndef Observer_multithreaded_hpp
#define Observer_multithreaded_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <memory>
#include <mutex>
#include <thread>

// Abstract observer interface
class Observer {
public:
    virtual ~Observer() {}
    virtual void update(int value) = 0;
};

// Subject class
class Subject {
private:
    int value_;
    std::vector<std::shared_ptr<Observer>> observers_;
    std::mutex mutex_;
public:
    void setValue(int value) {
        std::lock_guard<std::mutex> lock(mutex_);
        value_ = value;
        notifyObservers();
    }
    void attach(std::shared_ptr<Observer> observer) {
        std::lock_guard<std::mutex> lock(mutex_);
        observers_.push_back(observer);
    }
    void detach(std::shared_ptr<Observer> observer) {
        std::lock_guard<std::mutex> lock(mutex_);
        observers_.erase(std::remove(observers_.begin(), observers_.end(), observer), observers_.end());
    }
    void notifyObservers() {
        for (auto& observer : observers_) {
            observer->update(value_);
        }
    }
};

// Concrete observer classes
class ConcreteObserver1 : public Observer {
public:
    void update(int value) override {
        std::cout << "ConcreteObserver1 received update with value " << value << " on thread " << std::this_thread::get_id() << std::endl;
    }
};

class ConcreteObserver2 : public Observer {
public:
    void update(int value) override {
        std::cout << "ConcreteObserver2 received update with value " << value << " on thread " << std::this_thread::get_id() << std::endl;
    }
};

// Client code
int main() {
    Subject subject;
    
    // Create observers
    std::shared_ptr<Observer> observer1 = std::make_shared<ConcreteObserver1>();
    std::shared_ptr<Observer> observer2 = std::make_shared<ConcreteObserver2>();
    
    // Attach observers to subject
    subject.attach(observer1);
    subject.attach(observer2);
    
    // Change subject value and notify observers
    std::thread thread1([&subject]() {
        subject.setValue(42);
    });
    
    // Detach one observer from subject
    std::thread thread2([&subject, observer1]() {
        subject.detach(observer1);
    });
    
    // Change subject value and notify remaining observer
    std::thread thread3([&subject]() {
        subject.setValue(99);
    });
    
    thread1.join();
    thread2.join();
    thread3.join();
    
    return 0;
}

#endif /* Observer_multithreaded_hpp */
