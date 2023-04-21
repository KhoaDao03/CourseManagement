/*==========================================================================*/
// Author: Khoa Dao


#include <cstring>
#include <iostream>
#include <cstdlib>
#include <limits>

#include "course.h"

using namespace std;

// function name (course list, int size)
void addCourse(course*&, int&);
void removeCourse(course*&, int , int&);

int askUpdateCourse();
int askUpdateStudent();
int askFindCourse();
int askFindStudent();
int askDeleteCourse();
void pause();


// function name (course list)
void processUpdateCourse(course*&, int);

// function name (int size)
int askCourse(int);
int askStudent(int);


int typeOfFunction();

// processFunction(int choice, course list, int size)
void processFunction(int, course*&, int&);

// function name (course list, size)
void printFunction(course*&, int);
void printCourses(course*, int);
void printStudents(course*, int);
void printEverything(course*, int);

// function name(course list, course #, list size)
void setNewCourse(course*&, int, int);
void insertCourseName(course*&, int);
void insertCourseCode(course*&, int);
void insertCourseLocation(course*&, int);

// function name(course list, list size)
void findCourseName(course*&, int);
int findCourseCode(course*&, int);
void findCourseLocation(course*&, int);

// function name(course list, course #, student #)
void setNewStudent(course*&, int, int);
void insertStudentName(course*&, int, int);
void insertStudentClassification(course*&, int, int);
void insertStudentMajor(course*&, int, int);
void insertStudentId(course*&, int, int);

// function name (course list, int course #)
void findStudentName(course*&, int);
void findStudentId(course*&, int);

int main(){

    int size = 2;
    int choice;
    course* list = new course[size];
    cout<< "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<< endl;
    cout << "          Welcome to the course management program."   << endl;
    cout<< "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<< endl
    << endl;
    printEverything(list,size);
    cout << "Would you like to setup the 2 initial courses? " << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cin >> choice;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    if (choice == 1){
        for (int i = 0; i < size; i++){
            cout << "Course: " << i+1 << endl;
            setNewCourse(list, i, size);
        }
    }
    while (true){
        processFunction(typeOfFunction(), list, size);
    }
    
    delete [] list;

    return true;
}





/*==========================================================================*/
void addCourse(course*& l,int& size){
    size ++;
    course* temp = new course[size];
    
    for (int i = 0 ; i < size-1 ; i ++){
        temp[i] = l[i];
    }
    
    delete [] l;
    l = temp;
}





/*==========================================================================*/
void removeCourse(course*& l, int r, int& size){

    for (int i = r ; i < size-1 ; i ++){
        l[i] = l[i+1];
    }
    size --;
    course* temp = new course[size];
    for (int i = 0 ; i < size; i ++){
    temp[i] = l[i];
    }
    delete [] l;
    l = temp;
    
}





/*==========================================================================*/
int typeOfFunction(){
    int num = 0;
    while (true){
        cout << "List functions:" << endl;
        cout << "1. Add course" << endl;
        cout << "2. Add student to a course" << endl;
        cout << "3. Update a course/student" << endl;
        cout << "4. Prints out" << endl;
        cout << "5. Find students" << endl;
        cout << "6. Find course" << endl;
        cout << "7. Remove course" << endl;
        cout << "Choose 1,2,3,4,5,6,7 for each desire functions or -1 to quit the program"
        << endl;
        
        cin >> num;
        if (num > 0 && num < 8){
                cin.clear();
                cin.ignore(1000,'\n');
                return num;
        } else if (num == -1) {
            abort();
        }
        else
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "Input is invalid." << endl;
            cout << "Please try again" << endl <<endl;
            
        }
    }
}





