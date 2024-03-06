//
// Created by tasnim on 11/2/2023.
//

#ifndef ASSIGNMENT_2_OOP_SUBSTRACTING_H
#define ASSIGNMENT_2_OOP_SUBSTRACTING_H
#include <iostream>
#include<string>
#include "algorithm"
using namespace std;
#include <iostream>
#include<string>
#include "algorithm"
using namespace std;
bool fraction(string s1,string s2){
    if(count(s1.begin(), s1.end(),'.')==0&& count(s2.begin(), s2.end(),'.')==0){
        return false;
    }
    else return true;
}
bool equal_size(string s1,string s2){
    if(s1.size()==s2.size())return true;
    else return false;
}
bool greather_than(string s1,string s2){
    for(int i=0;i<s1.size();i++){
        if(s1[i]<s2[i]) return false;
    }
    return true;
}
string substracting(string s1,string s2){
    string s3 = "";
    int max_lenght = max(s1.size(),s2.size());
    s1  =string(max_lenght-s1.size(),'0')+s1;
    s2  =string(max_lenght-s2.size(),'0')+s2;
    s3 = string(max_lenght-s1.size(),'0')+s3;
    bool carry = false;
    int cnt;
    for(int i=s1.size()-1;i>=0;i--){
        if(s1[i]<s2[i]){

            if(carry ==false){
                cnt = 0;
                int num1 = 10+(s1[i]-'0');
                int result = num1-(s2[i]-'0');
                s3+=char(result+'0');
//            cnt++;
                carry = true;

            }

            else {
                int num1 = (10+(s1[i]-'0'))-1;
                int result = num1-(s2[i]-'0');
                s3+=char(result+'0');
//            cnt++;

            }

        }
        else if (s1[i]>s2[i]){
            if(carry ==false){
                int result = (s1[i]-'0') - (s2[i]-'0');
                s3+=char(result+'0');
                carry = false;

            }
            else {

                int result = (((s1[i]-'0')-1) - (s2[i]-'0'));
                s3+=char(result+'0');
                carry =false;
            }
        }
        else {
            if(carry== false){
                int result = (s1[i]-'0')-(s2[i]-'0');
                s3+=char(result+'0');
            }
            else{
                int num1 = 10+(s1[i]-'0');
                num1-=1;
                int result = num1-(s2[i]-'0');
                s3+=char(result+'0');
            }
        }
    }
    reverse(s3.begin(),s3.end());
    return s3;
}
string compring_int (string s1,string s2){
    string larger,smaller;
    string ans;
    if(equal_size(s1,s2)==true) {
        if(greather_than(s1,s2)){
            larger=s1;
            smaller=s2;
            ans = substracting(larger,smaller);
        }
        else {
            larger = s2;
            smaller = s1;
            ans = substracting(larger,smaller);

        }
    }
    else {
        if(s1.size()>s2.size()){
            larger=s1;
            smaller=s2;
            ans = substracting(larger,smaller);

        }
        else {
            larger = s2;
            smaller = s1;
            ans = substracting(larger,smaller);

        }
    }
    return ans;
}
bool greater_fraction(string s1,string s2){

    string fraction1 = s1.substr(s1.find('.')+1,s1.size());
    string fraction2 = s2.substr(s2.find('.')+1,s2.size());
    if(greather_than(fraction1,fraction2)){
        return true;
    }
    else return false;
}
string sustracting_fraction(string s1,string s2){

    string fraction1 = s1.substr(s1.find('.')+1,s1.size());
    string fraction2 = s2.substr(s2.find('.')+1,s2.size());
    string s3 = "";
    int max2 = max(fraction1.size(),fraction2.size());


    bool carry = false;

    fraction1  =fraction1+string(max2-fraction1.size(),'0');
    fraction2  =fraction2+string(max2-fraction2.size(),'0');
    s3 =s3+ string(max2-fraction1.size(),'0');
    int cnt;
    for(int i=fraction1.size()-1;i>=0;i--){
        if(fraction1[i]<fraction2[i]){

            if(!carry){
                cnt = 0;
                int num1 = 10+(fraction1[i]-'0');
                int result = num1-(fraction2[i]-'0');
                s3+=char(result+'0');
//                cnt++;
                carry = true;
            }

            else {
                int num1 = (10+(fraction1[i]-'0'))-1;
                int result = num1-(fraction2[i]-'0');
                s3+=char(result+'0');
//                cnt++;

            }

        }
        else if (fraction1[i]>fraction2[i]){
            if(carry ==false){
                int result = (fraction1[i]-'0') - (fraction2[i]-'0');
                s3+=char(result+'0');
                carry = false;

            }
            else {

                int result = (((fraction1[i]-'0')-1) - (fraction2[i]-'0'));
                s3+=char(result+'0');
                carry =false;
            }
        }
        else {
            if(carry== false){
                int result = (fraction1[i]-'0')-(fraction2[i]-'0');
                s3+=char(result+'0');
            }
            else{
                int num1 = 10+(fraction1[i]-'0');
                num1-=1;
                int result = num1-(fraction2[i]-'0');
                s3+=char(result+'0');
            }
        }
    }
    s3+='.';
    string  int1 = s1.substr(0,s1.find('.'));
    string int2 = s2.substr(0,s2.find('.'));
    int max_lenght = max(int1.size(),int2.size());
    s3 = string(max_lenght-int1.size(),'0')+s3;
    int1  =string(max_lenght-int1.size(),'0')+int1;
    int2  =string(max_lenght-int2.size(),'0')+int2;

    for(int i= int1.size()-1;i>=0;i--){
        if(int1[i]<int2[i]){

            if(carry ==false){
                cnt=0;
                int num1 = 10+(int1[i]-'0');
                int result = num1-(int2[i]-'0');
                s3+=char(result+'0');
//                cnt++;
                carry = true;

            }

            else {
                int num1 = (10+(int1[i]-'0'))-1;
                int result = num1-(int2[i]-'0');
                s3+=char(result+'0');
//                cnt++;

            }

        }
        else if (int1[i]>int2[i]){
            if(carry ==false){
                int result = (int1[i]-'0') - (int2[i]-'0');
                s3+=char(result+'0');
                carry = false;

            }
            else {

                int result = (((int1[i]-'0')-1) - (int2[i]-'0'));
                s3+=char(result+'0');
                carry =false;
            }
        }
        else {
            if(carry== false){
                int result = (int1[i]-'0')-(int2[i]-'0');
                s3+=char(result+'0');
            }
            else{
                int num1 = 10+(int1[i]-'0');
                num1-=1;
                int result = num1-(int2[i]-'0');
                s3+=char(result+'0');
            }
        }
    }
    reverse(s3.begin(),s3.end());
    return s3;
}
string equal_size_fraction(string s1,string s2){

    string  int1 = s1.substr(0,s1.find('.'));
    string int2 = s2.substr(0,s2.find('.'));
    string fraction1 = s1.substr(s1.find('.')+1,s1.size());
    string fraction2 = s2.substr(s2.find('.')+1,s2.size());
    string larger,smaller,ans;
    if(equal_size(int1,int2)){
        if(greather_than(int1,int2)){
            larger = s1;
            smaller = s2;
            ans = sustracting_fraction(larger,smaller);
        }
        else if(!greather_than(int1, int2)){
            if(greater_fraction(s1,s2)) {
                larger =s1;
                smaller=s2;
                ans = sustracting_fraction(larger,smaller);

            }
            else {
                larger=s2;
                smaller=s1;
                ans = sustracting_fraction(larger,smaller);

            }
        }
    }
    else {
        if(int1.size()>int2.size()){
            larger=s1;
            smaller=s2;
            ans = sustracting_fraction(larger,smaller);

        }
        else if(int1.size()<int2.size()) {
            larger = s2;
            smaller=s1;
            ans = sustracting_fraction(larger,smaller);

        }
    }
    return ans;
}

#endif //ASSIGNMENT_2_OOP_SUBSTRACTING_H
