///double(7): bijoy+jahangir, 
///        mobin_vai,
///        noor+salauddin
///        sojib+tanvir

///single(15): sumon,bappy,monir_vai,nazmul_vai,
///        sakib,morsa,himel,asad,mohabbat,
///        imran,hridoy,amit,jibon,raihan,parvej.
/// total border: 22.

/// laptop(8): sumon,bijoy,mubin_vai,
///          monir_vai,nazmul_vai,
///          noor,sojib,mohabbat.

///desktop(3): morsa,bappy,sakib.

///cooker(2): asad, mohabbat
///iron(2): jahangir, amit

#include <bits/stdc++.h>

using namespace std;

int main()
{
    double Bill,motor,_double,single,laptop,desktop,heater,cooker,Taka,head,extra,money;
    cout<<"Enter Total Amount: ";
    cin>>Bill;
    cout<<"Motor_Bill_per_Person: ";
    cin>>motor;
    cout<<"Double: ";
    cin>>_double;
    cout<<"Single: ";
    cin>>single;
    cout<<"Laptop: ";
    cin>>laptop;
    cout<<"Desktop: ";
    cin>>desktop;
    cout<<"Water Heater: ";
    cin>>heater;
    cout<<"Rice Cooker: ";
    cin>>cooker;
    laptop = 30*laptop;
    desktop = 50*desktop;
    heater = 10*heater;
    cooker = 90*cooker;
    Taka = Bill - (laptop+desktop+heater+cooker);
    cout<<"taka: "<<Taka<<endl;
    head = (Taka/(single+_double));
    cout<<"head: "<<head<<endl;
    extra = head/3;
    cout<<"extra: "<<extra<<endl;
    //single = single*extra;
    money = Taka - (single*extra);
    cout<<"money: "<<money<<endl;
    money = money/(single+_double);
    cout<<"money: "<<money<<endl;
    cout<<"Double: "<<(int)money+motor+3<<endl;
    cout<<"Single: "<<(int)(money+extra+motor+3)<<endl;
    return 0;
}
