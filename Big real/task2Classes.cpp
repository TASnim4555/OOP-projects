
#include "task2Classes.h"
#include "adding.h"
#include "substracting.h"

BigReal::BigReal(string no):num(no) // initialized  constructor to set num by given string from the user
 {

     if(is_Valid(num))
     { int_part = "";
         frac_part="";
         size = num.length();
         bool fl =true;
         for(int i =0;i< size;i++){
             if(num[0]=='+'||num[0]=='-')
                 sign =num[0];
             else
                 sign = '+';
             if(num[i]=='.'){
                 fl =false;
                 place_of_point = i;
             }
             if(fl&&num[i]!='+'&&num[i]!='-'&&num[i]!='.'){
                 int_part+= num[i];
             }
             else if(!fl &&num[i]!='+'&&num[i]!='-'&&num[i]!='.'){
                 frac_part+= num[i];
             }

         }
         num = {num.begin()+1,num.end()};
         if(int_part.empty())
             int_part= "0";
         if(frac_part.empty())
             frac_part="0";
     }
     else { sign ='+';
         num = "0.0";
         int_part = "0";
         frac_part = "0";
         place_of_point =1;
     }


}


BigReal::BigReal() :num("0.0")// default constructor to set num by 0.0
{

}


int BigReal::get_size()  // return the size of int exclude the sign
{
    return size-1;
}


char BigReal::get_sign() {
    return sign; // return the sign

}


string BigReal::get_intPart() {
    return int_part;
}


string BigReal::get_fracPart() { // return fract part
    return frac_part;
}

bool BigReal::is_Valid(string num) // check if the given string is real number
{
    int iter =0;
    bool f1 = 1; // bool to check the point
    size = num.length();
    if(size==1&&(num[0]<'0'||num[0]>'9')) //check if the num is one digit and a number
        return 0;
    else if(size==2&&(num[1]<'0'||num[1]>'9'))  // check if the num is 2 digits and index 1 is a number
        return 0;
    else if(size==0) // if num is empty
        return 0;

    if(num[0]=='+'||num[0]=='-') // if the number start is sign
        sign = num[0],iter =1;
    else if(num[0]>='0'&&num[0]<='9') // if not sign given consider it's +
        sign = '+';
    else return 0;


    for (int i = iter;i<size;++i){ // start iteration after the sign to check other digits
        if(num[i]=='.') // check number of points if they are more than 1 return not valid
        {
            if(f1)
                f1 =0,place_of_point = i;
            else
                return 0;
        }
        else if(num[i]<'0'||num[i]>'9') // if you found a char not a point nor number return false it is not valid num
            return 0;


    }
    if(int_part == "") // if not int part assign it by 0
        int_part = "0";
    if(frac_part =="") // if not fract  part assign it by 0
        frac_part = "0";

    return 1; // return valid if all invalid conditions not satisfied
}
BigReal BigReal::operator+(BigReal &n2)
{
    BigReal n3;

        if((std::count(this->num.begin(), this->num.end(),'.')==0&&count(n2.num.begin(),n2.num.end(),'.')>0)||(count(this->num.begin(), this->num.end(),'.')>0&&count(n2.num.begin(),n2.num.end(),'.')>0)||(count(this->num.begin(), this->num.end(),'.')>0&&count(n2.num.begin(),n2.num.end(),'.')==0)){
           if(this->sign=='+'&&n2.sign=='+'){
               n3.num= adding_fraction(n2.num, this->num);
               n3.sign='+';

           }
           else if(this->sign=='-'&&n2.sign=='+') {
               if( *this < n2){

                   n3.num = equal_size_fraction(n2.num,this->num);
                   n3.sign='+';
               }
               else {
                   n3.num = equal_size_fraction(this->num,n2.num);
                   n3.sign='-';
               }
           }
           else if(this->sign=='+'&&n2.sign=='-'){
               if(*this<n2){
                   n3.num = equal_size_fraction(n2.num,this->num);
                   n3.sign='-';
               }
               else {
                   n3.num = equal_size_fraction(this->num,n2.num);
                   n3.sign='+';
               }
           }
           else if(this->sign=='-'&&n2.sign=='-'){
               n3.num = adding_fraction(this->num,n2.num);
               n3.sign='-';
           }

        }
        else {
            if(this->sign=='+'&&n2.sign=='+'){
                n3.num= adding(n2.int_part, this->int_part);
                n3.sign='+';

            }
            else if(this->sign=='-'&&n2.sign=='+') {
                if(*this<n2){
                    n3.num = equal_size_fraction(n2.num,this->num);
                    n3.sign='+';
                }
                else {
                    n3.num = equal_size_fraction(this->num,n2.num);
                    n3.sign='-';
                }
            }
            else if(this->sign=='+'&&n2.sign=='-'){
                if(*this<n2){
                    n3.num = equal_size_fraction(n2.num,this->num);
                    n3.sign='-';
                }
                else {
                    n3.num = equal_size_fraction(this->num,n2.num);
                    n3.sign='+';
                }
            }
            else{
                n3.num = adding(this->num,n2.num);
                n3.sign='-';
            }        }
  n3.setNum(n3.num);



return n3;

}
BigReal BigReal::operator-(BigReal &n2) {
    BigReal n3;


    if((std::count(this->num.begin(), this->num.end(),'.')==0&&count(n2.num.begin(),n2.num.end(),'.')>0)||(count(this->num.begin(), this->num.end(),'.')>0&&count(n2.num.begin(),n2.num.end(),'.')>0)||(count(this->num.begin(), this->num.end(),'.')>0&&count(n2.num.begin(),n2.num.end(),'.')==0)){
        if(this->sign=='+'&&n2.sign=='+'){
            if(*this>n2){
                n3.num= sustracting_fraction(this->num,n2.num);
                n3.sign='+';
            }
            else {
                n3.num= sustracting_fraction(n2.num,this->num);
                n3.sign='-';
            }


        }
        else if(this->sign=='-'&&n2.sign=='+') {
            if(*this>n2){
                n3.num= adding_fraction(n2.num,this->num);
                n3.sign='+';
            }
            else {
                n3.num= sustracting_fraction(n2.num,this->num);
                n3.sign='-';
            }
        }
        else if(this->sign=='+'&&n2.sign=='-'){
   n3.num = adding_fraction(this->num,n2.num);
   n3.sign ='+';
        }
        else{
            if(*this>n2){
                n3.num= sustracting_fraction(this->num,n2.num);
                n3.sign='-';
            }
            else {
                n3.num= sustracting_fraction(n2.num,this->num);
                n3.sign='+';
            }
        }

    }
    else {
//n3.num= n3.int_part;
        if(this->sign=='+'&&n2.sign=='+'){
            if(*this>n2){
                n3.num= substracting(this->num,n2.num);
                n3.sign='+';
            }
            else {
                n3.num= substracting(n2.num,this->num);
                n3.sign='-';
            }


        }
        else if(this->sign=='-'&&n2.sign=='+') {
            if(*this>n2){
                n3.num= substracting(this->num,n2.num);
                n3.sign='+';
            }
            else {
                n3.num= substracting(n2.num,this->num);
                n3.sign='-';
            }
        }
        else if(this->sign=='+'&&n2.sign=='-'){

            n3.num = substracting(this->num,n2.num);
        }
        else{
            if(*this>n2){
                n3.num= substracting(this->num,n2.num);
                n3.sign='-';
            }
            else {
                n3.num= substracting(n2.num,this->num);
                n3.sign='+';
            }
        }     }
    n3.setNum(n3.num);



    return n3;
}

