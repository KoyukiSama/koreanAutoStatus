#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* String; // create String data type
const char* STRUCT_WORDCOUNT_FORMAT = "[%i]";
const char* STRUCT_WORD_FORMAT_IN = "(%i, %c, %[^,],)\n";
const char* STRUCT_WORD_FORMAT_OUT = "[%i](%i, %c, %s,)\n";


// SETTINGS -------------------------------------------------------------------!
// in quotes, put path-to-file of words
// "./words.dat" , . means it's in the current directory
const String FILE_PATH_WORDS = "./words.dat";
// SETTINGS -------------------------------------------------------------------!

// TODO count user input to make space for serialisation

struct KoreanWordList {
    int WordCount;
    struct Word* WordList;
};
struct Word {
    int count;
    char status; // U, S, K respectively unknown, seen, known, these are to indicate if the person has the following words on seen or on known
    int size;
    String word;
};

void serialize(String FILE_PATH_WORDS, struct KoreanWordList *KoreanWordList) { // save to file
    // open file with error handling
    FILE* file = fopen(FILE_PATH_WORDS, "w");      if (file == NULL) { perror("Error opening file"); return; }

    // set structs for easier access
    int WordCount = KoreanWordList->WordCount; // set count
    struct Word* WordList = KoreanWordList->WordList;

    // print structs to file
    fprintf(file, STRUCT_WORDCOUNT_FORMAT, WordCount); // print wordCount to file
    for(int i = 0; i<WordCount; i++) { // print struct Word to file
        fprintf(file, STRUCT_WORD_FORMAT_OUT, WordList[i].size, WordList[i].count, WordList[i].status, WordList[i].word);
        free(WordList[i].word);
    }
    free(WordList);
    free(KoreanWordList);
    fclose(file);
}

struct KoreanWordList* deserialise(String FILE_PATH_WORDS, int inputSize) { // load objects from file
    // open file with error handling
    FILE* file = fopen(FILE_PATH_WORDS, "r");        if (file == NULL) { free(file); perror("Error opening file"); return NULL; }

    // malloc structs and get word count
    struct KoreanWordList *KoreanWordList = malloc(sizeof(*KoreanWordList));        if (KoreanWordList == NULL) { free(KoreanWordList); perror("Error allocating memory for KoreanWordList struct"); return NULL; }
    fscanf(file, STRUCT_WORDCOUNT_FORMAT, &(KoreanWordList->WordCount)); // load wordCount to file
    KoreanWordList->WordList = malloc(sizeof(struct Word) * (KoreanWordList->WordCount * 2 + inputSize));      if (KoreanWordList->WordList == NULL) {free(KoreanWordList->WordList); perror("Error allocating memory for WordList struct"); return NULL;}

    // set structs for easier access
    int WordCount = KoreanWordList->WordCount;
    struct Word* WordList = KoreanWordList->WordList;

    // scanf file for rest of words
    for (int i = 0; i<WordCount; i++) {
        fscanf(file, "[%i]", &WordList[i].size);
        WordList[i].word = malloc(sizeof(char) * WordList[i].size + 1); if (WordList[i].word == NULL) {free(WordList[i].word); perror("Error allocating for string word"); return NULL;}
        fscanf(file, STRUCT_WORD_FORMAT_IN, &WordList[i].count, &WordList[i].status, WordList[i].word);
    }

    fclose(file);

    return KoreanWordList;
}

int main(int argc, char *argv[]) {
    // korean ADD
    if ( strcmp(argv[1], "add") == 0 && argc > 2 ) {

        argv = (argv + 2); // set pointer to begin of words
        int addWordCount = argc - 2;
        struct KoreanWordList* KoreanWordList = deserialise(FILE_PATH_WORDS, addWordCount);         if (KoreanWordList == NULL) { perror("Error deserializing in ADD section"); return 1; }
        int tempWordCount = KoreanWordList->WordCount;
        struct Word* WordList = KoreanWordList->WordList;
        char wordFound = 0;

        for (int i = 0; i<addWordCount; i++) {
            for (int j = 0; j<tempWordCount; j++) {
                if (strcmp(WordList[j].word, argv[i]) == 0) { // if word is found
                    WordList[j].count++;
                    wordFound = 1;
                    break;
                }
            }
            if (wordFound == 0) { // if not found, add it
                WordList[tempWordCount].count = 0; // set count to 0
                WordList[tempWordCount].status = 'U'; // set status to unknown
                WordList[tempWordCount].size = strlen(argv[i]); // set size to length
                strcpy(WordList[tempWordCount].word, argv[i]); // set word to current add word

                tempWordCount++; // increment word count to account for new word
            }
            wordFound = 0;
        }
        KoreanWordList->WordCount = tempWordCount;
        serialize(FILE_PATH_WORDS, KoreanWordList);
        free(KoreanWordList);
    }

    // korean CHECK
    else if (strcmp(argv[1], "check") == 0 && argc == 2) { // if korean check 

    }
    

    // korean HELP
    else if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) {
        FILE *file = fopen("./help.txt", "r");          if (file == NULL) { printf("Error opening help file.txt"); return 2; }

        int ch ;while ( ( ch = fgetc(file)) != EOF ); {
            putchar(ch);
        }

        printf("help File written!");
        fclose(file);
        return 0;
    }

    // korean ERROR
    else { // if any random word
        printf("Error? try, korean -h or korean --help");
        return 1;
    }
    
}