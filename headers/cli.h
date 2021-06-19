#ifndef CLI_H
#define CLI_H
#include <iostream>
#include <fstream>
#include <filesystem>
#include <locale>
#include <codecvt>
#include <fcntl.h>
#include <io.h>
#include <string>

#include "tasks.h"

#include "boost/filesystem/fstream.hpp"
#include "boost/program_options.hpp"

namespace po = boost::program_options;
namespace fs = boost::filesystem;

class cli
{
    po::options_description optionsDescriptions {"Allowed options"};
    po::variables_map map;
public:
    cli( int argc, char* argv[] );
    int exec();
private:
    std::string  inputFilePath, outputFilePath;
    std::string  search, reaplace;
};

#endif // CLI_H
