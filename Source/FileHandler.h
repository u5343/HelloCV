#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class FileHandler{
    private:
    std::ifstream fileReader;
    std::ofstream fileWriter;
    public:
    std::string readFile(const std::string& file){
        fileReader.open(file);
        std::stringstream ss;
        ss << fileReader.rdbuf();
        fileReader.close();
        return ss.str();
    }
    void writeFile(const std::string& file,std::string content){
        fileWriter.open(file);
        fileWriter << content;
        fileWriter.close();
    }
};