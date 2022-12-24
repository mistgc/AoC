#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const char *res_path = "res/1-1_input.txt";
vector<int> elf_calories;

template <class T> void read_data(T path) {
    fstream in;
    in.open(path);
    if (!in.is_open()) {
       return;
    }
    string line;
    int sum = 0;
    while (getline(in, line)) {
        char begin = *line.begin();
        if (line.length() < 1 || begin == '\n' || begin == '\t' || begin == ' ' || begin == '\r') {
            elf_calories.push_back(sum);
            sum = 0;
        } else {
            sum += stoi(line);
        }
    }
}

int main() {

    read_data(res_path);
    cout << *max_element(elf_calories.begin(), elf_calories.end()) << endl;

    return 0;
}
