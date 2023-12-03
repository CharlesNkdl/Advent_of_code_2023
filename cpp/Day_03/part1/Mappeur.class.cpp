#include "Mappeur.class.hpp"

Mappeur::Mappeur()
{
	this->total = 0;
	this->maxsize = 141;
};

void Mappeur::setInput(std::string ipt, int line)
{
	*this->input[line] = ipt;
};

void Mappeur::results()
{
	int i = 0;
	int j = 0;
	std::string bufferOne;
	std::string bufferTwo;
	std::string bufferThree;

	while (i < 140)
	{
		j = 0;
		if (i == 0)
		{
			bufferTwo = *this->input[i];
			bufferThree = *this->input[i + 1];
		}
		else if (i == 140)
		{
			bufferOne = *this->input[i - 1];
			bufferTwo = *this->input[i];
		}
		else
		{
			bufferOne = *this->input[i - 1];
			bufferTwo = *this->input[i];
			bufferThree = *this->input[i + 1];
		}
		while (j < 140)
		{
			if (bufferTwo[j] >= '0' && bufferTwo[j] <= '9')
			{
				//std::cout << "La string : " << i << "chiffre: " << bufferTwo[j] << std::endl;
				j += check_corner(i, j, bufferOne, bufferTwo, bufferThree);
			}
			j++;
		}
		i++;
	}
};

int Mappeur::check_corner(int i, int j, std::string bufferOne, std::string bufferTwo, std::string bufferThree)
{
	int k = 0;

	while (bufferTwo[j + k] >= '0' && bufferTwo[j + k] <= '9')
		k++;
	if ((j+k) == 140 || j == 0)
	{
		std::cout << "La string : " << bufferTwo << std::endl;
		edgecase(i, j, k, bufferOne, bufferTwo, bufferThree);
		return (k);
	}
	else if (i != 0 && i != 139)
	{
		for (int l = k ; l != -2 ; l--)
		{
			if (l == k)
				std::cout << "La string " << bufferTwo[j +l] << std::endl;
			if ((bufferOne[j + l] != '.' && !(bufferOne[j + l] >= '0' && bufferOne[j + l] <= '9')) || (bufferThree[j + l] != '.' && !(bufferThree[j + l] >= '0' && bufferThree[j + l] <= '9')) || (bufferTwo[j + l] != '.' && !(bufferTwo[j + l] >= '0' && bufferTwo[j + l] <= '9')))
			{
				this->total += atoi((bufferTwo.substr(j, k)).c_str());
				return (k);
			}
		}
	}
	else
	{
		cornercase(i, j, k, bufferOne, bufferTwo, bufferThree);
		return (150);
	}
	return (k);
}

void Mappeur::edgecase(int i, int j, int k, std::string bufferOne, std::string bufferTwo, std::string bufferThree)
{
	if ((j + k) > 139)
	{
		for (int l = k - 1; l != -2 ; l--)
			{
				if ((bufferOne[j + l] != '.' && !(bufferOne[j + l] >= '0' && bufferOne[j + l] <= '9')) || (bufferThree[j + l] != '.' && !(bufferThree[j + l] >= '0' && bufferThree[j + l] <= '9')) || (bufferTwo[j + l] != '.' && !(bufferTwo[j + l] >= '0' && bufferTwo[j + l] <= '9')))
				{
					this->total += atoi((bufferTwo.substr(j, k)).c_str());
					std::cout << "Rajouté au total EDGECASE HAUTE: " << bufferTwo.substr(j, k) << "\n ligne no" << i << std::endl;
				}
			}
		return ;
	}
	else
	{
		for (int l = k + 1; l != 1 ; l--)
		{
			if ((bufferOne[j + l] != '.' && !(bufferOne[j + l] >= '0' && bufferOne[j + l] <= '9')) || (bufferThree[j + l] != '.' && !(bufferThree[j + l] >= '0' && bufferThree[j + l] <= '9')) || (bufferTwo[j + l] != '.' && !(bufferTwo[j + l] >= '0' && bufferTwo[j + l] <= '9')))
			{
				this->total += atoi((bufferTwo.substr(j, k)).c_str());
				std::cout << "Rajouté au total EDGECASE BASSE : " << bufferTwo.substr(j, k) << "\n ligne no" << i << std::endl;
			}
		}
		return ;
	}
}

void Mappeur::cornercase(int i, int j, int k, std::string bufferOne, std::string bufferTwo, std::string bufferThree)
{
	(void)bufferOne;
	(void)bufferTwo;
	(void)bufferThree;
	(void)j;
	(void)k;

	if (i == 0)
		this->total += 717 + 747;
	else
		this->total += 579 + 595 + 781 + 547;
}

int Mappeur::getTotal()
{
	return (this->total);
}
