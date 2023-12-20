#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void show_board(int disc_states[][8]);
//vector<direction_value*> legal_move(int disc_states[][8], int turn);
int calculate_score(int disc_states[][8], int turn);
void change_disks(int disc_states[][8], int turn, int row, int column);
int validation1(int disc_states[][8], int turn, int row, int column);
int validation2(int disc_states[][8], int turn, int row, int column);
int validation3(int disc_states[][8], int turn, int row, int column);
int validation4(int disc_states[][8], int turn, int row, int column);
int validation5(int disc_states[][8], int turn, int row, int column);
int validation6(int disc_states[][8], int turn, int row, int column);
int validation7(int disc_states[][8], int turn, int row, int column);
int validation8(int disc_states[][8], int turn, int row, int column);
void valid_check (int disc_states[][8], int turn);

int main()
{
    int turn = 1;
    int select_row, select_column;
    int black_score=2, white_score=2;
    int black_flag, white_flag;
    //vector<direction_value*> valid_moves;
    int disc_states[8][8];
    for (int i=0; i<8; i++)
        for (int j=0; j<8; j++)
            disc_states[i][j] = 0;
    disc_states[3][3] = -1;
    disc_states[3][4] = 1;
    disc_states[4][3] = 1;
    disc_states[4][4] = -1;
    show_board(disc_states);
    cout << ".(dot) is valid position\n" << endl << flush;
    system("PAUSE");
    while(1){
        black_flag = 0;
        white_flag = 0;
        turn = 1;
        valid_check (disc_states, turn);
        int sum_valid = 0;
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                if(disc_states[i][j]==2)
                    sum_valid++;
            }
        }
        if (sum_valid==0)
            black_flag = 1;
        else{
            while(1){
                black_score = calculate_score(disc_states, 1);
                white_score = calculate_score(disc_states, -1);
                show_board(disc_states);
                cout << "Black Score : " << black_score << "\tWhite Score : " << white_score << endl << flush;
                cout << "Number of validation move : " << sum_valid << endl;
                cout << "Black, It is your turn ... Select row and column of your desired block" << endl << flush;
                cout << "Row : ";
                cin >> select_row;
                cout << "Column : ";
                cin >> select_column;
                if(disc_states[select_row-1][select_column-1]==2)
                    break;
            }
            change_disks(disc_states, turn, select_row-1, select_column-1);
        }
        turn = -1;
        valid_check (disc_states, turn);
        sum_valid = 0;
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                if(disc_states[i][j]==2)
                    sum_valid++;
            }
        }
        if (sum_valid==0)
            white_flag = 1;
        else{
            while(1){
                black_score = calculate_score(disc_states, 1);
                white_score = calculate_score(disc_states, -1);
                show_board(disc_states);
                cout << "Black Score : " << black_score << "\tWhite Score : " << white_score << endl << flush;
                cout << "White, It is your turn ... Select row and column of your desired block" << endl << flush;
                cout << "Number of validation move : " << sum_valid << endl;
                cout << "Row : ";
                cin >> select_row;
                cout << "Column : ";
                cin >> select_column;
                if(disc_states[select_row-1][select_column-1]==2)
                    break;
            }
            change_disks(disc_states, turn, select_row-1, select_column-1);
        }
        if ((black_flag==1)&&(white_flag==1))
            break;
    }
    system("CLS");
    black_score = calculate_score(disc_states, 1);
    white_score = calculate_score(disc_states, -1);
    cout << "Black Score : " << black_score << "\tWhite Score : " << white_score << endl << flush;
    if (black_score > white_score)
        cout << "\nBlack wins !!!" << endl;
    else if (black_score < white_score)
        cout << "\nWhite wins !!!" << endl;
    else
        cout << "\nWhat a game! NO one wins!!! what we have here? A DRAWWWW!!!" << endl;
    system("PAUSE");
    return 0;
}

void show_board(int disc_states[][8]){
    system ("CLS");
    cout << "  \\column" << endl << flush;
    cout << "row\\ 1   2   3   4   5   6   7   8" << endl << flush;
    cout <<"   ---------------------------------"<<endl << flush;
    for (int i=0; i<8; i++){
        cout << ' ' << i+1 << ' ';
        for (int j=0; j<17; j++){
            if(j%2==0)
                cout << '|';
            else{
                if (disc_states[i][(j-1)/2]==0)
                    cout << "   ";
                else if (disc_states[i][(j-1)/2]==1)
                    cout << " B ";
                else if (disc_states[i][(j-1)/2]==-1)
                    cout << " W ";
                else
                    cout << " . ";
            }
        }
        cout <<"\n   ---------------------------------"<<endl << flush;
    }
}

