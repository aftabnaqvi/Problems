//
//  SmartPointer.hpp
//  Interview2023
//
//  Created by Syed Naqvi on 3/8/23.
//

#ifndef SmartPointer_hpp
#define SmartPointer_hpp

#include <stdio.h>
#include <iostream>

template<typename T>
class SharedPointer {
  int* m_pRefCount = new int(0); // ref Count should be pointer and allocated on heap. important
  T* m_pData = nullptr;

public:
    SharedPointer(T data){
        std::cout<<"SharedPointer - T ctor" << std::endl;
      m_pData = new int(data);
      ++*m_pRefCount;
    }
    
    SharedPointer(T* pData){
        std::cout<<"SharedPointer - T* ctor" << std::endl;
        if(pData == nullptr){
            return;
        }

        m_pData = pData;
        ++(*m_pRefCount);
    }
    
    SharedPointer(const SharedPointer<T>& rhs){
        std::cout<<"SharedPointer - copy ctor" << std::endl;
        m_pRefCount = rhs.m_pRefCount;
        m_pData = rhs.m_pData;
        ++(*m_pRefCount);
    }
  
    // Assignment operator
    SharedPointer<T>& operator= (const SharedPointer<T>& rhs){
        if(&rhs == this) {
          return *this;
        }
        
        std::cout<<"operator= called" <<std::endl;
        --(*m_pRefCount);
        if (*m_pRefCount == 0) {
            std::cout<<"operator= -- refCount: " << *m_pRefCount << std::endl;
            delete m_pData;
            m_pData = nullptr;
        }

        m_pRefCount = rhs.m_pRefCount;
        m_pData = rhs.m_pData;
        ++(*m_pRefCount);
        return *this;
    }

    ~SharedPointer() {
        if(--(*m_pRefCount) == 0) {
            std::cout<<"~SharedPointer dtor: refCount: " << *m_pRefCount <<std::endl;
            delete m_pData;
            m_pData = nullptr;
            delete m_pRefCount;
            m_pRefCount = nullptr;
        }
    }

    T& operator*(){
        return *m_pData;
    }

    T* operator->(){
        return m_pData;
    }
    
    int use_count() {
        return *m_pRefCount;
    }
    
    T* get() {
        return m_pData;
    }
};


#endif /* SmartPointer_hpp */
