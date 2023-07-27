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

// Test fixture class which is inherited from google's test class
class TestFixtureTestSuite : public testing::Test
{
    // Anything we write in this class should be under protected
    protected:
    A *aPtr;
    B *bPtr;
    C *cPtr;

    TestFixtureTestSuite()
    {
        // initialization
    }

    ~TestFixtureTestSuite
    {
        // releasing the resources
    }

    // Alternate option instead of constructor and destructor, we can use SetUp and TearDown provided by google and override them
    // SetUp() is a API provided by google's test class
    void SetUp()
    {
        this->cPtr = new C();
        this->bPtr = new B(cPtr);
        this->aPtr = new A(bPtr);
    }

    // TearDown() is a API provided by google's test class
    void TearDown()
    {
        delete cPtr;
        delete bPtr;
        delete aPtr;
    }
}

TEST_F(TestFixtureTestSuite, OperationTrueTest)
{
    // Arrange
    // Given by the fixture class TestFixtureTestSuite
    // Act and Assert
    ASSERT_TRUE(aPtr->operation());
}

TEST_F(TestFixtureTestSuite, OperationTrueTest)
{
    // Arrange
    // Given by the fixture class TestFixtureTestSuite
    // Act and Assert
    ASSERT_FALSE(aPtr->operation());
}

/*TEST(TestFixtureTestSuite, OperationTrueTest)
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
}*/

