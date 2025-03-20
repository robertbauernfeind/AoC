#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

int abs1(const int &n) {
    if (n < 0) {
        return n * -1;
    }
    return n;
}

bool isIncreasing(const vector<int> &report) {
    for (int i = 1; i < report.size(); i++) {
        const int n1 = report[i - 1];
        const int n2 = report[i];

        const int diff = n1-n2;
        if (n1 > n2
            || (abs1(diff) < 1 || abs1(diff) > 3)) {
            return false;
        }
    }
    return true;
}

bool isDecreasing(const vector<int> &report) {
    for (int i = 1; i < report.size(); i++) {
        const int n1 = report[report.size() - i - 1];
        const int n2 = report[report.size() - i];

        const int diff = n1-n2;
        if (n1 < n2
            || (abs1(diff) < 1 || abs1(diff) > 3)) {
            return false;
        }
    }
    return true;
}

void starOne(string &content) {
    stringstream ss(content);
    string line;
    vector<string> lines;

    while (getline(ss, line, '\n')) {
        lines.push_back(line);
    }

    vector<vector<int> > reports;
    for (const auto &l: lines) {
        stringstream ls(l);
        string n;
        vector<int> report;
        while (getline(ls, n, ' ')) {
            report.push_back(stoi(n));
        }
        reports.push_back(report);
    }
    // ===========================

    // ==== Validate reports ====
    // valid if all increasing or decreasing
    // valid if difference between two adjacent numbers is
    // at least one and at most 3

    int safeReports = 0;
    for (const auto &r: reports) {
        bool inc = isIncreasing(r);
        bool dec = isDecreasing(r);
        if (inc || dec) {
            safeReports++;
        }
    }
    // ==========================

    cout << "Result for *: " << safeReports << endl;
}


void starTwo(string &content) {
}

stringstream readFile(const string &filename) {
    if (ifstream file(filename); file.is_open()) {
        stringstream ss;
        ss << file.rdbuf();
        file.close();
        return ss;
    }
    cout << "Error: Unable to open file " << filename << endl;
    exit(1);
}

int main() {
    // https://adventofcode.com/2024/day/2

    const stringstream cs = readFile("test-data-1.txt");
    string content = cs.str();
    starOne(content);
    starTwo(content);

    return 0;
}
