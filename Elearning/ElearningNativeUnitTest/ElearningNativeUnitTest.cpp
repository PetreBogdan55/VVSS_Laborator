#include "pch.h"
#include "CppUnitTest.h"
#include "Utils.h"
#include "Student.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ElearningNativeUnitTest
{
	TEST_CLASS(ElearningNativeUnitTest)
	{
	public:
		//$(SolutionDir)Elearning\IntegrationLayer\Logger\
		
		TEST_METHOD(TestMethod1)
		{
			int actual = 2 + 3;
			int expected = 5;
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestCalculateAverage)
		{
			std::vector<double> vector = { 3,6,9 };
			double actual = calculateAverage(vector);
			double expected = 6;
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestCalculateAverageEmptyVector)
		{
			std::vector<double> vector = {};
			try {
				calculateAverage(vector);
			}
			catch (const std::invalid_argument& e)
			{
				Assert::IsTrue(std::string(e.what()) == "Vector gol");
			}
		}

		TEST_METHOD(TestMaxValue)
		{
			std::vector<int> vector = { 6,8,9 };
			int actual = maxValue(vector);
			int expected = 9;
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestMaxValueNegativeValues)
		{
			std::vector<int> vector = { -56,-38,-19 };
			int actual = maxValue(vector);
			int expected = -19;
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestMaxValueEmptyVector)
		{
			std::vector<int> vector = { };
			try {
				maxValue(vector);
			}
			catch (const std::invalid_argument& e)
			{
				Assert::IsTrue(std::string(e.what()) == "Vector gol");
			}
		}

		TEST_METHOD(CheckStudent)
		{
			Student student("Ion", "Popescu", "ion.popescu@student.unitbv.ro",
				"", "", "", 3);
			Assert::IsTrue(student.getFirstName().size() != 0);
			Assert::IsTrue(student.getStudyYear() >= 1);
			Assert::IsTrue(student.getEmail().find("@student.unitbv.ro") !=
				std::string::npos);
		}
	};
}
