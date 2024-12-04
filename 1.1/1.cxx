#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <algorithm>
#include <ranges>
#include <cmath>

int main (int argc, char** argv)
{
	if (argc < 2)
	{
		std::cout << "Wrong Usage." << std::endl;
		return 69;
	}

	std::filesystem::path path {argv[1]};

	if (!std::filesystem::exists (path))
	{
		std::cout << "File doesn't exist!" << std::endl;
		return 1;
	}

	std::fstream file;
	file.open(path, std::ios::in);

	if (!file.is_open ())
	{
		std::cout << "Can't open file: " << path << std::endl;
	}

	std::cout << "File " << path << " has been open" << std::endl;
	std::cout << "Hello, Advenging of Code" << std::endl; 

	std::vector<int> lv{};
	std::vector<int> rv{};
	
	for (int a, b; (file >> a) && (file >> b);)
	{
		lv.push_back(a);
		rv.push_back(b);
	}

	std::ranges::sort (lv);
	std::ranges::sort (rv);

	int diff {};

	for (size_t i {}; i < lv.size(); i++)
	{
		diff += std::abs (lv[i] - rv[i]);
	}

	std::cout << "Result: " << diff << std::endl;
	file.close();
	std::cout << "File " << path << " has been close" << std::endl;

	return 0;
}

