#include <stdio.h>;

typedef char* String; // create String data type


// SETTINGS -------------------------------------------------------------------!
// in quotes, put path-to-file of words
// "/home/(name)/KimchiReader-Auto-Status/words.dat"
const String FILE_PATH = "/home/katarina/repos/KimchiReader-Auto-Status/words.dat";

// SETTINGS -------------------------------------------------------------------!


struct Word {
    int count;
    String word;
    String status;
};

void serialize(FILE* file, String FILE_PATH) {
    file = fopen(FILE_PATH, "w+");
}

struct Word* deserialise() {

}

int main(int argc, char *argv[]) {

}