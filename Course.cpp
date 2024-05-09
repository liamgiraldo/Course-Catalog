//
//  Course.cpp
//  Assignment 9
//
//  Created by Liam Giraldo on 10/31/23.
//
#include <iostream>
using namespace std;  //introduces namespace std
#include "Course.h"

//Access the methods from our defined course class, and declare their functions.
//These are getters and setters that allow us to modify the class variables.
int Course::getStudentCount()
{
    return numStudents;
}

string Course::getCourseName()
{
    return name;
}

string Course::getInstructor()
{
    return instructor;
}

string Course::getCourseTitle(){
    return title;
}

void Course::setStudentCount(int count)
{
    numStudents = count;
}

void Course::setCourseName(string theName)
{
    name = theName;
}

void Course::setInstructor(string theInstructor)
{
    instructor = theInstructor;
}

void Course::setCourseTitle(string theTitle){
    title = theTitle;
}
