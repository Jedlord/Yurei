#include "Token.h"
#include <vector>
#include <iostream>

std::vector<Token> lex(const std::string& src)
{
    std::vector<Token> tokens;
    for (int i = 0; i < src.length(); i++)
    {
        std::string buff;
        char c = src.at(i);

        if(std::isspace(c))
        {
            continue;
        }

        else if (std::isalpha(c))
        {
            buff.push_back(c);
            i++; c = src.at(i);
            while (std::isalnum(c))
            {
                buff.push_back(c);
                i++; c = src.at(i);
            }
            i--;

            if (buff == "return")
            {
                tokens.push_back(Token(TokenType::RETURN));
                buff.clear();
                continue;
            }
            else
            {
                std::cerr << "No valid token can be made from \"" << buff << "\"" << std::endl;
                exit(EXIT_FAILURE);
            }
        }

        else if (std::isdigit(c))
        {
            buff.push_back(c);
            i++; c = src.at(i);
            while (std::isdigit(c))
            {
                buff.push_back(c);
                i++; c = src.at(i);
            }
            i--;
            tokens.push_back(Token(TokenType::INT_LITERAL, buff));
            buff.clear();
        }

        else if (c == ';')
        {
            tokens.push_back(Token(TokenType::SEMICOLON));
        }

        else
        {
            std::cerr << "No tokens could be generated" << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    
    return tokens;
}