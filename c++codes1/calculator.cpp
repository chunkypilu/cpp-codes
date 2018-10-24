//File including and preprocessor declaration
#include <iostream>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#define new_cal 1
#define old_cal 0
//stand_calc class to define standard calculator functions
class stand_calc
{
/*Protyping of standard calculator functions. These functions
are static, therefore calling of these functions is possible with
the name of the class. There is no need to create an object of the
class. */
public:
static double addition(double,double);
static double subtract(double,double);
static double multiplication(double,double);
static double division(double,double *);
static double modulus(double *,double *);
};
//scien_calc class to define scientific calculator functions
class scien_calc
{
public:
static double square(double);
static double cube(double);
static double power(double,double);
static double sq_root(double);
static long int fact(double);
static double sin_func(double);
static double cos_func(double);
static double tan_func(double);
};
//addition function will add two numbers
double stand_calc::addition(double a, double b)
{
return(a+b);
}
//subtract function will subtract the second number from the first
number double stand_calc::subtract(double a, double b)
{
return(a-b);
}
//multiplication function will multiply two numbers
double stand_calc::multiplication(double a, double b)
{
return(a*b);
}
/*division function will divide the first number by the second
number. This function accepts two arguments, one is copy of a
variable and another is pointer type because if accepting divisor is
zero, then this function will show a message to enter the divisor
again. Using pointer means that the entered value of the divisor for
this function should be updated at the main function also.*/
double stand_calc::division(double a, double *b)
{
while(*b==0)
{
cout<<“\nCannot divide by zero.”;
cout<<“\nEnter second number again:”;
cin>>*b;
}
return(a/(*b));
}


double stand_calc::modulus(double *a, double *b)
{
while(*b==0)
{
cout<<“\nCannot divide by zero.”;
cout<<“\nEnter second number again:”;
cin>>*b;
}
//Converting double into an integer
int x=(int)*a;
int y=(int)*b;
if(*a-x>0||*b-y>0)
cout<<“\nConverting decimal number into an integer to
perform modulus”;
*a=x;
*b=y;
return(x%y);
}
//Declaration of scien_calc class functions starts from here.
//square function of scien_calc class to return accepting number to
the power 2
double scien_calc::square(double x)
{
return(pow(x,2));
}
//cube function of scien_calc class to return accepting number to
the power 3
double scien_calc::cube(double x)
{
return(pow(x,3));
}
//power function of scien_calc class to return the first number to
the power of the second number
double scien_calc::power(double x,double y)
{
return(pow(x,y));
}
//sq_rrot function of scien_calc class to return the square root of
the entered number double scien_calc::sq_root(double x)
{
return(sqrt(x));
}
/*fact function of the scien_calc class to return a long integer as
factorial of an accepting number. This will convert accepting number
into an integer before calculating the factorial*/
long int scien_calc::fact(double x)


