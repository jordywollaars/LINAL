#include "pch.h"
#include "CppUnitTest.h"

#include "../LinalEindopdracht/Matrix.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MatrixTesting
{
	TEST_CLASS(Creation)
	{
	public:
		TEST_METHOD(MatrixCreationSizeFourByFour)
		{
			Matrix<double> m = Matrix<double>(4, 4);

			Assert::AreEqual(4, (int)m.getColSize());
			Assert::AreEqual(4, (int)m.getRowSize());
		}

		TEST_METHOD(MatrixCreationSizeTwoByTwo)
		{
			Matrix<double> m = Matrix<double>(2, 2);

			Assert::AreEqual(2, (int)m.getColSize());
			Assert::AreEqual(2, (int)m.getRowSize());
		}

		TEST_METHOD(MatrixCreationWithInitialValue)
		{
			Matrix<double> m = Matrix<double>(2, 2, 5.0);

			Assert::AreEqual(5.0, m(0, 0));
			Assert::AreEqual(5.0, m(0, 1));
			Assert::AreEqual(5.0, m(1, 0));
			Assert::AreEqual(5.0, m(1, 1));
		}
	};

	TEST_CLASS(Multiplication)
	{
	public:
		TEST_METHOD(Multiply2TwoByTwoMatrices)
		{
			Matrix<double> m1 = Matrix<double>(2, 2);
			m1(0, 0) = 5;
			m1(1, 0) = 3;
			m1(0, 1) = 2;
			m1(1, 1) = 1;

			Matrix<double> m2 = Matrix<double>(2, 2);
			m2(0, 0) = 4;
			m2(1, 0) = 2;
			m2(0, 1) = 1;
			m2(1, 1) = 0;

			Matrix<double> mMultiplied = m1 * m2;

			Assert::AreEqual(24.0, mMultiplied(0, 0));
			Assert::AreEqual(5.0, mMultiplied(0, 1));
			Assert::AreEqual(14.0, mMultiplied(1, 0));
			Assert::AreEqual(3.0, mMultiplied(1, 1));
		}

		TEST_METHOD(Multiply3ThreeByThreeMatrices)
		{
			Matrix<double> m1 = Matrix<double>(3, 3);
			m1(0, 0) = 5;
			m1(0, 1) = 3;
			m1(0, 2) = 2;
			m1(1, 0) = 1;
			m1(1, 1) = 4;
			m1(1, 2) = 6;
			m1(2, 0) = 3;
			m1(2, 1) = 2;
			m1(2, 2) = 8;

			Matrix<double> m2 = Matrix<double>(3, 3);
			m2(0, 0) = 5;
			m2(0, 1) = 5;
			m2(0, 2) = 5;
			m2(1, 0) = 5;
			m2(1, 1) = 5;
			m2(1, 2) = 5;
			m2(2, 0) = 5;
			m2(2, 1) = 5;
			m2(2, 2) = 5;

			Matrix<double> m3 = Matrix<double>(3, 3);
			m3(0, 0) = 8;
			m3(0, 1) = 3;
			m3(0, 2) = 5;
			m3(1, 0) = 3;
			m3(1, 1) = 9;
			m3(1, 2) = 3;
			m3(2, 0) = 1;
			m3(2, 1) = 3;
			m3(2, 2) = 7;

			Matrix<double> mMultiplied = m1 * m2 * m3;

			Assert::AreEqual(600.0, mMultiplied(0, 0));
			Assert::AreEqual(750.0, mMultiplied(0, 1));
			Assert::AreEqual(750.0, mMultiplied(0, 2));

			Assert::AreEqual(660.0, mMultiplied(1, 0));
			Assert::AreEqual(825.0, mMultiplied(1, 1));
			Assert::AreEqual(825.0, mMultiplied(1, 2));

			Assert::AreEqual(780.0, mMultiplied(2, 0));
			Assert::AreEqual(975.0, mMultiplied(2, 1));
			Assert::AreEqual(975.0, mMultiplied(2, 2));
		}

		TEST_METHOD(MultiplyMatrixByScalar)
		{
			Matrix<double> m1 = Matrix<double>(3, 3);
			m1(0, 0) = 5;
			m1(0, 1) = 3;
			m1(0, 2) = 2;
			m1(1, 0) = 1;
			m1(1, 1) = 4;
			m1(1, 2) = 6;
			m1(2, 0) = 3;
			m1(2, 1) = 2;
			m1(2, 2) = 8;

			Matrix<double> mMultiplied = m1 * 2.0;

			Assert::AreEqual(10.0, mMultiplied(0, 0));
			Assert::AreEqual(6.0, mMultiplied(0, 1));
			Assert::AreEqual(4.0, mMultiplied(0, 2));

			Assert::AreEqual(2.0, mMultiplied(1, 0));
			Assert::AreEqual(8.0, mMultiplied(1, 1));
			Assert::AreEqual(12.0, mMultiplied(1, 2));

			Assert::AreEqual(6.0, mMultiplied(2, 0));
			Assert::AreEqual(4.0, mMultiplied(2, 1));
			Assert::AreEqual(16.0, mMultiplied(2, 2));
		}

		TEST_METHOD(RowSizeDoesNotEqualColSize)
		{
			auto func = [] {
				Matrix<double> m1 = Matrix<double>(2, 2);
				Matrix<double> m2 = Matrix<double>(3, 3);

				Matrix<double> mMultiplied = m1 * m2;
			};
			Assert::ExpectException<std::exception>(func);
		}
	};

	TEST_CLASS(SpecificMatrices)
	{
	public:
		TEST_METHOD(TranslationMatrix5OnX)
		{
			Matrix<double> m = Matrix<double>::getTranslationMatrix(5, 0, 0);

			Assert::AreEqual(1.0, m(0, 0));
			Assert::AreEqual(1.0, m(1, 1));
			Assert::AreEqual(1.0, m(2, 2));
			Assert::AreEqual(1.0, m(3, 3));
			Assert::AreEqual(5.0, m(0, 3));
			Assert::AreEqual(0.0, m(1, 3));
			Assert::AreEqual(0.0, m(2, 3));
		}

		TEST_METHOD(TranslationMatrix3OnY)
		{
			Matrix<double> m = Matrix<double>::getTranslationMatrix(0, 3, 0);

			Assert::AreEqual(1.0, m(0, 0));
			Assert::AreEqual(1.0, m(1, 1));
			Assert::AreEqual(1.0, m(2, 2));
			Assert::AreEqual(1.0, m(3, 3));
			Assert::AreEqual(0.0, m(0, 3));
			Assert::AreEqual(3.0, m(1, 3));
			Assert::AreEqual(0.0, m(2, 3));
		}

		TEST_METHOD(TranslationMatrix1OnZ)
		{
			Matrix<double> m = Matrix<double>::getTranslationMatrix(0, 0, 1);

			Assert::AreEqual(1.0, m(0, 0));
			Assert::AreEqual(1.0, m(1, 1));
			Assert::AreEqual(1.0, m(2, 2));
			Assert::AreEqual(1.0, m(3, 3));
			Assert::AreEqual(0.0, m(0, 3));
			Assert::AreEqual(0.0, m(1, 3));
			Assert::AreEqual(1.0, m(2, 3));
		}

		TEST_METHOD(TranslationMatrix8OnXYZ)
		{
			Matrix<double> m = Matrix<double>::getTranslationMatrix(8, 8, 8);

			Assert::AreEqual(1.0, m(0, 0));
			Assert::AreEqual(1.0, m(1, 1));
			Assert::AreEqual(1.0, m(2, 2));
			Assert::AreEqual(1.0, m(3, 3));
			Assert::AreEqual(8.0, m(0, 3));
			Assert::AreEqual(8.0, m(1, 3));
			Assert::AreEqual(8.0, m(2, 3));
		}

		TEST_METHOD(ScalingMatrix8OnX)
		{
			Matrix<double> m = Matrix<double>::getScalingMatrix(8, 0, 0);

			Assert::AreEqual(8.0, m(0, 0));
			Assert::AreEqual(0.0, m(1, 1));
			Assert::AreEqual(0.0, m(2, 2));
			Assert::AreEqual(1.0, m(3, 3));
		}

		TEST_METHOD(ScalingMatrix2OnY)
		{
			Matrix<double> m = Matrix<double>::getScalingMatrix(0, 2, 0);

			Assert::AreEqual(0.0, m(0, 0));
			Assert::AreEqual(2.0, m(1, 1));
			Assert::AreEqual(0.0, m(2, 2));
			Assert::AreEqual(1.0, m(3, 3));
		}

		TEST_METHOD(ScalingMatrix6OnZ)
		{
			Matrix<double> m = Matrix<double>::getScalingMatrix(0, 0, 6);

			Assert::AreEqual(0.0, m(0, 0));
			Assert::AreEqual(0.0, m(1, 1));
			Assert::AreEqual(6.0, m(2, 2));
			Assert::AreEqual(1.0, m(3, 3));
		}

		TEST_METHOD(ScalingMatrix20OnXYZ)
		{
			Matrix<double> m = Matrix<double>::getScalingMatrix(20, 20, 20);

			Assert::AreEqual(20.0, m(0, 0));
			Assert::AreEqual(20.0, m(1, 1));
			Assert::AreEqual(20.0, m(2, 2));
			Assert::AreEqual(1.0, m(3, 3));
		}
	};
}
