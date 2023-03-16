//
//  SmartPointer.cpp
//  Interview2023
//
//  Created by Syed Naqvi on 3/8/23.
//

#include "SmartPointer.hpp"

//int main(){
//  //----
//    int* pData = new int(5);
//    SharedPointer spInt(pData);
//    std::cout << "spInt.data: " << *spInt << std::endl;
//    std::cout << "spInt.use_count: " << spInt.use_count() << std::endl;
//    
//    SharedPointer spInt2(100);
//    std::cout << "spInt2.data: " << *spInt2 << std::endl;
//    std::cout << "spInt2.use_count: " << spInt2.use_count() << std::endl;
//    
//    std::cout << "spInt.data: " << *spInt << std::endl;
//    std::cout << "spInt.use_count: " << spInt.use_count() << std::endl;
//
//    spInt = spInt2;
//    std::cout << "spInt.data: " << *spInt << std::endl;
//    std::cout << "spInt.use_count: " << spInt.use_count() << std::endl;
//    
//    std::cout << "spInt2.data: " << *spInt2 << std::endl;
//    std::cout << "spInt2.use_count: " << spInt2.use_count() << std::endl;
//    
//    SharedPointer spInt3 = spInt;
//    std::cout << "spInt3.data: " << *spInt3 << std::endl;
//    std::cout << "spInt3.use_count: " << spInt3.use_count() << std::endl;
//    {
//        SharedPointer spInt4(200);
//        std::cout << "spInt4.data: " << *spInt4 << std::endl;
//        std::cout << "spInt4.use_count: " << spInt4.use_count() << std::endl;
//        
//        spInt3 = spInt4;
//        std::cout << "spInt3.data: " << *spInt3 << std::endl;
//        std::cout << "spInt3.use_count: " << spInt3.use_count() << std::endl;
//    }
//    
////-----
//    {
//        std::shared_ptr<int> spInteger(new int(5));
//        std::cout << "spInteger.data: " << *spInteger << std::endl;
//        std::cout << "spInteger.use_count: " << spInteger.use_count() << std::endl;
//        
//        std::shared_ptr<int> spInteger2 = nullptr;
//        spInteger2 = spInteger;
//        std::cout << "spInteger2.data: " << *spInteger2 << std::endl;
//        std::cout << "spInteger2.use_count: " << spInteger2.use_count() << std::endl;
//        
//        //std::shared_ptr<int> spInteger2(5);
//    }
//  return 0;
//}
