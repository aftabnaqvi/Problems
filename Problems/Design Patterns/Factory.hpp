//
//  Factory.hpp
//  Problems
//
//  Created by Syed Naqvi on 4/1/23.
//

#ifndef Factory_hpp
#define Factory_hpp

#include <iostream>
#include <memory>

// Base class for products
class Product {
public:
    virtual ~Product() {}
    virtual void operation() = 0;
};

// Concrete products
class ConcreteProduct1 : public Product {
public:
    void operation() override {
        std::cout << "ConcreteProduct1 operation" << std::endl;
    }
};

class ConcreteProduct2 : public Product {
public:
    void operation() override {
        std::cout << "ConcreteProduct2 operation" << std::endl;
    }
};

enum ProductType{
    PRODUCT1 = 1,
    PRODUCT2 = 2,
};

// Factory class
class Factory {
public:
    std::unique_ptr<Product> createProduct(ProductType type) {
        switch(type) {
            case PRODUCT1:
                return std::make_unique<ConcreteProduct1>();
            case PRODUCT2:
                return std::make_unique<ConcreteProduct2>();
            default:
                throw std::invalid_argument("Invalid product type");
        }
    }
};

// Client code
//int main() {
//    Factory factory;
//    std::unique_ptr<Product> product1 = factory.createProduct(ProductType::PRODUCT1);
//    std::unique_ptr<Product> product2 = factory.createProduct(ProductType::PRODUCT2);
//
//    product1->operation();
//    product2->operation();
//
//    return 0;
//}
#endif /* Factory_hpp */
