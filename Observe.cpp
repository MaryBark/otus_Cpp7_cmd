#include "Observe.h"
#include <iostream>
//using namespace std;


FileObserver::FileObserver()
{}

//---------------------------------------------------------------------------------------
void FileObserver::print(const std::vector<std::string> &comm, const std::string time)
{
    std::ofstream file;

    std::string path("fileCom" + time + ".log");

    file.open(path);

    for (auto& command : comm) {
        file << command << "\n";
    }

    file.close();
}

//---------------------------------------------------------------------------------------
TerminalObserver::TerminalObserver()
{}

//---------------------------------------------------------------------------------------
void TerminalObserver::print(const std::vector<std::string> &comm, const std::string)
{
    std::cout << "Files: ";
    bool first = true;
    for (auto& command : comm) {
        if (!first) { std::cout << ","; }
        std::cout << command;
        first = false;
    }
    std::cout << std::endl;
}
