#include <gtest/gtest.h>
#include "../common.h"
#include "../sa.h"

TEST(libsatest, test_sa_set_family_unspec) {
    sockaddr_in sa{.sin_family = AF_INET, .sin_port = htons(1000)};

    sa_set_family(reinterpret_cast<sockaddr *>(&sa), AF_UNSPEC);

    EXPECT_EQ(sa.sin_family, AF_UNSPEC);
}

TEST(libsatest, test_sa_set_family_ipv4) {
    sockaddr_in sa{.sin_family = AF_UNSPEC, .sin_port = htons(1000)};

    sa_set_family(reinterpret_cast<sockaddr *>(&sa), AF_INET);

    EXPECT_EQ(sa.sin_family, AF_INET);
}

TEST(libsatest, test_sa_set_family_ipv6) {
    sockaddr_in6 sa{.sin6_family = AF_UNSPEC, .sin6_port = htons(1000)};

    sa_set_family(reinterpret_cast<sockaddr *>(&sa), AF_INET6);

    EXPECT_EQ(sa.sin6_family, AF_INET6);
}
