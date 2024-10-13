#define ErrorMessege "There is no common prefix among the input strings."


#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using std::string;
using std::vector;


string massiveReading(string mass) 
{
    string prefix;
    string word;
    string newPrefix;
    short emptyWordErrorCheck = 0;


    for (char letter : mass)
    {
        if (letter == '"' || letter == '[')
        {
            emptyWordErrorCheck++;
            if (emptyWordErrorCheck >= 4) return ErrorMessege;
            continue;
        }
        emptyWordErrorCheck = 0;

        if (letter == ',' || letter == ']')
        {
            // Операция на случай самого первого слова
            if (prefix.size() == 0)
            {
                prefix = word;
                word.clear();
                continue;
            }

            newPrefix.clear();

            for (short i = 0; i < std::min(prefix.size(), word.size()); i++)
            {
                if (prefix[i] != word[i])
                {
                    if (i == 0)
                        return ErrorMessege;

                    break;
                }
                newPrefix.push_back(prefix[i]);
            }
            prefix = newPrefix;
            word.clear();
        }

        else 
            word.push_back(letter);
    }
    return prefix;
};

int main() {
    
    string mass;
    
    std::getline(std::cin, mass);

    std::cout << massiveReading(mass);

}


