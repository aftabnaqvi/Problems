//
//  Adapter.hpp
//  Problems
//
//  Created by Syed Naqvi on 4/1/23.
//

#ifndef Adapter_hpp
#define Adapter_hpp

#include <stdio.h>
#include <iostream>
#include <memory>

/**
 * The Adaptee contains some useful behavior, but its interface is incompatible
 * with the existing client code. The Adaptee needs some adaptation before the
 * client code can use it.
 */
class Adaptee {
public:
    void specificRequest() {
        std::cout << "Adaptee: specific request" << std::endl;
    }
};

/**
 * The Target defines the domain-specific interface used by the client code.
 */

class Target {
public:
    virtual ~Target() {}
    virtual void request() {
    std::cout << "Target: The default target's behavior.\n";
    }
};

/**
 * The Adapter makes the Adaptee's interface compatible with the Target's
 * interface.
 */
class Adapter : public Target {
private:
    std::unique_ptr<Adaptee> adaptee_;
    
public:
    Adapter(std::unique_ptr<Adaptee> adaptee) : adaptee_(std::move(adaptee)) {}
    void request() override {
        adaptee_->specificRequest();
    }
};

/**
 * The client code supports all classes that follow the Target interface.
 */
void clientCode(Target *target) {
  target->request();
}

// Client code
//int main() {
//    std::unique_ptr<Target> defaultTarget = std::make_unique<Target>();
//    clientCode(defaultTarget.get());
//    
//    std::unique_ptr<Adaptee> adaptee = std::make_unique<Adaptee>();
//    std::unique_ptr<Target> target = std::make_unique<Adapter>(std::move(adaptee));
//    clientCode(target.get());
//    return 0;
//}

#endif /* Adapter_hpp */
