#include <stdio.h>;

typedef char* String; // create String data type
const char* STRUCT_WORD_FORMAT = "(%i, %s, %c)\n";

// SETTINGS -------------------------------------------------------------------!
// in quotes, put path-to-file of words
// "/home/(name)/KimchiReader-Auto-Status/words.dat"
const String FILE_PATH = "/home/katarina/repos/KimchiReader-Auto-Status/words.dat";

// SETTINGS -------------------------------------------------------------------!

struct KoreanWordList {
    int WordCount;
    struct Word* WordList;
};
struct Word {
    int count;
    String word;
    char status; // U, S, K respectively unknown, seen, known, these are to indicate if the person has the following words on seen or on known
};

void serialize(FILE* file, String FILE_PATH, struct KoreanWordList KoreanWordList) {
    file = fopen(FILE_PATH, "w+");

    int WordCount = KoreanWordList.WordCount; // set count
    struct Word* WordList = KoreanWordList.WordList;

    fprintf(file, "[%i]", WordCount); // print wordCount to file
    for(int i; i<WordCount; i++) { // print struct Word to file
        fprintf(file, STRUCT_WORD_FORMAT, WordList[i].count, WordList[i].word, WordList[i].status);
    }
}

struct Word* deserialise() {

}

int main(int argc, char *argv[]) {

}