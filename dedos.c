#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int save(int a[5000][2], int c[2], int i)
{ // função que salva o nº de dedos de cada round
    int *x;
    int *y;
    a[i][0] = c[0];
    x = &a[i][0];
    a[i][1] = c[1];
    y = &a[i][1];
}

int check(int a[5000][2], int b[5000][2], int c[2], int d[2], int i)
{ // função que compara o estado atual e anteriores do jogo
    int x, y, z;
    x = 0;
    y = 0;
    do
    {
        if ((c[0] == a[x][0] && c[1] == a[x][1]) && (d[0] == b[y][0] && d[1] == b[y][1]) && (x == y))
        {
            z = 0;
            break;
        }
        else
        {
            x++;
            y++;
            z = 1;
        }

    } while (x <= i && y <= i);
    return z;
}

int player(char v[22], char w[22])
{ // função de escolha dos players
    int x;
    char a[22] = {"chico-esperto"};
    char b[22] = {"humano"};
    char c[22] = {"ao-calhas"};
    if (strcmp(a, v) == 0 && strcmp(a, w) == 0)
    { // chico esperto vs chico esperto
        x = 0;
    }
    else if (strcmp(a, v) == 0 && strcmp(b, w) == 0)
    { // chico esperto vs humano
        x = 1;
    }
    else if (strcmp(a, v) == 0 && strcmp(c, w) == 0)
    { // chico esperto vs ao calhas
        x = 2;
    }
    else if (strcmp(b, v) == 0 && strcmp(a, w) == 0)
    { // humano vs chico esperto
        x = 3;
    }
    else if (strcmp(b, v) == 0 && strcmp(b, w) == 0)
    { // humano vs humano
        x = 4;
    }
    else if (strcmp(b, v) == 0 && strcmp(c, w) == 0)
    { // humano vs ao calhas
        x = 5;
    }
    else if (strcmp(c, v) == 0 && strcmp(a, w) == 0)
    { // ao calhas vs chico esperto
        x = 6;
    }
    else if (strcmp(c, v) == 0 && strcmp(b, w) == 0)
    { // ao calhas vs humano
        x = 7;
    }
    else if (strcmp(c, v) == 0 && strcmp(c, w) == 0)
    { // ao calhas vs ao calhas
        x = 8;
    }
    else if (((strcmp(a, v) != 0) && (strcmp(b, v) != 0) && (strcmp(c, v) != 0)) && ((strcmp(a, w) == 0) || (strcmp(b, w) == 0) || (strcmp(c, w) == 0)))
    { // caso player1 seja inválido
        x = 9;
    }
    else if (((strcmp(a, w) != 0) && (strcmp(b, w) != 0) && (strcmp(c, w) != 0)) && ((strcmp(a, v) == 0) || (strcmp(b, v) == 0) || (strcmp(c, v) == 0)))
    { // caso player2 seja invalido
        x = 10;
    }
    else
    {
        x = 11;
    };
    return x;
}

int *dedos(int j[2])
{ // função que faz modulo 5 do numero de dedos
    int *p;
    p = (int *)(malloc(sizeof(2)));
    p = j;

    for (int x = 0; x < 2; x++)
    {
        if (j[x] < 5)
        {
        }
        else if (j[x] == 5)
        {
            j[x] = 0;
        }
        else if (j[x] > 5)
        {
            j[x] = j[x] % 5;
        }
    }
    return p;
}

char *ac(char c[4], int b)
{ // função que escolhe a próxima jogada do ao-calhas (é combinada com a função jogadasac)
    char *p = c;

    if (b == 0)
    {
        strcpy(c, "de");
    }
    else if (b == 1)
    {
        strcpy(c, "dd");
    }
    else if (b == 2)
    {
        strcpy(c, "ed");
    }
    else if (b == 3)
    {
        strcpy(c, "ee");
    }
    else if (b == 4)
    {
        strcpy(c, "=");
    }
    return p;
}

