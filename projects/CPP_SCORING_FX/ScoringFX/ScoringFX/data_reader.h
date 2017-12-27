/*
CURRENCY RANKING C++ MASTER 203 PROJECT

Date: 22/12/2017
File: Namespace for importing data
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>

namespace data_reader {

	// IMPORTING THE LIST OF CURRENCIES
	
	std::vector<std::string> ImportCurrencies(const std::string& path){
		// Import
		std::ifstream file(path); // Path

		if (!file.is_open())
		{ std::cerr << "Unable to open file" << "\n";
		  std::exit(-1); }
		// Vector
		std::vector<std::string> vector;
		std::copy(std::istream_iterator<std::string>(file), std::istream_iterator<std::string>(), std::back_inserter(vector));
		file.close();

		return vector;
	}
	

	// IMPORTING THE ANTISYMMETRIC MATRIX DATA

	std::vector<std::vector<double>> ImportSkewMatrix(const std::string& path, const int nb_currencies) {
		
		// Import
		std::ifstream file(path);
		if (!file) { std::cout << "Cannot open file.\n"; }

		// Matrix
		int D = nb_currencies;
		std::vector<std::vector<double>> matrix(D, std::vector<double>(D));
		for (int i = 0; i < D; i++) {
			for (int j = 0; j < D; j++) {
				file >> matrix[i][j]; } }
		file.close();

		return matrix;
	}

}