/*==========================================================================*/
void processFunction(int c, course*& l, int& size){
    if (c == 1){
        // add course
        int choice;
        addCourse(l, size);
        cout << "Size: " << size <<endl;
        printCourses(l,size);

        bool done = false;
        while (!done){
            cout << "Would you like to set up the new course?" << endl;
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            cin >> choice;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            if (choice == 1){ 
                setNewCourse(l, size-1, size);
                done = true;
            } else if (choice == 2){
                done = true;
            } else {
                cin.clear();
                cin.ignore(1000,'\n');
                cout << "Input is invalid." << endl;
                cout << "Please try again" << endl <<endl;
            }
        }
    
    } else if (c == 2){

        // add student
        cout << "Add student into course." << endl;
        printCourses(l,size);
        int choice = askCourse(size);
        l[choice].addStudent();
        int cSize = l[choice].getSize();
        setNewStudent(l,choice,cSize-1);
            
    } else if (c == 3) {
        // update
        cout << "Update course" << endl;
        processUpdateCourse(l, size);

    } else if (c == 4) {
        // print
        printFunction(l, size);
        
        
    } else if (c == 5) {
        // find students

        printCourses(l, size);
        int cCourse = askCourse(size); 
        int choice = askFindStudent();
        if (choice == 1){
            findStudentName(l,cCourse);
        } else if (choice == 2){
            findStudentId(l,cCourse);
        }
        
        
    } else if (c == 6) {
        // find course
        int ask = askFindCourse();
        if (ask == 1){
            findCourseName(l,size);
        } else if (ask == 2){
            findCourseCode(l,size);
        } else if (ask == 3){
            findCourseLocation(l,size);
        }
        
    } else if (c == 7) {
        // remove course
        int choice;
        cout << "Remove course from list." << endl;

        int d = askDeleteCourse();
        if ( d == 1 ){
            choice = askCourse(size);
        removeCourse(l, choice, size);
        cout << "Course is removed from the list." << endl;

        } else if (d == 2){
            choice = findCourseCode(l,size);
        removeCourse(l, choice, size);
        cout << "Course is removed from the list." << endl;

        }

        
    }
    pause();
}





/*==========================================================================*/
void setNewCourse(course*& list, int i, int size){

        cout << endl;
        insertCourseName(list, i);

        insertCourseCode(list, i);

        insertCourseLocation(list, i);
        
        cout << list[i] << endl;

        int num;
        bool done = false;
        while (!done){
            cout << "For the roster/students:" << endl;
            cout << "1. Copy from an existing roster" << endl;
            cout << "2. Manually enter student." << endl;
            cout << "3. Do it later" << endl;
            cout << "Choose 1,2,3 for each desire function, -1 to quit the program or 0 to go back."
            << endl;
            cin >> num;
            if (num > -1 && num < 4){
                cin.clear();
                cin.ignore(1000,'\n');
                done = true;

                if (num == 1){
                    
                    cout << "Copy all student from another roster." << endl;
                    printCourses(list,size);
                    int cCourse = askCourse(size); 
                    list[i].copyStudents(list[cCourse]);


                } else if (num == 2){

                    int numStu = list[i].getSize();
                    for (int z = 0; z < numStu; z++){
                        cout << endl;
                        cout << "Student: " << z+1 << endl;
                        setNewStudent(list, i, z);
                    }

                }

            } else if (num == -1) {
                abort();
            }
            else
            {
                cin.clear();
                cin.ignore(1000,'\n');
                cout << "Input is invalid." << endl;
                cout << "Please try again" << endl <<endl;
            }
            

        }
        
    
    // copy roster

}





/*==========================================================================*/
void printFunction(course*& list, int size){
    int num = 0;
    bool done = false;
    while (!done){
        cout << "What do you want to print? " << endl;
        cout << "1. Roster" << endl;
        cout << "2. Students" << endl;
        cout << "3. Courses and Students" << endl;
        cout << "Choose 1,2,3 for each desire functions or -1 to quit the program"
        << endl;
        
        cin >> num;
        if (num == 1) {
            printCourses(list,size);
            done = true;
        } else if (num == 2) {
            
            cout << "Print student lists from course" << endl;
            printCourses(list,size);
            int z = askCourse(size);
            printStudents(list, z);
            done = true;
        } else if (num == -1) {
            abort();
        } else if (num == 3){
            done = true;
            cout << "Print courses and students." << endl;
            printEverything(list,size);
        }
        else
        {
            cout << "Input is invalid." << endl;
            cout << "Please try again" << endl <<endl;
            
        }
    }
    cout << endl;
}





