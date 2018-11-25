#include "palindrome.h"
#include <CUnit/CUnit.h>

void test_is_palindrome_words()
{
	CU_ASSERT_TRUE(is_palindrome("radar"));
	CU_ASSERT_FALSE(is_palindrome("hello"));
	CU_ASSERT_TRUE(is_palindrome("wow"));
	CU_ASSERT_TRUE(is_palindrome("ll"));
	CU_ASSERT_TRUE(is_palindrome("raar"));
}

void test_is_palindrome_sentences()
{
	CU_ASSERT_TRUE(is_palindrome("live evil"));
	CU_ASSERT_FALSE(is_palindrome("This senstence is no palindrome"));
}

// has to be case sensitive
void test_is_palindrome_case()
{
	CU_ASSERT_TRUE(is_palindrome("wow"));
	CU_ASSERT_FALSE(is_palindrome("woW"));
	CU_ASSERT_TRUE(is_palindrome("WoW"));
	CU_ASSERT_TRUE(is_palindrome("Wow"));
}

// edge cases
void test_is_palindrome_edge()
{
	CU_ASSERT_TRUE(is_palindrome(""));
	CU_ASSERT_TRUE(is_palindrome("a"));
}

//entry of test
int main()
{
   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   /* add a suite to the registry */
   pSuite = CU_add_suite("palindrome", NULL, NULL);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   if ((NULL == CU_add_test(pSuite, "test is_palindrome() for words", 
						   test_is_palindrome_words)) ||
       (NULL == CU_add_test(pSuite, "test is_palindrome() for sentences", 
							test_is_palindrome_sentences)) ||
       (NULL == CU_add_test(pSuite, "test is_palindrom() for case sensitivity",
							test_is_palindrome_case)) ||
       (NULL == CU_add_test(pSuite, "test is_palindrome() for edge cases",
							test_is_palindrome_edge))
	  )
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* Run all tests using the CUnit Basic interface */
   CU_basic_run_tests();
   CU_cleanup_registry();

   return CU_get_error();
}
