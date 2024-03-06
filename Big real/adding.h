//
// Created by tasnim on 11/1/2023.
//

#ifndef ASSIGNMENT_2_OOP_ADDING_H
#define ASSIGNMENT_2_OOP_ADDING_H

#include "iostream"
#include "string"
#include "algorithm"
using namespace std;
string adding(string s1,string s2){
    bool carry = false;
    s1 = s1.substr(0,s1.find('.'));
    s2 = s2.substr(0,s2.find('.'));

    string s3="";
    int max_lenght = max(s1.size(),s2.size());
    s1  =string(max_lenght-s1.size(),'0')+s1;

    s2  =string(max_lenght-s2.size(),'0')+s2;
    s3 = string(max_lenght-s1.size(),'0')+s3;
    for (int i = (s1.size()) - 1; i >= 0; i--) {
        int result = (s1[i] - '0') + (s2[i] - '0');
//        cout<<result<<"\n";

        if (result <= 9) {
            if (carry == false) {
                s3+=(char(result+'0'));
                carry=false;

            }
            else {
                if(result<9){
                    s3 += (char((result + 1) + '0'));
                    carry=false;
                }
                else {
                    s3 += (char((result + 1)%10 + '0'));
                    carry = true;

                }



            }
//            reverse(s3.begin(),s3.end());
        }
        else {
            if (carry == false) {
                s3 += (char((result % 10) + '0'));
                carry = true;
            }

            else {
                s3 += char(((result % 10) + 1) + '0');
                carry = true;
            }

        }
    }
    if(carry ==true){
        s3+='1';
    }
    reverse(s3.begin(),s3.end());
    return s3;
}
string adding_fraction(string s1,string s2){
    string fraction1,fraction2,s3;
    s3="";

    if(count(s1.begin(),s1.end(),'.')>0&& count(s2.begin(),s2.end(),'.')>0){
        fraction1 = s1.substr(s1.find('.')+1,s1.size());
        fraction2 = s2.substr(s2.find('.')+1,s2.size());
    }
    else if(count(s1.begin(),s1.end(),'.')==0&& count(s2.begin(),s2.end(),'.')>0){
        fraction2 = s2.substr(s2.find('.')+1,s2.size());

    }
    else if(count(s1.begin(),s1.end(),'.')>0&& count(s2.begin(),s2.end(),'.')==0){
        fraction1 = s1.substr(s1.find('.')+1,s1.size());

    }
    else {
        fraction1="";
        fraction2="";
    }
    int max_lenght = max(fraction1.size(),fraction2.size());

    fraction1  =fraction1+string(max_lenght-fraction1.size(),'0');
    fraction2  =fraction2+string(max_lenght-fraction2.size(),'0');


    bool carry = false;

//    s3 = s3+string(max_lenght-fraction1.size(),'0');
    for (int i = (fraction1.size()) - 1; i >= 0; i--) {
        int result = (fraction1[i] - '0') + (fraction2[i] - '0');
//        cout<<result<<"\n";

        if (result <= 9) {
            if (carry == false) {
                s3+=(char(result+'0'));
                carry=false;

            }
            else {
                if(result<9){
                    s3 += (char((result + 1) + '0'));
                    carry=false;
                }
                else {
                    s3 += (char((result + 1)%10 + '0'));
                    carry = true;

                }



            }
//            reverse(s3.begin(),s3.end());
        }
        else {
            if (carry == false) {
                s3 += (char((result % 10) + '0'));
                carry = true;
            }

            else {
                s3 += char(((result % 10) + 1) + '0');
                carry = true;
            }

        }
    }

    s3+='.';

    s1 = s1.substr(0,s1.find('.'));
    s2 = s2.substr(0,s2.find('.'));

    int max2 = max(s1.size(),s2.size());
    s1  =string(max2-s1.size(),'0')+s1;
    s2  =string(max2-s2.size(),'0')+s2;
    s3 = string(max2-s1.size(),'0')+s3;
    for (int i = (s1.size()) - 1; i >= 0; i--) {
        int result = (s1[i] - '0') + (s2[i] - '0');
//        cout<<result<<"\n";

        if (result <= 9) {
            if (carry == false) {
                s3+=(char(result+'0'));
                carry=false;

            }
            else {
                if(result<9){
                    s3 += (char((result + 1) + '0'));
                    carry=false;
                }
                else {
                    s3 += (char((result + 1)%10 + '0'));
                    carry = true;

                }



            }
//            reverse(s3.begin(),s3.end());
        }
        else {
            if (carry == false) {
                s3 += (char((result % 10) + '0'));
                carry = true;
            }

            else {
                s3 += char(((result % 10) + 1) + '0');
                carry = true;
            }

        }
    }
    if(carry ==true){
        s3+='1';
    }
    reverse(s3.begin(),s3.end());
    return s3;
}
#endif //ASSIGNMENT_2_OOP_ADDING_H
