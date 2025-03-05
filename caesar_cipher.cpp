#include <iostream>
#include <cstdint>
#include <stdlib.h>
#include <string>

std::string encode(std::string &input, int key)
{
    std::string result;
    for (char ch : input)
    {
        if (ch >= 'A' && ch <= 'Z')
        {
            result += char(((ch - 'A' + key) % 26) + 'A');
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            result += char(((ch - 'a' + key) % 26) + 'a');
        }
        else
        {
            result += ch;
        }
    }
    return result;
}

std::string decode(std::string &input, int key)
{
    std::string result;
    for (char ch : input)
    {
        if (ch >= 'A' && ch <= 'Z')
        {
            result += char(((ch - 'A' - key + 26) % 26) + 'A');
        }
        else if (ch >= 'A' && ch <= 'z')
        {
            result += char(((ch - 'a' - key + 26) % 26) + 'a');
        }
        else
        {
            result += ch;
        }
    }
    return result;

}


int main()
{
    std::cout << "Choose mode: \n"
                 "1 - Encode\n"
                 "2 - Decode\n"
                 "3 - Brute force decode (keys 0 to 26)\n";
    int mode;
    std::cin >> mode;

    int key;
    std::string input;

    if (mode == 1)
    {
        std::cout << "Enter key: ";
        std::cin >> key;
        std::cout << "Enter your text: " << std::endl;
        std::cin >> input;
        std::cout << "Here is your encoded text: \n" << encode(input, key) << std::endl;
    } 
    else if (mode == 2) 
    {
        std::cout << "Enter key: ";
        std::cin >> key;
        std::cout << "Enter your text: " << std::endl;
        std::cin >> input;
        std::cout << "Here is your decoded text: \n" << decode(input, key) << std::endl;
    } 
    else if (mode == 3) 
    {
        std::cout << "Enter your text: " << std::endl;
        std::cin >> input;

        for (int i = 0; i <= 26; i++)
        {
            std::cout << "key = " << i << std::endl;
            std::cout << decode(input, i) << std::endl;
            std::cout << "\n =================================== \n" << std::endl;
        }
    }

    return 0;
}