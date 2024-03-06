
#include <iostream>
using namespace std;
#ifndef ASSIGNMENT_2_OOP_TASK2CLASSES_H
#define ASSIGNMENT_2_OOP_TASK2CLASSES_H


class BigReal {
    string num;

    int place_of_point;


    bool is_Valid(string num);

public:
    string int_part, frac_part;
    int size;
    char sign;
    BigReal();

    BigReal(string no);
    BigReal (const BigReal& other);
    void setNum(string no);
    int  get_size();
    char get_sign();
    string get_intPart();
    string get_fracPart();

    BigReal operator+(BigReal &other);
    BigReal operator-(BigReal &other);


    bool operator< (BigReal anotherReal);
    bool operator> (BigReal anotherReal);
    bool operator== (BigReal anotherReal);
    friend ostream& operator<< (ostream& out, BigReal& num);

};


#endif //ASSIGNMENT_2_OOP_TASK2CLASSES_H
