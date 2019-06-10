#include "console/progress_bar.h"

#include <iostream>
#include <cmath>
#include <unistd.h>

using namespace Console;


/**
 * - Initialize the progress bar.
 * - Initialize the total items to progress.
 */
ProgressBar::ProgressBar(Interfaces::OutputInterface * output, const unsigned int totalItems = 100)
{
    m_output = output;
    m_totalItems = totalItems;

    m_redrawFrequency = 60;
    m_indicator = '>';

    m_width = 100;
    m_progress = 1;
    m_currentPercentage = 0.0;
    m_maxPercentage = 100.0;
}

/**
 * Start the progress bar.
 *
 * @return void
 */
void ProgressBar::start()
{
    draw();
}

/**
 * Advance the progress bar.
 *
 * @param const unsigned int progress
 * @return void
 */
void ProgressBar::advance(const unsigned int progress)
{
    if (m_progress >= m_totalItems) {
        m_progress = m_totalItems;
    } else {
        m_progress += progress;
    }

    draw();
}

/**
 * Stops the progress bar.
 * 
 * @return ProgressBar
 */
void ProgressBar::stop()
{
    std::cout << '\n';
    std::cout.flush();
}

/**
 * Draw the progress bar.
 * 
 * @return void
 */
void ProgressBar::draw()
{
    m_indicator.resize(m_width);
    std::fill(m_indicator.begin(), m_indicator.begin()+m_width, '-');

    m_currentPercentage = std::floor(((m_progress * m_width) / ((m_totalItems / m_maxPercentage) * 100)));
    unsigned int position = static_cast<unsigned int>((m_currentPercentage / m_maxPercentage) * m_width);
    
    
    if (m_currentPercentage < m_maxPercentage) {
        std::fill(m_indicator.begin(), m_indicator.begin()+position, '=');
        m_indicator[position] = '>';
    }

    std::cout << '\r' << m_currentPercentage << '%' << " [" << m_indicator.c_str() << "] items: " << m_progress << " / " << m_totalItems;
    std::cout.flush();
    
    usleep(m_redrawFrequency * 1000);
}
