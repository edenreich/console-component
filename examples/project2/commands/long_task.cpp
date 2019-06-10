#include "long_task.h"

#include <iostream>
#include <thread>
#include <chrono>
#include <console/progress_bar.h>


/**
 * An example for a long running task
 * 
 * @return void
 */
void LongTask::exampleTask(Interfaces::OutputInterface * output)
{
    const unsigned int items = 1000;

    Console::ProgressBar * progressBar1 = output->createProgressBar(items);
    
    progressBar1->start();

    for (int i = 0; i < items; i++)
    {
        // long running task..
        progressBar1->advance(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(60));
    }

    progressBar1->stop();

    delete progressBar1;
}

/**
 * An example for a long running task2
 * 
 * @return void
 */
void LongTask::exampleTask2(Interfaces::OutputInterface * output)
{
    const unsigned int items = 1000;

    Console::ProgressBar * progressBar2 = output->createProgressBar(items);

    progressBar2->start();
    
    for (int i = 0; i < items; i++)
    {
        // long running task..
        progressBar2->advance(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(60));
    }

    progressBar2->stop();

    delete progressBar2;
}

/**
 * Retrieve the name of the command.
 *
 * @return std::string
 */
std::string LongTask::getName()
{
    return "long-task";
}

/**
 * Retrieve the description of the command.
 *
 * @return std::string
 */
std::string LongTask::getDescription()
{
    return "this is a long running task";
}

/**
 * Handle the command.
 *
 * @param InputInterface * input
 * @param OutputInterface * output
 * @return ExitCode
 */
ExitCode LongTask::handle(Interfaces::InputInterface * input, Interfaces::OutputInterface * output)
{
    output->writeLine("Making a long running tasks..");
    
    std::thread t1(&LongTask::exampleTask, this, output);
    std::thread t2(&LongTask::exampleTask2, this, output);

    output->writeLine("Spawned tasks..");

    t1.join();
    t2.join();

    output->writeLine("Tasks completed..");

    return ExitCode::Ok;
}
