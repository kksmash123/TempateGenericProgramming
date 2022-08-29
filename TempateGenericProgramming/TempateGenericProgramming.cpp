#include <iostream>
using namespace std;

//template function declaration

template <typename T> void basicFun1(T x);
template <typename T1, typename T2> void basicFun2(T1 x, T2 y);
template <typename T1, typename T2 = int> void basicFun3(T1 x, T2 y);
template <typename T> void BasicFun4(T x, int y);



//template function definition
//1.Basic single type parameter
template <typename T> 
void basicFun1(T x)
{
    cout <<"Value at x : "<< x << endl;
}


//2.Multiple type parameter
template <typename T1, typename T2> 
void basicFun2(T1 x,T2 y)
{
    cout << "value at x : " << x << " | Value at y : " << y << endl;

}


//3. with defualt parameter
template <typename T1,typename T2 =int> 
void basicFun3(T1 x, T2 y)
{
    cout << "value at x : " << x << " | Value at y : " << y << endl;
}


//4.using different type with some constant parameter
template <typename T>
void BasicFun4(T x,int y)
{
    cout << "value at x : " << x << " | Value at y : " << y << endl;
}


//5.overloading template function called explicit specialization 
//Explicitly overload function for specific datatype 
//here overloading the basic single parameter template function for char datatype
template <> void basicFun1<char>(char x)
{
    cout << "Template basicFun1 overloading for char : " << endl;
    cout << "value at x : " << x<<endl;
}

//6. returning different datatype as per parameter , template used for returning
template <typename T>
T findGreater(T x, T y)
{
    return x >= y ? x : y;
}


int main()
{
    //for basic fun1
    cout << "Basic Fun1 :" << endl;
    basicFun1(10);
    basicFun1(20.5);
    basicFun1("keerthana");
    basicFun1('a');

    //for basic fun2
    cout << "Basic Fun2 :" << endl;
    basicFun2(10, 20);
    basicFun2(10.5, 20);
    basicFun2("pavi", 20.25);
    basicFun2(10, "keer");

    //with defualt template parameter
    cout << "Basic Fun3 :" << endl;
    basicFun3(10,20);
    basicFun3("keerthana", "pavithra");
    basicFun3("keerthana", 'a');


    //with constant parameter

    cout << "Basic Fun4 : " << endl;
    BasicFun4(10, 10);    //y->given as int , taken as int only
    BasicFun4(10, 'a');   //y->given as char ,taken as int by convert to its ascii value
    BasicFun4(10, 20.25); //y->given as float, taken as int by truncate its value after decimal
    //BasicFun4(10, "keerthana"); -> error reason argument mismatch 
    //it is much intelligent that convert float and char to its expected type 
    //but string can't convertable so it throws error

   
    //Different Return type using template function

    cout << "Find Greater : " << endl;
    cout << "Find Greater Results : " << findGreater(10, 10)<<endl;
    cout << "Find Greater Results : " << findGreater(5.5, 2.5) << endl;
    cout << "Find Greater Results : " << findGreater('a', 'A')<<endl;

}
