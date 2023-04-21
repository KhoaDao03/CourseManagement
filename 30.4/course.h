#include "student.h"

class course {

    friend std::ostream & operator << (std::ostream& , const course&);

    private:
        char* name;
        char* code;
        char* location;  // location
        student* roster;
        int size;

    public:
        course();
        ~course();

        void operator=(const course&);
        void copyStudents(const course&);

        
        char* getName() const;
        char* getCode() const;
        char* getLocat() const;
        int getSize() const;
        student& getStudent(int) const;
        //char* getRost() const;

        void setName(const char*);
        void setCode(const char*);
        void setLocat(const char*);
        
        void addStudent();
        void removeStudent(int);

        bool checkStudent(int) const ;

};