/*==========================================================================*/
void insertCourseName(course*& list, int i){
    char tempCString[500];
    cout << "Enter name for course: " << endl;
    cin.get(tempCString, 499);
    list[i].setName(tempCString);
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
}
void insertCourseCode(course*& list, int i){
    char tempCString[9];
    cout << "Enter course's code: " << endl;
    cin.get(tempCString, 8);
    list[i].setCode(tempCString);
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
}
void insertCourseLocation(course*& list, int i){
    char tempCString[12];
    cout << "Enter course's location: " << endl;
    cin.get(tempCString, 11);
    list[i].setLocat(tempCString);
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
}





/*==========================================================================*/
void findCourseName(course*& list, int size){
    char tempCString[500];
    cout << "Enter name for course: " << endl;
    cin.get(tempCString, 499);
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    for (int i=0; i < size; i++){
        if (strcmp(list[i].getName(),tempCString)==0){
            cout << list[i] << endl;
            break;
        }
        if (i == size-1){
            cout << "Course unavailable." << endl;
        }
    }
}

int findCourseCode(course*& list, int size){
    char tempCString[9];
    cout << "Enter course's code: " << endl;
    cin.get(tempCString, 8);
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    for (int i=0; i < size; i++){
        if (strcmp(list[i].getCode(),tempCString)==0){
            cout << list[i] << endl;
            return i;
        }   
        if (i == size-1){
            cout << "Course unavailable." << endl;
        }
    }
}

void findCourseLocation(course*& list, int size){
    char tempCString[10];
    cout << "Enter course's location: " << endl;
    cin.get(tempCString, 11);
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    for (int i=0; i < size; i++){
        if (strcmp(list[i].getLocat(),tempCString)==0){
            cout << list[i] << endl;
            break;
        }
        if (i == size-1){
            cout << "Course unavailable." << endl;
        }
    }
}





/*==========================================================================*/
void setNewStudent(course*& l, int choice, int student){
    insertStudentName(l, choice, student);
    insertStudentClassification(l, choice, student);
    insertStudentMajor(l, choice, student);
    insertStudentId(l, choice, student);

    // prints out the change
    cout << l[choice].getStudent(student) << endl;
}

void insertStudentName(course*& l, int choice, int student){
    char tempCString[500];
    cout << "Enter student's name: " << endl;
    cin.get(tempCString, 499);
    l[choice].getStudent(student).setName(tempCString);
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
}

void insertStudentClassification(course*& l, int choice, int student){
    char ch;
    cout << "Enter student's classification: " << endl;
    cin >> ch;
    l[choice].getStudent(student).setClasif(ch);
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
}
void insertStudentMajor(course*& l, int choice, int student){
    char tempCString[500];
    cout << "Enter student's major: " << endl;
    cin.get(tempCString, 499);
    l[choice].getStudent(student).setMajor(tempCString);
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
}

void insertStudentId(course*& l, int choice, int student){
    char tempCString[500];
    cout << "Enter student's ID: " << endl;
    cin.get(tempCString, 499);
    l[choice].getStudent(student).setId(tempCString);
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
}





/*==========================================================================*/
void findStudentName(course*& l, int choice){
    char tempCString[500];
    cout << "Enter student's name to find: " << endl;
    cin.get(tempCString, 499);
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    int size = l[choice].getSize();
    for (int i=0; i < size; i++){
        if (strcmp(l[choice].getStudent(i).getName(),tempCString)==0){
            cout << l[choice].getStudent(i) << endl;
            break;
        }
        if (i == size-1){
            cout << "Student unavailable." << endl;
        }
    }
}
void findStudentId(course*& l, int choice){
    char tempCString[500];
    cout << "Enter student's name to find: " << endl;
    cin.get(tempCString, 499);
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    int size = l[choice].getSize();
    for (int i=0; i < size; i++){
        if (strcmp(l[choice].getStudent(i).getId(),tempCString)==0){
            cout << l[choice].getStudent(i) << endl;
            break;
        }
        if (i == size-1){
            cout << "Student unavailable." << endl;
        }
    }
}





