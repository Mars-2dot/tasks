#ifndef CLI_H
#define CLI_H
#include <iostream>
#include <fstream>
#include <filesystem>

#include <F:/code/C++/tasks/build/task_13_1_45/boost/src/external_boost/boost/filesystem/fstream.hpp>
#include <F:/code/C++/tasks/build/task_13_1_45/boost/src/external_boost/boost/program_options.hpp>

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
    std::string  inputFilePath;
    std::string  search, reaplace;
    bool readAndReplaceFile( std::string nameFile, std::string stringToSearch, std::string stringToReplace );
};

#endif // CLI_H
