//============================================================================
// Name        : Airfoil Calculator.cpp
// Author      : Trent Collins
// Description : Calculate lift and drag for given air foils
//============================================================================

#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int main() {

double x1=0, y1=0, x2=0, y2=0; //set up data variables that will be used
double s=0; //total surface area (unitless)
double r=0,dx,dy;//variable used to simplify steps in calculation
double cl, cd, wn;// variables for the coefficients of lift and drag, wn stands for wing number
double q, p=0.413, v=50; // dynamic pressure, density (kg/m^3), velocity (m/s)
double L, D; // lift and drag (wing with length of 1 m)
int n=0;
char type, vall;
cout<<"Which airfoil would you like to calculate the lift for? NACA 0009 (a), NACA 0012 (b), NACA 2414 (c), NACA 2415 (d)"<<endl;
cin>>type;
while(type!='a'&& type!='b'&& type!='c'&&type!='d'){
cout<<"Invalid input, try again:\n";
cin>>type;
}
switch (type){
case 'a':
{
ifstream file;
	file.open ("NACA0009.dat"); //open data file that will be used
		file>>x1>>y1>>x2>>y2;
	for(n=0;n<70;n++){//loop initialization


		dx=x2-x1; //change in x
		dy=y2-y1; //change in y

		r= pow(dx,2)+pow(dy,2);
		s += pow(r,0.5); //Distance formula
		x1=x2;
		y1=y2;
		file>>x2>>y2;
	}
}
	break;


case 'b':
{
	ifstream file;
	file.open ("NACA0012.dat"); //open data file that will be used
		file>>x1>>y1>>x2>>y2;
	for(n=0;n<70;n++){//loop initialization


		dx=x2-x1; //change in x
		dy=y2-y1; //change in y

		r= pow(dx,2)+pow(dy,2);
		s += pow(r,0.5); //Distance formula
		x1=x2;
		y1=y2;
		file>>x2>>y2;


}
}
	break;
case 'c':
{
	ifstream file;
	file.open ("NACA2414.dat"); //open data file that will be used
		file>>x1>>y1>>x2>>y2;
	for(n=0;n<70;n++){//loop initialization


		dx=x2-x1; //change in x
		dy=y2-y1; //change in y

		r= pow(dx,2)+pow(dy,2);
		s += pow(r,0.5); //Distance formula
		x1=x2;
		y1=y2;
		file>>x2>>y2;


}
}
	break;

case 'd':
{
	ifstream file;
	file.open ("NACA2415.dat"); //open data file that will be used
		file>>x1>>y1>>x2>>y2;
	for(n=0;n<70;n++){//loop initialization


		dx=x2-x1; //change in x
		dy=y2-y1; //change in y

		r= pow(dx,2)+pow(dy,2);
		s += pow(r,0.5); //Distance formula
		x1=x2;
		y1=y2;
		file>>x2>>y2;


}
}
	break;
default:
	cout<<"Invalid input";
}

if (type=='a'){
	cl=0.2974; cd=0.02197; wn=9; //at alpha=3 degrees
}else if (type=='b'){
	cl=0.4492; cd=0.02334; wn=12;
}else if (type=='c'){
	cl= 0.4365; cd=0.03678; wn=2414;
}else if (type=='d'){
	cl=0.3950; cd=0.03968; wn=2415;
}


q= (0.5)*p*(pow(v,2)); //calculate dynamic pressure
L= q * s * cl; //calculate lift
D= q * s * cd; //calculate drag

cout<<"For NACA "<<wn<<" lift is equal to: "<<L<<" N and drag is equal to: "<<D<<" N"<<endl;
cout<<"Values found: surface area is "<<s<<" coefficient of lift is "<<cl<<" and coefficient of drag is "<<cd;
	return 0;
}
