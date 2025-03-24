#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

bool isIncreasing(const vector<int> &report) {
    for (int i = 1; i < report.size(); i++) {
        const int n1 = report[i - 1];
        const int n2 = report[i];

        if (n1 > n2
            || (abs(n1 - n2) < 1 || abs(n1 - n2) > 3)) {
            return false;
        }
    }
    return true;
}

bool isDecreasing(const vector<int> &report) {
    for (int i = 1; i < report.size(); i++) {
        const int n1 = report[report.size() - i - 1];
        const int n2 = report[report.size() - i];

        if (n1 < n2
            || (abs(n1 - n2) < 1 || abs(n1 - n2) > 3)) {
            return false;
        }
    }
    return true;
}

size_t indexOf(const vector<int> &report, const int &value) {
    for (size_t i = 0; i < report.size(); i++) {
        if (report[i] == value) {
            return i;
        }
    }

    return -1;
}

bool safe(const vector<int> &report) {
    return isIncreasing(report) || isDecreasing(report);
}

bool safeWithDampener(const vector<int> &report) {
    for (int i = 0; i < report.size(); i++) {
        vector<int> copy(report);
        copy.erase(copy.begin() + i);
        if (safe(copy)) return true;
    }

    return false;
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
        if (r.empty()) {
            continue;
        }

        if (safe(r)) {
            safeReports++;
        }
    }
    // ==========================

    cout << "Result for *: " << safeReports << endl;
}

void starTwo(string &content) {
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
        if (r.empty()) {
            continue;
        }

        if (safe(r)) {
            safeReports++;
        } else if (safeWithDampener(r)) {
            safeReports++;
        }
    }
    // ==========================

    cout << "Result for **: " << safeReports << endl;
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
    cout << " ==== Advent of Code 2024 | Day 02 ==== " << endl;
    // https://adventofcode.com/2024/day/2

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
