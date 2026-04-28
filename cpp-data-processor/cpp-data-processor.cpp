#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Function to compute average
double computeAverage(const vector<double>& numbers) {
    if (numbers.empty()) return 0.0;

    double sum = 0;
    for (double n : numbers) {
        sum += n;
    }
    return sum / numbers.size();
}

// Function to compute min and max
void computeMinMax(const vector<double>& numbers, double& minVal, double& maxVal) {
    if (numbers.empty()) return;

    minVal = numbers[0];
    maxVal = numbers[0];

    for (double n : numbers) {
        if (n < minVal) minVal = n;
        if (n > maxVal) maxVal = n;
    }
}

int main() {
    ifstream file("data.txt");

    if (!file.is_open()) {
        cout << "Failed to open file." << endl;
        return 1;
    }

    vector<double> numbers;
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        double value;
        ss >> value;
        numbers.push_back(value);
    }

    file.close();

    double avg = computeAverage(numbers);

    double minVal, maxVal;
    computeMinMax(numbers, minVal, maxVal);

    cout << "Data Summary:\n";
    cout << "Count: " << numbers.size() << endl;
    cout << "Average: " << avg << endl;
    cout << "Min: " << minVal << endl;
    cout << "Max: " << maxVal << endl;

    return 0;
}