#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <fstream>

using namespace std;

unordered_map<string, string> correct_guide {
    pair<string, string>("A", "Y"),
    pair<string, string>("B", "Z"),
    pair<string, string>("C", "X")
};

unordered_map<string, string> another_correct_guide {
    pair<string, string>("A", "X"),
    pair<string, string>("B", "Y"),
    pair<string, string>("C", "Z")
};

unordered_map<string, int> map {
    pair<string, int>("X", 1),
    pair<string, int>("Y", 2),
    pair<string, int>("Z", 3)
};

const char* res_path = "res/2-1_input.txt";

template <class T>
void read_data(T path) {
    fstream in;
    in.open(path);
    if (!in.is_open()) { return; }
    string line;
    int sum = 0;
    string a, b;
    while (getline(in, line)) {
        if (line.length() < 1) continue;
        istringstream iss {line};
        iss >> a >> b;
        if (b == "Y") sum += map[another_correct_guide[a]] + 3;
        else if (b == "Z") sum += map[correct_guide[a]] + 6;
        else sum += 6 - map[another_correct_guide[a]] - map[correct_guide[a]];
    }
    cout << sum << endl;
}

int main() {
    read_data(res_path);
    return 0;
}
