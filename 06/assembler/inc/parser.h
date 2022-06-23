#if !defined(__PARSER_H__)
#define __PARSER_H__

#include <string>
#include <fstream>
#include <iostream>
#include <cassert>

typedef enum {
    A_INSTRUCTION,
    C_INSTRUCTION,
    LABEL,
    EMPTY_INSTRUCTION 
} INSTRUCTION_TYPE;


class PARSER {

private:
    std::ifstream *f;
    std::string nowIns;
    int lineNum; 

public:
    PARSER(std::string fileName) {
        f = new std::ifstream(fileName);
        assert(f->is_open());

        lineNum = -1;
    }
    ~PARSER() {
        f->close();
        delete f;
    }

    INSTRUCTION_TYPE getInsType(void) {
        int index = 0;
        while(index < nowIns.size() && ' ' == nowIns[index]) {
            index++;
        }
        if(index == nowIns.size()) {
            return EMPTY_INSTRUCTION;
        } else if('/' == nowIns[index] && '/' == nowIns[index + 1]) {
            return EMPTY_INSTRUCTION;
        } else if('@' == nowIns[index]) {
            return A_INSTRUCTION;
        } else if('(' == nowIns[index]) {
            return LABEL;
        } else {
            return C_INSTRUCTION;
        }
    }

    bool hasNextLine(void) {
        int c = f->peek(); 
        return c == EOF ? false : true;
    }

    void getNextLine(void) {
        getline(*f, nowIns);
        INSTRUCTION_TYPE insType = getInsType();
        if(A_INSTRUCTION == insType ||
           C_INSTRUCTION == insType) {
            lineNum++;
        }
    }

    std::string getString(void) {
        return nowIns;
    }

    int getLineNum(void) {
        return lineNum;
    }

    // for A-instruction
    std::string getNum(void) {
        std::string res; 
        int index = -1;
        for(int i = index + 1;i < nowIns.size();i++) {
            if('@' == nowIns[i]) {
                index = i;
                break;
            }
        }

        for(int i = index + 1;i < nowIns.size();i++) {
            if(' ' == nowIns[i]) {
                continue;
            }

            if('/' == nowIns[i] && i + 1 < nowIns.size() && '/' == nowIns[i + 1]) {
                break;
            }

            res += nowIns[i];
        }
        return res;
    }
   
    // for C-instruction
    std::string getComp(void) {
        std::string res;
        int index = -1;
        for(int i = 0;i < nowIns.size();i++) {
            if(' ' == nowIns[i]) {
                continue;
            }

            if('=' == nowIns[i]) {
                index = i;
                break;
            }
        }
        index++;
        for(int i = index;i < nowIns.size() && ';' != nowIns[i];i++) {
            if(' ' == nowIns[i]) {
                continue;
            }

            if('/' == nowIns[i] && i + 1 < nowIns.size() && '/' == nowIns[i + 1]) {
                break;
            }

            res += nowIns[i];
        }

        return res;
    }

    std::string getDest(void) {
        std::string res;
        int index = 0;
        for(int i = 0;i < nowIns.size();i++) {
            if(' ' == nowIns[i]) {
                continue;
            }

            if('=' == nowIns[i]) {
                index = i;
                break;
            }
        }
       
        for(int i = 0;i < index;i++) {
            if(' ' == nowIns[i]) {
                continue;
            }

            if('/' == nowIns[i] && i + 1 < nowIns.size() && '/' == nowIns[i + 1]) {
                break;
            }

            res += nowIns[i];
        }
 
        return res;
    }

    std::string getJump(void) {
        int index = 0;
        std::string res;
        for(index = 0;index < nowIns.size();index++) {
            if(' ' == nowIns[index]) {
                continue;
            }

            if(nowIns[index] == ';') {
                break;
            }
        }
        index++;
        for(int i = index;i < nowIns.size();i++) {
            if(' ' == nowIns[i]) {
                continue;
            }

            if('/' == nowIns[i] && i + 1 < nowIns.size() && '/' == nowIns[i + 1]) {
                break;
            }

            res += nowIns[i];
        }
        
        return res;
    }

    // for Label
    std::string getLabel(void) {
        std::string res;
        for(int i = 0;i < nowIns.size() && ')' != nowIns[i];i++) {
            if(' ' == nowIns[i] || '(' == nowIns[i]) {
                continue;
            }

            res += nowIns[i];
        }
        return res;
    }
};

#endif /* __PARSER_H__ */
