#include <iostream>
#include "Crypto.h"
#include <string>
#include "FileHandler.h"
#include <limits>

class Menu{
    private:
    Crypto cpt;
    FileHandler handler;
    public:
    void showMenu(){
        std::cout << "1. 文本加密" << std::endl;
        std::cout << "2. 文本解密" << std::endl;
        std::cout << "3. 文件加密" << std::endl;
        std::cout << "4. 文件解密" << std::endl;
        std::cout << "5. 退出" << std::endl;
        std::cout << "请选择功能 (1-5): ";
        int ipt;
        std::cin >> ipt;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch(ipt){
            case 1:
            textEnc();
            break;
            case 2:
            textDec();
            break;
            case 3:
            fileEnc();
            break;
            case 4:
            fileDec();
            break;
            case 5:
            printf("\n");
            break;
            default:
            printf("ERROR");
        }

    }
    void textEnc(){
        std::cout << "请输⼊要加密的⽂本：" << std::endl;
        std::string str;
        getline(std::cin,str);
        std::cout << "请输⼊密钥：" << std::endl;
        int key;
        std::cin >> key;
        std::string* ptr = & str;        
        cpt.caesarEnc(ptr,key);
        std::cout << "加密结果：" << *ptr << std::endl;
    }
    void textDec(){
        std::cout << "请输⼊要解密的⽂本：" << std::endl;
        std::string str;
        getline(std::cin,str);
        std::cout << "请输⼊密钥：" << std::endl;
        int key;
        std::cin >> key;
        std::string* ptr = & str;        
        cpt.caesarDec(ptr,key);
        std::cout << "解密结果：" << *ptr << std::endl;
    }
    void fileEnc(){
        std::cout << "请输⼊要加密的⽂件:" << std::endl;
        std::string file;
        getline(std::cin,file);
        std::cout << "请输⼊密钥：" << std::endl;
        int key;
        std::cin >> key;
        std::string str = handler.readFile(file);
        cpt.caesarEnc(&str,key);
        handler.writeFile("encrypted.txt",str);
        std::cout << "加密结果已保存到：encrypted.txt" << std::endl;
    }
    void fileDec(){
        std::cout << "请输⼊要解密的⽂件:" << std::endl;
        std::string file;
        getline(std::cin,file);
        std::cout << "请输⼊密钥：" << std::endl;
        int key;
        std::cin >> key;
        std::string str = handler.readFile(file);
        cpt.caesarDec(&str,key);
        handler.writeFile("decrypted.txt",str);
        std::cout << "解密结果已保存到：decrypted.txt" << std::endl;
    }
};