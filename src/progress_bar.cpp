#include "console/progress_bar.h"
#include <thread>
#include <ostream>
#include <iostream>
#include <string>
#include <cmath>

using namespace Console;


/**
 * - Initialize the progress bar.
 * - Initialize the total items to progress.
 */
ProgressBar::ProgressBar(Interfaces::OutputInterface * output, const unsigned int totalItems)
{
    m_output = output;
    m_totalItems = totalItems;

    m_redrawFrequency = std::chrono::milliseconds { 60 };
    m_indicator = '>';
}

/**
 * Start the progress bar.
 *
 * @return void
 */
void ProgressBar::start()
{
    m_stop = false;

    std::cout << '\n';
    std::thread t(&ProgressBar::draw, this);

    t.detach();
}

/**
 * Advance the progress bar.
 *
 * @param const unsigned int progress
 * @return void
 */
void ProgressBar::advance(const unsigned int progress)
{
    if (m_progress > m_totalItems) {
        m_progress = m_totalItems;
    }

    m_progress = m_progress + progress;
}

/**
 * Stops the progress bar.
 * 
 * @return ProgressBar
 */
void ProgressBar::stop()
{
    m_stop = true;
}

/**
 * Draw the progress bar.
 * 
 * @return void
 */
void ProgressBar::draw()
{
    float percentage = 1;
    unsigned int currentPosition = 1;
    float maxPercentage = 100.0;
    unsigned int progressBarWidth = maxPercentage;
    m_indicator.resize(progressBarWidth);
    std::fill(m_indicator.begin(), m_indicator.begin()+progressBarWidth, '-');
    
    // @todos 
    // - check how to make this better
    // - check how not to force pthread linking, maybe add a flag to cmake, this is currently breaking example/project1
    do
    {
        if (percentage < maxPercentage) {
            currentPosition = static_cast<int>(percentage);
            m_indicator[currentPosition] = '=';
            m_indicator[currentPosition+1] = '>';
        }

        std::cout << '\r' << percentage << '%' << " [" << m_indicator.c_str() << "] items: " << m_progress << " / " << m_totalItems << std::flush;

        percentage = std::floor(m_progress / maxPercentage);
        std::this_thread::sleep_for(m_redrawFrequency);
    } while (!m_stop);
}
