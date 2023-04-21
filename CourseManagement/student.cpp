#include "student.h"
#include <cstring>
#include <iostream>

student::student(){
    name = new char[1];
    name[0] = '\0';
    
    classif = '\0';

    major = new char[1];
    major[0] = '\0';

    studentId = new char[1];
    studentId[0] = '\0';
}

student::student(const student& other){

    name = new char[strlen(other.getName())+1];
    strcpy(name, other.getName());

    classif = other.getClassif();

    major = new char[strlen(other.getMajor())+1];
    strcpy(major, other.getMajor());

    studentId = new char[strlen(other.getId())+1];
    strcpy(studentId, other.getId());
}

student::~student() {
    delete [] name;
    delete [] major;
    delete [] studentId;
}

void student::operator=(const student& other){


    name = new char[strlen(other.getName())+1];
    strcpy(name, other.getName());

    classif = other.getClassif();

    major = new char[strlen(other.getMajor())+1];
    strcpy(major, other.getMajor());

    studentId = new char[strlen(other.getId())+1];
    strcpy(studentId, other.getId());

}

char* student::getName() const{
    return name;
}
char* student::getMajor() const{
    return major;
}
char* student::getId() const{
    return studentId;
}
char student::getClassif() const{
    return classif;
}

void student::setName(const char* n){
    delete [] name;
    name = new char[strlen(n)+1];
    strncpy(name, n, strlen(n)+1);
}
void student::setClasif(const char c){
    classif = c;
}
void student::setMajor(const char* n){
    delete [] major;
    major = new char[strlen(n)+1];
    strcpy(major, n);
}
void student::setId(const char* i){
    delete [] studentId;
    studentId = new char[strlen(i)+1];
    strcpy(studentId, i);
}

std::ostream & operator << (std::ostream& out, const student& print){
    out << "Student Name: " << print.getName() << " || Classification: " << print.getClassif() 
    << " || Major: " << print.getMajor()<< " || Student ID: " << print.getId(); 
    return out;
}