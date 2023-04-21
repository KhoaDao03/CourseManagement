#include <iostream>

class student{

    friend std::ostream & operator << (std::ostream& , const student&);


    private:
        char* name;
        char classif;   // classification   
        char* major;
        char* studentId;
        
    public:
        student();
        student(const student&);
        ~student();

        void operator=(const student&); 

        char* getName() const;
        char getClassif() const;
        char* getMajor() const;
        char* getId() const;

        void setName(const char*);
        void setMajor(const char*);
        void setId(const char*);
        void setClasif(const char);
};