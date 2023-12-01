#include "Clues.class.hpp"

void Clues::setClues(std::string clues)
{
	this->clues = clues;
};

void Clues::transformClues()
{
	std::string lst[9] = {"one","two","six","four","five","nine","three","seven","eight"};
	std::string nbr[9] = {"o1ne","t2wo","s6ix","f4our","f5ive","n9e","th3ree","sev7n","eig8ht"};
	std::string buffer;

	buffer = this->clues;
	for (int j = 0; j < 9; j++)
	{
		for (int i = 0; i < 9; i++)
		{
			if (buffer.find(lst[i]) != std::string::npos)
			{
				buffer.replace(buffer.find(lst[i]), lst[i].length(), nbr[i]);
				this->clues = buffer;
			}
		}
	}
	this->clues = buffer;
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

std::string Clues::getClues()
{
	return (this->clues);
};