void *jogadas_ac(char v[4], int j1[2], int j2[2])
{
    setlocale(LC_ALL, "Portuguese");
    int x = 0;
    int i, maa;
    char a[3] = {"ee"};
    char b[3] = {"ed"};
    char c[3] = {"de"};
    char d[3] = {"dd"};
    char e[3] = {"="};
    do
    {
        if (strcmp(v, a) == 0 && (j2[0] && j1[0] != 0))
        {
            x = 1;
            j2[0] = j1[0] + j2[0];
            dedos(j2);
            printf("o ao-calhas utilizou os %d dedos da mão esquerda para atacar a mão esquerda do adversário que conta agora com %d dedos\n", j1[0], j2[0]);
        }
        else if (strcmp(v, b) == 0 && (j2[1] && j1[0] != 0))
        {
            x = 1;
            j2[1] = j1[0] + j2[1];
            dedos(j2);
            printf("o ao-calhas utilizou os %d dedos da mão esquerda para atacar a mão direita do adversário que conta agora com %d dedos\n", j1[0], j2[1]);
        }
        else if (strcmp(v, c) == 0 && (j2[0] && j1[1] != 0))
        {
            x = 1;
            j2[0] = j1[1] + j2[0];
            dedos(j2);
            printf("o ao-calhas utilizou os %d dedos da mão direita para atacar a mão esquerda do adversário que conta agora com %d dedos\n", j1[1], j2[0]);
        }
        else if (strcmp(v, d) == 0 && (j2[1] && j1[1] != 0))
        {
            x = 1;
            j2[1] = j1[1] + j2[1];
            dedos(j2);
            printf("o ao-calhas utilizou os %d dedos da mão direita para atacar a mão direita do adversário que conta agora com %d dedos\n", j1[1], j2[1]);
        }
        else if ((strcmp(v, e) == 0) && (j1[0] == 0 && j1[1] % 2 == 0))
        {
            x = 1;
            printf("o ao-calhas aproveitou a oportunidade para dividir os dedos por igual e reativar a mão direita\n");
            j1[0] = j1[1] / 2;
            j1[1] = j1[0];
        }
        else if ((strcmp(v, e) == 0) && (j1[1] == 0 && j1[0] % 2 == 0))
        {
            x = 1;
            printf("o ao-calhas aproveitou a oportunidade para dividir os dedos por igual e reativar a mão esquerda\n");
            j1[1] = j1[0] / 2;
            j1[0] = j1[1];
        }
        else
        {
            printf("escolha uma jogada válida:\n");
            for (i = 1; i < 2; i++)
            {
                maa = rand() % 5;
            }
            strcpy(v, ac(v, maa));
            x = 0;
        }
    } while (x == 0);
}

void *jogadas(char v[4], int j1[2], int j2[2], char nm1[22], char nm2[22])
{ // função que realiza as jogadas do humano
    setlocale(LC_ALL, "Portuguese");
    int x;
    char a[3] = {"ee"};
    char b[3] = {"ed"};
    char c[3] = {"de"};
    char d[3] = {"dd"};
    char e[3] = {"="};
    char f[3] = {";"};
    do
    {
        if (strcmp(v, a) == 0 && j2[0] != 0 && j1[0] != 0)
        {
            x = 1;
            j2[0] = j1[0] + j2[0];
            dedos(j2);
            printf("o %s utilizou os %d dedos da mão esquerda para atacar a mão esquerda do adversário que conta agora com %d dedos\n", nm1, j1[0], j2[0]);
        }
        else if (strcmp(v, b) == 0 && j2[1] != 0 && j1[0] != 0)
        {
            x = 1;
            j2[1] = j1[0] + j2[1];
            dedos(j2);
            printf("o %s utilizou os %d dedos da mão esquerda para atacar a mão direita do adversário que conta agora com %d dedos\n", nm1, j1[0], j2[1]);
        }
        else if (strcmp(v, c) == 0 && j2[0] != 0 && j1[1] != 0)
        {
            x = 1;
            j2[0] = j1[1] + j2[0];
            dedos(j2);
            printf("o %s utilizou os %d dedos da mão direita para atacar a mão esquerda do adversário que conta agora com %d dedos\n", nm1, j1[1], j2[0]);
        }
        else if (strcmp(v, d) == 0 && j2[1] != 0 && j1[1] != 0)
        {
            x = 1;
            j2[1] = j1[1] + j2[1];
            dedos(j2);
            printf("o %s utilizou os %d dedos da mão direita para atacar a mão direita do adversário que conta agora com %d dedos\n", nm1, j1[1], j2[1]);
        }
        else if ((strcmp(v, e) == 0) && (j1[0] == 0 && j1[1] % 2 == 0))
        {
            x = 1;
            printf("o %s aproveitou a oportunidade para dividir os dedos por igual e reativar a mão direita\n", nm1);
            j1[0] = j1[1] / 2;
            j1[1] = j1[0];
        }
        else if ((strcmp(v, e) == 0) && (j1[1] == 0 && j1[0] % 2 == 0))
        {
            x = 1;
            printf("o %s aproveitou a oportunidade para dividir os dedos por igual e reativar a mão esquerda\n", nm1);
            j1[1] = j1[0] / 2;
            j1[0] = j1[1];
        }
        else if (strcmp(v, f) == 0)
        {
            x = 1;
            printf("o %s desistiu!!\n %s venceu!!\n", nm1, nm2);
            j1[0] = 0;
            j1[1] = 0;
        }
        else
        {
            x = 0;
            memset(v, 0, 4);
            fflush(stdin);
            printf("escolha uma jogada válida:");
            gets(v);
            fflush(stdin);
        }
    } while (x == 0);
}

