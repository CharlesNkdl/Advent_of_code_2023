#ifndef CLUES_HPP
#define CLUES_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

class Bag
{
	private :
		int total;
		int green;
		int red;
		int blue;
		int currGreen;
		int currRed;
		int currBlue;
		int gamenbr;
		std::string input;

	public :
		Bag();
		void setCubes(int red, int green, int blue);
		void setInput(std::string, int game);
		void results();
		int resultspergame();
		void check();
		int getTotal();
		bool checkeur(std::string);
};

#endif
