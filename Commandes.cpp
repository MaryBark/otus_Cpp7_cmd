#include "Commandes.h"
#include <iostream>


Commandes::Commandes(int N) :m_block_size(N),
    m_comm_counter(0),
    m_bracket_counter(0),
    m_time("")
{}

//--------------------------------------------------------------------------
Commandes::~Commandes()
{
    if (m_is_reg)
        if (m_comm_counter)
            notify();
}

void Commandes::subscribe(std::unique_ptr<Observe> &&obs)
{
    m_obs.emplace_back(std::move(obs));
}

void Commandes::setTime()
{
    std::time_t temp_time;
    temp_time=std::time(0);
    std::stringstream ss;
    ss << temp_time;
    ss >> m_time;
}

void Commandes::notify()
{
    for (auto& u: m_obs)
    {
        u->print(m_comm, m_time);
    }
    m_comm.clear();
    m_time.clear();
}

void Commandes::add_command(const std::string &s)
{
    if (std::cin.eof()) { return; }

    if (s[0] == '{')
    {
        if (m_comm_counter)
        {
            notify();
            m_comm_counter = 0;
        }

        ++m_bracket_counter;
        m_is_reg = false;
        return;
    }
    else if (s[0] == '}')
    {
        --m_bracket_counter;
        if (!m_bracket_counter)
        {
            notify();
            m_is_reg = true;
        }
    }

    else {
        if (m_comm.empty()) { setTime(); }
        m_comm.push_back(s);
        if (m_is_reg)
        {
            ++m_comm_counter;
            if (m_comm_counter == m_block_size)
            {
                notify();
                m_comm_counter = 0;
            }
        }
    }

}
