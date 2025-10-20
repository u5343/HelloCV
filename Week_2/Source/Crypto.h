
#include <iostream>
#include <string>

class Crypto{
    public:
    std::string caesarEnc(std::string* str,int shift){
        for(char &ch : *str){
            if(isupper(ch)){
                ch = (ch - 'A' + shift) % 26 + 'A';
            }else if(islower(ch)){
                ch = (ch - 'a' + shift) % 26 + 'a';
            }
        }
        return *str;
    }
    std::string caesarDec(std::string* str,int shift){
        for(char &ch : *str){
            if(isupper(ch)){
                ch = (26 + ch - 'A' - shift) % 26 + 'A';
            }else if(islower(ch)){
                ch = (26 + ch - 'a' - shift) % 26 + 'a';
            }
        }
        return *str;
    }
};
