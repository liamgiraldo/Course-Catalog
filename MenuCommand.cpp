//
//  MenuCommand.cpp
//  Assignment 9
//
//  Created by Liam Giraldo on 10/31/23.
//

#include "MenuCommand.h"
#include <iostream>

void MenuCommand::display(){
    //just print out the title and character
    std::cout << mPromptChar << "> " << mTitle << "\n";
}
bool MenuCommand::select(){
    //call the location pointer function action
    return action();
}
//When a MenuCommand pointer is deleted, we should say something
MenuCommand::~MenuCommand(){
    std::cout << "MenuCommand destructor: " << this->mTitle << "\n";
}

