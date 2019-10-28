#include "fetch_data.h"

#include <iostream>
#include <thread>
#include <future>
#include <functional>
#include <chrono>
#include <utility>
#include <sstream>
#include <console/progress_bar.h>


/**
 * An example for a long running task
 * 
 * @param Console::Interfaces::OutputInterface * output
 * @return std::vector
 */
std::vector<int> FetchData::fetch(Console::Interfaces::OutputInterface * output)
{
    const unsigned int items = 15;
    std::vector<int> veryUsefuldata;

    Console::ProgressBar * progressBar = output->createProgressBar(items);

    output->writeLine("Sending an http request..");

    progressBar->start();

    for (int i = 0; i <= items; i++)
    {
        // Simulate an http request.
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        // Storing the data.
        veryUsefuldata.emplace_back(i);

        progressBar->advance(1);
    }

    progressBar->stop();

    delete progressBar;

    return veryUsefuldata;
}

/**
 * Retrieve the name of the command.
 *
 * @return std::string
 */
std::string FetchData::getName()
{
    return "fetch:data";
}

/**
 * Retrieve the description of the command.
 *
 * @return std::string
 */
std::string FetchData::getDescription()
{
    return "fetch data from an external api";
}

/**
 * Retrieve the command options.
 *
 * @return Console::Types::AvailableOptions
 */
Types::AvailableOptions FetchData::getOptions()
{
    Types::AvailableOptions options;

    options["-t"] = std::pair<std::string, std::string>("--threads", "the amount of threads to run");

    return options;
}

/**
 * Handle the command.
 *
 * @param Console::Interfaces::InputInterface * input
 * @param Console::Interfaces::OutputInterface * output
 * @return ExitCode
 */
ExitCode FetchData::handle(Interfaces::InputInterface * input, Interfaces::OutputInterface * output)
{    
    // Create a packaged task.
    std::packaged_task<std::vector<int>()> task(std::bind(&FetchData::fetch, this, output));

    // Get the promise object.
    std::future<std::vector<int>> promise = task.get_future();

    // Move the task into a separate thread.
    std::thread t(std::move(task));

    // Get the promise results.
    std::vector<int> results = promise.get();
    
    // Join the thread to the main context.
    t.join();

    // Output the results.
    output->writeLine("Printing the results from the request:");
    for (auto & data : results)
    {
        std::stringstream ss;
        ss << data;

        output->writeLine(ss.str());
    }

    output->writeLine("Task completed..");

    return ExitCode::Ok;
}
