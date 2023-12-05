#include "Clues.class.hpp"

Clues::Clues()
{
	this->total = 0;
	this->clues = "";
	for (int i = 0; i < 12; i++)
		this->numbers[i] = 0;
	for (int i = 0; i < 204; i++)
		this->goodnumberspercard[i] = 0;
	this->cards = 0;
	this->goodnumbers = 0;
};

void Clues::setClues(std::string clues)
{
	this->clues = clues;
	for (int i = 0; i < 12; i++)
		this->numbers[i] = 0;
	this->goodnumbers = 0;
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

void Clues::getNumbers()
{
	size_t i;
	int j;
	int hisNumber;
	int buffer;

	hisNumber = 0;
	buffer = 0;
	j = 0;
	i = 0;
	while (this->clues[i] != ':')
		i++;
	while (this->clues[i] != '|')
	{
		if (this->clues[i] >= '0' && this->clues[i] <= '9')
		{
			hisNumber = 1;
			this->numbers[j] = this->numbers[j] * 10 + (this->clues[i] - '0');
		}
		else if (hisNumber == 1)
		{
			hisNumber = 0;
			j++;
		}
		i++;
	}
	hisNumber = 0;
	while (i <= this->clues.length())
	{
		if (this->clues[i] >= '0' && this->clues[i] <= '9')
		{
			hisNumber = 1;
			buffer = buffer * 10 + (this->clues[i] - '0');
		}
		else if (hisNumber == 1)
		{
			for (int k = 0; k < 12; k++)
			{
				if (this->numbers[k] == buffer)
				{
					//std::cout << "buffer : " << buffer << std::endl;
					this->goodnumbers++;
				}
			}
			hisNumber = 0;
			buffer = 0;
		}
		i++;
	}
};

void Clues::addTotal()
{
	int addit;

	addit = 0;
	/*std::cout << "good numbs" << this->goodnumbers << std::endl;
	for (int i = 0; i < 12; i++)
	{
		std::cout << this->numbers[i] << std::endl;
	}
	for (int i = 0; i < this->goodnumbers ; i++)
		if (addit == 0)
			addit = 1;
		else
			addit = addit * 2;
	std::cout << "addit : " << addit << std::endl;*/
	this->goodnumberspercard[this->cards] = this->goodnumbers;
	std::cout << "goodnumberspercard[" << this->cards << "] : " << this->goodnumberspercard[this->cards] << std::endl;
	this->cards++;
	this->total = this->total + addit;
};

int Clues::countScratch()
{
	int i;
	int j;
	int totalus;
	int copies[204];

	for (int i = 0; i < 202; i++)
		copies[i] = 1;
	totalus = 0;
	i = 0;
	j = 0;
	while (i < 202)
	{
		totalus = totalus + copies[i];
		if (this->goodnumberspercard[i] > 0)
		{
			for (int h = copies[i]; h > 0; h--)
			{
				for (int k = 0; k < this->goodnumberspercard[i]; k++)
				{
					j = i + k + 1;
					copies[j] = copies[j] + 1;
					//std::cout << "rajouter une copie à" << j << "grâce a la carte"<< i << std::endl;
				}
			}
		}
		//std::cout << "copies[" << i << "] : " << copies[i] << std::endl;
		std::cout << "totalus : " << totalus << std::endl;
		i++;
	}
	return (totalus);
};
int Clues::getTotal()
{
	return (this->total);
};
