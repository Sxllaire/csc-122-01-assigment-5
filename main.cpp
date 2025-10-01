//*************************************************************
//
//Danil Alieinikov
//H00880905
//CSC122-01
//
//I certify that this is my work and where appropriate an extension
//of the starter code provided by the assignment
//************************************************************

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
