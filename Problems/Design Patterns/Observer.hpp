//
//  Observer.hpp
//  Problems
//
//  Created by Syed Naqvi on 4/1/23.
//

#ifndef Observer_hpp
#define Observer_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <memory>

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
public:
    void setValue(int value) {
        value_ = value;
        notifyObservers();
    }
    void attach(std::shared_ptr<Observer> observer) {
        observers_.push_back(observer);
    }
    void detach(std::shared_ptr<Observer> observer) {
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
        std::cout << "ConcreteObserver1 received update with value " << value << std::endl;
    }
};

class ConcreteObserver2 : public Observer {
public:
    void update(int value) override {
        std::cout << "ConcreteObserver2 received update with value " << value << std::endl;
    }
};

// Client code
//int main() {
//    Subject subject;
//    
//    // Create observers
//    std::shared_ptr<Observer> observer1 = std::make_shared<ConcreteObserver1>();
//    std::shared_ptr<Observer> observer2 = std::make_shared<ConcreteObserver2>();
//    
//    // Attach observers to subject
//    subject.attach(observer1);
//    subject.attach(observer2);
//    
//    // Change subject value and notify observers
//    subject.setValue(42);
//    
//    // Detach one observer from subject
//    subject.detach(observer1);
//    
//    // Change subject value and notify remaining observer
//    subject.setValue(99);
//    
//    return 0;
//}

#endif /* Observer_hpp */
