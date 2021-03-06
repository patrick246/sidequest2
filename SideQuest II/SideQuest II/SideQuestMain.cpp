#include <cstdlib>
#include <iostream>

#include "App.h"
#include "Config.h"

int main()
/** Main of the Sidequest2 */{
	try
	{
		Config c("config.txt");
		App app(c);
		app.run();
	}
	catch (std::exception& exc)
	{
		std::cerr << "Exception in game: " << exc.what() << '\n';
	}
	return 0;
}