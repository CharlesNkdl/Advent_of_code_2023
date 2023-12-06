#include "Clues.class.hpp"

Clues::Clues()
{
	this->total = 0;
	this->category = -1;
};

void Clues::setClues(std::string clues)
{
	this->clues = clues;
	parser();
};

void Clues::parser()
{
	if (this->category == -1)
	{
		setSeeds();
		this->category++;
	}
	else if (isalpha(this->clues[0]))
	{
		std::cout << "category choser" << std::endl;
		reset_checkeur();
		this->category++;
	}
	else if (isdigit(this->clues[0]))
	{
		category_choser();
		return ;
	}
	return ;
};

void Clues::reset_checkeur()
{
	for (size_t i = 0; i < 20; i++)
		this->checkeur[i] = 0;
};

void Clues::category_choser()
{

	if (this->category == 1)
		seed_soil();
	else if (this->category == 2)
		soil_fertilizer();
	else if (this->category == 3)
		fertilizer_water();
	else if (this->category == 4)
		water_light();
	else if (this->category == 5)
		light_temp();
	else if (this->category == 6)
		temp_humidity();
	else if (this->category == 7)
		humidity_location();
	else
		return ;
};

void Clues::setSeeds()
{
	size_t stock;
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	stock = 0;
	while (this->clues[i] != ':')
		i++;
	while (i <= this->clues.length())
	{
		if (isdigit(this->clues[i]))
		{
			stock = stock * 10 + (this->clues[i] - '0');
		}
		else if (!(isdigit(this->clues[i])) && stock != 0)
		{
			this->seeds[j] = stock;
			std::cout << this->seeds[j] << std::endl;
			this->checkeur[j] = 0;
			stock = 0;
			j++;
		}
		i++;
	}
}
size_t *Clues::setRanges()
{
	size_t *oui = new size_t[3];
	size_t j;
	size_t k;

	for (size_t i = 0; i < 3; i++)
		oui[i] = 0;
	j = 0;
	k = 0;
	while (j <= this->clues.length() && k < 3)
	{
		if (isdigit(this->clues[j]))
			oui[k] = oui[k] * 10 + (this->clues[j] - '0');
		else if (!(isdigit(this->clues[j]) && oui[k] != 0))
			k++;
		j++;
	}
	return (oui);
};

void Clues::seed_soil()
{
	size_t *ranges;
	size_t i;

	i = 0;
	ranges = setRanges();
	std::cout << "ranges" << ranges[0] << ranges[1] << ranges[2] << std::endl;
	while (i < 20)
	{
		if ((this->seeds[i] >= ranges[1] && this->seeds[i] < (ranges[1] + ranges[2])) && (this->checkeur[i] == 0))
		{
			this->seeds[i] = ranges[0] + (this->seeds[i] - ranges[1]);
			this->checkeur[i] = 1;
			std::cout << "seedsoil seed number " << i << " value " << this->seeds[i] << std::endl;
		}
		i++;
	}
	delete [] ranges;
};

void Clues::soil_fertilizer()
{
	size_t *ranges;
	size_t i;

	i = 0;
	ranges = setRanges();
	while (i < 20)
	{
		if ((this->seeds[i] >= ranges[1] && this->seeds[i] < (ranges[1] + ranges[2])) && (this->checkeur[i] == 0))
		{
			this->seeds[i] = ranges[0] + (this->seeds[i] - ranges[1]);
			this->checkeur[i] = 1;
			std::cout << "soil seed number " << i << " value " << this->seeds[i] << std::endl;
		}
		i++;
	}
	delete [] ranges;
};
void Clues::fertilizer_water()
{
	size_t *ranges;
	size_t i;

	i = 0;
	ranges = setRanges();
	while (i < 20)
	{
		if ((this->seeds[i] >= ranges[1] && this->seeds[i] < (ranges[1] + ranges[2])) && (this->checkeur[i] == 0))
		{
			this->seeds[i] = ranges[0] + (this->seeds[i] - ranges[1]);
			this->checkeur[i] = 1;
			std::cout << "ferti seed number " << i << " value " << this->seeds[i] << std::endl;
		}
		i++;
	}
	delete [] ranges;
};

void Clues::water_light()
{
	size_t *ranges;
	size_t i;


	i = 0;
	ranges = setRanges();
	while (i < 20)
	{

		if ((this->seeds[i] >= ranges[1] && this->seeds[i] < (ranges[1] + ranges[2])) && (this->checkeur[i] == 0))
		{
			this->seeds[i] = ranges[0] + (this->seeds[i] - ranges[1]);
			this->checkeur[i] = 1;
			std::cout << "water seed number " << i << " value " << this->seeds[i] << std::endl;
		}
		i++;
	}
	delete [] ranges;
};

void Clues::light_temp()
{
	size_t *ranges;
	size_t i;

	i = 0;
	ranges = setRanges();
	while (i < 20)
	{
		if ((this->seeds[i] >= ranges[1] && this->seeds[i] < (ranges[1] + ranges[2])) && (this->checkeur[i] == 0))
		{
			this->seeds[i] = ranges[0] + (this->seeds[i] - ranges[1]);
			this->checkeur[i] = 1;
			std::cout << "light " << i << " value " << this->seeds[i] << std::endl;
		}
		i++;
	}
	delete [] ranges;
};

void Clues::temp_humidity()
{
	size_t *ranges;
	size_t i;

	i = 0;
	ranges = setRanges();
	while (i < 20)
	{
		if ((this->seeds[i] >= ranges[1] && this->seeds[i] < (ranges[1] + ranges[2])) && (this->checkeur[i] == 0))
		{
			this->seeds[i] = ranges[0] + (this->seeds[i] + ranges[1]);
			this->checkeur[i] = 1;
			std::cout << "temp_humidity seed number " << i << " value " << this->seeds[i] << std::endl;
		}
		i++;
	}

	delete [] ranges;
};

void Clues::humidity_location()
{
	size_t *ranges;
	size_t i;

	i = 0;
	ranges = setRanges();
	while (i < 20)
	{
		if ((this->seeds[i] >= ranges[1] && this->seeds[i] < (ranges[1] + ranges[2])) && (this->checkeur[i] == 0))
		{
			this->seeds[i] = ranges[0] + (this->seeds[i] - ranges[1]);
			this->checkeur[i] = 1;
		}
		i++;
	}
	delete [] ranges;
};

void Clues::addTotal()
{
	size_t addit;

	addit = 0;
	this->total = this->total + addit;
};

size_t Clues::getTotal()
{
	size_t i;
	size_t min;

	i = 0;
	min = this->seeds[i];

	while (i < 20)
	{
		std :: cout << this->seeds[i] << std::endl;
		if (this->seeds[i] < min)
			min = this->seeds[i];
		i++;
	}
	return (min);
};
