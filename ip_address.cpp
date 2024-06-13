#include <iostream>
#include <sstream>

std::string ipAddress;
int octet = 0;
bool ip_address = false;
bool symbols = false;
bool allow_check = false;



void get_address_octet(){
    std::istringstream ipAdd(ipAddress);
    std::string part;
    int count_octet = 0;
    while (std::getline(ipAdd, part, '.')){
        count_octet++;
        if (count_octet == 4){
            allow_check = true;
        }
    }
    if (count_octet != 4){
        std::cout << "Invalid";
    }
}

/**/


void valid_address(){
    std::istringstream ipAdd(ipAddress);
    std::string part;
    int count_octet = 0;

    for(int i = 0; i < ipAddress.length(); i++){
        if( !((ipAddress[i] >= '0' && ipAddress[i] <= '9') || ipAddress[i] == '.' ) ){
            std::cout << "Invalid";
            symbols = false;
            break;
        } else if ( ((ipAddress[i] >= '0' && ipAddress[i] <= '9') || ipAddress[i] == '.' ) ){
            symbols = true;
        }
    }

    if(symbols == true){
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
}

void print_octet(){
    std::cout << "Input octet number: ";
    std::cin >> octet;
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



int main(){
    std::cout << "Input ip address in format xxx.xxx.xxx.xxx: ";
    std::getline(std::cin, ipAddress);
    get_address_octet();
    if (allow_check){
        valid_address();
    }
    if(ip_address){
        std::cout << "IP Address is valid\n";
        print_octet();
    }
}