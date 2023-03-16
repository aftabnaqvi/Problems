//
//  sample_test.cpp
//  MainTest
//
//  Created by Syed Naqvi on 3/10/23.
//

#include <iostream>
#include <memory>

#include <gtest/gtest.h>

#include "../Interview2023/SmartPointer.hpp"

using namespace std;

class Test1
{
public:
    Test1()
    {
        cout << "Test::ctor()\n";
    }
    
    Test1(int x)
    {
        cout << "Test::ctor() - x: " << x <<endl;
    }
    
    void doSomething()
    {
        cout << "Test:: do something\n";
    }
};

TEST(SmartPointers, BasicTest) {
    SharedPointer<int> spInt(new int(5));
    SharedPointer<int> spInt2 = spInt;
    EXPECT_EQ(spInt.use_count(), spInt2.use_count());
    EXPECT_EQ(*spInt, *spInt2);
    EXPECT_EQ(spInt.get(), spInt2.get());
}

TEST(SmartPointers, Test_1) {
    SharedPointer<int> spInt(new int(5));
    SharedPointer<int> spInt2 = nullptr;
    spInt2 = spInt;
    cout << "spInt2.use_count(): " << spInt2.use_count() << endl;
    EXPECT_EQ(spInt.use_count(), spInt2.use_count());
    EXPECT_EQ(*spInt, *spInt2);
}

TEST(SmartPointers, Test_2) {
    SharedPointer<int> spInt(new int(5));
    SharedPointer<int> spInt2 = nullptr;
    spInt2 = spInt;
    EXPECT_EQ(spInt.use_count(), spInt2.use_count());
    SharedPointer<int> spInt3(3);
    EXPECT_EQ(spInt3.use_count(), 1);
    spInt2 = spInt3;
    EXPECT_EQ(spInt3.use_count(), 2);
    EXPECT_EQ(spInt2.use_count(), 2);
    EXPECT_EQ(*spInt2, *spInt3);
    
    EXPECT_EQ(spInt.use_count(), 1);
    EXPECT_EQ(*spInt, 5);
}

TEST(SmartPointers, Test_3) {
    SharedPointer<char> spInt(new char('a'));
    SharedPointer<char> spInt2 = nullptr;
    spInt2 = spInt;
    cout << "spInt2.use_count(): " << spInt2.use_count() << endl;
    EXPECT_EQ(spInt.use_count(), spInt2.use_count());
    EXPECT_EQ(*spInt, *spInt2);
}

TEST(SmartPointers, Test_4) {
    SharedPointer<Test1> spTest(new Test1(100));
    SharedPointer<Test1> spTest2 = nullptr;
    spTest->doSomething();
    
    spTest2 = spTest;
    
    EXPECT_EQ(spTest.use_count(), spTest2.use_count());
    EXPECT_EQ(spTest.get(), spTest2.get());
}

TEST(SmartPointers, Test_100) {
    std::shared_ptr<int> spInt(new int(5));
    std::shared_ptr<int> spInt2 = nullptr;
    spInt2 = spInt;
    EXPECT_EQ(spInt.use_count(), spInt2.use_count());
    EXPECT_EQ(*spInt, *spInt2);
}
