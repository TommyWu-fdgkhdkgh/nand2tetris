#if !defined(__CODE_H__)
#define __CODE_H__

#include <string>
#include <iostream>

// translate string to binary
class CODE {
public:
    // for A-instruction
    std::string getNum(std::string &s) {
        int num = atoi(s.c_str());
        std::string res;
        while(num != 0) {
            res = std::to_string(num % 2) + res;
            num /= 2;
        }

        while(15 != res.size()) {
            res = "0" + res;
        }

        return res;
    }

    // for C-instruction
    std::string getComp(std::string &s) {
        if("0" == s) {
            return "0101010"; 
        } else if("1" == s) {
            return "0111111";
        } else if("-1" == s) {
            return "0111010";
        } else if("D" == s) {
            return "0001100";
        } else if("A" == s) {
            return "0110000";
        } else if("!D" == s) {
            return "0001101";
        } else if("!A" == s) {
            return "0110001";
        } else if("-D" == s) {
            return "0001111";
        } else if("-A" == s) {
            return "0110011";
        } else if("D+1" == s) {
            return "0011111";
        } else if("A+1" == s) {
            return "0110111";
        } else if("D-1" == s) {
            return "0001110";
        } else if("A-1" == s) {
            return "0110010";
        } else if("D+A" == s) {
            return "0000010";
        } else if("D-A" == s) {
            return "0010011";
        } else if("A-D" == s) {
            return "0000111";
        } else if("D&A" == s) {
            return "0000000";
        } else if("D|A" == s) {
            return "0010101";
        } else if("M" == s) {
            return "1110000";
        } else if("!M" == s) {
            return "1110001";
        } else if("-M" == s) {
            return "1110011";
        } else if("M+1" == s) {
            return "1110111";
        } else if("M-1" == s) {
            return "1110010";
        } else if("D+M" == s) {
            return "1000010";
        } else if("D-M" == s) {
            return "1010011";
        } else if("M-D" == s) {
            return "1000111";
        } else if("D&M" == s) {
            return "1000000";
        } else if("D|M" == s) {
            return "1010101";
        }
        return "";
    }

    std::string getDest(std::string &s) {
        if("" == s) {
            return "000"; 
        } else if("M" == s) {
            return "001"; 
        } else if("D" == s) {
            return "010"; 
        } else if("MD" == s) {
            return "011"; 
        } else if("A" == s) {
            return "100"; 
        } else if("AM" == s) {
            return "101"; 
        } else if("AD" == s) {
            return "110"; 
        } else if("AMD" == s) {
            return "111"; 
        }
        return "";
    }

    std::string getJump(std::string &s) {
        if("" == s) {
            return "000";
        } else if("JGT" == s) {
            return "001";
        } else if("JEQ" == s) {
            return "010";
        } else if("JGE" == s) {
            return "011";
        } else if("JLT" == s) {
            return "100";
        } else if("JNE" == s) {
            return "101";
        } else if("JLE" == s) {
            return "110";
        } else if("JMP" == s) {
            return "111";
        }
        return "";
    }
};

#endif /* __CODE_H__ */
