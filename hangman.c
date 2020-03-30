#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>

/*
char *list[12] ={
"positive", "programming","ball", "soccer",
"boardgame", "sportman","peace", "goalkeeper",
"green", "technology","avenger", "awesome"
};*/

void Welcome(int nmLetter){printf("Welcome to Hangman game, you have 5 lives, and your word has %d letters\n", nmLetter);}
void Answer(int j,int length,char*word){for(j=0;j<length; j++){word[j]='*';}}
char *list = "cinderella";

int main(void) {
   int wordi = 0, length, lives = 5;
   char word[25];
   length = strlen(&list[wordi]);
   int j, correct, i = 0;
   char symb;
   srand((unsigned int) time(NULL));
   Welcome(length);
   Answer(j,length,word);

   word[length] = 0;
   printf("%s\n", word);

   while ((lives > 0) && (i < length)) {
      correct = 0;
      printf("Guess it: ");

      do {
         scanf("%c", &symb);
         symb = tolower(symb);
         if (((symb < 'a') || (symb > 'z')) && (symb > ' ')) {
            printf("Invalid character\nWrite a letter: ");
         }

      } while ((symb < 'a') || (symb > 'z'));
      
      for (j = 0; j < length; j++) {
         if (symb == word[j]) {
            printf("This character already used.\n");
            lives--;
            printf("Same letter wrote. %i lives left.\n", lives);
            break;
         }
      }

      if (j == length) {
         for (j = 0; j < length; j++) {
            if (symb == list[j]) {
               word[j] = symb;
               i++;
               correct = 1;
            }
         }

         if (correct == 0) {
            lives--;
            if (lives > 0) {
               printf("Fail. %i lives left.\n", lives);
            } else {
               printf("Looser.\n");
               return 0;
            }
         } else {
            if (i < length) {
               printf("Correct.\n");
            } else {
               printf("Winner\n");
            }
         }

         printf("You have %s\n", word);
      }
   }
}