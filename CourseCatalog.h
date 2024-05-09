//
//  CourseCatalog.h
//  Assignment 9
//
//  Created by Liam Giraldo on 10/31/23.
//

#ifndef CourseCatalog_h
#define CourseCatalog_h

#include "Course.h"
#include <vector>
#include <map>

#include <iostream>
//Creating the CourseCatalog class
class CourseCatalog {
public:
  void listCourses();
  void addNewCourse();
  void removeCourse();
  void updateCourse();
    void editCourseName();
    void editCourseTitle();
    void editCourseInstructor();
    void editCourseEnrollment();
private:
    //this is a map that has a string key and course value
    //We use this to store our courses.
    std::map<std::string,Course> mCourses;
};


#endif /* CourseCatalog_h */
