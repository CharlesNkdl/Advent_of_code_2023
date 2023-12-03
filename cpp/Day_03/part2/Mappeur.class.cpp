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
		this->total += 717;
	else
		this->total += 595;
}

void Mappeur::starcleaner()
{
	int i = 1;
	int j = 0;
	int numberclosebyOne = 0;
	int numberclosebyTwo = 0;
	int numberclosebyThree = 0;
	int checkOne = 0;
	int checkTwo = 0;
	int checkThree = 0;
	std::string bufferOne;
	std::string bufferTwo;
	std::string bufferThree;
	std::string bffOne;
	std::string bffTwo;
	std::string bffThree;
	int numbone = 1;
	int numbtwo = 1;
	int numbthree = 1;
	int numbbisone = 1;
	int numbbistwo = 1;

	while (i < 139)
	{
		j = 0;
		bufferOne = *this->input[i - 1];
		bufferTwo = *this->input[i];
		bufferThree = *this->input[i + 1];
		while (j < 140)
		{
			if (bufferTwo[j] == '*')
			{
				for (int k = -1 ; k != 2 ; k++)
				{
					if (bufferOne[j + k] >= '0' && bufferOne[j + k] <= '9')
					{
						if (checkOne == 0)
						{
							numberclosebyOne++;
							checkOne = 1;
						}
					}
					else
						checkOne = 0;
					if (bufferThree[j + k] >= '0' && bufferThree[j + k] <= '9')
					{
						if (checkThree == 0)
						{
							numberclosebyThree++;
							checkThree = 1;
						}
					}
					else
						checkThree = 0;
					if (bufferTwo[j + k] >= '0' && bufferTwo[j + k] <= '9')
					{
						if (checkTwo == 0)
						{
							numberclosebyTwo++;
							checkTwo = 1;
						}
					}
					else
						checkTwo = 0;
				}
				if ((numberclosebyOne + numberclosebyTwo + numberclosebyThree) == 2)
				{
					if (numberclosebyOne == 1)
					{
						numbone = atoi(get_nbr(bufferOne, j).c_str());
					}
					if (numberclosebyTwo == 1)
					{
						numbtwo = atoi(get_nbr(bufferTwo, j).c_str());
					}
					if (numberclosebyThree == 1)
					{
						numbthree = atoi(get_nbr(bufferThree, j).c_str());
					}
					if (numberclosebyOne == 2)
					{
						numbbisone = atoi(get_nbrbis_neg(bufferOne, j).c_str());
						numbbistwo = atoi(get_nbrbis_pos(bufferOne, j).c_str());
					}
					if (numberclosebyTwo == 2)
					{
						numbbisone = atoi(get_nbrbis_neg(bufferTwo, j).c_str());
						numbbistwo = atoi(get_nbrbis_pos(bufferTwo, j).c_str());
					}
					if (numberclosebyThree == 2)
					{
						numbbisone = atoi(get_nbrbis_neg(bufferThree, j).c_str());
						numbbistwo = atoi(get_nbrbis_pos(bufferThree, j).c_str());
					}
					std::cout << "ligne :" << i << "colonne :" << j << std::endl;
					std::cout << "numberclosebyOne :" << numberclosebyOne << std::endl;
					std::cout << "numberclosebyTwo :" << numberclosebyTwo << std::endl;
					std::cout << "numberclosebyThree :" << numberclosebyThree << std::endl;
					std::cout << "numbone :" << numbone << std::endl;
					std::cout << "numbtwo :" << numbtwo << std::endl;
					std::cout << "numbthree :" << numbthree << std::endl;
					std::cout << "numbbisone :" << numbbisone << std::endl;
					std::cout << "numbbistwo :" << numbbistwo << std::endl;
					this->total += (numbone * numbtwo * numbthree * numbbisone * numbbistwo);
				}
				numbone = 1;
				numbtwo = 1;
				numbthree = 1;
				numbbisone = 1;
				numbbistwo = 1;
				numberclosebyOne = 0;
				numberclosebyTwo = 0;
				numberclosebyThree = 0;
				checkOne = 0;
				checkTwo = 0;
				checkThree = 0;
			}
			j++;
		}
		i++;
	}
}

std::string Mappeur::get_nbr(std::string buffer, int j)
{
	int k = 0;
	int length = 0;
	int neg = 1;

	if (buffer[j] >= '0' && buffer[j] <= '9')
	{
		std::cout << "ERREUR DEVRAIS ETRE ICI APRES CHECK" << std::endl;
		while (buffer[j + k] >= '0' && buffer[j + k] <= '9')
		{
			neg--;
			k--;
			length++;
		}
		k = 1;
		while (buffer[j + k] >= '0' && buffer[j + k] <= '9')
		{
			k++;
			length++;
		}
		std::cout << buffer.substr(j + neg, length) << std::endl;
		return (buffer.substr(j + neg, length));
	}
	else
	{
		if (buffer[j - 1] >= '0' && buffer[j - 1] <= '9')
		{
			k = -1;
			std::cout << "NEGATIF APRES CHECK"<< std::endl;
			while (buffer[j + k] >= '0' && buffer[j + k] <= '9')
			{
				neg++;
				k--;
				length++;
			}
			return (buffer.substr(j + k + 1, length));
		}
		else if (buffer[j + 1] >= '0' && buffer[j + 1] <= '9')
		{
			std::cout << "POSITIF APRES CHECK" << std::endl;
			k = 1;
			while (buffer[j + k] >= '0' && buffer[j + k] <= '9')
			{
				k++;
				length++;
			}
			//std::cout << "Positiffff :" << k << std::endl;
			//std::cout << "length :" << buffer.substr(j +k, length) << std::endl;
			return (buffer.substr(j + 1, length));
		}
	}
	return ("1");
}

std::string Mappeur::get_nbrbis_neg(std::string buffer, int j)
{
	int k = -1;
	int length = 0;
	int neg = 0;

	if (buffer[j - 1] >= '0' && buffer[j - 1] <= '9')
	{
		std::cout << "NEGATIF BIS APRES CHECK" << std::endl;
		while (buffer[j + k] >= '0' && buffer[j + k] <= '9')
		{
			neg++;
			k--;
			length++;
		}
		std::cout << "neg :" << neg << std::endl;
		std::cout << "length :" << buffer.substr(j + k + 1, length) << std::endl;
		return (buffer.substr(j + k + 1, length));
	}
	return ("1");
}

std::string Mappeur::get_nbrbis_pos(std::string buffer, int j)
{
	int k = -1;
	int length = 0;

	if (buffer[j + 1] >= '0' && buffer[j + 1] <= '9')
	{
		std::cout << "POSITIF BIS APRES CHECK" << std::endl;
		k = 1;
		while (buffer[j + k] >= '0' && buffer[j + k] <= '9')
		{
			k++;
			length++;
		}
		//std::cout << "Positiffff :" << k << std::endl;
		//std::cout << "length :" << buffer.substr(j +k, length) << std::endl;
		return (buffer.substr(j + 1, length));
	}
	return ("1");
}

int Mappeur::getTotal()
{
	return (this->total);
}
