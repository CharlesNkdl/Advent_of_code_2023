#ifndef MAPPEUR_HPP
#define MAPPEUR_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <cstdlib>

class Mappeur
{
	private :
		int total;
		std::string input[141][141];
		int maxsize;

	public :
		Mappeur();
		void setInput(std::string, int game);
		void results();
		int check_corner(int i, int j, std::string bufferOne, std::string bufferTwo, std::string bufferThree);
		int getTotal();
		void edgecase(int i, int j, int k, std::string bufferOne, std::string bufferTwo, std::string bufferThree);
		void cornercase(int i, int j, int k, std::string bufferOne, std::string bufferTwo, std::string bufferThree);
};

#endif
