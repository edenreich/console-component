#include "console/progress_bar.h"

#include <iostream>
#include <cmath>
#include <unistd.h>

using namespace Console;


/**
 * - Initialize the progress bar.
 * - Initialize the total items to progress.
 * 
 * @param Interfaces::OutputInterface * output
 * @param const unsigned int totalItems
 */
ProgressBar::ProgressBar(Interfaces::OutputInterface * output, const unsigned int totalItems)
{
    m_output = output;
    m_totalItems = totalItems;

    m_redrawFrequency = 60;
    m_indicator = '>';

    m_width = 50;
    m_position = 0;
    m_progress = 0;
    m_currentPercentage = 0;
    m_maxPercentage = 100;
}

/**
 * Destroy the progress bar.
 */
ProgressBar::~ProgressBar()
{
    stop();
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
    if (m_progress < m_totalItems) {
        m_progress = m_progress + progress;
    } else {
        m_progress = m_totalItems;
    }

    draw();
}

/**
 * Stop the progress bar.
 * 
 * @return void
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

    m_currentPercentage = std::floor((static_cast<float>(m_progress) / static_cast<float>(m_totalItems)) * m_maxPercentage);
    m_position = std::floor((static_cast<float>(m_currentPercentage) / static_cast<float>(m_maxPercentage)) * m_width);

    if (m_currentPercentage > m_maxPercentage) {
        m_position = m_width;
    }

    std::fill(m_indicator.begin(), m_indicator.begin()+m_position, '=');
    m_indicator[m_position] = '>';

    std::cout << '\r' << m_currentPercentage << '%' << " [" << m_indicator.c_str() << "] items: " << m_progress << " / " << m_totalItems;
    std::cout.flush();
}
