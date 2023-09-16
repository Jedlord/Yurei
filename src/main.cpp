#include <iostream>
#include <fstream>
#include <sstream>
#include "Lexer.h"

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        std::cerr << "Incorrect usage" << std::endl;
        std::cerr << "Usage: yurei <input.yr>" << std::endl;
        return EXIT_FAILURE;
    }

    std::string contents;
    { // read file
        std::stringstream contentStream;
        std::fstream input(argv[1], std::ios::in);
        contentStream << input.rdbuf();
        input.close();
        contents = contentStream.str();
    }

    //std::cout << contents << std::endl;

    std::vector<Token> tokens = lex(contents);

    return EXIT_SUCCESS;
}