//Emad Khezri
//Map Class
//This class entire the Maps, cities,
//roads , features of roads, distance

#ifndef MAP_H
#define MAP_H


class Map
{
private:
	int numberOfCities; //Number of cities in the Map
	int minValue,maxValue; //Minimum and Maximum value of city coordinate
	int numberOfAnts; //Number of ants in the Map
	double alpha,beta,eFactor; //Alpha, beta, and evaporate factor
	Ant* ant; //Ants of map
	City* list; //List of cities in the Map
	double** distance; //distance between city i and city j
	double** vPheremone; //virtual Pheremone on the edges
	double** probability; //The Probability to go from city i to city j
	int bestIndex; //Index of best path
	double bestTotalDistance; //Best total distance of ants

public:
	Map(){}; //Default Constraction of Map
	void makeFile(parametrs); //Make file of cities
	void initialize(parametrs); //Initalize variables related to ants
	City searchList(int key_argu) {return list[key_argu];} //Return key element of the list
	City* radomizeList(); //Randomize the list of cities
	void setNextCityOfPath(City); //setting the next element of path
	void calcDistance(); //Calculate Distance of Cities
	double getDistance(int i_argu,int j_argu) {return distance[i_argu][j_argu];} //Return distance between two cities
	double getBestTotalDistance(){return bestTotalDistance;} //return best total distance
	void reinforceVPheremone(int,int); //Reinforce the edges it has used
	void evaporateVPheremone(double); //The virtual pheremone evaporates
	void calcProbability(); //Calculate probability to go from city i to city j
	void tsp(); //Start The algorithm
	void reset(); //Reset the map
	void freeMemory(); //Free memory that allocated
	string getBestPath(); //return best path of ants
};

#endif