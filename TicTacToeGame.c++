#include <iostream>
#include <cctype>
using namespace std;
int currentPlayer;
char currentMarker;
char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
void drawBoard()
{
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    
}   

bool placemarker(int slot)
{
    int row = (slot-1)/3;
    int col = (slot-1)%3;

    if (board[row][col] != 'X' && board[row][col] != 'O')
    {
        board[row][col] = currentMarker;
        return true;
    }
    else{ 
        return false;
    }
}

int winner()
{
    //rows
    for (int i=0; i<3; i++)
    {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return currentPlayer;
    }
    //columns
    for (int i=0; i<3; i++)
    {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return currentPlayer;
        }
    }
    //diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return currentPlayer;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return currentPlayer;
    }
    return 0;
}
void swapPlayerAndMarker()
{
    if(currentMarker == 'X')
    {
        currentMarker = 'O';
    }
    else
    {
        currentMarker = 'X';
    }

    if(currentPlayer == 1)
    {
        currentPlayer = 2;
    }
    else
    {
        currentPlayer = 1;
    }
}

void game()
{
    cout << "Player1 choose your marker (X or O): " ;
    char markerP1;
    cin >> markerP1;

    currentPlayer = 1;
    currentMarker = toupper(markerP1);

    if(currentMarker != 'X' && currentMarker != 'O')
{
    cout << "Invalid marker!";
    return;
}

    char markerP2 = (currentMarker == 'X') ? 'O' : 'X';
    cout << "Player 2 will be " << markerP2 << endl;

    drawBoard();
    int playerwon = 0;
    for(int i=0 ; i<9; i++)
    {
        cout << "it's player " << currentPlayer << "'s turn. Enter your slot: ";
        int slot;
        cin >> slot;

        if(slot < 1 || slot > 9){
            cout << "it is not a valid slot, you may try again.";
            i--;
            continue;
        }
        if(!placemarker(slot)){
            cout << "slot is occupied, try again \n.";
            i--;
            continue;
        }
        drawBoard();
        playerwon = winner();

        if(playerwon == 1)
        {
            cout << "player 1 wins!";
            break;
        }
        if(playerwon == 2)
        {
            cout << "player 2 wins!";
            break;
        }
        swapPlayerAndMarker();
    }
    // for(int i=0; i<9; i++)
    // {
    //     if(playerwon == 1 || playerwon == 2)
    //         break;

    //     swapPlayerAndMarker();
    // }

    if(playerwon == 0)
        cout << "It's a tie game!";

    }


int main()
{
    game();
    return 0;
}