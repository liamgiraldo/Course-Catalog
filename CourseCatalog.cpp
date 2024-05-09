//
//  CourseCatalog.cpp
//  Assignment 9
//
//  Created by Liam Giraldo on 10/31/23.
//

#include "CourseCatalog.h"

#include <stdio.h>
#include <iostream>
#include "Course.h"
#include <vector>
//We have to create a type that we can insert into our map
typedef std::map<std::string,Course>::value_type NCourse;
//We also have to created a type that we can use as a map iterator
//(ok we don't really have to but I did it anyways)
typedef std::map<std::string,Course>::iterator CourseIterator;
void CourseCatalog::listCourses(){
    std::cout << "Courses\n";
    std::cout << "================================================================\n";
    //We use a for loop to go through each of the courses in the vector and print out their important information.
    //I use auto to automatically set the type
    for(auto i : mCourses){
        std::cout << i.second.getCourseName() << " " << i.second.getCourseTitle() << " " << i.second.getInstructor() << " (" << i.second.getStudentCount() << ")\n";
    }
}
void CourseCatalog::addNewCourse(){
    //The user inputs their course information here
    std::cout << "Add New Course\n";
    std::string string;
    Course course;
    std::cout << "Course Name:";
    //getline is used to take in strings
    std::cin.ignore();
    getline(std::cin, string);
    course.setCourseName(string);
    std::cout << "Course Title:";
    getline(std::cin, string);
    course.setCourseTitle(string);
    std::cout << "Course Instructor:";
    getline(std::cin, string);
    course.setInstructor(string);
    int num;
    std::cout << "Student Count:";
    //regular cin is for not strings
    std::cin>>num;
    course.setStudentCount(num);
    //create the course map object to be added into mCourses
    NCourse c1(course.getCourseName(), course);
    //insert it
    mCourses.insert(c1);
    std::cin.ignore();
}
void CourseCatalog::removeCourse(){
    std::string string;
    std::cout << "Enter the name of the course to remove: ";
    std::cin.ignore();
    getline(std::cin, string);
    CourseIterator p = mCourses.find(string);
    //If we can find the course that the user inputted, erase it
    if(p != mCourses.end()){
        std::cout << "Removing " << string << "\n";
        mCourses.erase(string);
        return;
    }
    //otherwise it doesn't exist.
    std::cout << "Course " << string << " does not exist.\n";
}
void CourseCatalog::updateCourse(){
    //do this later
    std::cout << "updateCourse not implemented yet.\n";
}
void CourseCatalog::editCourseName(){
    std::string string;
    std::string newName;
    std::cout << "Enter the name of the course to rename: ";
    std::cin.ignore();
    getline(std::cin, string);
    CourseIterator p = mCourses.find(string);
    //If we can find the course that the user inputted, erase it
    if(p != mCourses.end()){
        std::cout << "Enter the new name for the course: ";
        getline(std::cin, newName);
        p->second.setCourseName(newName);
        NCourse c(newName, p->second);
        mCourses.insert(c);
        mCourses.erase(string);
        std::cout << string << " renamed to " << newName << "\n";
        return;
    }
    std::cout << "Course " << string << " does not exist.\n";
}
void CourseCatalog::editCourseTitle(){
    std::string string;
    std::string newTitle;
    std::cout << "Enter the name of the course to edit the title of: ";
    std::cin.ignore();
    getline(std::cin, string);
    CourseIterator p = mCourses.find(string);
    //If we can find the course that the user inputted, erase it
    if(p != mCourses.end()){
        std::cout << "Enter the new title for the course: ";
        getline(std::cin, newTitle);
        p->second.setCourseTitle(newTitle);
        std::cout << string << " title changed to " << newTitle << "\n";
        return;
    }
    std::cout << "Course " << string << " does not exist.\n";
}
void CourseCatalog::editCourseInstructor(){
    std::string string;
    std::string newInstructor;
    std::cout << "Enter the name of the course to edit the instructor name for: ";
    std::cin.ignore();
    getline(std::cin, string);
    CourseIterator p = mCourses.find(string);
    //If we can find the course that the user inputted, erase it
    if(p != mCourses.end()){
        std::cout << "Enter the new instructor name for the course: ";
        getline(std::cin, newInstructor);
        p->second.setInstructor(newInstructor);
        std::cout << string << " Instructor changed to " << newInstructor << "\n";
        return;
    }
    std::cout << "Course " << string << " does not exist.\n";
}
void CourseCatalog::editCourseEnrollment(){
    std::string string;
    int newEnrollment;
    std::cout << "Enter the name of the course to edit enrollment for: ";
    std::cin.ignore();
    getline(std::cin, string);
    CourseIterator p = mCourses.find(string);
    //If we can find the course that the user inputted, erase it
    if(p != mCourses.end()){
        std::cout << "Enter the new enrollment for the course: ";
        std::cin >> newEnrollment;
        p->second.setStudentCount(newEnrollment);
        std::cout << string << " Enrollment changed to " << newEnrollment << "\n";
        return;
    }
    std::cout << "Course " << string << " does not exist.\n";
}
