#include "course.h"
#include <cstdlib>
#include <iostream>
#include <cstring>
using std :: endl;
course::course(){
    size = 2;
    name = new char[1];
    name[0] = '\0';
    
    code = new char[8];     // act as an array char[7]
    code[0] = '\0';

    location = new char[11];    // act as an array char[10]
    location[0] = '\0';

    roster = new student[size];
}


course::~course(){
    delete [] name;
    delete [] roster;
    delete [] code;
    delete [] location;
}


void course::operator=(const course& other){

    name = new char[strlen(other.getName())+1];
    strcpy(name, other.getName());

    
    setCode(other.getCode());

    setLocat(other.getLocat());

    size = other.getSize();

    roster = new student[size];
    for (int i = 0; i < size; i++){
        getStudent(i) = other.getStudent(i);
    }

}


void course::copyStudents(const course& other){


    size = other.getSize();
    roster = new student[size];
    for (int i = 0; i < size; i++){
        getStudent(i) = other.getStudent(i);
    }

}


char* course::getName() const{
    return name;
}
char* course::getCode() const{
    return code;
}
char* course::getLocat() const{
    return location;
}
int course::getSize() const{
    return size; 
}
student& course::getStudent(int s) const{
    if (checkStudent(s)){
        return roster[s];
    }
}



void course::setName(const char* n){
    delete [] name;
    name = new char[strlen(n)+1];
    strncpy(name, n, strlen(n)+1);
}
void course::setCode(const char* c){
    strncpy(code, c, 7);
}
void course::setLocat(const char* l){
    strncpy(location, l, 10);
}

void course::addStudent(){
    size ++;
    student* temp = new student[size];
    
    for (int i = 0 ; i < size-1 ; i ++){
        temp[i] = roster[i];
    }
    
    delete [] roster;
    roster = temp;
}

void course::removeStudent(int r){

    if (checkStudent(r)){
        size --;
        student* temp = new student[size];
        for (int i = r ; i < size ; i ++){
            roster[i] = roster[i+1];
        }
        for (int i = 0 ; i < size ; i ++){
        temp[i] = roster[i];
        }
        delete [] roster;
        roster = temp;
    }
}

bool course::checkStudent(int c) const{
    if ( c > size || c < 0) {
        std::cout << "Student unavailable";
        return false;
    } else {
        return true;
    }
}


std::ostream & operator << (std::ostream& out, const course& print){
    out << "Course Name: " << print.getName() << " || Code: " << print.getCode() << " || Location: "
    << print.getLocat() << " || Number of Students: "  << print.getSize() << endl;
    
    return out;
}

