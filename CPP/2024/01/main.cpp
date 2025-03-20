#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void starOne(string &content);

void starTwo(string &content);

stringstream readFile(const string &filename);

void sortArray(vector<int> &arr);

int abs1(const int &n);

int countOccurrences(const vector<int> &arr, const int &value);

int main() {
    cout << " ==== Advent of Code 2024 | Day 01 | * ==== " << endl;

    // ==== Read file content ====
    stringstream cs = readFile("test-data-1.txt");
    string content = cs.str();
    starOne(content);
    starTwo(content);

    cs.clear();
    content.clear();

    cs = readFile("data-1.txt");
    content = cs.str();
    starOne(content);
    starTwo(content);

    return 0;
}

void starOne(string &content) {
    stringstream cs(content);
    string line;
    vector<string> lines;

    while (getline(cs, line, '\n')) {
        lines.push_back(line);
    }

    vector<int> n1, n2;
    for (const auto &l: lines) {
        stringstream ss(l);
        string n;
        getline(ss, n, ' ');
        n1.push_back(stoi(n));
        n.clear();
        getline(ss, n);
        n2.push_back(stoi(n));
    }
    // ===========================

    // ==== Sort n1 and n2 ====
    sortArray(n1);
    sortArray(n2);
    // ========================

    // ==== Distances ====
    vector<int> distances;

    for (int i = 0; i < n1.size(); i++) {
        int val = n1[i] - n2[i];
        distances.push_back(abs1(val));
    }
    // ===================

    // ==== Calculate total distance ====
    int totalDistance = 0;
    for (const auto &d: distances) {
        totalDistance += d;
    }
    // ==================================

    cout << "Result for *: " << totalDistance << endl;
}

void starTwo(string &content) {
    stringstream cs(content);
    string line;
    vector<string> lines;

    while (getline(cs, line, '\n')) {
        lines.push_back(line);
    }

    vector<int> n1, n2;
    for (const auto &l: lines) {
        stringstream ss(l);
        string n;
        getline(ss, n, ' ');
        n1.push_back(stoi(n));
        n.clear();
        getline(ss, n);
        n2.push_back(stoi(n));
    }
    // ===========================

    // ==== Calculate similarity score ====
    int similarityScore = 0;
    for (const auto &n: n1) {
        const int occupied = countOccurrences(n2, n);
        similarityScore += occupied * n;
    }

    cout << "Result for **: " << similarityScore << endl;
}

stringstream readFile(const string &filename) {
    if (ifstream file(filename); file.is_open()) {
        stringstream ss;
        ss << file.rdbuf();
        file.close();
        return ss;
    } else {
        cout << "Error: Unable to open file " << filename << endl;
        exit(1);
    }
}

void sortArray(vector<int> &arr) {
    for (size_t i = 0; i < arr.size(); i++) {
        for (size_t j = i + 1; j < arr.size(); j++) {
            if (arr[i] > arr[j]) {
                // swap
                const auto temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int abs1(const int &n) {
    if (n < 0) {
        return n * -1;
    }
    return n;
}

int countOccurrences(const vector<int> &arr, const int &value) {
    int occurrences = 0;

    for (const int &i: arr) {
        if (i == value) {
            occurrences++;
        }
    }

    return occurrences;
}
