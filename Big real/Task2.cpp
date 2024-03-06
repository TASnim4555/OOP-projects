#include <iostream>
#include "task2Classes.h"
using namespace std;

int main (){
    string bigReal;
    //cin>>bigReal;
    BigReal b1("-.a2");
   // BigReal b2(bigReal);
    //BigReal b3 (b1);
    cout<<"tring doctor test cases\n";
    BigReal b4("+111111111111111111.0000000000000000000000011111111111");
    BigReal b5 ("-.0000000000000099999999999999911111111111111111999999");
    BigReal b6 ("+ 00099.999");
    BigReal b7 ("+-999000000");
    BigReal b8 ("99900.011111");
    BigReal b10 (b8);

BigReal x4 =b4+b5;
BigReal b9 = b8;
//adding test
//test 1
    BigReal x1("+11000000000000000000000006666");
    BigReal x2("+444440000000000000000000000000000000");

    BigReal x3 = (x1+x2);

cout<<x3<<'\n';
//test 2
    BigReal x6("+110000000000.000111111");
    BigReal x5("-4444400.111");

    BigReal x7 = x6+x5;

    cout<<x7<<'\n';
    //test 3
    BigReal x8("+10002");
    BigReal x9("+10.102222222222222222222222222222222222222");

    BigReal x10 = x8-x9;

    cout<<x10<<'\n';
    //test4
    BigReal x11("-1000200.1111");
    BigReal x12("+5000000000");

    BigReal x13 = x12-x11;

    cout<<x13<<'\n';
    //subtracting test
    //test 1
    BigReal x14("+1000000000");
    BigReal x15("-999999");
    BigReal x16 = x14-x15;
    cout<<x16<<"\n";
    //test2
    BigReal x17("+1000000000.111111");
    BigReal x18("+2000000");
    BigReal x19 = x17-x18;
    cout<<x19<<"\n";
    //test3
    BigReal x20 ("+10000000000000000");
    BigReal x21("-200");
    BigReal x22 = x21-x20;
    cout<<x22<<"\n";
    //test4

//    cout<<x4<<'\n';
//cout<<x4<<'\n';
//cout<<x1<<'\n';
//    cout<<b9<<'\n';
//    b9.setNum("+22.78973765");
////cout<<b9;
//if(x2>x1)
//    cout<<"x2 is greater\n";
//if(b8==b10)
//    cout<<"equality\n";
//if(b5<b6)
//    cout<<"b5 is the smallest";

}