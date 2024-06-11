#include <iostream>

std::string email;
bool validate = false;
bool glValid = false;

void email_check(){
    std::cout << "Input email:";
    std::cin >> email;
    int countDogs = 0;
    

    for (int j = 0; j < email.length(); j++){
        
        if (email[j] == '@'){
            countDogs++;
            if (countDogs == 1) {
                validate = true;
            } else {validate = false; break;}
        }

        if (email.find('@') > 0 && email.find('@') < 64){
            validate = true;
        } else {validate = false; break;} 

        if (email.length() <= 128) {
            validate = true;
        } else {validate = false; break;}

        if (!(email[0] == '.' || email[email.find('@') - 1] == '.')){
            validate = true;
        } else {validate = false; break;}

        if (email[j] == '.' && email[j + 1] == '.'){
            validate = false;
            break;
        }

        for (int l = 0; l < email.find('@'); l++){ 
            if (email[l] == 33 || email[l] == 35 || email[l] == 36 || email[l] == 37 || email[l] == 38 || email[l] == 39 || email[l] == 42 || email[l] == 43 || email[l] == 45 ||
                    email[l] == 47 || email[l] == 61 || email[l] == 63 || email[l] == 94 || email[l] == 95 || email[l] == 96 || email[l] == 123 || email[l] == 124 ||
                    email[l] == 125 || email[l] == 126){
                        validate = true;
            }
        }



    }
}

void second_chapter(){
    if (validate){
        for (int i = email.find('@') + 1; i < email.length(); i++){

            if (!(email[email.find('@') + 1] == '.' || email[email.length() - 1] == '.')){
                glValid = true;
            } else {glValid = false; break;}

            if (email[i] == '.' && email[i + 1] == '.'){
            validate = false;
            break;
        }

            if ((email[i] >= 97 && email[i] <= 122) || email[i] == 46 || email[i] == 45){
                glValid = true;
            } else {glValid = false; break;}
        }
    }
}

int main(){
    email_check();
    second_chapter();
    if (glValid){
        std::cout << "Yes";
    } else {std::cout << "No";}
}