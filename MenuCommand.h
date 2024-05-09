//
//  MenuCommand.h
//  Assignment 9
//
//  Created by Liam Giraldo on 10/31/23.
//

#ifndef MenuCommand_h
#define MenuCommand_h

#include <stdio.h>
#include <iostream>
#include "MenuItem.h"
#include <functional>

//Instantiate an inherited sublcass MenuCommand of MenuItem
class MenuCommand : public MenuItem{
public:
    //Our constructor can handle taking in a function, which is the action that is executed upon selecting this option.
    MenuCommand(char c, std::string t, std::function<bool()> f):MenuItem(c, t){
        action = f;
    }
    //Destructor
    ~MenuCommand();
    //only need to reimplement these two.
    void display();
    bool select();
private:
    std::function<bool()> action;
};

#endif /* MenuCommand_h */
