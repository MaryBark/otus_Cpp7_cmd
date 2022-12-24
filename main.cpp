#include <iostream>
#include "Observe.h"
#include "Commandes.h"

//using namespace std;

int main(int, char * argv[])
{
    Commandes command_log(std::atoi(argv[1]));
    command_log.subscribe(std::make_unique<FileObserver>());
    command_log.subscribe(std::make_unique<TerminalObserver>());


    std::string s;
    while (std::getline(std::cin, s)) {
        command_log.add_command(s);
    }

    return 0;
}
