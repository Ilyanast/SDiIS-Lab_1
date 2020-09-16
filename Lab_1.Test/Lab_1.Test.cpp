#include "CppUnitTest.h"
#include "../Fraction.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab1Test
{
	TEST_CLASS(Lab1Test)
	{
	public:

		TEST_METHOD(TestConstructor)
		{
			Fraction fraction(3, -2);
			Assert::AreEqual(fraction.get_numerator(), -3);
			Assert::AreEqual(fraction.get_denominator(), 2);
		}

		TEST_METHOD(TestOperatorPlus)
		{
			Fraction first_fraction(139, 46), second_fraction(49, 87), result(14347, 4002);
			Assert::IsTrue(first_fraction + second_fraction == result);
		}

		TEST_METHOD(TestOperatorAssigmentPlus)
		{
			Fraction first_fraction(14347, 4002);
			Assert::AreEqual((first_fraction += 3).get_numerator(), 26353);
		}

		TEST_METHOD(TestOperatorMinus)
		{
			Fraction first_fraction(114, 7), second_fraction(83, 17), result(1357, 119);
			Assert::IsTrue(first_fraction - second_fraction == result);
		}

		TEST_METHOD(TestOperatorAssigmentMinus)
		{
			Fraction first_fraction(1357, 119);
			Assert::AreEqual((first_fraction -= 3).get_numerator(), 1000);
		}

		TEST_METHOD(TestOperatorMultiple)
		{
			Fraction first_fraction(-56, 3), second_fraction(17, 26), result(-476, 39);
			Assert::IsTrue(first_fraction * second_fraction == result);
		}

		TEST_METHOD(TestOperatorAssigmentMultiple)
		{
			Fraction first_fraction(-476, 39);
			Assert::AreEqual((first_fraction *= 4).get_numerator(), -1904);
		}

		TEST_METHOD(TestOperatorSplit)
		{
			Fraction first_fraction(-5, 2), second_fraction(-2, 5), result(25, 4);
			Assert::IsTrue(first_fraction / second_fraction == result);
		}

		TEST_METHOD(TestOperatorAssigmentSplit)
		{
			Fraction first_fraction(25, 4);
			Assert::AreEqual((first_fraction /= -2).to_double(), double(-3.125));
		}

		TEST_METHOD(TestGetNumerator)
		{
			Fraction first_fraction(7, 3);
			Assert::AreEqual(first_fraction.get_numerator(), 7);
		}

		TEST_METHOD(TestGetDenominator)
		{
			Fraction first_fraction(7, 3);
			Assert::AreEqual(first_fraction.get_denominator(), 3);
		}

		TEST_METHOD(TestGetIntegerPart)
		{
			Fraction first_fraction(7, 3);
			Assert::AreEqual(first_fraction.get_integer_part(), 2);
		}

		TEST_METHOD(TestToDouble)
		{
			Fraction first_fraction(3, 2);
			Assert::AreEqual(first_fraction.to_double(), double(1.5));
		}

		TEST_METHOD(TestOperarorLess)
		{
			Fraction first_fraction(3, 2), second_fraction(414, 234);
			Assert::IsTrue(first_fraction < second_fraction);
		}

		TEST_METHOD(TestOperarorMore)
		{
			Fraction first_fraction(3, 2);
			Assert::IsTrue(first_fraction > 1);
		}

		TEST_METHOD(TestOperarorMoreEqual)
		{
			Fraction first_fraction(8, 2);
			Assert::IsTrue(first_fraction >= 4 && first_fraction >= 3);
		}

		TEST_METHOD(TestOperarorLessEqual)
		{
			Fraction first_fraction(9, 2), second_fraction(8, 2);
			Assert::IsTrue(second_fraction <= 4 && second_fraction <= first_fraction);
		}
	};
}
