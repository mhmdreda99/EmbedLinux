/**
 * @file userid.cpp
 * @author Mohamed Reda (moreda491999@gmail.com)
 * @brief  print user id and info then copy it to system  path to run it from any where
 * @version 0.1
 * @date 2024-01-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
#include <unistd.h>

int main(){
    std::cout << "User ID: " << getuid() << std::endl;
    std::cout << "User name: " << getlogin() << std::endl;

    // copy the file to system path
    //system("cp userid /usr/bin");
    return 0; 
    }
    