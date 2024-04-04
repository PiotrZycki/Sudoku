#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

//Sprawdzanie arg[1]
int arg_check(char*arg[]){
    char gnr[]="generuj";
    char slv[]="rozwiazuj";
    char chk[]="sprawdz";
    char prt[]="wypisz";

    if(strcmp(gnr,arg[1])==0){return 0;}
    else if(strcmp(slv,arg[1])==0) {return 1;}
    else if(strcmp(chk,arg[1])==0){return 2;}
    else if(strcmp(prt,arg[1])==0){return 3;}

    else{return -1;}
}

//Poziom trudności
int level_difficulty(char*arg[]){
    char p_easy[]="latwe";
    char p_medium[]="srednie";
    char p_hard[]="trudne";

    if(strcmp(p_easy,arg[2])==0){
        return 0;
    }
    else if(strcmp(p_medium,arg[2])==0){
        return 1;
    }
    if(strcmp(p_hard,arg[2])==0){
        return 2;
    }
    else{
        return -1;
    }
}

//Wypełnianie tablicy zerami
void filling_zeros(int N, int tab[N][N]){
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            tab[i][j]=0;
        }
    }
}

//Sprawdzanie dostępności w rzędach
int check_row(int N, int tab[N][N], int row, int liczba){
    for(int i=0; i<N; i++){
        if(tab[row][i]==liczba){
            return 1;
        }
    }
    return 0;
}

//Sprawdzanie dostępności w kolumnach
int check_col(int N, int tab[N][N], int col, int liczba){
    for(int i=0; i<N; i++){
        if(tab[i][col]==liczba){
            return 1;
        }
    }
    return 0;
}

//Sprawdzanei dostępności w kwadratach
int check_square(int N, int tab[N][N], int row1, int row2, int col1, int col2, int liczba){
    for(int i=row1; i<row2; i++){
        for(int j=col1; j<col2; j++){
            if(tab[i][j]==liczba){
                return 1;
            }
        }
    }
    return 0;
}

//Wybór kwadratu do sprawdzenia
int check_box(int N, int tab[N][N], int row, int col, int liczba){

    if(row>=0 && row<3){
        if(col>=0 && col<3){
            if(check_square(N,tab,0,3,0,3,liczba)){return 1;}
        }
        else if(col>=3 && col<6){
            if(check_square(N,tab,0,3,3,6,liczba)){return 1;}
        }
        else if(col>=6 && col<9){
            if(check_square(N,tab,0,3,6,9,liczba)){return 1;}
        }
    }

    else if(row>=3 && row<6){
        if(col>=0 && col<3){
            if(check_square(N,tab,3,6,0,3,liczba)){return 1;}
        }
        else if(col>=3 && col<6){
            if(check_square(N,tab,3,6,3,6,liczba)){return 1;}
        }
        else if(col>=6 && col<9){
            if(check_square(N,tab,3,6,6,9,liczba)){return 1;}
        }
    }

    else if(row>=6 && row<9){
        if(col>=0 && col<3){
            if(check_square(N,tab,6,9,0,3,liczba)){return 1;}
        }
        else if(col>=3 && col<6){
            if(check_square(N,tab,6,9,3,6,liczba)){return 1;}
        }
        else if(col>=6 && col<9){
            if(check_square(N,tab,6,9,6,9,liczba)){return 1;}
        }
    }
    return 0;
}

//Rozwiązywanie
int solve(int N, int tab[N][N], int row, int col){
    int col_n=0,row_n=0;
    if(row>=8 && col>=8)    //Dotarcie do końca planszy
    {
        if(tab[row][col]!=0){
            return 1;
        }
        else{
            for (int i = 1; i < 10; i++) {
                if((check_row(N,tab,row,i)==0) && (check_col(N,tab,col,i)==0) && (check_box(N,tab,row, col, i)==0)){
                    tab[row][col]=i;
                    return 1;
                }
            }
            tab[row][col]=0;
            return 0;
        }
    }

    if(tab[row][col]!=0){
        if(col<8){
            col++;
        }
        else if(col>=8){
            col=0;
            row++;
        }

        if(solve(N,tab,row,col)==1){
            return 1;
        }
        else{return 0;}
    }

    if(tab[row][col]==0){
        for (int i = 1; i < 10; i++) {
            if((check_row(N,tab,row,i)==0) && (check_col(N,tab,col,i)==0) && (check_box(N,tab,row, col, i)==0)){
                tab[row][col]=i;
                if(col<8){
                    col_n=col+1;
                    row_n=row;
                }
                else if(col>=8){
                    col_n=0;
                    row_n=row+1;
                }

                if(solve(N,tab,row_n,col_n)==1){
                    return 1;
                }
            }
        }
        tab[row][col]=0;
        return 0;
    }
}

