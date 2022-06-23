#include <gtest/gtest.h>
#include "code.h"


TEST(code, getNum) {
    CODE c = CODE();
    
    std::string s;
    std::string input = "3";
    s = c.getNum(input);
    EXPECT_EQ("000000000000011", s);

    input = "7";
    s = c.getNum(input);
    EXPECT_EQ("000000000000111", s);

    input = "8";
    s = c.getNum(input);
    EXPECT_EQ("000000000001000", s);
}

int main(int argc, char *argv[]) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
