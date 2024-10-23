#include <stdio.h>;

typedef char* String; // create String data type
const char* STRUCT_WORDCOUNT_FORMAT = "[%i]";
const char* STRUCT_WORD_FORMAT_IN = "(%i, %c, %50[^,])";
const char* STRUCT_WORD_FORMAT_OUT = "(%i, %c, %s)\n";


// SETTINGS -------------------------------------------------------------------!
// in quotes, put path-to-file of words
// "/home/(name)/KimchiReader-Auto-Status/words.dat"
const String FILE_PATH_WORDS = "/home/katarina/repos/KimchiReader-Auto-Status/words.dat";
const String FILE_PATH_WORDCOUNT = "/home/katarina/repos/KimchiReader-Auto-Status/wordcount.dat";
// SETTINGS -------------------------------------------------------------------!


struct KoreanWordList {
    int WordCount;
    struct Word* WordList;
};
struct Word {
    int count;
    char status; // U, S, K respectively unknown, seen, known, these are to indicate if the person has the following words on seen or on known
    int length;
    String word;
};

void serialize(String FILE_PATH_WORDS, struct KoreanWordList KoreanWordList) { // save to file
    // open file with error handling
    FILE* file = fopen(FILE_PATH_WORDS, "w+");
    if (file == NULL) { perror("Error opening file"); return; }

    // set structs for easier access
    int WordCount = KoreanWordList.WordCount; // set count
    struct Word* WordList = KoreanWordList.WordList;

    // print structs to file
    fprintf(file, STRUCT_WORDCOUNT_FORMAT, WordCount); // print wordCount to file
    for(int i = 0; i<WordCount; i++) { // print struct Word to file
        fprintf(file, STRUCT_WORD_FORMAT_OUT, WordList[i].count, WordList[i].status, WordList[i].word);
    }

    fclose(file);
}

struct KoreanWordList* deserialise(String FILE_PATH) { // load objects from file
    // open file with error handling
    FILE* file = fopen(FILE_PATH, "w+");
    if (file == NULL) { perror("Error opening file"); return; }

    // malloc struct

    // scan file
    fprintf(file, STRUCT_WORDCOUNT_FORMAT, WordCount); // load wordCount to file
    for (int i = 0; i<WordCount; i++) {
        fscanf(file, STRUCT_WORD_FORMAT_IN, &WordList[i].count, &WordList[i].status, WordList[i].word, WordList[i].length);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {

}