//
//  Menu.h
//  Assignment 9
//
//  Created by Liam Giraldo on 10/31/23.
//

#ifndef Menu_h
#define Menu_h

#include <iostream>
#include <stdio.h>
#include "MenuItem.h"
#include <map>

//Instantiate an inherited subclass of MenuItem. Also takes in a character and a string.
class Menu : public MenuItem{
    public:
        Menu(char c, std::string t):MenuItem(c, t){
            
        }
    //We can only take in a MenuItem pointer because we cannot directly create MenuItem objects as MenuItem is an abstract class.
        void addMenuItem(std::shared_ptr<MenuItem> mItem);
        void display();
        bool select();
        bool promptUser();
    //Menu destructor
        ~Menu();
    private:
        //This is a key value pair map where each menu item can be accessed with their character key.
    //Previously done with MenuItem pointers, but is now done using a shared pointer.
        std::map<char,std::shared_ptr<MenuItem>> mItems;
};


#endif /* Menu_h */