bool BigReal::operator< (BigReal anotherReal){
    if (sign=='+'&&anotherReal.sign=='-'){
        return false;
    }
    else if (sign=='-'&&anotherReal.sign=='+'){
        return true;
    }
    else if (sign=='+'&&anotherReal.sign=='+'||sign=='-'&&anotherReal.sign=='-'){

        if (int_part.size()==anotherReal.int_part.size()){
            if (int_part<anotherReal.int_part) return true;
            else if (int_part==anotherReal.int_part){
                if (frac_part.size()==anotherReal.frac_part.size()){
                    if (frac_part<anotherReal.frac_part) return true;
                }
                else if (frac_part.size()!=anotherReal.frac_part.size()){
                    int s1=frac_part.size();int s2=anotherReal.frac_part.size();
                    if (s1>s2){
                        int loops = s1-s2;
                        while (loops--){
                            anotherReal.frac_part.push_back('0');
                        }
                    }
                    else if (s1<s2){
                        int loops = s2-s1;
                        while (loops--){
                            frac_part.push_back('0');
                        }
                    }
                    if (frac_part<anotherReal.frac_part) return true;
                }
            }
        }
        else if (int_part.size()!=anotherReal.int_part.size()){
            int size1=int_part.size();int size2=anotherReal.int_part.size();
            if (size1>size2){
                int t = size1-size2;
                while (t--){
                    anotherReal.int_part='0'+anotherReal.int_part;
                }
            }
            else if (size1<size2){
                int t = size2-size1;
                while (t--){
                    int_part='0'+int_part;
                }
            }
            if (int_part<anotherReal.int_part) return true;
        }
        else return false ;
    }
}
//Bigger then operator >
bool BigReal::operator> (BigReal anotherReal){
    if (sign=='+'&&anotherReal.sign=='-'){
        return true;
    }
    else if (sign=='-'&&anotherReal.sign=='+'){
        return false;
    }
    else if (sign=='+'&&anotherReal.sign=='+'||sign=='-'&&anotherReal.sign=='-'){

        if (int_part.size()==anotherReal.int_part.size()){
            if (int_part>anotherReal.int_part) return true;
            else if (int_part==anotherReal.int_part){
                if (frac_part.size()==anotherReal.frac_part.size()){
                    if (frac_part>anotherReal.frac_part) return true;
                }
                else if (frac_part.size()!=anotherReal.frac_part.size()){
                    int s1=frac_part.size();int s2=anotherReal.frac_part.size();
                    if (s1>s2){
                        int loops = s1-s2;
                        while (loops--){
                            anotherReal.frac_part.push_back('0');
                        }
                    } else if (s1 < s2) {
                        int loops = s2 - s1;
                        while (loops--) {
                            frac_part.push_back('0');
                        }
                    }
                    if (frac_part > anotherReal.frac_part) return true;
                }
            }
        } else if (int_part.size() != anotherReal.int_part.size()) {
            int size1 = int_part.size();
            int size2 = anotherReal.int_part.size();
            if (size1 > size2) {
                int t = size1 - size2;
                while (t--) {
                    anotherReal.int_part = '0' + anotherReal.int_part;
                }
            } else if (size1 < size2) {
                int t = size2 - size1;
                while (t--) {
                    int_part = '0' + int_part;
                }
            }
            if (int_part > anotherReal.int_part) return true;
        } else return false;
    }
}



