#include <gtest/gtest.h>
#include "../common.h"
#include "../sa.h"

TEST(libsatest, test_sa_has_len_field) {
#ifdef SIN6_LEN
    EXPECT_EQ(sa_has_len_field(), true);
#else
    EXPECT_EQ(sa_has_len_field(), false);
#endif
}
