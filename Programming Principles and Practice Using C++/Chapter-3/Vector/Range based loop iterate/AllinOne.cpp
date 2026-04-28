#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    std::vector<double> temps;

    std::cout << "Enter temperature (stop with non-number like x):\n";

    // Input  + push_back (dynamic growth)
    for (double temp; std::cin >> temp;) {

        temps.push_back(temp);
        std::cout << "Added: " << temp
                  << " | Size: " << temps.size()
                  << " | Capacity: " << temps.capacity() << '\n';
    }

    // Check empty
    if (temps.size() == 0) {

        std::cout << "No Data!\n";
        return 0;
    }

    // Average calculation (range-for, copy)
    double sum = 0;
    for (double x : temps) {

        sum += x;
    }

    std::cout << "\nAverage: " << sum / temps.size() << '\n';

    // Modify values (reference)
    for (double& x : temps) {

        x = x * 1.1; // increase 10%
    }

    std::cout << "\nAfter increase:\n";
    for (double x : temps) {

        std::cout << x << " ";
    }
    std::cout << '\n';

    // Sort
    std::sort(temps.begin(), temps.end()); // sort generic so specific we use begin and end use identify

    std::cout << "\nSorted values:\n";
    for (double x : temps) {

        std::cout << x << " ";
    }
    std::cout << '\n';

    // Median
    double median = temps[temps.size() / 2];

    std::cout << "\nMedian: " << median << '\n';

    return 0;
}