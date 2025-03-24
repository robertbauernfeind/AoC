#include <chrono>
#include <fstream>
#include <iostream>
#include <regex>

using namespace std;
using namespace chrono;

int p1(const vector<string> &v) {
    vector<string> copy(v);
    int count = 0;
    const regex reg(R"(mul\((\d{1,3}),(\d{1,3})\))");
    smatch match;

    for (auto &l: copy) {
        while (std::regex_search(l, match, reg)) {
            const int n1 = stoi(match[1].str());
            const int n2 = stoi(match[2].str());
            count += n1 * n2;

            l = match.suffix().str();
        }
    }

    return count;
}

int p2(const vector<string> &v) {
    vector<string> copy(v);
    int count = 0;
    smatch match;
    bool enabled = true;

    const regex reg(R"(mul\((\d{1,3}),(\d{1,3})\))");
    const regex on(R"(do\(\))");
    const regex off(R"(don't\(\))");
    const regex combo(R"(mul\((\d+),(\d+)\)|do\(\)|don't\(\))");

    for (auto &l: copy) {
        while (std::regex_search(l, match, combo)) {
            if (regex_match(match.str(), on)) {
                enabled = true;
            }
            if (regex_match(match.str(), off)) {
                enabled = false;
            }

            if (enabled && regex_match(match.str(), reg)) {
                const int n1 = stoi(match[1].str());
                const int n2 = stoi(match[2].str());
                count += n1 * n2;
            }

            l = match.suffix().str();
        }
    }
    return count;
}

int main() {
    const auto start = high_resolution_clock::now();

    cout << " ==== Advent of Code 2024 | Day 03 ==== " << endl;
    // https://adventofcode.com/2024/day/3
    ifstream fi("data-1.txt");
    string line;
    vector<string> memories;

    while (getline(fi, line)) {
        memories.push_back(line);
    }

    cout << "Day 3: Mull it Over" << endl
            << "Part 1     - " << p1(memories) << endl
            << "Part 2     - " << p2(memories) << endl
            << "Run time   - " << duration_cast<microseconds>(high_resolution_clock::now() - start).count() / 1000
            << "ms. " << endl;

    return 0;
}
