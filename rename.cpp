// rename.cpp -- rename files (C++ version)
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

void usage() {
    cout << "usage: rename old_string new_string file_pattern" << endl;
}

int main(int argc, char **argv) {
    if (argc < 4) {
        usage();
        return 1;
    }
    string currentString = argv[1];
    string replaceString = argv[2];
    int currentStringLength = currentString.size();
    int replaceStringLength = replaceString.size();
    size_t pos;
    for (int i = 3; i < argc; i++) {
        string currentName = argv[i];
        string newName = currentName;
        pos = newName.find(currentString);
        while(pos != string::npos) {
            newName.replace(pos, currentStringLength, replaceString);
            pos = newName.find(currentString, pos + replaceStringLength);
        }
        if (rename(currentName.c_str(), newName.c_str()) != 0) {
            string err = "Error renaming file: " + currentName;
            perror(err.c_str());
        }
    }
    return 0;
}
