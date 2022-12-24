#ifndef OBSERVE_H
#define OBSERVE_H


#pragma once
#include <fstream>
#include <vector>

///
/// \brief The Observe class - interface
///
class Observe
{
public:
    virtual void print(const std::vector<std::string>&, const std::string) = 0;
    virtual ~Observe() = default;
};

///
/// \brief The FileObserver class - for files to command
///
class FileObserver: public Observe
{
public:
    FileObserver();

private: // чтобы юзать сию функцию только через интерфейс
    virtual void print(const std::vector<std::string>& comm, const std::string time);
};

///
/// \brief The TerminalObserver class - for terminal
///
class TerminalObserver: public Observe
{
public:
    TerminalObserver();

private: // аналогично
    virtual void print(const std::vector<std::string>& comm, const std::string);
};

#endif // OBSERVE_H