void *chico(int j1[2], int j2[2])
{
    setlocale(LC_ALL, "Portuguese");
    int x;
    char a[3] = {"ee"};
    char b[3] = {"ed"};
    char c[3] = {"de"};
    char d[3] = {"dd"};
    char e[3] = {"="};
    char f[3] = {";"};

    do
    {
        if ((j1[0] > j1[1]) && ((j2[0] < j2[1]) || (j2[0] == j2[1])) && ((j2[0] && j1[0]) != 0))
        {
            // mao esquerda ataca esquerda
            printf("%s\n", a);
            j2[0] = j1[0] + j2[0];
            dedos(j2);
            printf("o jogador 1 utilizou os %d dedos da mão esquerda para atacar a mão esquerda do adversário que conta agora com %d dedos\n", j1[0], j2[0]);
        }
        else if ((j1[0] > j1[1]) && (j2[1] < j2[0]) && ((j2[1] && j1[0]) != 0))
        {
            // mao esquerda ataca direita
            printf("%s\n", b);
            j2[1] = j1[0] + j2[1];
            dedos(j2);
            printf("o jogador 1 utilizou os %d dedos da mão esquerda para atacar a mão direita do adversário que conta agora com %d dedos\n", j1[0], j2[1]);
        }
        else if ((j1[1] > j1[0]) && ((j2[0] < j2[1]) || (j2[0] == j2[1])) && ((j2[0] && j1[1]) != 0))
        {
            // mao direita ataca esquerda
            printf("%s\n", c);
            j2[0] = j1[1] + j2[0];
            dedos(j2);
            printf("o jogador 1 utilizou os %d dedos da mão direita para atacar a mão esquerda do adversário que conta agora com %d dedos\n", j1[1], j2[0]);
        }
        else if ((j1[1] > j1[0]) && (j2[1] < j2[0]) && ((j2[1] && j1[1]) != 0))
        {
            // mao direita ataca direita
            printf("%s\n", d);
            j2[1] = j1[1] + j2[1];
            dedos(j2);
            printf("o jogador 1 utilizou os %d dedos da mão direita para atacar a mão direita do adversário que conta agora com %d dedos\n", j1[1], j2[1]);
        }
        else if ((j1[0] == j1[1]) && ((j2[0] && j1[0]) != 0))
        {
            // caso as maos sejam iguais esquerda ataca esquerda
            printf("%s\n", a);
            j2[0] = j1[0] + j2[0];
            dedos(j2);
            printf("o jogador 1 utilizou os %d dedos da mão esquerda para atacar a mão esquerda do adversário que conta agora com %d dedos\n", j1[0], j2[0]);
        }
        else if (((j1[0] > j1[1]) || (j1[0] == j1[1])) && j2[0] == 0 && j2[1] != 0)
        {
            // mão esquerda maior ou as duas iguais e o oponente tem a mão esquerda igual a 0 -»esquerda ataca direita
            printf("%s\n", b);
            j2[1] = j1[0] + j2[1];
            dedos(j2);
            printf("o jogador 1 utilizou os %d dedos da mão esquerda para atacar a mão direita do adversário que conta agora com %d dedos\n", j1[0], j2[1]);
        }
        else if (((j1[0] > j1[1]) || (j1[0] == j1[1])) && j2[1] == 0 && j2[0] != 0)
        {
            // mão esquerda maior ou as duas iguais e o oponente tem a mão direita igual a 0 -» esquerda ataca esquerda
            printf("%s\n", a);
            j2[0] = j1[0] + j2[0];
            dedos(j2);
            printf("o jogador 1 utilizou os %d dedos da mão esquerda para atacar a mão esquerda do adversário que conta agora com %d dedos\n", j1[0], j2[0]);
        }
        else if ((j1[1] > j1[0]) && j2[0] == 0 && j2[1] != 0)
        {
            // mão direita maior e o oponente tem a mão esquerda igual a 0 -» direita ataca direita
            printf("%s\n", d);
            j2[1] = j1[1] + j2[1];
            dedos(j2);
            printf("o jogador 1 utilizou os %d dedos da mão direita para atacar a mão direita do adversário que conta agora com %d dedos\n", j1[1], j2[1]);
        }
        else if ((j1[1] > j1[0]) && j2[1] == 0 && j2[0] != 0)
        {
            // mão direita maior e o oponente tem a mão direita igual a 0 -» direita ataca esquerda
            printf("%s\n", c);
            j2[0] = j1[1] + j2[0];
            dedos(j2);
            printf("o jogador 1 utilizou os %d dedos da mão direita para atacar a mão esquerda do adversário que conta agora com %d dedos\n", j1[1], j2[0]);
        }
    } while (x == 0);
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Portuguese");
    int j1[2] = {1, 1}, j2[2] = {1, 1}, x, random, i, amb, z;
    char j[4], aoc[4], nome[22], nome2[22];
    int sv1[5000][2], sv2[5000][2];
    sv1[0][0] = 0;
    sv1[0][1] = 0;
    sv2[0][0] = 0;
    sv2[0][1] = 0;
    amb = 0;
    strcpy(nome, argv[1]);
    strcpy(nome2, argv[2]);

    do
    {
        x = player(nome, nome2);
        if (x == 0)
        { // ce vs ce
            printf("Jogo dos dedos: %s vs %s\n", nome, nome2);
            printf(" chico-esperto1:%d %d\n chico-esperto2:%d %d\n", j1[0], j1[1], j2[0], j2[1]);

            do
            {
                printf("chico-esperto1 faz a sua jogada: ");
                chico(j1, j2);
                printf(" chico-esperto1:%d %d\n chico-esperto2:%d %d\n", j1[0], j1[1], j2[0], j2[1]);
                if (j2[0] == 0 && j2[1] == 0)
                {
                    printf("o chico-esperto1 venceu!!! parabéns!!\n");
                    break;
                }
                else
                {
                    z = check(sv1, sv2, j1, j2, amb);

                    if (z == 0)
                    {
                        printf("o jogo terminou empatado\n");
                        break;
                    }
                    else
                    {
                        save(sv1, j1, amb);
                        save(sv2, j2, amb);
                        amb++;
                        printf("chico-esperto2 faz a sua jogada:");
                        chico(j2, j1);
                        printf(" chico-esperto1:%d %d\n chico-esperto2:%d %d\n", j1[0], j1[1], j2[0], j2[1]);
                        if (j1[0] == 0 && j1[1] == 0)
                        {
                            printf("o chico-esperto2 venceu!!! parabéns!!\n");
                        }
                    }
                }
            } while (((j1[0] != 0) || (j1[1] != 0)) && ((j2[0] != 0) || (j2[1] != 0)));
        }
        else if (x == 1)
        { // ce vs hum
            printf("Jogo dos dedos: %s vs %s\n", nome, nome2);
            printf(" chico-esperto1:%d %d\n        humano2:%d %d\n", j1[0], j1[1], j2[0], j2[1]);

            do
            {
                printf("chico-esperto1 faz a sua jogada: ");
                chico(j1, j2);
                printf(" chico-esperto1:%d %d\n        humano2:%d %d\n", j1[0], j1[1], j2[0], j2[1]);
                if (j2[0] == 0 && j2[1] == 0)
                {
                    printf("o chico-esperto1 venceu!!! parabéns!!\n");
                    break;
                }
                else
                {
                    z = check(sv1, sv2, j1, j2, amb);

                    if (z == 0)
                    {
                        printf("o jogo terminou empatado\n");
                        break;
                    }
                    else
                    {
                        save(sv1, j1, amb);
                        save(sv2, j2, amb);
                        amb++;
                        printf("humano2 faça a sua jogada: ");
                        gets(j);
                        jogadas(j, j2, j1, nome2, nome);
                        printf(" chico-esperto1:%d %d\n        humano2:%d %d\n", j1[0], j1[1], j2[0], j2[1]);
                        if (j1[0] == 0 && j1[1] == 0)
                        {
                            printf("o humano2 venceu!!! parabéns!!\n");
                        }
                    }
                }
            } while (((j1[0] != 0) || (j1[1] != 0)) && ((j2[0] != 0) || (j2[1] != 0)));
        }
        else if (x == 2)
        { // ce vs ac
            printf("Jogo dos dedos: %s vs %s\n", nome, nome2);
            printf("chico-esperto1:%d %d\n     ao-calhas2:%d %d\n", j1[0], j1[1], j2[0], j2[1]);

            do
            {
                printf("chico-esperto1 faz a sua jogada: ");
                chico(j1, j2);
                printf("chico-esperto1:%d %d\n     ao-calhas2:%d %d\n", j1[0], j1[1], j2[0], j2[1]);
                if (j2[0] == 0 && j2[1] == 0)
                {
                    printf("o chico-esperto1 venceu!!! parabéns!!\n");
                    break;
                }
                else
                {
                    z = check(sv1, sv2, j1, j2, amb);

                    if (z == 0)
                    {
                        printf("o jogo terminou empatado\n");
                        break;
                    }
                    else
                    {
                        save(sv1, j1, amb);
                        save(sv2, j2, amb);
                        amb++;
                        for (i = 0; i < 2; i++)
                        {
                            random = rand() % 5;
                        }
                        printf("ao-calhas2 faz a sua jogada: %s", ac(aoc, random));
                        jogadas_ac(ac(aoc, random), j2, j1);
                        printf("chico-esperto1:%d %d\n     ao-calhas2:%d %d\n", j1[0], j1[1], j2[0], j2[1]);
                        if (j1[0] == 0 && j1[1] == 0)
                        {
                            printf("o ao-calhas2 venceu!!! parabéns!!\n");
                        }
                    }
                }
            } while (((j1[0] != 0) || (j1[1] != 0)) && ((j2[0] != 0) || (j2[1] != 0)));
        }
        else if (x == 3)
        { // hum vs ce
            printf("Jogo dos dedos: %s vs %s\n", nome, nome2);
            printf("        humano1:%d %d\n chico-esperto2:%d %d\n", j1[0], j1[1], j2[0], j2[1]);

            do
            {
                printf("humano1 faça a sua jogada: ");
                gets(j);
                jogadas(j, j1, j2, nome, nome2);
                printf("        humano1:%d %d\n chico-esperto2:%d %d\n", j1[0], j1[1], j2[0], j2[1]);
                if (j2[0] == 0 && j2[1] == 0)
                {
                    printf("o humano1 venceu!!! parabéns!!\n");
                    break;
                }
                else
                {
                    z = check(sv1, sv2, j1, j2, amb);

                    if (z == 0)
                    {
                        printf("o jogo terminou empatado\n");
                        break;
                    }
                    else
                    {
                        save(sv1, j1, amb);
                        save(sv2, j2, amb);
                        amb++;
                        printf("chico-esperto2 faça a sua jogada: ");
                        chico(j2, j1);
                        printf("        humano1:%d %d\n chico-esperto2:%d %d\n", j1[0], j1[1], j2[0], j2[1]);
                        if (j1[0] == 0 && j1[1] == 0)
                        {
                            printf("o chico-esperto2 venceu!!! parabéns!!\n");
                        }
                    }
                }
            } while (((j1[0] != 0) || (j1[1] != 0)) && ((j2[0] != 0) || (j2[1] != 0)));
        }
        else if (x == 4)
        { // hum vs hum
            printf("Jogo dos dedos: %s vs %s\n", nome, nome2);
            printf(" humano1:%d %d\n humano2:%d %d\n", j1[0], j1[1], j2[0], j2[1]);

            do
            {
                printf("humano1 faça a sua jogada: ");
                gets(j);
                jogadas(j, j1, j2, nome, nome2);
                printf(" humano1:%d %d\n humano2:%d %d\n", j1[0], j1[1], j2[0], j2[1]);
                if (j2[0] == 0 && j2[1] == 0)
                {
                    printf("o humano1 venceu!!! parabéns!!\n");
                    break;
                }
                else
                {
                    z = check(sv1, sv2, j1, j2, amb);

                    if (z == 0)
                    {
                        printf("o jogo terminou empatado\n");
                        break;
                    }
                    else
                    {
                        save(sv1, j1, amb);
                        save(sv2, j2, amb);
                        amb++;
                        printf("humano2 faça a sua jogada: ");
                        gets(j);
                        jogadas(j, j2, j1, nome2, nome);
                        printf(" humano1:%d %d\n humano2:%d %d\n", j1[0], j1[1], j2[0], j2[1]);
                        if (j1[0] == 0 && j1[1] == 0)
                        {
                            printf("o humano2 venceu!!! parabéns!!\n");
                        }
                    }
                }
            } while (((j1[0] != 0) || (j1[1] != 0)) && ((j2[0] != 0) || (j2[1] != 0)));
        }
        else if (x == 5)
        { // hum vs ac
            printf("Jogo dos dedos: %s vs %s\n", nome, nome2);
            printf("    humano1:%d %d\n ao-calhas2:%d %d\n", j1[0], j1[1], j2[0], j2[1]);

            do
            {
                printf("humano1 faça a sua jogada: ");
                gets(j);
                jogadas(j, j1, j2, nome, nome2);
                printf("    humano1:%d %d\n ao-calhas2:%d %d\n", j1[0], j1[1], j2[0], j2[1]);
                if (j2[0] == 0 && j2[1] == 0)
                {
                    printf("o humano1 venceu!!! parabéns!!\n");
                    break;
                }
                else
                {
                    z = check(sv1, sv2, j1, j2, amb);

                    if (z == 0)
                    {
                        printf("o jogo terminou empatado\n");
                        break;
                    }
                    else
                    {
                        save(sv1, j1, amb);
                        save(sv2, j2, amb);
                        amb++;
                        for (i = 0; i < 2; i++)
                        {
                            random = rand() % 5;
                        }
                        printf("ao-calhas2 faz a sua jogada: %s\n", ac(aoc, random));
                        jogadas_ac(ac(aoc, random), j2, j1);
                        printf("    humano1:%d %d\n ao-calhas2:%d %d\n", j1[0], j1[1], j2[0], j2[1]);
                        if (j1[0] == 0 && j1[1] == 0)
                        {
                            printf("o ao-calhas2 venceu!!! parabéns!!\n");
                        }
                    }
                }
            } while (((j1[0] != 0) || (j1[1] != 0)) && ((j2[0] != 0) || (j2[1] != 0)));
        }
        else if (x == 6)
        { // ac vs ce
            printf("Jogo dos dedos: %s vs %s\n", nome, nome2);
            printf("    ao-calhas1:%d %d\n chico-esperto2:%d %d\n", j1[0], j1[1], j2[0], j2[1]);

            do
            {
                for (i = 0; i < 2; i++)
                {
                    random = rand() % 5;
                }
                printf("ao-calhas1 faz a sua jogada: %s", ac(aoc, random));
                jogadas_ac(ac(aoc, random), j1, j2);
                printf("    ao-calhas1:%d %d\n chico-esperto2:%d %d\n", j1[0], j1[1], j2[0], j2[1]);
                if (j2[0] == 0 && j2[1] == 0)
                {
                    printf("o ao-calhas1 venceu!!! parabéns!!\n");
                    break;
                }
                else
                {
                    z = check(sv1, sv2, j1, j2, amb);

                    if (z == 0)
                    {
                        printf("o jogo terminou empatado\n");
                        break;
                    }
                    else
                    {
                        save(sv1, j1, amb);
                        save(sv2, j2, amb);
                        amb++;
                        printf("chico-esperto2 faça a sua jogada: ");
                        chico(j2, j1);
                        printf("    ao-calhas1:%d %d\n chico-esperto2:%d %d\n", j1[0], j1[1], j2[0], j2[1]);
                        if (j1[0] == 0 && j1[1] == 0)
                        {
                            printf("o chico-esperto2 venceu!!! parabéns!!\n");
                        }
                    }
                }
            } while (((j1[0] != 0) || (j1[1] != 0)) && ((j2[0] != 0) || (j2[1] != 0)));
        }
        else if (x == 7)
        { // ac vs hum
            printf("Jogo dos dedos: %s vs %s\n", nome, nome2);
            printf("ao-calhas1:%d %d\n    humano2:%d %d\n", j1[0], j1[1], j2[0], j2[1]);

            do
            {
                for (i = 0; i < 2; i++)
                {
                    random = rand() % 5;
                }
                printf("ao-calhas1 faz a sua jogada: %s", ac(aoc, random));
                jogadas_ac(ac(aoc, random), j1, j2);
                printf("ao-calhas1:%d %d\n    humano2:%d %d\n", j1[0], j1[1], j2[0], j2[1]);
                if (j2[0] == 0 && j2[1] == 0)
                {
                    printf("o ao-calhas1 venceu!!! parabéns!!\n");
                    break;
                }
                else
                {
                    z = check(sv1, sv2, j1, j2, amb);

                    if (z == 0)
                    {
                        printf("o jogo terminou empatado\n");
                        break;
                    }
                    else
                    {
                        save(sv1, j1, amb);
                        save(sv2, j2, amb);
                        amb++;
                        printf("humano2 faça a sua jogada: ");
                        gets(j);
                        jogadas(j, j2, j1, nome2, nome);
                        printf("ao-calhas1:%d %d\n    humano2:%d %d\n", j1[0], j1[1], j2[0], j2[1]);
                        if (j1[0] == 0 && j1[1] == 0)
                        {
                            printf("o humano2 venceu!!! parabéns!!\n");
                        }
                    }
                }
            } while (((j1[0] != 0) || (j1[1] != 0)) && ((j2[0] != 0) || (j2[1] != 0)));
        }
        else if (x == 8)
        { // ac vs ac
            printf("Jogo dos dedos: %s vs %s\n", nome, nome2);
            printf("ao-calhas1:%d %d\n ao-calhas2:%d %d\n", j1[0], j1[1], j2[0], j2[1]);

            do
            {
                for (i = 0; i < 2; i++)
                {
                    random = rand() % 5;
                }
                printf("ao-calhas1 faz a sua jogada: %s", ac(aoc, random));
                jogadas_ac(ac(aoc, random), j1, j2);
                printf("ao-calhas1:%d %d\n ao-calhas2:%d %d\n", j1[0], j1[1], j2[0], j2[1]);
                if (j2[0] == 0 && j2[1] == 0)
                {
                    printf("o ao-calhas1 venceu!!! parabéns!!\n");
                    break;
                }
                else
                {
                    z = check(sv1, sv2, j1, j2, amb);

                    if (z == 0)
                    {
                        printf("o jogo terminou empatado\n");
                        break;
                    }
                    else
                    {
                        save(sv1, j1, amb);
                        save(sv2, j2, amb);
                        amb++;
                        for (i = 0; i < 2; i++)
                        {
                            random = rand() % 5;
                        }
                        printf("ao-calhas2 faz a sua jogada: %s", ac(aoc, random));
                        jogadas_ac(ac(aoc, random), j2, j1);
                        printf("ao-calhas1:%d %d\n ao-calhas2:%d %d\n", j1[0], j1[1], j2[0], j2[1]);
                        if (j1[0] == 0 && j1[1] == 0)
                        {
                            printf("o ao-calhas2 venceu!!! parabéns!!\n");
                        }
                    }
                }
            } while (((j1[0] != 0) || (j1[1] != 0)) && ((j2[0] != 0) || (j2[1] != 0)));
        }
        else if (x == 9)
        {
            printf("player1 invalido\n");
            printf("escolha outro player:");
            gets(nome);
        }
        else if (x == 10)
        {
            printf("player2 invalido\n");
            printf("escolha outro player:");
            gets(nome2);
        }
        else
        {
            printf("player1 e 2 invalido\n");
            printf("escolha outro player1:");
            gets(nome);

            printf("escolha outro player2:");
            gets(nome2);
        }
    } while (x == 9 || x == 10 || x ==11);
}