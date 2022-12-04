#include <iostream>
#include <string>

#include "ParseArgs.h"

std::optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 3)
	{
		return std::nullopt;
	}

	Args args;
	args.inputFile = argv[1];
	args.outputFile = argv[2];

	return args;
}