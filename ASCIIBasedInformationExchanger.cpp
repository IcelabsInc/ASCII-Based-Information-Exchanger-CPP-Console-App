#include <iostream>
#include <string>

#define CHARACTERSLENGTH 94

// I know it is not a good practice. There is an easy way of doing this but it is just for explanation purposes.
char asciiCharacters[CHARACTERSLENGTH] = {' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}'};
int asciiCharactersDecimalForm[CHARACTERSLENGTH] = {32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125};


std::string DecimalToBinary(int number)
{
    // Help to convert decimal number to binary number.
    if (number == 0)
        return "0";
    if (number == 1)
        return "1";

    if (number % 2 == 0)
        return DecimalToBinary(number / 2) + "0";
    else
        return DecimalToBinary(number / 2) + "1";
}

int BinaryToDecimal(std::string number)
{
    // Helps to convert a binary number into decimal number.
    int result = 0, pow = 1;
    for (int i = number.length() - 1; i >= 0; --i, pow <<= 1)
        result += (number[i] - '0') * pow;

    return result;
}

void Encode()
{
    // Helps to encode the text to ASCII standard.
    std::string text;

    // getting input from user.
    std::cout << "--> Enter your text to encode:\n";
    std::getline(std::cin, text);

    std::cout << "--> Encoding your input using ASCII standard.\n\n";

    int arrayLength = text.length();

    std::string binaryForm = "";

    for (int character = 0; character < arrayLength; character++)
    {
        for (int asciiChar = 0; asciiChar < CHARACTERSLENGTH; asciiChar++)
        {
            if (asciiCharacters[asciiChar] == text[character])
            {
                std::string encodedCharacter = DecimalToBinary(asciiCharactersDecimalForm[asciiChar]);

                for (int done = encodedCharacter.length(); done < 8; done++)
                {
                    binaryForm += "0";
                }

                binaryForm += encodedCharacter;

                break;
            }
        }
    }

    std::cout << "Your encoded text with ASCII standard is " << binaryForm << std::endl;
}

void Decode()
{
    // Helps to decode the text to ASCII standard.
    std::string text;

    // getting input from user.
    std::cout << "--> Enter your binary to decode:\n";
    std::getline(std::cin, text);

    std::cout << "--> Decoding your input using ASCII standard.\n\n";

    int charactersLength = text.length() / 8;

    // Extracting each character binary code.
    int characterCount = 0;
    int numCount = 0;

    std::string characterArray[charactersLength];

    for (int i = 0; i < text.length(); i++)
    {
        if (numCount == 8)
        {
            characterCount++;
            numCount = 0;
        }

        characterArray[characterCount] += text[i];
        numCount++;
    }

    // Converting the characters from binary to number and then to characters.
    std::string decodedText = "";
    
    for (int character = 0; character < charactersLength; character++)
    {
        int charNumber = BinaryToDecimal(characterArray[character]);

        for (int asciiChar = 0; asciiChar < CHARACTERSLENGTH; asciiChar++)
        {
            if (charNumber == asciiCharactersDecimalForm[asciiChar])
            {
                decodedText += asciiCharacters[asciiChar];
                break;
            }
        }
    }

    std::cout << "Your decoded text with ASCII standard is " << decodedText << std::endl;
}

int main()
{
    while (true)
    {
        int userChoice;
        
        std::cout << "*********************** START ***********************";
        std::cout << std::endl;

        std::cout << "--> Enter 0 for Encoding, 1 for Decoding and 2 for Quitting:\n";
        std::cin >> userChoice;

        // This will fix getline error.
        std::cin.ignore();

        if (userChoice == 0)
        {
            Encode();
        }
        else if (userChoice == 1)
        {
            Decode();
        }
        else if (userChoice == 2)
        {
            break;
        }
        else
        {
            std::cout << "--> You entered an invalid input.\n";
        }
        std::cout << "*********************** END ***********************";
        std::cout << std::endl << std::endl;
    }

    return 0;
}

