#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    unordered_map<string, vector<string>> mp;
    mp["seulf"] = {"12", "23"};
    cout << mp["seulf"][0] << endl;
    return 0;
}
