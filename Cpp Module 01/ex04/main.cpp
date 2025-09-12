#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
	size_t pos = 0;
	std::string s1;
	std::string s2;
	std::string line;
	std::string filename;
	if (ac != 4)
	{
		std::cout << "the progame must have 3 parametres" << std::endl;
		return 1;
	}
	std::ifstream in_file(av[1]);
	if (!in_file.is_open())
	{
		std::cout << "Error in opening file" << std::endl;
		return 1;
	}
	filename = av[1];
	s1 = av[2];
	s2 = av[3];
	filename.append(".replace");
	std::ofstream out_file(filename);
	if (!out_file.is_open())
	{
		std::cout << "Error in opening file" << std::endl;
		return 1;
	}
	if (s1 == s2)
	{
		while (std::getline(in_file, line))
			out_file << line << std::endl;
		in_file.close();
		out_file.close();
		return (0);
	}
	while (std::getline(in_file, line))
	{
		while ((pos = line.find(s1)) !=  std::string::npos)
		{
			line = line.erase(pos, s1.length());
			line = line.insert(pos, s2);
		}
		out_file << line << std::endl;
	}
	in_file.close();
	out_file.close();
	return 0;
}