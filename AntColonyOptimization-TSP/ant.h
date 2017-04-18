//Emad Khezri
//Ant Class

#ifndef ANT_H
#define ANT_H

class Ant
{
private:
	int numberOfCities; //Number of city in the map
	City* path; //Path of ant
	int start; //Start point of path
	int current; //Current point of path
	double totalDistance; //Total Distance of path

public:
	Ant(){}; //Default Constraction
	void initialize(int,City*,double**,double**); //Initialize ant variables
	void setStart(int s_argu) {start=s_argu;} //Set the start pointer
	int getStart() {return start;} //Return Start pointer
	int getCurrent() {return current;} //Return current pointer
	void reset(); //Reset Path and current
	City searchPath(int key_argu); //Return key element of the path
	string getPath(); //Return string of path of ant
	int getNextCity(double**); //Return index of next city to be go
	void setNextCityOfPath(int); //setting the next element of path
	void reinforceVPheremone(double **,double**); //Reinforce the edges it has used
	double getTotalDistance(double **); //return total distance of path
};

#endif