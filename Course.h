//
//  Course.h
//  Assignment 9
//
//  Created by Liam Giraldo on 10/31/23.
//

#ifndef Course_h
#define Course_h

#include <stdio.h>
#include <iostream>

class Course
{
public:
    //Defining the getters
    int getStudentCount();
    std::string getCourseName();
    std::string getInstructor();
    std::string getCourseTitle();
    // Defining the setters
    void setStudentCount(int count);
    void setCourseName(std::string theName);
    void setInstructor(std::string theInstructor);
    void setCourseTitle(std::string theTitle);
  
private:
    // Defining the member variables
    std::string name;
    std::string instructor;
    std::string title;
    int numStudents;
};

#endif /* Course_h */
