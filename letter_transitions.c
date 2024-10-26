/*Name: Pranav Vijay Nadgir
Roll no: CS22B1034
Write a C program to perform the frequency of transitions between vowels and consonants in a sentence from the user. Calculate the average number of transitions per word and identify words with the highest transition rate, displaying them in descending order.

Sample Input:
[“in chennai”]

Sample Output:
in:
Transitions:
i -> n: 1 transition (vowel to consonant)
Total transitions: 1

chennai:
Transitions:
c -> e: 1 transition (consonant to vowel)
e -> n: 1 transition (vowel to consonant)
n -> a: 1 transition (consonant to vowel)
a -> i: no transition (both vowels)
Total transitions: 3

Total transitions: 1+3=4
Number of words: 2
Average transition per Word: 4/2=2
Words with Highest Transition Rate (Descending Order):
chennai (3 transitions)
in (1 transition )
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char sentence[50];
char** words;
int sen_len=0,word_count=0,total_transitions=0,transitions[50][2];//(word_pos,word_transition_count);

int is_vowel(char c)
{
    if(tolower(c) == 'a' ||tolower(c) == 'e' ||tolower(c) == 'i' ||tolower(c) == 'o' ||tolower(c) == 'u' )
        return 1;
    else return 0;
}

int main()
{
    int j=0,k=0;
    char c;
    printf("Enter the sentence: ");
    scanf(" %[^\n]",sentence);
    
    //split sentence into array of words:
    sen_len = strlen(sentence);
    for(int i=0; i<sen_len; i++)//iterate char wise through entire sentence:
    {
        if(sentence[i] == ' ')
            word_count++;
    }
    word_count++;
    words = (char**)malloc(word_count*sizeof(char*));
    for(int i=0; i<word_count; i++)
    {
        words[i] = (char*)malloc(10*sizeof(char));
    }
    //printf("word_count=%d\n",word_count);
    for(int i=0; i<word_count; i++)
    {
        c=sentence[j];
        k=0;
        while(c!=' ' && c!='\0')
        {
            words[i][k++] = c;
            c=sentence[++j];
        }
        words[i][j++] = '\0';
    }
    // for(int i=0; i<word_count; i++)
    // {
    //     printf("%s\n",words[i]);
    // }
    
    //find transitions:
    printf("Transitions:\n");
    int word_transition=0,wor_len=0,p1=0,p2=1;
    for(int i=0; i<word_count; i++)
    {
        wor_len=strlen(words[i]);
        printf("Word: %s\n",words[i]);
        word_transition=0;
        p1=0;
        p2=1;
        for(int j=0; j<wor_len; j++)
        {
            if(words[i][p2]=='\0')
                break;
            if(is_vowel(words[i][p1]) && !is_vowel(words[i][p2]))//vowel to consonant
            {
                word_transition++;
                total_transitions++;
                printf("%c -> %c: 1 transition(vowel to consonant)\n",words[i][p1],words[i][p2]);
                
            }
            else if(!is_vowel(words[i][p1]) && is_vowel(words[i][p2]))//consonant to vowel
            {
                word_transition++;
                total_transitions++;
                printf("%c -> %c: 1 transition(consonant to vowel)\n",words[i][p1],words[i][p2]);
            }
            p1++;
            p2++;
        }
        printf("Total word transitions: %d\n\n",word_transition);
        transitions[i][0] = i;
        transitions[i][1] = word_transition;
    }
    printf("\nResults:\n");
    printf("Total transitions: %d\nNumber of words: %d\n Average transition per word: %.2f\n",total_transitions,word_count,((float)total_transitions/(float)word_count));
    printf("\nWords with highest transition rate(descending order):\n");
    //sort transitions array based on 2nd index:
    int temp[1][2];
    for(int i=0;i<word_count;i++)
    {
        for(int j=0;j<word_count-i;j++)
        {
            if(transitions[j][1]<transitions[j+1][1])
            {
                //swap
                temp[0][0] = transitions[j][0];
                temp[0][1] = transitions[j][1];
                transitions[j][0] = transitions[j+1][0];
                transitions[j][1] = transitions[j+1][1];
                transitions[j+1][0] = temp[0][0];
                transitions[j+1][1] = temp[0][1];
            }
        }
    }
    for(int i=0;i<word_count;i++)
    {
        //printf("(%d,%d)\n",transitions[i][0],transitions[i][1]);
        printf("%s (%d transitions)\n",words[transitions[i][0]],transitions[i][1]);
    }
    return 0;
}
