#include "gtest/gtest.h"

class C{};
class B {
    C *ptr;
    public:
    B(C* addressOfObject): ptr{addressOfObject} {

    }
};
class A {
    B *ptr;
    public:
    A(B* addressOfObject): ptr{addressOfObject} {

    }
    bool operation() {
        return true;
    }
};

TEST(TestFixtureTestSuite, OperationTrueTest)
{
    // Arrange
    C cObj;
    B bObj(&cObj);
    A aObj(&bObj);

    // Act and Assert
    ASSERT_TRUE(aObj.operation());
}

TEST(TestFixtureTestSuite, OperationFalseTest)
{
    // Arrange
    C cObj;
    B bObj(&cObj);
    A aObj(&bObj);

    // Act and Assert
    ASSERT_FALSE(aObj.operation());
}

