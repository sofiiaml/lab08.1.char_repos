#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "CppUnitTest.h"
#include "../Pr08.1.char/Pr08.1.char.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81char
{
	TEST_CLASS(UnitTest81char)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char str[] = "asd+=gfd--+";
			Assert::AreEqual(5, Count(str));

			char* dest = new char[15];
			dest = Change(str);
			Assert::AreEqual("asd+=gfd***+", dest);
		}
	};
}
