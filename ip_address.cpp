#include <iostream>
#include <sstream>

std::string ipAddress;
int octet = 0;
bool ip_address = false;

void get_address_octet(){
    std::istringstream ipAdd(ipAddress);
    std::string part;
    int count_octet = 0;
    while (std::getline(ipAdd, part, '.')){
        count_octet++;
        if (count_octet == octet){
            std::cout << "Number is: " << std::stoi(part);
        }
    }
}


void valid_address(){
    std::cout << "Input ip adress in format xxx.xxx.xxx.xxx: ";
    std::getline(std::cin, ipAddress);
    std::cout << "Input octet number: ";
    std::cin >> octet;

    std::istringstream ipAdd(ipAddress);
    std::string part;
    int count_octet = 0;

    while(getline(ipAdd, part, '.')){
        int number;
        if (std::istringstream(part) >> number){
            if (number >= 0 && number <= 255){
                ip_address = true;
            } else {
                std::cout << "Invalid";
                ip_address = false;
                break;
            }
        } else {std::cout << "Invalid"; break;}
    }
}



int main(){
    valid_address();

    if (ip_address){
        get_address_octet();
    }
}