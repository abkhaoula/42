#include <iostream>
#include <limits>
#include <cfloat>
#include <cstdlib>
#include <climits>

using namespace std;

int     isInt(std::string &input)
{
    int i = 0;
    if (input[i] == '-' || input[i] == '+')
        i++;
    while (input[i])
    {
        if (!isdigit(input[i]) || input[i] == '-' || input[i] == '+')
        {
            return (0);
        }
        else
            i++;
    }
    return (1);
}

int     isFloat(std::string &literal)
{
    int i = 0;
    int dot = 0;
    if (literal[i] == '-' || literal[i] == '+')
        i++;
    while (literal[i])
    {
        if (literal[i] == '.')
        {
            i++;
            dot++;
        }
        if ((literal[i] == 'f' || literal[i] == 'F') && (size_t)(i + 1) == literal.size())
        {
            i++;
            continue;
        }
        if (!isdigit(literal[i++]))
            return (0);
    }
    if (dot > 1)
        return (0);
    return (1);
}

int     isDouble(std::string &literal)
{
    int i = 0;
    int dot = 0;
    if (literal[i] == '-' || literal[i] == '+')
        i++;
    while (literal[i])
    {
        if (literal[i] == '.')
            dot++;
        else if (!isdigit(literal[i]))
            return (0);
        i++;
    }
    if (dot > 1)
        return (0);
    return (1);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Please provide a valid literal as an argument." << endl;
        return (1);
    }

    string input = argv[1];

    
    if (input == "inf" || input == "inff" || input == "infl")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << "inff" << std::endl;
        std::cout << "double: " << "inf" << std::endl;
        return (0);
    }
    else if (input == "-inf" || input == "-inff" || input == "-infl")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << "-inff" << std::endl;
        std::cout << "double: " << "-inf" << std::endl;
        return (0);
    }
    else
    {
        char c = 0;
        int i = 0;
        float f = 0.0f;
        double d = 0.0;
        // is displayable char (what if I type some bulshit)
        if (input.length() == 1 and ((input[0] <= 47 and input[0] >= 32) or (input[0] <= 126 and input[0] >= 58))) 
        {
            c = input[0];
            i = static_cast<int>(c);
            f = static_cast<float>(i);
            d = static_cast<double>(i);
        }
        // is int
        else if (isInt(input))
        {
            i = std::stod(input);
            c = static_cast<char>(i);
            f = static_cast<float>(i);
            d = static_cast<double>(i);
        }
        // is double
        else if (isDouble(input))
        {
            d = std::stod(input);
            f = static_cast<float>(d);
            i = static_cast<int>(d);
            if (d == static_cast<double>(i))
                c = static_cast<char>(i);
        }
        // is float
        else if (isFloat(input))
        {
            f = std::stof(input);
            d = static_cast<double>(f);
            i = static_cast<int>(f);
            if (f == static_cast<float>(i))
                c = static_cast<char>(i);

        }
        else
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return (0);
        }


        // Displaying the char
        std::cout << "char: ";
        if ((c >= 32 && c <= 47) || (c >= 58 && c <= 126))
            std::cout << "'" <<  c << "'" << std::endl;
        else if (c < 32 || c > 126 || (c >= 48 && c <= 57))
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "impossible" << std::endl;
        
        // Displaying the int
        std::cout << "int: ";
        if (i >= INT_MIN && i <= INT_MAX)
            std::cout << i << std::endl;
        else
            std::cout << "impossible" << std::endl;
        
        // Displaying the float
        std::cout << "float: ";
        if (f >= -FLT_MIN && f <= FLT_MAX)
        {
            if (i == f)
                std::cout << f << ".0f" << std::endl;
            else
                std::cout << f << "f" << std::endl;
        }
        else
            std::cout << "impossible" << std::endl;
        
        // Displaying the double
        std::cout << "double: ";
        if (d >= -DBL_MIN && d <= DBL_MAX)
        {
            if (d == f)
                std::cout << d << ".0" << std::endl;
            else
                std::cout << d << std::endl;
        }
        else
            std::cout << "impossible" << std::endl;
        
    }

    return 0;
}