//Emad Khezri
//Implementation of Map Class

#include "stdafx.h"


void Map::makeFile(parametrs p_argu)
{
	//Initialize variables of Map class
	numberOfCities = p_argu.numOfCities;
	minValue = p_argu.minValue;
	maxValue = p_argu.maxValue;
	fstream fHandle; //Handle to city file
	list = new City[numberOfCities]; //initialize City variable
	fHandle.open(p_argu.fileName,ios::out); //Open the file to work with

	for(int i=0; i < numberOfCities; i++)
	{
		//Insert random cities coordinate to the file and list array
		int randomXCoord,randomYCoord;
		//Generate random variable between minValue and maxValue
		randomXCoord = rand() % (maxValue-minValue) + minValue; 
		randomYCoord = rand() % (maxValue-minValue) + minValue;
		//Writing file
		fHandle<<"city ";
		fHandle<<(i+1);
		fHandle<<"   : x =  ";
		fHandle<<randomXCoord;
		fHandle<<"    y = ";
		fHandle<<randomYCoord;
		fHandle<<"\n";
		//Inserting X and Y coordinate to list array
		list[i].setIndex(i);
		list[i].setX(randomXCoord);
		list[i].setY(randomYCoord);
	}
	fHandle.close();
}

void Map::initialize(parametrs p_argu)
{

	//Initialize
	distance = new double *[numberOfCities];
	vPheremone = new double *[numberOfCities];
	probability = new double *[numberOfCities];

	for(int i=0; i < numberOfCities; i++)
	{
		distance[i] = new double[numberOfCities]();
		vPheremone[i] = new double[numberOfCities]();
		probability[i] = new double[numberOfCities]();
	}	

	//Initialize variable related to ants
	numberOfAnts = p_argu.numOfAnts;
	alpha = p_argu.alpha;
	beta = p_argu.beta;
	eFactor = p_argu.evaporateFactor;
	ant = new Ant[numberOfAnts]();

	//Calculate Distance matrix
	calcDistance();
	for(int i=0; i<numberOfAnts; i++)
		ant[i].initialize(numberOfCities,radomizeList(),distance,vPheremone);





}

City* Map::radomizeList()
{
	City* tempList = new City[numberOfCities]; //Temporary list
	City tempCity; //Temporary city
	int rand1,rand2; //Two swapping variables
	for(int i=0; i < numberOfCities ;i++)
		tempList[i] = list[i]; //Storing list in temporary list
	for(int i=0; i < numberOfCities ;i++)
	{
		rand1 = rand() % numberOfCities; //Get First index for swapping
		rand2 = rand() % numberOfCities; //Get Second index for swapping
		tempCity = tempList[rand1];
		tempList[rand1] = tempList[rand2];
		tempList[rand2] = tempCity;
	}
	return tempList; //Returning randomized list
}

void Map::calcDistance()
{
	double xElem,yElem;
	double param; //Parametr for SQRT
	for(int i=0; i < numberOfCities; i++)
		for(int j=0; j < numberOfCities; j++)
		{
			xElem = list[i].getX() - list[j].getX();//Subtract X coordinate of i and j
			yElem = list[i].getY() - list[j].getY();//Subtract Y coordinate of i and j
			xElem = pow(xElem,2.0);
			yElem = pow(yElem,2.0);
			param = xElem + yElem; //Store the parametr in param variable
			distance[i][j] = sqrt(param);
		}
}

void Map::evaporateVPheremone(double p_argu)
{
	for(int i=0; i < numberOfCities ; i++)
		for(int j=0; j < numberOfCities ; j++)
			vPheremone[i][j] *= (1-p_argu);
}

void Map::calcProbability()
{
	double multiply,multiplyer;
	for(int i=0; i < numberOfCities; i++)
	{
		for(int j=0; j < numberOfCities; j++)
		{
			if(i==j)
				probability[i][j] = 0;
			else
			{
				multiply = pow(vPheremone[i][j],alpha);
				multiplyer = pow(distance[i][j],(-1*beta));
				probability[i][j] = multiply*multiplyer;
			}
		}
	}
}

void Map::tsp()
{
	reset();
	calcProbability();
	int tempCity; //Temporary variable for arthimetic calculation
	for(int i=0; i<numberOfCities-1; i++)
	{
		for(int j=0; j<numberOfAnts; j++)
		{
			tempCity = ant[j].getNextCity(probability);
			ant[j].setNextCityOfPath(tempCity);
		}

		evaporateVPheremone(eFactor);
	}
	//Refine Vpheremone
			reset();
	for(int j=0; j<numberOfAnts; j++)
			ant[j].reinforceVPheremone(distance,vPheremone);
	//
	double min = ant[0].getTotalDistance(distance); //Help variable to store min distabce
	bestIndex = 0;
	for(int i=1; i<numberOfAnts; i++)
		if(min > ant[i].getTotalDistance(distance))
		{
			min = ant[i].getTotalDistance(distance);
			bestIndex = i;
		}
	bestTotalDistance = min;
}

void Map::reset()
{
	for(int i=0; i<numberOfAnts ; i++)
		ant[i].reset();
}

void Map::freeMemory()
{
	delete ant;
	delete distance;
	delete vPheremone;
	delete probability;
}

string Map::getBestPath()
{
	string tempString;
	tempString = ant[bestIndex].getPath();
	return tempString;
}