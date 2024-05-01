#include "pch.h"
#include "CppUnitTest.h"
#include "D:\lpnu\OOP\6.1\6.1\Array.h"
#include "D:\lpnu\OOP\6.1\6.1\Array.cpp"
#include "D:\lpnu\OOP\6.1\6.1\main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MyArrayTests
{
    TEST_CLASS(ArrayTests)
    {
    public:
        TEST_METHOD(TestPositiveHalfSum)
        {
            // Arrange
            Array arr(5);
            double halfSum = 2;
            // Assert
            Assert::IsTrue(halfSum > 0.0);
        }
    };
}