//operator equality
bool BigReal::operator== (BigReal anotherReal){
    if (sign==anotherReal.sign){
        if (int_part.size()==anotherReal.int_part.size()){
            if (frac_part.size()==anotherReal.frac_part.size()){
                if (int_part==anotherReal.int_part&&frac_part==anotherReal.frac_part){
                    return true;
                }
            }
            else if (frac_part.size()!=anotherReal.frac_part.size()){
                int s1=frac_part.size();int s2=anotherReal.frac_part.size();
                if (s1>s2){
                    int loops = s1-s2;
                    while (loops--){
                        anotherReal.frac_part.push_back('0');
                    }
                }
                else if (s1<s2){
                    int loops = s2-s1;
                    while (loops--){
                        frac_part.push_back('0');
                    }
                }
                if (int_part==anotherReal.int_part&&frac_part==anotherReal.frac_part) return true;
            }
        }
        else if (int_part.size()!=anotherReal.int_part.size()){
            int size1=int_part.size();int size2=anotherReal.int_part.size();
            if (size1>size2){
                int t = size1-size2;
                while (t--){
                    anotherReal.int_part='0'+anotherReal.int_part;
                }
            }
            else if (size1<size2){
                int t = size2-size1;
                while (t--){
                    int_part='0'+int_part;
                }
            }
            if (frac_part.size()==anotherReal.frac_part.size()){
                if (int_part==anotherReal.int_part&&frac_part==anotherReal.frac_part) return true;
            } else if (frac_part.size()!=anotherReal.frac_part.size()){
                int s1=frac_part.size();int s2=anotherReal.frac_part.size();
                if (s1>s2){
                    int loops = s1-s2;
                    while (loops--){
                        anotherReal.frac_part.push_back('0');
                    }
                }
                else if (s1<s2){
                    int loops = s2-s1;
                    while (loops--){
                        frac_part.push_back('0');
                    }
                }
                if (int_part==anotherReal.int_part&&frac_part==anotherReal.frac_part) return true;
            }
        }
    }
    return false ;
}
//cout overloading
ostream& operator<< (ostream& out, BigReal& num){
  out << num.sign<<num.num;
    return out;
}

BigReal::BigReal(const BigReal &other) {
   //cout<< "this is setted copy constructor\n";
      sign = other.sign;
      size = other.size;
     int_part = other.int_part;
     frac_part = other.frac_part;
}

void BigReal::setNum(string no) {
    if (is_Valid(no)) {
        int_part = "";
        frac_part = "";
        size = no.length();
        bool fl = true;
        for (int i = 0; i < size; i++) {
            if (no[0] == '+' || no[0] == '-')
                sign = no[0];
            else
                sign = '+';
            if (no[i] == '.') {
                fl = false;
                place_of_point = i;
            }
            if (fl && no[i] != '+' && no[i] != '-' && no[i] != '.') {
                int_part += no[i];
            } else if (!fl && no[i] != '+' && no[i] != '-' && no[i] != '.') {
                frac_part += no[i];
            }

        }
        no = {no.begin() + 1, no.end()};
        if (int_part.empty())
            int_part = "0";
        if (frac_part.empty())
            frac_part = "0";
    }
}
















