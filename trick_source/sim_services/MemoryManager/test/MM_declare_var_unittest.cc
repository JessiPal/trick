/*
 * $Id: MM_declare_var_unittest.cc 3642 2014-08-21 17:03:58Z jpenn1 $
 */

#include <gtest/gtest.h>
#include "MM_test.hh"
#include "MM_user_defined_types.hh"


/*
 Test Fixture.
 */
class MM_declare_var : public ::testing::Test {
	protected:
	Trick::MemoryManager *memmgr;
		MM_declare_var() { memmgr = new Trick::MemoryManager; }
		~MM_declare_var() { delete memmgr;   }
		void SetUp() {}
		void TearDown() {}
};

/*
 This template function validates an ALLOC_INFO record created as a result
 of creating a variable using declare_var.
 */
template <typename T>
void validate_alloc_info_local(Trick::MemoryManager *memmgr,
                T *test_var,
                TRICK_TYPE trick_type,
                const char *type_name,
                const char *var_name,
                int num,
                int num_index,
                int *extent ) {

        ALLOC_INFO* alloc_info = NULL;
        alloc_info = memmgr->get_alloc_info_of(test_var);

        validate_alloc_info(alloc_info, test_var, trick_type, type_name, var_name, num, num_index, extent);

        EXPECT_EQ( alloc_info->stcl, TRICK_LOCAL) <<
                "Storage class (stcl) for a var created with var_declare should always be TRICK_LOCAL.";
}


/* ================================================================================
                                      Test Cases
   ================================================================================
*/

TEST_F(MM_declare_var, Character) {
	char *test_var = (char *)memmgr->declare_var("char");
        validate_alloc_info_local(memmgr, test_var, TRICK_CHARACTER, NULL, NULL, 1, 0, NULL);
}

TEST_F(MM_declare_var, UnsignedCharacter) {
	unsigned char *test_var = (unsigned char *)memmgr->declare_var("unsigned char");
        validate_alloc_info_local(memmgr, test_var, TRICK_UNSIGNED_CHARACTER, NULL, NULL, 1, 0, NULL);
}

TEST_F(MM_declare_var, String) {
        std::string *test_var = (std::string *)memmgr->declare_var("std::string");
        validate_alloc_info_local(memmgr, test_var, TRICK_STRING, NULL, NULL, 1, 0, NULL);
}

TEST_F(MM_declare_var, Short) {
        short *test_var = (short *)memmgr->declare_var("short");
        validate_alloc_info_local(memmgr, test_var, TRICK_SHORT, NULL, NULL, 1, 0, NULL);
}

TEST_F(MM_declare_var, UnsignedShort) {
        unsigned short *test_var = (unsigned short *)memmgr->declare_var("unsigned short");
        validate_alloc_info_local(memmgr, test_var, TRICK_UNSIGNED_SHORT, NULL, NULL, 1, 0, NULL);
}

TEST_F(MM_declare_var, Integer) {
        int *test_var = (int *)memmgr->declare_var("int");
        validate_alloc_info_local(memmgr, test_var, TRICK_INTEGER, NULL, NULL, 1, 0, NULL);
}

TEST_F(MM_declare_var, UnsignedInteger) {
        unsigned int *test_var = (unsigned int *)memmgr->declare_var("unsigned int");
        validate_alloc_info_local(memmgr, test_var, TRICK_UNSIGNED_INTEGER, NULL, NULL, 1, 0, NULL);
}

TEST_F(MM_declare_var, Long) {
        long *test_var = (long *)memmgr->declare_var("long");
        validate_alloc_info_local(memmgr, test_var, TRICK_LONG, NULL, NULL, 1, 0, NULL);
}

TEST_F(MM_declare_var, UnsignedLong) {
        unsigned long *test_var = (unsigned long *)memmgr->declare_var("unsigned long");
        validate_alloc_info_local(memmgr, test_var, TRICK_UNSIGNED_LONG, NULL, NULL, 1, 0, NULL);
}

TEST_F(MM_declare_var, Float) {
        float *test_var = (float *)memmgr->declare_var("float");
        validate_alloc_info_local(memmgr, test_var, TRICK_FLOAT, NULL, NULL, 1, 0, NULL);
}

