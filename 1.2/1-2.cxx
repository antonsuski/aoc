#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <algorithm>
#include <ranges>
#include <cmath>
#include <unordered_map>
#include <ostream>

// template<typename T, typename U>
// std::ostream operator<< (std::ostream& out, const std::unordered_map&<T,U> u_map)
// {
// 	for (const auto&[key, val]: u_map)
//	{
//		out << "[key: " << key << "][val" << val << "]\n";
//	}
//
//	out << std::endl;
//
//	return out;
// }

auto print_key_val (const auto& key, const auto& val)
{
	std::cout << "[key: " << key << "][val: " << val << "]\n";
}

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

	std::unordered_map<int, int> rum;

	for (auto &&i : rv)
	{
		rum.insert({i, 0});
		rum[i]++;
	}	

	for (const auto &[key, val]:rum)
	{
		print_key_val(key, val);
	}

	std::cout << "-----------------------\n";
	unsigned int sum {};
	for (const auto& i:lv)
	{
		print_key_val(i, rum[i]);
		sum += rum[i] * i;
	}

	std::cout << "###########\n Result: " << sum << std::endl;

	file.close();
	std::cout << "File " << path << " has been close" << std::endl;

	return 0;
}

