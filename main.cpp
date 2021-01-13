#include <iostream>
#include <fstream>

#include "libs/md5.h"

#define PASSWD_FILE "password.txt"
#define PASSWD_MAX_SIZE 32

int check_password(std::string user_password);
std::string read_password_from_file(std::string filename);

int main(int argc, char const *argv[]){
    if (argc < 2) {
        std::cout << "Add your password in start parameter!!!" << std::endl;
        return 0;
    }

    std::string user_password = md5(argv[1]);
    std::cout << "Your password's MD5 hash: " << user_password << std::endl;

    if (check_password(user_password) == 0) 
        std::cout << "Password correct!" << std::endl;
    else
        std::cout << "Password incorrect!" << std::endl;

    return 1;
}

int check_password(std::string user_password) {
    std::string true_password = read_password_from_file(PASSWD_FILE);
    return true_password.compare(user_password);
}

std::string read_password_from_file(std::string filename){
    std::string password;
    std::ifstream passwd_file;

    passwd_file.open(filename);
    passwd_file >> password;
    passwd_file.close();

    return password;
}