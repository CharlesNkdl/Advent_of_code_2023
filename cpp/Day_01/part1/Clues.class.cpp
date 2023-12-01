#include "Clues.class.hpp"

void Clues::setClues(std::string clues)
{
	this->clues = clues;
};

char Clues::getLast()
{
	int i;

	i = this->clues.length() - 1;
	while (i >= 0)
	{
		if (this->clues[i] >= '0' && this->clues[i] <= '9')
			return (this->clues[i]);
		i--;
	}
	return ('0');
};

char Clues::getFirst()
{
	int i;
	int longueur;

	i = -1;
	longueur = this->clues.length();
	while (++i < longueur)
	{
		if (this->clues[i] >= '0' && this->clues[i] <= '9')
			return (this->clues[i]);
	}
	return ('0');
};

void Clues::addTotal()
{
	int addit;

	addit = ((getFirst() - '0') * 10) + (getLast() - '0');
	this->total = this->total + addit;
};

int Clues::getTotal()
{
	return (this->total);
};
