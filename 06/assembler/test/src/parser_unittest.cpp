#include <gtest/gtest.h>
#include "parser.h"

TEST(parser, getStringFromAddAsm) {
    PARSER p = PARSER("./test/data/Add.asm"); 
    std::string st;

    EXPECT_EQ(-1, p.getLineNum());

    p.getNextLine();
    st = p.getString();    
    EXPECT_EQ(st, "// This file is part of www.nand2tetris.org");
    EXPECT_EQ(-1, p.getLineNum());
    EXPECT_EQ(EMPTY_INSTRUCTION, p.getInsType());
    EXPECT_EQ(true, p.hasNextLine());

    p.getNextLine();
    st = p.getString();
    EXPECT_EQ(st, "// and the book \"The Elements of Computing Systems\"");
    EXPECT_EQ(-1, p.getLineNum());
    EXPECT_EQ(EMPTY_INSTRUCTION, p.getInsType());
    EXPECT_EQ(true, p.hasNextLine());

    p.getNextLine();
    st = p.getString();
    EXPECT_EQ(st, "// by Nisan and Schocken, MIT Press.");
    EXPECT_EQ(-1, p.getLineNum());
    EXPECT_EQ(EMPTY_INSTRUCTION, p.getInsType());
    EXPECT_EQ(true, p.hasNextLine());

    p.getNextLine();
    st = p.getString();
    EXPECT_EQ(st, "// File name: projects/06/add/Add.asm");
    EXPECT_EQ(-1, p.getLineNum());
    EXPECT_EQ(EMPTY_INSTRUCTION, p.getInsType());
    EXPECT_EQ(true, p.hasNextLine());

    p.getNextLine();
    st = p.getString();
    EXPECT_EQ(st, "");
    EXPECT_EQ(-1, p.getLineNum());
    EXPECT_EQ(EMPTY_INSTRUCTION, p.getInsType());
    EXPECT_EQ(true, p.hasNextLine());

    p.getNextLine();
    st = p.getString();
    EXPECT_EQ(st, "// Computes R0 = 2 + 3  (R0 refers to RAM[0])");
    EXPECT_EQ(-1, p.getLineNum());
    EXPECT_EQ(EMPTY_INSTRUCTION, p.getInsType());
    EXPECT_EQ(true, p.hasNextLine());

    p.getNextLine();
    st = p.getString();
    EXPECT_EQ(st, "");
    EXPECT_EQ(-1, p.getLineNum());
    EXPECT_EQ(EMPTY_INSTRUCTION, p.getInsType());
    EXPECT_EQ(true, p.hasNextLine());

    p.getNextLine();
    st = p.getString();    
    EXPECT_EQ(st, "(START)");
    EXPECT_EQ(LABEL, p.getInsType());
    EXPECT_EQ(-1, p.getLineNum());
    EXPECT_EQ("START", p.getLabel());
    EXPECT_EQ(true, p.hasNextLine());

    p.getNextLine();
    st = p.getString();
    EXPECT_EQ(st, "    @2");
    EXPECT_EQ(0, p.getLineNum());
    EXPECT_EQ(A_INSTRUCTION, p.getInsType());
    EXPECT_EQ(true, p.hasNextLine());
    EXPECT_EQ("2", p.getNum());

    p.getNextLine();
    st = p.getString();
    EXPECT_EQ(st, "    D=A");
    EXPECT_EQ(1, p.getLineNum());
    EXPECT_EQ(C_INSTRUCTION, p.getInsType());
    EXPECT_EQ(true, p.hasNextLine());
    EXPECT_EQ("A", p.getComp());
    EXPECT_EQ("D", p.getDest());
    EXPECT_EQ("", p.getJump());

    p.getNextLine();
    st = p.getString();
    EXPECT_EQ(st, "    @3");
    EXPECT_EQ(2, p.getLineNum());
    EXPECT_EQ(A_INSTRUCTION, p.getInsType());
    EXPECT_EQ(true, p.hasNextLine());
    EXPECT_EQ("3", p.getNum());


    p.getNextLine();
    st = p.getString();
    EXPECT_EQ(st, "    D=D+A");
    EXPECT_EQ(3, p.getLineNum());
    EXPECT_EQ(C_INSTRUCTION, p.getInsType());
    EXPECT_EQ(true, p.hasNextLine());
    EXPECT_EQ("D+A", p.getComp());
    EXPECT_EQ("D", p.getDest());
    EXPECT_EQ("", p.getJump());


    p.getNextLine();
    st = p.getString();
    EXPECT_EQ(st, "    @0");
    EXPECT_EQ(4, p.getLineNum());
    EXPECT_EQ(A_INSTRUCTION, p.getInsType());
    EXPECT_EQ(true, p.hasNextLine());
    EXPECT_EQ("0", p.getNum());

    p.getNextLine();
    st = p.getString();
    EXPECT_EQ(st, "    M=D");
    EXPECT_EQ(5, p.getLineNum());
    EXPECT_EQ(C_INSTRUCTION, p.getInsType());
    EXPECT_EQ(true, p.hasNextLine());
    EXPECT_EQ("D", p.getComp());
    EXPECT_EQ("M", p.getDest());
    EXPECT_EQ("", p.getJump());


    p.getNextLine();
    st = p.getString();
    EXPECT_EQ(st, "");
    EXPECT_EQ(5, p.getLineNum());
    EXPECT_EQ(EMPTY_INSTRUCTION, p.getInsType());
    EXPECT_EQ(false, p.hasNextLine());

}

int main(int argc, char *argv[]) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
