#include "pch.h"
#include "CppUnitTest.h"
#include "../main-project/rate.h"
#include "C:/Users/User/cpp-console-library-subscription/main-project/processingg.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{
	rate* build_rate(char bank[MAX_STRING_SIZE], double purchase, double sale, char address[MAX_STRING_SIZE]) {
		rate* rt = new rate;
		strncpy_s(rt->bank, bank, MAX_STRING_SIZE);
		rt->bank[MAX_STRING_SIZE - 1] = '\0';
		rt->purchase = purchase;
		rt->sale = sale;
		strncpy_s(rt->address, address, MAX_STRING_SIZE);
		rt->address[MAX_STRING_SIZE - 1] = '\0';
		return rt;
	}

	void delete_rate(rate* array[], int size) {
		for (int i = 0; i < size; i++) {
			delete array[i];
		}
	}


	TEST_CLASS(unittestproject)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			rate* rt[3];
			rt[0] = build_rate("Беларусбанк", 2.85, 0.5, "ул.Титова");
			rt[1] = build_rate("Альфабпнк", 2.05, 2.5, "ул.Кирова");
			rt[2] = build_rate("СберБанк", 3.12, 3.5, "ул.Леонова");
			Assert::AreEqual(0.5, process(rt, 2));
			delete_rate(rt, 2);
		}
	};
}
