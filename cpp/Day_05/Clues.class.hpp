#ifndef CLUES_HPP
#define CLUES_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

class Clues
{
	private :
		int total;
		std::string clues;
		int category;
		//int ranges[3];
		size_t seeds[20];
		int checkeur[20];

	public :
		Clues();
		size_t *setRanges();
		void setSeeds();
		void seed_soil();
		void soil_fertilizer();
		void fertilizer_water();
		void water_light();
		void light_temp();
		void temp_humidity();
		void humidity_location();
		void parser();
		void setClues(std::string);
		void addTotal();
		void reset_checkeur();
		size_t getTotal();
		void category_choser();
};


#endif
