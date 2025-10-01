// *************************************************************************** 
// 
//   Your Name 
//   Your Harper ID
//   Your Course and Section Number 
// 
//   I certify that this is my own work and where appropriate an extension 
//   of the starter code provided for the assignment. 
// ***************************************************************************

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <iomanip> 

int main() {
    std::string filename;
    std::cout << "Enter the name of the input file: ";
    std::cin >> filename;

    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error opening file.\n";
        return 1;
    }

    // count numbers
    double temp;
    int count = 0;

    while (inFile >> temp) {
        count++;
    }

    if (count == 0) {
        std::cerr << "No data found in file.\n";
        return 1;
    }

    // dynamic array
    inFile.clear();    
    inFile.seekg(0);               

    double* data = new double[count];
    for (int i = 0; i < count; ++i) {
        inFile >> data[i];
    }
    inFile.close();

    // Sorting
    std::sort(data, data + count);

    // Find median
    double median;
    if (count % 2 == 1) {
        median = data[count / 2];
    } else {
        median = (data[count / 2 - 1] + data[count / 2]) / 2.0;
    }

    // Output
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "The median is: " << median << std::endl;

    delete[] data;

    return 0;
}
