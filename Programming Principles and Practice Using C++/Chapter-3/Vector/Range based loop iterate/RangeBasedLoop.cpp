#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    std::vector<double> temps;

    for (double temp; std::cin >> temp; )
         temps.push_back(temp);

    if (temps.size() == 0) {

        std::cout << "No Data\n";
        return 0;
    }
    
    // mean
    double sum = 0;
    for (double x : temps) // range based loop iterate like (for loop)
        sum += x;

    std::cout << "Average: " << sum / temps.size() << '\n';
    
    // median
    std::sort(temps.begin(), temps.end()); // sort is like coparative operater
    std::cout << "Median: " << temps[temps.size() / 2] << '\n';

    return 0;

}