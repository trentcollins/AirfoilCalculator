//============================================================================
// Name        : AEM.cpp
// Author      : Trent Collins
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int main() {

double x1=0, y1=0, x2=0, y2=0; //set up data variables that will be used
double s=0; //total surface area
double r=0,dx,dy;//variable used to simplify steps in calculation
double cl, cd;// variables for the coefficients of lift and drag
int n=0;
char type;
cout<<"Which airfoil would you like to calculate the lift for? NACA 0009 (a), NACA 0012 (b), NACA 2414 (c), NACA (2415) (d)"<<endl;
cin>>type;
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
	cl=0.2974; cd=0.02197; //at alpha=3 degrees
}else if (type=='b'){
	cl=0.4492; cd=0.02334;
}else if (type=='c'){
	cl= 0.4365; cd=0.03678;
}else if (type=='d'){
	cl=0.3950; cd=0.03968;
}




	return 0;
}
