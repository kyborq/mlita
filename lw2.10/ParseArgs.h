#pragma once

struct Args
{
	std::string inputFile;
	std::string outputFile;
};

std::optional<Args> ParseArgs(int argc, char* argv[]);
