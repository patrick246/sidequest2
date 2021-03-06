#include "Config.h"
#include <fstream>
#include <sstream>
#include <iostream>

/** read the config file */
Config::Config(std::string filename)
{
	std::ifstream file(filename, std::ios::in);
	if (!file)
	{
		std::cerr << "Could not load config file: " << filename << '\n';
		throw std::runtime_error(std::string("Config::(constructor): Could not load config file ") + filename);
	}
	while (!file.eof())
	{
		std::string line;
		std::getline(file, line);

		if (line.size() >= 2 && line[0] != '/' && line[1] != '/')
		{

			auto index = line.find('=');
			if (index == line.size() - 1)
				continue;

			m_config.insert(std::make_pair(std::string(line.begin(), line.begin() + (index)), std::string(line.begin() + (index + 1), line.end())));
		}
	}
}


