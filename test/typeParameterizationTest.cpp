#include "gtest/gtest.h"
using testing::Types;

class ITempSensor
{
    public:
    virtual int getOutsideTemp() = 0;
};

class ModelATempSensor : public ITempSensor
{
    public:
    int getOutsideTemp()
    {
        return 23;
    }
};

class ModelBTempSensor : public ITempSensor
{
    public:
    int getOutsideTemp()
    {
        return 25;
    }
};

class ModelCTempSensor : public ITempSensor
{
    public:
    int getOutsideTemp()
    {
        return 23;
    }
};

class AutoTempRegulator
{
    ITempSensor *tempSensorPtr;

    public:
    AutoTempRegulator(ITempSensor *sensorType) : tempSensorPtr(sensorType) {}

    void regulateTemp()
    {
        this->tempSensorPtr->getOutsideTemp();
    }
};

// Template
template <typename T>
ITempSensor* createObject(); // Factory function
// Template specilization
template <>
ITempSensor* createObject<ModelATempSensor>() { return new ModelATempSensor(); }
template <>
ITempSensor* createObject<ModelBTempSensor>() { return new ModelBTempSensor(); }
template <>
ITempSensor* createObject<ModelCTempSensor>() { return new ModelCTempSensor(); }

template <typename T>
class TempSensorFixture : public testing::Test
{
    protected:
    // Arrange
    ITempSensor *objUnderTest;
    TempSensorFixture() : objUnderTest { createObject<T>() } {}
};

typedef Types<ModelATempSensor, ModelBTempSensor, ModelCTempSensor> Implementations;

TYPED_TEST_SUITE(TempSensorFixture, Implementations);

TYPED_TEST(TempSensorFixture, GetTempTest) 
{
	ASSERT_EQ(this->objUnderTest->getOutsideTemp(), 23);
}

// Interaction testing for the void function

// method 1: Stub
class FakeTempSensor: public ITempSensor
{
    public:
    int getOutsideTemp() { return 0; }
};

TEST(AutoTempRegulatorTestSuite, RegulateTempTest)
{
    FakeTempSensor stub;
    AutoTempRegulator codeUnderTest(&stub);
    codeUnderTest.regulateTemp();
}


// method 2: hand-made mock
class FakeTempSensor: public ITempSensor
{
    public:
    int getOutsideTempCallCount = 0;
    int getOutsideTemp() { getOutsideTempCallCount += 1; return 0; }
};

TEST(AutoTempRegulatorTestSuite, RegulateTempInteractionTest)
{
    FakeTempSensor mockObj;
    AutoTempRegulator codeUnderTest(&mockObj);
    codeUnderTest.regulateTemp();
    ASSERT_EQ(mockObj.getOutsideTempCallCount, 1);
}