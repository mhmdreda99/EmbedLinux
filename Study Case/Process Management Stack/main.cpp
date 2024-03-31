// include Dependacies 
#include <iostream> 
#include <thread>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace std::chrono_literals;

/**
 * @brief This function generates a high CPU load by performing a 
 * large number of operations in a loop.
 * 
 */
void loadCPU() {


    // Declare a volatile double variable. The volatile keyword indicates that the value of the variable may change at any time--without any action being taken by the code.
    volatile double result = 0;

    // Loop a large number of times to generate CPU load.
    for (int i = 0; i < 1000000; ++i) {
        // Add a random number between 0 and 999 to the result.
        result += std::rand() % 1000;
    }
}
/**
 * @brief 
 *  The main function of the program. It generates a random delay, 
 * calls the loadCPU function twice, and then prints a message to the console.
 * 
 * @return int 
 */
int main ()
{
    // Seed the random number generator with the current time.
    std::srand(std::time(nullptr));

    // Enter an infinite loop.
    while (true)
    {
        // Generate a random delay between 100 and 101 milliseconds.
        int delay = std::rand() % 1 + 100;

        // Call the loadCPU function twice to generate CPU load.
        loadCPU();
        loadCPU();

        // Print a message to the console.
        cout << "Hello from process" << endl;
    }
    return 0 ;
}