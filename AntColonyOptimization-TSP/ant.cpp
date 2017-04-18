//Emad Khezri
//Implementation of Ant Class

#include "stdafx.h"


void Ant::initialize(int num_argu, City* c_argu,double** distance_argu,double** vPheremone_argu)
{
	totalDistance = 0.0; //Zero distance
	numberOfCities = num_argu; //Initalize number of city
	path = new City[num_argu]; //Allocate memory to path
	for(int i=0; i<num_argu ; i++)
	{
		path[i] = c_argu[i];  //Save c_argu to the path
	}
	start = path[0].getIndex(); //Set the start point
	path[0].setVisited(true); //First city is visited
	current = 0; //Set the current point
	for(int i=1; i<num_argu; i++)
	{
		setNextCityOfPath(i);
	}
	reset();
	reinforceVPheremone(distance_argu,vPheremone_argu);
}

City Ant::searchPath(int key_argu)
{
	for(int i=0; i < numberOfCities; i++)
		if(path[i].getIndex() == key_argu)
			return path[i];
	return path[0];
}

int Ant::getNextCity(double **probability_argu)
{
	double* probBox = new double[numberOfCities+1]();
	double sum=0; //Sum of the prob
	int currentCityIndex=path[current].getIndex(); //Index of current city
	int nextCityIndex; //Index of next city
	double* tempProbability; //Temporary probability
	tempProbability = new double[numberOfCities];
	double randProb = (double)rand() / (double)(RAND_MAX-1); //Random probability between 0 and 1
	for(int i=0; i < numberOfCities; i++)
	{
		if(searchPath(i).isVisited())
			tempProbability[i] = 0;
		else
			tempProbability[i] = probability_argu[currentCityIndex][i];
		sum += tempProbability[i];
	}
	for(int i=0; i<numberOfCities ;i++)
	{
		probBox[i+1] = probBox[i] + (tempProbability[i]/sum); 
		if(randProb >= probBox[i] && randProb < probBox[i+1])
		{
			nextCityIndex = i; //find the index of next city
			break;
		}
	}
	return nextCityIndex;
}

void Ant::setNextCityOfPath(int nextCity_argu)
{
	current++; //Increment Current
	City tempCity = path[current]; //Temp for swapping
	path[current] = path[nextCity_argu];
	path[nextCity_argu] = tempCity; //Store the next city in current pointer
	path[current].setVisited(true);
}

void Ant::reinforceVPheremone(double** distance_argu,double** vPheremone_argu)
{
	double l = getTotalDistance(distance_argu);
	for(int i=0;i<numberOfCities-1;i++)
	{
		current++;
		int src = path[current-1].getIndex(); //Source city
		int dest = path[current].getIndex(); //Destination city
		//Reinforce value to Vpheremone with 1/L
		vPheremone_argu[src][dest] += 1/l; 
	}
}

double Ant::getTotalDistance(double** distance_argu)
{
	double temp = 0; //temp variable 
	for(int i=0; i<numberOfCities-1; i++)
		temp+= distance_argu[path[i].getIndex()][path[i+1].getIndex()];
	temp+= distance_argu[path[0].getIndex()][path[numberOfCities-1].getIndex()];
	totalDistance = temp;
	return totalDistance;
}

void Ant::reset()
{
	current = 0;
	for(int i=1; i<numberOfCities; i++)
		path[i].setVisited(false);
}

string Ant::getPath()
{
	string tempString = "";
	string resultString = "";
	msclr::interop::marshal_context context;
	for(int i=0;i<numberOfCities;i++)
	{
		tempString = context.marshal_as<std::string>(path[i].getIndex().ToString());
		resultString = resultString + tempString + "-";
	}
	tempString = context.marshal_as<std::string>(path[0].getIndex().ToString());
	resultString = resultString + tempString;
	return resultString;
}