/*==========================================================================*/
void printCourses(course* l, int size){
    cout << endl;
    for (int i = 0; i < size; i++) {
        cout << i+1 << ". "<< l[i] << endl;
    }
}

void printStudents(course* list, int course){
    cout << endl;
    cout << list[course] << endl;
    int numStu = list[course].getSize();
    for (int i = 0; i < numStu; i++) {
        cout << i+1 << ". " << list[course].getStudent(i) << endl;
    }
}

void printEverything(course* l, int size){
    int numStu;
    cout << "The current list:" << endl;
    for (int i = 0; i < size; i++) {
        cout << i+1 << ". "<< l[i] << endl;
        numStu = l[i].getSize();
        for (int z = 0; z < numStu; z++) {
            cout << z+1 << ". " << l[i].getStudent(z) << endl;
        }
        cout << endl << endl;
    }
}





/*==========================================================================*/
int askCourse(int size){
    int choice;
    while (true){
        cout << "Which course you would like to choose?" << endl;
        cin >> choice;
        if (choice > 0 && choice < size+1){
            cin.clear();
            cin.ignore(1000,'\n');
            return choice-1;
        } else if (choice == -1) {
            abort();
        }
        else
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "Input is invalid." << endl;
            cout << "Please try again" << endl <<endl;
        }
    }
    
}


int askStudent(int size){
    int choice;
    while (true){
        cout << "Which student you would like to choose?" << endl;
        cin >> choice;
        if (choice > 0 && choice < size+1){
            cin.clear();
            cin.ignore(1000,'\n');
            choice--;
            return choice;
        } else if (choice == -1) {
            abort();
        }
        else
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "Input is invalid." << endl;
            cout << "Please try again" << endl <<endl;
        }
    }
    
}





/*==========================================================================*/
void pause(){
    cout << endl;
    cout << "Process complete. Press enter to continue...";
    cin.get();
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
}





/*==========================================================================*/
int askUpdateCourse(){
    int num = 0;
    while (true){
        cout << "What do you want to edit for this course?" << endl;
        cout << "1. Change Name." << endl;
        cout << "2. Change Code." << endl;
        cout << "3. Change Location." << endl;  
        cout << "4. Copy Students from an existing roster." << endl; 
        cout << "5. Change Roster/update students." << endl;  
        cout << "Choose 1,2,3,4 for each desire functions, -1 to quit the program, or 0 to go back."
        << endl;
        cin >> num;
        if (num > -1 && num < 6){
            cin.clear();
            cin.ignore(1000,'\n');
            return num;
        } else if (num == -1) {
            abort();
        }
        else
        {
            cout << "Input is invalid." << endl;
            cout << "Please try again" << endl <<endl;
            cin.clear();
            cin.ignore(1000,'\n');
        }
    }
}


int askUpdateStudent(){
    int num = 0;
    while (true){
        cout << "What do you want to edit for this student?" << endl;
        cout << "1. Change Name." << endl;
        cout << "2. Change Classification." << endl;
        cout << "3. Change Major." << endl;  
        cout << "4. Change Student ID." << endl;
        cout << "5. Remove Student." << endl;  
        cout << "6. Copy student from different course" << endl;
        cout << "7. Update all data" << endl;
        cout << "Choose 1,2,3,4,5,6,7 for each desire functions, -1 to quit the program or 0 to go back."
        << endl;
        cin >> num;
        if (num > -1 && num < 8){
            cin.clear();
            cin.ignore(1000,'\n');
            return num;
        } else if (num == -1) {
            abort();
        }
        else
        {
            cout << "Input is invalid." << endl;
            cout << "Please try again" << endl <<endl;
            cin.clear();
            cin.ignore(1000,'\n');
        }
    }
}





