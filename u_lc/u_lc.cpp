#include <iostream>
#include <fstream>
#include <future>

int linesInFile(const std::string& fileName);

int main(int argc, char* argv[]){

    int resultLinesCount = 0;

    if (argc == 1){

        std::cout<<"u_lc <filename>/-c(take data from pipline)"<<std::endl;
        return 1;

    }else if(argc == 2 && std::string(argv[1]) == std::string("-c")){

        while (std::cin){
            std::string strFileName;
            std::cin >> strFileName;

            int fileLineCount = linesInFile(strFileName);
            std::cout << strFileName << " " << fileLineCount << std::endl;

            resultLinesCount += fileLineCount;
        }

    }else{
        while(argc>2,--argc)
            resultLinesCount += linesInFile(std::string(argv[argc]));
    }

    std::cout << resultLinesCount << std::endl;

    return 0;
}

int linesInFile(const std::string& fileName){

    int resultLinesCount = 0;

    std::ifstream fileToRead;
    fileToRead.open(fileName, std::ios::in);

    std::string stringFromFile;
    if (fileToRead.is_open())
        while(std::getline(fileToRead, stringFromFile))
            ++resultLinesCount;

    fileToRead.close();

    return resultLinesCount;
}
