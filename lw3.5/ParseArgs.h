#pragma once
#include <optional>

struct Args
{
	std::string inputFile;
	std::string outputFile;
};

std::optional<Args> ParseArgs(int argc, char* argv[]);
