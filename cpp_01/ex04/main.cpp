#include <iostream>
#include <fstream>

std::string my_replace(std::string content, std::string toReplace, std::string replaceWith)
{
	int i = 0;
	std::string result;

	size_t found = content.find(toReplace);
	if (found != std::string::npos)
	{
		while (found != std::string::npos)
		{
			result += content.substr(i, found - i);
			result += replaceWith;
			i = found + toReplace.length();
			found = content.find(toReplace, i);
		}
		result += content.substr(i, content.length());
	}
	else
		result = content;
	return (result);
}

int	main(int argc, char **argv) {
	if (argc != 4)
	{
		std::cout << "Wrong number of parameters. Program exiting." << std::endl;
		return (0);
	}
	else
	{
		std::string f1name(argv[1]);
		std::string toReplace(argv[2]);
		std::string replaceWith(argv[3]);
		std::string content;
		char c;
		std::ifstream f1(f1name);
		if (!f1.is_open())
			std::cout << "File " << f1name << " does not exist or invalid file. Program exiting." << std::endl;
		else
		{
			std::ofstream f2(f1name + ".replace");
			while (!f1.eof() && f1 >> std::noskipws >> c)
			{
				content += c;
			}
			content = my_replace(content, toReplace, replaceWith);
			f2 << content;
		}
	}
	return (0);
}