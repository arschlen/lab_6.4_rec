#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_6.4_rec/6.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int SIZE = 5;
			double mas[SIZE] = { -1.5, 2.3, 0.0, 4.1, -3.2 };
			int expected = 2;

			int result = CountPositive(mas, SIZE);

			Assert::AreEqual(expected, result);
		}
	};
}
