//Emad Khezri
//Implementation of City Class

#include "stdafx.h"


City::City(int x_argu, int y_argu, int i_argu)
{
	//Initialize variables of City class
	x = x_argu;
	y = y_argu;
	index = i_argu;
}

int City::getX()
{
	return x;
}

int City::getY()
{
	return y;
}

int City::getIndex()
{
	return index;
}

bool City::isVisited()
{
	return visited;
}