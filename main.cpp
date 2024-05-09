//
//  main.cpp
//  Assignment 9
//
//  Created by Liam Giraldo on 10/31/23.
//

#include <iostream>
#include "CourseCatalog.h"
#include "Menu.h"
#include "MenuCommand.h"
int main(int argc, const char * argv[]) {
    //Create a course catalog object
    CourseCatalog catalog;
    //Create a menu called mainMenu
    Menu mainMenu('0',"Main");
    //Create a submenu
    std::shared_ptr<Menu> courseMenuPtr(new Menu('2',"Edit Courses"));
    //Add 5 options to the submenu
    courseMenuPtr->addMenuItem(std::shared_ptr <MenuCommand>(new MenuCommand('1',"Edit Course Name",[&catalog]()->bool{
        //This is a lambda expression. It allows us to pass an anonymous function into our class.
        //This function just prints out the course name and returns true to continue prompting.
        catalog.editCourseName();
        return true;
    })));
    courseMenuPtr->addMenuItem(std::shared_ptr<MenuCommand>(new MenuCommand('2',"Edit Course Title",[&catalog]()->bool{
        //Just like the previous one, just different option
        catalog.editCourseTitle();
        return true;
    })));
    courseMenuPtr->addMenuItem(std::shared_ptr<MenuCommand>(new MenuCommand('3',"Edit Course Instructor", [&catalog]()->bool{
        catalog.editCourseInstructor();
        return true;
    })));
    courseMenuPtr->addMenuItem(std::shared_ptr<MenuCommand>(new MenuCommand('4',"Edit Course Enrollment", [&catalog]()->bool{
        catalog.editCourseEnrollment();
        return true;
    })));
    courseMenuPtr->addMenuItem(std::shared_ptr<MenuCommand>(new MenuCommand('b',"Back",[]()->bool{
        //we want to return false here because we don't want to continue prompting in the current menu
        return false;
    })));
    //Add 4 more options to the main menu
    mainMenu.addMenuItem(std::shared_ptr<MenuCommand>(new MenuCommand('1',"List Courses", [&catalog]()->bool{
        catalog.listCourses(); return true;
    })));
    mainMenu.addMenuItem(courseMenuPtr);
    mainMenu.addMenuItem(std::shared_ptr<MenuCommand>(new MenuCommand('3',"Add New Course", [&catalog]()->bool{
        catalog.addNewCourse();
        return true;
    })));
    mainMenu.addMenuItem(std::shared_ptr<MenuCommand>(new MenuCommand('4',"Remove Course", [&catalog]()->bool{
        catalog.removeCourse();
        return true;
    })));
    mainMenu.addMenuItem(std::shared_ptr<MenuCommand>(new MenuCommand('Q',"Quit",[]()->bool{
        //we don't want to continue prompting at all
        return false;
    })));
    //Select the mainMenu, starting the loop
    mainMenu.select();
}
