#include <iostream>
#include <unordered_map>
using namespace  std;

int main() {
    int N;
    cin >> N;

    string a[N];
    for (int i = 0; i < N; ++i) {
        std::cin >> a[i];
    }

    unordered_map<char, int> d1;
     unordered_map<char, int> d2;

    for (char i : a[0]) {
        d1[i] = d1[i] + 1;
    }

    for (int i = 1; i < N; ++i) {
        d2.clear();
        for (char j : a[i]) {
            d2[j] = d2[j] + 1;
        }

        unordered_map<char, int> d3;
        for (const auto& j : d2) {
            d3[j.first] = std::min(d1[j.first], d2[j.first]);
        }

        d1 = d3;

        int c = 0;
        for (const auto& i : d1) {
            c += i.second;
        }

        cout << c << endl;
    }

    return 0;
}