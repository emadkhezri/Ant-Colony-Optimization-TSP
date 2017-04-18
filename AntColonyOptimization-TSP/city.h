//Emad Khezri
//City Class
//Each city has x,y and index

#ifndef CITY_H
#define CITY_H

class City
{
private:
	int x,y,index; //X and Y coordinate of city,Index which related to the city
	bool visited; //is it visited in the past or not?
public:
	City() {x=y=index=0;visited=false;} //Default constraction
	City(int,int,int); //Constraction whit input argu
	int getX(); //Return X coordinate of city
	int getY(); //Return Y coordinate of city
	int getIndex(); //Return Index of city
	bool isVisited(); //Return True if the city is visited
	void setX(int x_argu) {x=x_argu;} //Replace X coordinate with argu
	void setY(int y_argu) {y=y_argu;} //Replace Y coordinate with argu
	void setIndex(int i_argu) {index = i_argu;} //Replace Index with argu
	void setVisited(bool b) {visited = b;} //Set visited true
};

#endif