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

template <class T>
void sort_vec(vector<T> &v) {
    sort(v.begin(), v.end());
}

int main() {

    read_data(res_path);
    sort_vec(elf_calories);
    int sum = 0;
    for (int i = elf_calories.size()-1; i >= elf_calories.size() - 3; i--) {
        sum += elf_calories[i];
    }
    cout << sum << endl;
    return 0;
}