int validation1(int disc_states[][8], int turn, int row, int column){
    if(column+2<8){
        if(disc_states[row][column+1] == -turn){
            for(int j=column+2; j<8; j++){
                if((disc_states[row][j]==0)||(disc_states[row][j]==2))
                    return 0;
                if(disc_states[row][j]==turn)
                    return 1;
            }
        }
    }
    return 0;
}
int validation2(int disc_states[][8], int turn, int row, int column){
    if((0<=row-2)&&(column+2<8)){
        if(disc_states[row-1][column+1] == -turn){
            for(int i=row-2,j=column+2; 0<=i&&j<8; i--,j++){
                if((disc_states[i][j]==0)||(disc_states[i][j]==2))
                    return 0;
                if(disc_states[i][j]==turn)
                    return 1;
            }
        }
    }
    return 0;
}
int validation3(int disc_states[][8], int turn, int row, int column){
    if(0<=row-2){
        if(disc_states[row-1][column] == -turn){
            for(int i=row-2; 0<=i; i--){
                if((disc_states[i][column]==0)||(disc_states[i][column]==2))
                    return 0;
                if(disc_states[i][column]==turn)
                    return 1;
            }
        }
    }
    return 0;
}
int validation4(int disc_states[][8], int turn, int row, int column){
    if((0<=row-2)&&(0<=column-2)){
        if(disc_states[row-1][column-1] == -turn){
            for(int i=row-2,j=column-2; 0<=i&&0<=j; i--,j--){
                if((disc_states[i][j]==0)||(disc_states[i][j]==2))
                    return 0;
                if(disc_states[i][j]==turn)
                    return 1;
            }
        }
    }
    return 0;
}
int validation5(int disc_states[][8], int turn, int row, int column){
    if(0<=column-2){
        if(disc_states[row][column-1] == -turn){
            for(int j=column-2; 0<=j; j--){
                if((disc_states[row][j]==0)||(disc_states[row][j]==2))
                    return 0;
                if(disc_states[row][j]==turn)
                    return 1;
            }
        }
    }
    return 0;
}
int validation6(int disc_states[][8], int turn, int row, int column){
    if((row+2<8)&&(0<=column-2)){
        if(disc_states[row+1][column-1] == -turn){
            for(int i=row+2,j=column-2; i<8&&0<=j; i++,j--){
                if((disc_states[i][j]==0)||(disc_states[i][j]==2))
                    return 0;
                if(disc_states[i][j]==turn)
                    return 1;
            }
        }
    }
    return 0;
}
int validation7(int disc_states[][8], int turn, int row, int column){
    if(row+2<8){
        if(disc_states[row+1][column] == -turn){
            for(int i=row+2; i<8; i++){
                if((disc_states[i][column]==0)||(disc_states[i][column]==2))
                    return 0;
                if(disc_states[i][column]==turn)
                    return 1;
            }
        }
    }
    return 0;
}
int validation8(int disc_states[][8], int turn, int row, int column){
    if((row+1<8)&&(column+1<8)){
        if(disc_states[row+1][column+1] == -turn){
            for(int i=row+2,j=column+2; i<8&&j<8; i++,j++){
                if((disc_states[i][j]==0)||(disc_states[i][j]==2))
                    return 0;
                if(disc_states[i][j]==turn)
                    return 1;
            }
        }
    }
    return 0;
}

void valid_check (int disc_states[][8], int turn){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if (disc_states[i][j]==0){
                int flag = 0;
                int flag1 = validation1(disc_states, turn, i, j);
                int flag2 = validation2(disc_states, turn, i, j);
                int flag3 = validation3(disc_states, turn, i, j);
                int flag4 = validation4(disc_states, turn, i, j);
                int flag5 = validation5(disc_states, turn, i, j);
                int flag6 = validation6(disc_states, turn, i, j);
                int flag7 = validation7(disc_states, turn, i, j);
                int flag8 = validation8(disc_states, turn, i, j);
                flag = flag1 + flag2 + flag3 + flag4 + flag5 + flag6 + flag7 + flag8;
                if (flag>0)
                    disc_states[i][j] = 2;
            }
        }
    }
}