TEST_F(MM_declare_var, Double) {
        double *test_var = (double *)memmgr->declare_var("double");
        validate_alloc_info_local(memmgr, test_var, TRICK_DOUBLE, NULL, NULL, 1, 0, NULL);
}

// Bitfields are tested elsewhere.

TEST_F(MM_declare_var, LongLong) {
        long long *test_var = (long long *)memmgr->declare_var("long long");
        validate_alloc_info_local(memmgr, test_var, TRICK_LONG_LONG, NULL, NULL, 1, 0, NULL);
}

TEST_F(MM_declare_var, UnsignedLongLong) {
        unsigned long long *test_var = (unsigned long long *)memmgr->declare_var("unsigned long long");
        validate_alloc_info_local(memmgr, test_var, TRICK_UNSIGNED_LONG_LONG, NULL, NULL, 1, 0, NULL);
}

// Hmmm. What to do with the silly TRICK_FILE_POINTER type.

TEST_F(MM_declare_var, Boolean) {
        bool *test_var = (bool *)memmgr->declare_var("bool");
        validate_alloc_info_local(memmgr, test_var, TRICK_BOOLEAN, NULL, NULL, 1, 0, NULL);
}

TEST_F(MM_declare_var, WideCharacter) {
        wchar_t *test_var = (wchar_t *)memmgr->declare_var("wchar_t");
        validate_alloc_info_local(memmgr, test_var, TRICK_WCHAR, NULL, NULL, 1, 0, NULL);
}


// Intrinsic Type Arrays

TEST_F(MM_declare_var, AnonOneDimDoubleArray) {
	double *test_var = (double *)memmgr->declare_var("double[5]");
        int extents[8] = {5,0,0,0,0,0,0,0};
        validate_alloc_info_local(memmgr, test_var, TRICK_DOUBLE, NULL, NULL, 5, 1, extents);
}

TEST_F(MM_declare_var, NamedOneDimDoubleArray) {
	double *test_var = (double *)memmgr->declare_var("double myarray[5]");
        int extents[8] = {5,0,0,0,0,0,0,0};
        validate_alloc_info_local(memmgr, test_var, TRICK_DOUBLE, NULL, "myarray", 5, 1, extents);
}

TEST_F(MM_declare_var, AnonOneDimDoublePtrArray) {
	double **test_var = (double **)memmgr->declare_var("double*[5]");
        int extents[8] = {5,0,0,0,0,0,0,0};
        validate_alloc_info_local(memmgr, test_var, TRICK_DOUBLE, NULL, NULL, 5, 2, extents);
}

TEST_F(MM_declare_var, AnonTwoDimDoubleArray) {
	double *test_var = (double *)memmgr->declare_var("double[3][4]");
        int extents[8] = {3,4,0,0,0,0,0,0};
        validate_alloc_info_local(memmgr, test_var, TRICK_DOUBLE, NULL, NULL, 12, 2, extents);
}

TEST_F(MM_declare_var, AnonThreeDimDoubleArray) {
	double *test_var = (double *)memmgr->declare_var("double[2][3][4]");
        int extents[8] = {2,3,4,0,0,0,0,0};
        validate_alloc_info_local(memmgr, test_var, TRICK_DOUBLE, NULL, NULL, 24, 3, extents);
}

// User-defined types

TEST_F(MM_declare_var, UserDefinedSingleton) {
        UDT1 *test_var = (UDT1 *)memmgr->declare_var("UDT1");
        validate_alloc_info_local(memmgr, test_var, TRICK_STRUCTURED, "UDT1", NULL, 1, 0, NULL);
}

TEST_F(MM_declare_var, UserDefinedOneDimArray) {
        UDT1 *test_var = (UDT1 *)memmgr->declare_var("UDT1[3]");
        int extents[8] = {3,0,0,0,0,0,0,0};
        validate_alloc_info_local(memmgr, test_var, TRICK_STRUCTURED, "UDT1", NULL, 3, 1, extents);
}

TEST_F(MM_declare_var, UserDefinedTwoDimArray) {
        UDT1 *test_var = (UDT1 *)memmgr->declare_var("UDT1[3][4]");
        int extents[8] = {3,4,0,0,0,0,0,0};
        validate_alloc_info_local(memmgr, test_var, TRICK_STRUCTURED, "UDT1", NULL, 12, 2, extents);
}
