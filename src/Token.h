#include <optional>
#include <string>
#include <ostream>

enum class TokenType
{
    RETURN,
    INT_LITERAL,
    SEMICOLON
};

struct Token
{
    Token(TokenType type, const std::optional<std::string>& value = std::nullopt)
    {
        this->type = type;
        this->value = value;
    }
    TokenType type;
    std::optional<std::string> value;
};