//
//  MenuItem.h
//  Assignment 9
//
//  Created by Liam Giraldo on 10/31/23.
//

#include <stdio.h>

#ifndef MenuItem_h
#define MenuItem_h
#include <iostream>
//Instantiate the menuItem class.
class MenuItem {
    public:
    //Contains a character for the selector, and a string for the title
        MenuItem(char c,std::string t){
            mPromptChar = c;
            mTitle = t;
        };
    //These functions must be overriden by the subclasses.
        virtual bool select() = 0;
        virtual void display() = 0;
        char getPromptChar() {
            return mPromptChar;
        }
    //Destructor called upon MenuItem pointer deletion
        ~MenuItem(){
            std::cout << "MenuItem " <<mTitle <<" deleted.\n";
        }
    protected:
        char mPromptChar;
        std::string mTitle;
};
#endif /* MenuItem_h */