{
int n=(int)x;
long int f=l;
while(n>l)
{
f*=n;
n-;
}
return f;
}
//sin_func of the scien_calc class to return the sin value of x
double scien_calc::sin_func(double x)
{
return(sin(x));
}
//cos_func of the scien_calc class to return the cos value of x
double scien_calc::cos_func(double x)
{
return(cos(x));
}
//tan_func of the scien_calc class to return the tan value of x
double scien_calc::tan_func(double x)
{
return(tan(x));
}
//Displaying the menus to enter the options and values
void main ()
{
double numl, num2, num3, temp;
int choicel=0,choice2,flag;
//Loop of main menu from where the program starts. It will show
the menu to choose the type of calculator.
do
{
clrscr();
cout <<“========Type of Calculators=======”;
cout <<“\nl\tStandard Calculator\n2\tScientific Calculator
\n3\tQuit”;
cout<<“\nChoose the type of calculator:”;
cin>>choiwce1;
flag=new_cal;
//To perform an operation according to the entered option in
the main menu switch(choice1)
{
case 1:
//Loop to display the standard calculator menu
do
{
clrscr();
cout<<“==========Standard Calculator===========”;

cout<<“\nl\tAddition\n2\tSubtraction\n3\tMultiplication\n4\
tDivision\n5\tModulus\n6\tReturn to Previous Menu\n7\tQuit”;
//Option 8 will be displayed only when working on
old calculations. Here, already a number is saved in the calculator
memory.
if(flag==old_cal)
cout<<“\n8\tClear Memory”;
cout <<“\nChoose the type of calculation:”;
cin>>choice2;
//To perform operation and call functions of the
stand_calc class
switch(choice2)
{
case 1:
//If a new calculation is there,
then accept the first number else previous calculation result will
be the first number.
if (flag==new_cal)
{
cout<<“Enter first number:”;
cin>>numl;
}
else
{
numl=temp;
cout<<“\nFirst number is
”<<numl<<endl;
}
cout<<“Enter second number:”;
cin>>num2;
num3=stand_calc::addition(numl,num2);
cout<<“\nAddition of ”<<numl<<“ and
”<<num2<<“ is ”<<num3;
cout<<“\nPress any key to
continue.........”;
getch();
temp=num3;
flag=old_cal;
break;
case 2:
if (flag==new_cal)
{
cout<<“Enter first number:”;
cin>>numl;
}
else
{
numl=temp;
cout<<“\nFirst number is
”<<numl<<endl;
}
cout<<“Enter second number:”;
cin>>num2;
num3=stand_calc::subtract(numl,num2);
cout<<“\nSubtraction of ”<<num2<<“
from ”<<numl<<“ is ”<<num3;
cout<<“\nPress any key to
continue.........”;
getch();
temp=num3;
flag=old_cal;
break;
case 3:
if (flag==new_cal)
{
cout<<“Enter first number:”;
cin>>num1;
}
else
{
numl=temp;
cout<<“\nFirst number is
”<<num1<<endl;
}
cout<<“Enter second number:”;
cin>>num2;
num3=stand_calc::multiplication(numl,num2);
cout<<“\nMultiplication of ”<<numl<<“
and ”<<num2<<“ is ”<<num3;
cout<<“\nPress any key to
continue........”;
getch();
temp=num3;
flag=old_cal;
break;
case 4:
if (flag==new_cal)
{
cout<<“Enter first number:”;
cin>>numl;
}
else
{
num1=temp;
cout<<“\nFirst number is
”<<numl<<end1;
}
cout<<“Enter second number:”;
cin>>num2;
num3=stand_calc::division(numl,&num2);
cout<<“\nDivision of ”<<numl<<“ by
”<<num2<<“ is ”<<num3;
cout<<“\nPress any key to

continue.........”;
getch();
temp=num3;
flag=old_cal;
break;
case 5:
if (flag==new_cal)
{
cout<<“Enter first number:”;
cin>>num1;
}
else
{
num1=temp;
cout<<“\nFirst number is
”<<numl<<end1;
}
cout<<“Enter second number:”;
cin>>num2;
num3=stand_calc::modulus(&numl,&num2);
cout<<“\nModulus of ”<<numl<<“ by
”<<num2<<“ is ”<<num3;
cout<<“\nPress any key to
continue.........”;
getch();
temp=num3;
flag=old_cal;
break;
case 6:
cout<<“\nReturning to previous menu.”;
cout<<“\nPress any key to
continue.........”;
getch();
break;
case 7:
cout<<“\nQuitting..........”;
cout<<“\nPress any key to
continue.........”;
getch();
exit(O);
case 8:
//If a new calculation is going on
then 8 is an invalid option, else 8 is an option to start a new calculation
if(flag==new_cal)
{
cout<<“\nInvalid choice.”;
cout<<“\nPress any key to
continue.........”;
getch();
}
else
{
temp=;
flag=new_cal;
}
break;
default:
cout<<“\nInvalid choice.”;
cout<<“\nPress any key to
continue.........”;
getch();
break;
}
}while (choice2!=6);
break;
case 2:
//Loop to display scientific calculator menu
do
{
clrscr();
cout<<“==========Scientific Calculator=========”;
cout<<“\nl\tSquare\n2\tCube\n3\tPower\n4\tFactorial\n5\tSin\n6\tCos\
n7\tTan\n8\tReturn to previous menu\n9\tQuit”;
if(flag==old_cal)
cout<<“\nlO\tClear Memory”;
cout<<“\nChoose the type of calculation:”;
cin>>choice2;
switch(choice2)
{
case 1:
if (flag==new_cal)
{
cout<<“Enter number to find
square:”;
cin>>numl;
}
else
{
numl=temp;
cout<<“\nNumber is
”<<numl<<endl;
}
num3=scien_calc::square(numl);
cout<<“\nSquare of ”<<numl<<“ is
”<<num3;
cout<<“\nPress any key to
continue.........”;
getch();
temp=num3;
flag=old_cal;
break;
case 2:
if (flag==new_cal)

{
cout<<“Enter number to find
cube:”;
cin>>num1;
}
else
{
num1=temp;
cout<<“\nNumber is
”<<numl<<end1;
}
num3=scien_calc::cube(num1);
cout<<“\nCube of ”<<num1<<“ is
”<<num3;
cout<<“\nPress any key to
continue.........”;
getch();
temp=num3;
flag=old_cal;
break;
case 3:
if (flag==new_cal)
{
cout<<“Enter first number
for base to find power:”;
cin>>numl;
}
else
{
numl=temp;
cout<<“\nFirst number is
”<<num1<<end1;
}
cout<<“Enter second number for power
to find power”;
cin>>num2;
num3=scien_calc::power(numl,num2);
cout<<“\n”<<numl<<“ to the power
”<<num2<<“ is ”<<num3;
cout<<“\n Press any key to
continue.........”;
getch();
temp=num3;
flag=old_cal;
break;
case 4:
if (flag==new_ca1)
{
cout<<“Enter number to find
factorial:”;
cin>>numl;
}

else
{
numl=temp;
cout<<“\nNumber to find
factorial is ”<<numl<<endl;
}
long int num4=scien_calc::fact(numl);
cout<<“\nFactorial of ”<<numl<<“ is
”<<num4;
cout<<“\nPress any key to
continue.........”;
getch();
temp=num4;
flag=old_cal;
break;
case 5:
if (flag==new_cal)
{
cout<<“Enter number to find
sin value:”;
cin>>numl;
}
else
{
numl=temp;
cout<<“\nNumber for sin value
is ”<<numl<<endl;
}
num3=scien__calc:: sin_func(numl);
cout<<“\nSin value of”<<numl<<“is
”<<num3;
cout<<“\nPress any key to
continue.........”;
getch();
temp=num3;
flag=old_cal;
break;
case 6:
if (flag==new_cal)
{
cout<<“Enter number to find
cos value:”;
cin>>numl;
}
else
{
numl=temp;
cout<<“\nNumber for cos value
is ”<<numl<<end1;
}
num3=scien_calc::cos_func(numl);

cout<<“\nCos value of ”<<numl<<“ is
”<<num3;
cout<<“\nPress any key to
continue.........”;
getch();
temp=num3;
flag=old_cal;
break;
case 7:
if (flag==new_cal)
{
cout<<“Enter number to find
tan value:”;
cin>>numl;
}
else
{
num1=temp;
cout<<“\nNumber for tan value
is ”<<numl<<endl;
}
num3=scien_calc::tan_func(numl);
cout<<“\nTan value of ”<<numl<<“ is
”<<num3;
cout<<“\nPress any key to
continue.........”;
getch();
temp=num3;
flag=old_cal;
break;
case 8:
cout<<“\nReturning to previous menu.”;
cout<<“\nPress any key to
continue.........”;
getch();
break;
case 9:
cout<<“\nQuitting............”;
cout<<“\nPress any key to
continue.........”;
getch();
exit(0);
case 10:
if(flag==new_cal)
{
cout<<“\nInvalid choice.”;
cout<<“\nPress any key to
continue.........”;
getch();
}
else

{
temp=0;
flag=new_cal;
}
break;
default:
cout<<“\nInvalid choice.”;
cout<<“\nPress any key to
continue.........”;
getch();
break;
}
} While (choice2!=8);
break;
case 3:
cout<<“\nQuitting........”;
cout<<“\nPress any key to continue........”;
getch();
break;
default
cout<<“\nInvalid Choice.”;
cout<<“\npress any key to continue........”;
getch();
break;
}
}while (choice1!=3);
}
