#ifndef PROGRESS_BAR_H
#define PROGRESS_BAR_H

#include "interfaces/output_interface.h"


namespace Console {

    /**
     * The ProgressBar Class
     */
    class ProgressBar {

    public:

        /**
         * - Initialize the output interface.
         * - Initialize the total items to progress.
         */
        ProgressBar(Interfaces::OutputInterface * output, const unsigned int totalItems);

        /**
         * Start the progress bar.
         *
         * @return void
         */
        void start();

        /**
         * Advance the progress bar.
         *
         * @param const unsigned int progress
         * @return void
         */
        void advance(const unsigned int progress);

        /**
         * Stop the progress bar.
         * 
         * @return void
         */
        void stop();

    private:

        /**
         * Draw the progress bar.
         * 
         * @return void
         */
        void draw();

    private:

        /**
         * Store the output interface.
         * 
         * @var Interfaces::OutputInterface * m_output
         */
        Interfaces::OutputInterface * m_output;

        /**
         * Store the total amount of items.
         * 
         * @var unsigned int m_totalItems.
         */
        unsigned int m_totalItems;

        /**
         * Store the amount of items
         * to progress.
         * 
         * @var unsigned int m_items
         */
        unsigned int m_items;

        /**
         * Store the progress.
         * 
         * @var unsigned int m_progress
         */
        unsigned int m_progress;

        /**
         * Indicate how often should
         * the progress bar redraw
         * in milliseconds.
         * 
         * @var unsigned int m_redrawFrequency 
         */
        unsigned int m_redrawFrequency;

        /**
         * Store the indicator
         * for the progress.
         * 
         * @var std::string m_indicator
         */
        std::string m_indicator;

        /**
         * Store the width of the progress bar.
         * 
         * @var unsigned int m_width
         */
        unsigned int m_width;

        /**
         * Store the current percentage.
         * 
         * @var float m_currentPercentage
         */
        float m_currentPercentage;

        /**
         * Store the max percentage.
         * 
         * @var float m_maxPercentage
         */
        float m_maxPercentage;

    };

}


#endif // PROGRESS_BAR_H