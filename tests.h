#include <iostream>
#include <fstream>
#include <utility>
#include <cassert>
#include <cstdlib>

using namespace std;

void unit_test() {
    TreeMap<int,int> dict;

    // slownik jest pusty
    assert(dict.isEmpty() == true);
    assert(dict.size() == 0);
    assert(dict.contains(0) == false);

    // dodanie elementu do slownika
    dict.insert(0, 1);
    assert(dict.isEmpty() == false);
    assert(dict.size() == 1);
    assert(dict.contains(0) == true);
    assert(dict.value(0) == 1);

    // dodanie elementu do slownika jako pary
    dict.insert(pair<int,int>(1, 2));
    assert(dict.size() == 2);
    assert(dict.contains(1) == true);
    assert(dict.value(0) == 1);
    assert(dict.value(1) == 2);

    // operator []
    assert(dict[0] == 1);
    assert(dict[1] == 2);

    // operator [] tworzy nowy element
    dict[2] = 3;
    assert(dict.value(2) == 3);
    assert(dict.size() == 3);


    // nadpisanie wartosci dla istniejacego elementu
    dict.insert(2, 4);
    assert(dict.size() == 3);
    assert(dict.value(2) == 4);
}

void tadeusz_test(const int &numberOfWords) {
    TreeMap<int, string> dict;
    ifstream fp;
    fp.open("pan-tadeusz.txt");
    if (!fp.is_open()) {
        cerr << "Cannot open file.\n";
        return;
    }
    string word;
    unsigned int counter = 0;
    int key = 0;
    while (fp >> word && counter < numberOfWords) {
        key = rand() % 100;
        dict.insert(key, word);
        ++counter;
    }
    fp.close();
}