//Generowanie
void gen(int N, int tab[N][N], int lvl){
    int los_row, los_col, los_num, a, k;
    int temp[N][N];
    srand(time(NULL));

    if(lvl==0){a=35;}
    else if(lvl==1){a=25;}
    else if(lvl==2){a=15;}
    else{
        printf("\nNieznany argument\n");
        exit(0);
    }

    do {
        k=0;
        filling_zeros(N,tab);
        filling_zeros(N,temp);
        while (k < a) {
            do {
                los_row = rand() % 9;
                los_col = rand() % 9;
                los_num = 1 + rand() % 9;
            }
            while ((check_row(N, tab, los_row, los_num) == 1) || (check_col(N, tab, los_col, los_num) == 1) ||
                     (check_box(N, tab, los_row, los_col, los_num) == 1));
            tab[los_row][los_col] = los_num;
            k++;
        }
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                temp[i][j]=tab[i][j];
            }
        }
    }
    while(solve(N, temp, 0, 0) == 0);
}

//pozioma linia przerywana
void dashed_line(){
    printf("  ");
    for(int i=0; i<37; i++){
        printf("-");
    }
    printf("\n");
}

//Wyświetlanie
void print(int N, int tab[N][N]){
    for(int i=0; i<N; ++i){
        if(i==0||i==3||i==6){
            dashed_line();
        }

        for(int j=0; j<N; ++j){
            if(j==0||j==3||j==6){
                printf("  |");
            }

            if(tab[i][j]==0){
                printf("  .");
            }
            else {
                printf("  %d", tab[i][j]);
            }

            if(j==8){
                printf("  |");
            }
        }
        printf("\n");

        if(i==8){
            dashed_line();
        }
    }
}

//Czytanie pliku
void read_file(int N, int tab[N][N], char*arg[]){
    int j=1, i=0, k, l, G;
    char text[100];
    FILE *fp;

    fp=fopen(arg[2],"r");
    if(!fp){
        printf("\nPlik nie istnieje\n");
        exit(0);
    }

    //fseek(fp,0,SEEK_SET);
    while(fgets(text, 100, fp) ){
        l=8;
        G = atol(text);
        while(G){
            k=G%10;
            tab[i][l]=k;
            G /= 10;
            l--;
        }
        i++;
        j++;
    }
    fclose(fp);
}

//Zapis do pliku
void write_file(int N, int tab[N][N], char*arg[]){
    char c;
    FILE *fp;

    fp=fopen(arg[3],"w+");
    if(!fp){
        printf("\nBłąd zapisu do pliku.\n");
        exit(0);
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            c=tab[i][j]+'0';
            fputc(c, fp);
        }
        fputs("\n",fp);
    }
    fclose(fp);
}


int main(int n, char*arg[]) {
    SetConsoleOutputCP(CP_UTF8);
    int N=9;
    int tab[9][9];

    filling_zeros(N,tab);

    switch(arg_check(arg)){
        case 0:
            gen(N,tab,level_difficulty(arg));
            print(N, tab);
            write_file(N,tab,arg);
            printf("Wygenerowane sudoku zostało zapisane w pliku: %s.\n", arg[3]);
            break;

        case 1:
            read_file(N,tab,arg);
            if (solve(N, tab, 0, 0) == 0) {
                printf("\nBrak rozwiazan\n");
            }
            else {
                printf("\nRozwiązanie:\n");
                print(N, tab);
                write_file(N,tab,arg);
                printf("\nRozwiązanie zostało zapisane w pliku: %s.\n", arg[3]);
            }
            break;

        case 2:
            printf("\nSprawdzanie...\n");
            read_file(N,tab,arg);
            if (solve(N, tab, 0, 0)==1) {
                printf("\nSudoku jest poprawne.\n");
            }
            else{
                printf("\nSudoku nie jest możliwe do rozwiązania.\n");
            }
            break;

        case 3:
            read_file(N,tab,arg);
            print(N, tab);
            break;

        case -1:
            printf("\nNieznane polecenie.\n");
            break;

        default:
            printf("\nERROR/\n");
            break;
    }

    return 0;
}