void change1 (int disc_states[][8], int turn, int row, int column){
    int t=-1;
    if(disc_states[row][column+1] == -turn){
        for(int j=column+2; j<8; j++){
            if(disc_states[row][j]==0)
                break;
            if(disc_states[row][j]==turn){
                t = j-column;
                break;
            }
        }
    }
    for(int i=0; i<=t; i++)
        disc_states[row][column+i] = turn;
}

void change2 (int disc_states[][8], int turn, int row, int column){
    int t=-1;
    if(disc_states[row-1][column+1] == -turn){
        for(int i=row-2,j=column+2; 0<=i&&j<8; i--,j++){
            if(disc_states[i][j]==0)
                break;
            if(disc_states[i][j]==turn){
                t = j-column;
                break;
            }
        }
    }
    for(int i=0; i<=t; i++)
        disc_states[row-i][column+i] = turn;
}

void change3 (int disc_states[][8], int turn, int row, int column){
    int t=-1;
    if(disc_states[row-1][column] == -turn){
        for(int i=row-2; 0<=i; i--){
            if(disc_states[i][column]==0)
                break;
            if(disc_states[i][column]==turn){
                t = row-i;
                break;
            }
        }
    }
    for(int i=0; i<=t; i++)
        disc_states[row-i][column] = turn;
}

void change4 (int disc_states[][8], int turn, int row, int column){
    int t=-1;
    if(disc_states[row-1][column-1] == -turn){
        for(int i=row-2,j=column-2; 0<=i&&0<=j; i--,j--){
            if(disc_states[i][j]==0)
                break;
            if(disc_states[i][j]==turn){
                t = row-i;
                break;
            }
        }
    }
    for(int i=0; i<=t; i++)
        disc_states[row-i][column-i] = turn;
}

void change5 (int disc_states[][8], int turn, int row, int column){
    int t=-1;
    if(disc_states[row][column-1] == -turn){
        for(int j=column-2; 0<=j; j--){
            if(disc_states[row][j]==0)
                break;
            if(disc_states[row][j]==turn){
                t = column-j;
                break;
            }
        }
    }
    for(int i=0; i<=t; i++)
        disc_states[row][column-i] = turn;
}

void change6 (int disc_states[][8], int turn, int row, int column){
    int t=-1;
    if(disc_states[row+1][column-1] == -turn){
        for(int i=row+2,j=column-2; i<8&&0<=j; i++,j--){
            if(disc_states[i][j]==0)
                break;
            if(disc_states[i][j]==turn){
                t = i-row;
                break;
            }
        }
    }
    for(int i=0; i<=t; i++)
        disc_states[row+i][column-i] = turn;
}

void change7 (int disc_states[][8], int turn, int row, int column){
    int t=-1;
    if(disc_states[row+1][column] == -turn){
        for(int i=row+2; i<8; i++){
            if(disc_states[i][column]==0)
                break;
            if(disc_states[i][column]==turn){
                t = i-row;
                break;
            }
        }
    }
    for(int i=0; i<=t; i++)
        disc_states[row+i][column] = turn;
}

void change8 (int disc_states[][8], int turn, int row, int column){
    int t=-1;
    if(disc_states[row+1][column+1] == -turn){
        for(int i=row+2,j=column+2; i<8&&j<8; i++,j++){
            if(disc_states[i][j]==0)
                break;
            if(disc_states[i][j]==turn){
                t = j-column;
                break;
            }
        }
    }
    for(int i=0; i<=t; i++)
        disc_states[row+i][column+i] = turn;
}

void change_disks(int disc_states[][8], int turn, int row, int column){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(disc_states[i][j]==2)
                disc_states[i][j]=0;
        }
    }
    change1(disc_states, turn, row, column);
    change2(disc_states, turn, row, column);
    change3(disc_states, turn, row, column);
    change4(disc_states, turn, row, column);
    change5(disc_states, turn, row, column);
    change6(disc_states, turn, row, column);
    change7(disc_states, turn, row, column);
    change8(disc_states, turn, row, column);
}
int calculate_score(int disc_states[][8], int turn){
    int score = 0;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(disc_states[i][j]==turn)
                score++;
        }
    }
    return score;
}
