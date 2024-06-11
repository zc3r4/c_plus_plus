#include <iostream>

std::string entryText = "";
std::string text;
int jump = 0;

std::string encrypt_caesar(){
    std::cout << "Input text: ";
    std::cin >> text;
    std::cout << "Input number to jump: ";
    std::cin >> jump;

    for (int i = 0; i < text.length(); i++){
            char symbol = text[i];
        if (symbol >= 'a' && symbol <= 'z'){
            symbol -= 'a';
            int x = (int)symbol + jump;
            x = x % 26;
            symbol = (char)x + 'a';
            entryText = entryText + symbol;
            

        } else if (symbol >= 'A' && symbol <= 'Z'){
            symbol -= 'A';
            int x = (int)symbol + jump;
            x = x % 26;
            symbol = (char)x + 'A';
            entryText = entryText + symbol;
        } else {} 
    } 
    return entryText;
}


int main(){
    std::cout << encrypt_caesar();
}