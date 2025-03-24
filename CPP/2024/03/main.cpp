#include <chrono>
#include <fstream>
#include <iostream>
#include <regex>

using namespace std;
using namespace chrono;

int p1(vector<string> &v) {
    int count = 0;
    const regex reg(R"(mul\((\d{1,3}),(\d{1,3})\))");
    smatch match;

    for (auto &l: v) {
        while (std::regex_search(l, match, reg)) {
            const int n1 = stoi(match[1].str());
            const int n2 = stoi(match[2].str());
            count += n1 * n2;

            l = match.suffix().str();
        }
    }

    return count;
}

int main() {
    const auto start = high_resolution_clock::now();

    cout << " ==== Advent of Code 2024 | Day 03 ==== " << endl;
    // https://adventofcode.com/2024/day/3
    ifstream fi("test-data-1.txt");
    string line;
    vector<string> memories;

    while (getline(fi, line)) {
        memories.push_back(line);
    }

    cout << "Day 3: Mull it Over" << endl
            << "Part 1     - " << p1(memories) << endl
            << "Part 2     - " << "" << endl
            << "Run time   - " << duration_cast<microseconds>(high_resolution_clock::now() - start).count() / 1000
            << "ms. " << endl;

    return 0;
}
