#ifndef COMMANDES_H
#define COMMANDES_H


#pragma once
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <algorithm>
#include <ctime>
#include <sstream>
#include "Observe.h"


class Commandes
{
public:
    Commandes(int N);

    ~Commandes();

    void subscribe(std::unique_ptr<Observe>&& obs);

    void setTime();

    void notify();

    void add_command(const std::string& s);

private:
    std::vector< std::unique_ptr< Observe > > m_obs;
    std::vector< std::string > m_comm;

    std::size_t m_block_size;
    std::size_t m_comm_counter = 0;
    int m_bracket_counter = 0;
    bool m_is_reg = true;
    std::string m_time;
};

#endif // COMMANDES_H