/*==========================================================================*/
int askFindCourse(){
    int num = 0;
    while (true){
        cout << "How do you want to find course:" << endl;
        cout << "1. Name." << endl;
        cout << "2. Code." << endl;
        cout << "3. Location." << endl;  
        cout << "Choose 1,2,3 for each desire functions, -1 to quit the program or 0 to go back."
        << endl;
        cin >> num;
        if (num > -1 && num < 4){
            cin.clear();
            cin.ignore(1000,'\n');
            return num;
        } else if (num == -1) {
            abort();
        }
        else
        {
            cout << "Input is invalid." << endl;
            cout << "Please try again" << endl <<endl;
            cin.clear();
            cin.ignore(1000,'\n');
        }
    }
}


int askFindStudent(){
    int num = 0;
    while (true){
        cout << "How do you want to find course:" << endl;
        cout << "1. Name." << endl;
        cout << "2. Student ID." << endl;
        cout << "Choose 1,2 for each desire functions, -1 to quit the program or 0 to go back."
        << endl;
        cin >> num;
        if (num > -1 && num < 3){
            cin.clear();
            cin.ignore(1000,'\n');
            return num;
        } else if (num == -1) {
            abort();
        }
        else
        {
            cout << "Input is invalid." << endl;
            cout << "Please try again" << endl <<endl;
            cin.clear();
            cin.ignore(1000,'\n');
        }
    }
}





/*==========================================================================*/
void processUpdateCourse(course*& list, int size){
    printCourses(list, size);
    int cCourse = askCourse(size); 
    int choice = askUpdateCourse();
    if (choice == 1){

        insertCourseName(list, cCourse);
    
    } else if (choice == 2){

        insertCourseCode(list, cCourse);

    } else if (choice == 3){

        insertCourseLocation(list, cCourse);

    } else if (choice == 4) {

        cout << "Copy all student from another roster." << endl;
        printCourses(list,size);
        int oCourse = askCourse(size);
        if (oCourse != cCourse){
        list[cCourse].copyStudents(list[oCourse]);
        }
    
    } else if (choice == 5){

        int numStu = list[cCourse].getSize();
        printStudents(list, cCourse);
        int cStudent = askStudent(numStu); 
        int chosen = askUpdateStudent();
        if (chosen == 1){

            insertStudentName(list, cCourse, cStudent);
    
        } else if (chosen == 2){

            insertStudentClassification(list, cCourse, cStudent);

        } else if (chosen == 3){

            insertStudentMajor(list, cCourse, cStudent);

        } else if (chosen == 4){

            insertStudentId(list, cCourse, cStudent);
        
        } else if (chosen == 5){

            list[cCourse].removeStudent(cStudent);

        } else if (chosen == 6){
            printCourses(list, size);
            int cCourse1 = askCourse(size); 
            int numStu1 = list[cCourse1].getSize();
            printStudents(list, cCourse1);
            int cStudent1 = askStudent(numStu1); 
            list[cCourse].getStudent(cStudent) = list[cCourse1].getStudent(cStudent1); 
        } else if (chosen == 7) {
            setNewStudent(list,cCourse,cStudent);
        }


    } 
}





/*==========================================================================*/
int askDeleteCourse(){
    int num = 0;
    while (true){
        cout << "How do you want to delete course:" << endl;
        cout << "1. Course orders." << endl;
        cout << "2. Course code." << endl;
        cout << "Choose 1,2 for each desire functions, -1 to quit the program or 0 to go back."
        << endl;
        cin >> num;
        if (num > -1 && num < 3){
            cin.clear();
            cin.ignore(1000,'\n');
            return num;
        } else if (num == -1) {
            abort();
        }
        else
        {
            cout << "Input is invalid." << endl;
            cout << "Please try again" << endl <<endl;
            cin.clear();
            cin.ignore(1000,'\n');
        }
    }
}
