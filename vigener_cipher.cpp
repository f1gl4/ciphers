#include <iostream>
#include <cstdint>
#include <stdlib.h>
#include <string>

std::string encode(std::string &input, std::string &key)
{
    std::string result;
    int i = 0;
    for (auto ch : input)
    {
        if (ch >= 'A' && ch <= 'Z')
        {
            result += (((ch - 'A') + (key[i] - 'A')) % 26) + 'A';
            i++;
        }

        if (i >= key.length()) i = 0;
        //std::cout << i << " " << key << std::endl;
    }

    return result;
}

std::string decode(std::string &input, std::string &key)
{
    std::string result;
    int i = 0;
    for (auto ch : input)
    {
        if (ch >= 'A' && ch <= 'Z')
        {
            result += (((ch - 'A') - (key[i] - 'A') + 26) % 26) + 'A';
            i++;
        }

        if (i >= key.length()) i = 0;
        //std::cout << i << " " << key << std::endl;
    }

    return result;
}

std::string text = "SLUNECNEATEPLEPOCASICTVRTKEMPROZATIMKONCIVNASLEDUJICICHDVOUDNECHSEZATAHNEVETSI"
"NUUZEMIZASAHNEDESTNAHORACHANASEVEROVYCHODEVEVSECHPOLOHACHSNIHOVIKENDUBUDEP"
"OLOJASNOTEPLOTYVNOCIKLESNOUPODNULUPRESDENBUDEMAXIMALNESESTSTUPNU";

int main()
{
    //std::string key_vigener = "ZIMA";
    //std::cout << encode(text, key_vigener) << std::endl;

    std::cout << "Choose mode: \n"
                 "1 - Encode\n"
                 "2 - Decode\n";
    int mode;
    std::cin >> mode;

    std::string key_vigener;
    std::string input;

    if (mode == 1)
    {
        std::cout << "Enter key: ";
        std::cin >> key_vigener;
        //std::cout << "Enter your text: " << std::endl;
        //std::cin >> input;
        std::cout << "Here is your encoded text: \n" << encode(text, key_vigener) << std::endl;
    } 
    else if (mode == 2) 
    {
        std::cout << "Enter key: ";
        std::cin >> key_vigener;
        std::cout << "Enter your text: " << std::endl;
        std::cin >> input;
        std::cout << input << std::endl;
        std::cout << "Here is your decoded text: \n" << decode(input, key_vigener) << std::endl;
    } 

    return 0;
}