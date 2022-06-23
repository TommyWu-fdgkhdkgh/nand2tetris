#include <iostream>

#include "parser.h"
#include "code.h"
#include "symbolTable.h"



int main(int argc, char *argv[]) {

    if(2 != argc) {
        std::cout << "argv error!" << std::endl;
        return 1;
    }

    std::string nameOfAsm(argv[1]);
    PARSER *p = new PARSER(nameOfAsm);
    CODE *c = new CODE(); 
    SymbolTable *symT = new SymbolTable();


    while(p->hasNextLine()) {
        p->getNextLine();
        // std::cout << p->getString() << std::endl;
        if(LABEL == p->getInsType()) {
            std::string label = p->getLabel();
            int lineNum = p->getLineNum(); 
            symT->setSymbol(label, lineNum + 1);
            // std::cout << "label : " << label << ", value : " << symT->getValueOfSymbol(label) << std::endl;
        }
    }

    delete p;
    std::string binary;

    p = new PARSER(nameOfAsm);
    while(p->hasNextLine()) {
        std::string binOne;

        p->getNextLine();
        if(A_INSTRUCTION == p->getInsType()) {
            std::string num = p->getNum();    
            binOne += "0";
            if(num[0] >= '0' && num[0] <= '9') {
                binOne += c->getNum(num);
                // std::cout << binOne << std::endl;
            } else {
                std::string symbol = p->getNum(); 
                symT->addVariable(symbol);
                symbol = std::to_string(symT->getValueOfSymbol(symbol));
                binOne += c->getNum(symbol);
            }
            binOne += "\n";
        } else if(C_INSTRUCTION == p->getInsType()) {
            binOne += "111";
            std::string tmp;

            tmp = p->getComp();
            // std::cout << "comp : " << tmp << std::endl;
            binOne += c->getComp(tmp);
            
            tmp = p->getDest();
            // std::cout << "dest : " << tmp << std::endl;
            binOne += c->getDest(tmp);
        
            tmp = p->getJump();
            // std::cout << "jump : " << tmp << std::endl;
            binOne += c->getJump(tmp);  

            binOne += "\n";
        }

        binary += binOne;
    }   
    
    std::cout << binary;
   
    delete p;
    delete c;
    delete symT;

    return 0;
}
