#include "Bag.class.hpp"

Bag::Bag()
{
	this->total = 0;
	this->green = 0;
	this->red = 0;
	this->blue = 0;
	this->currGreen = 0;
	this->currRed = 0;
	this->currBlue = 0;
	this->gamenbr = 0;
	this->input = "";
};

void Bag::setInput(std::string ipt, int game)
{
	this->input = ipt;
	this->gamenbr = game;
};

void Bag::setCubes(int red, int green, int blue)
{
	this->red = red;
	this->green = green;
	this->blue = blue;
};

void Bag::results()
{
	int i;
	int leng;
	std::string buffer;

	i = 0;
	leng = this->input.length();
	while (i < leng)
	{
		if (this->input[i] == ':')
		{
			buffer = this->input.substr(i + 1, leng);
			this->input = buffer;
			return ;
		}
		i++;
	}
	return ;
}

int Bag::resultspergame()
{
	int i;
	int j;
	int leng;
	bool stock;

	i = 0;
	j = 0;
	stock = true;
	leng = this->input.length();
	while (i < leng && stock == true)
	{
		j = i + 1;
		while (j < leng)
		{
			if (this->input[j] == ';')
				break ;
			j++;
		}
		stock = checkeur(this->input.substr(i + 1, (j - i) - 1));
		i = j;
	}
	if (stock == true)
	{
		this->total += this->gamenbr;
		return (1);
	}
	else
		return (0);
}

bool Bag::checkeur(std::string str)
{
	int i;
	int nbrCubes;
	int leng;

	i = 0;
	nbrCubes = 0;
	leng = str.length();
	while (i < leng)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			nbrCubes = nbrCubes * 10 + (str[i] - '0');
		}
		if ((str[i] >= 'a' && str[i] <= 'z') && nbrCubes != 0)
		{
			if (str[i] == 'r')
			{
				if (this->red < nbrCubes)
					return (false);
				else
					nbrCubes = 0;
			}
			if (str[i] == 'g')
			{
				if (this->green < nbrCubes)
					return (false);
				else
					nbrCubes = 0;
			}
			if (str[i] == 'b')
			{
				if (this->blue < nbrCubes)
					return (false);
				else
					nbrCubes = 0;
			}
		}
		i++;
	}
	//std::cout << "Game " << this->gamenbr << ": good" << std::endl;
	return (true);
}

int Bag::getTotal()
{
	return (this->total);
}

void Bag::check()
{
	std::cout << "red: " << this->red << std::endl;
	std::cout << "green: " << this->green << std::endl;
	std::cout << "blue: " << this->blue << std::endl;
	std::cout << "currRed: " << this->currRed << std::endl;
	std::cout << "currGreen: " << this->currGreen << std::endl;
	std::cout << "currBlue: " << this->currBlue << std::endl;
	std::cout << "gamenbr: " << this->gamenbr << std::endl;
	std::cout << "input: " << this->input << std::endl;
}

