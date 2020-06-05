#include "s_time.h"


Time::Time() : m_beg(clock_t::now()) {}


void Time::reset()
{
    m_beg = clock_t::now();
}

double Time::elapsed() const
{

//    return std::chrono::duration_cast<std::chrono::seconds>
//            (clock_t::now() - m_beg).count();
    return std::chrono::duration_cast<second_t>
           (clock_t::now() - m_beg).count();
}
