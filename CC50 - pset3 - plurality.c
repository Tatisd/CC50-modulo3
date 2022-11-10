#include <cs50.h>
#include <stdio.h>
#include <string.h>


#define MAX 9 //definir numero maximo de candidatos

typedef struct
{
    string name;
    int votes;
}
candidate;

candidate candidates[MAX]; //array

int candidate_count;

bool vote(string name);
void print_winner(void);

int main(int argx, string argy[])
{
    if (argx < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }
    //argumentos
    candidate_count = argx - 1;
    if (candidate_count > MAX)
    {
        printf("O numero maximo de candidatos e %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argy[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("votantes: ");

    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Voto: ");

        if (!vote(name)) // se voto for inváliso
        {
            printf("Invalid vote.\n");
        }
    }
    print_winner(); //eleito
}
bool vote(string name) //contagem de votos
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0) //se o votado = nome
        {
            candidates[i].votes++;

            return true;
        }
    }

    return false;
}

void print_winner(void) //ganhador
{
    int x = 0; // maior numero de votos

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > x)
        {
            x = candidates[i].votes;
        }
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == x)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}