//
//  Menu.cpp
//  Assignment 9
//
//  Created by Liam Giraldo on 10/31/23.
//

#include "Menu.h"

#include <iostream>
#include "MenuItem.h"
//Create a map type and iterator type that we can use to create objects to add to our map.
typedef std::map<char,std::shared_ptr<MenuItem>>::value_type Item;
typedef std::map<char,std::shared_ptr<MenuItem>>::iterator ItemIterator;
void Menu::addMenuItem(std::shared_ptr<MenuItem> item){
    //Create a variable of Item type that we can insert into our map
    Item newItem(item->getPromptChar(), item);
    mItems.insert(newItem);
};
void Menu::display(){
    //Calling display on a Menu will display it's character, title, and a >
    std::cout << mPromptChar << "> " << mTitle << ">\n";
}
bool Menu::promptUser(){
    bool result;
    char choice;
    //First we prompt the user to enter a choice
    std::cout << "\nEnter Choice: ";
    std::cin >>  choice;
    ItemIterator p = mItems.find(choice);
    //If the user's selected choice is in our map
    if(p != mItems.end()){
        //then select that choice.
        //If the option selected is not Quit or Back, result will be true, otherwise false.
        result = p->second->select();
        //Result tells us whether we should continue prompting the user or not.
        //If result is true, we should continue prompting the user to select an option.
        //If result is false, we should stop.
        return result;
    }
//    }
    std::cout << "Invalid choice \n";
    return true;
}
bool Menu::select(){
    bool keepGoing = true;
    //This loop runs until the user selects Quit or Back
    while(keepGoing){
        //First, print out the title of the current menu we are on.
        std::cout << "==== "<< mTitle << " MENU ====\n";
        //Display all of the menuItem options within our current menu.
        for(auto i : mItems){
            i.second->display();
        }
        //Then, prompt the user. If the selected option is Quit or Back, we stop this select loop.
        if(this->promptUser() == false){
            break;
        }
    }
    //Otherwise, we want to continue prompting the user.
    return true;
}
//Called when a Menu is deleted from memory
Menu::~Menu(){
    std::cout << "Menu destructor: " << this->mTitle << "\n";
}
