#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;

void fill(char arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr[i][j] = ' ';
        }
    }
}

void display(char arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j < 2)
            {
                cout << arr[i][j];
                cout << "|";
            }
            if (j == 2)
            {
                cout << arr[i][j];
                cout << endl;
            }
        }
        if (i < 2)
        {
            cout << "-----";
            cout << endl;
        }
    }
}

bool checker(char arr[3][3], string k)
{

    for (int i = 0; i < 3; i++)
    {
        {
            if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != ' ')
            {

                if (k == "Player 2 turn")
                {
                    cout << "Player 2 is winner" << endl;
                    return true;
                }
                else
                    cout << "Player 1 is winner" << endl;
                return true;
            }
            else if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[1][i] != ' ')
            {

                if (k == "Player 2 turn")
                {
                    cout << "Player 2 is winner" << endl;
                    return true;
                }
    
                else
                    cout << "Player 1 is winner" << endl;
                return true;
            }
            else if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[1][1] != ' ')
            {

                if (k == "Player 2 turn")
                {
                    cout << "Player 2 is winner" << endl;
                    return true;
                }
        
                else
                    cout << "Player 1 is winner" << endl;
                return true;
            }
            else if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[1][1] != ' ')
            {

                if (k == "Player 2 turn")
                {
                    cout << "Player 2 is winner" << endl;
                    return true;
                }
                else
                    cout << "Player 1 is winner" << endl;
                return true;
            }
        }
    }
    return false;
}


bool checkercomput(char arr[3][3], string k) {
    string winner;

    // Check rows for a winner
    for (int i = 0; i < 3; i++) {
        if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != ' ') {
            winner = (arr[i][0] == 'x') ? "Player" : "Computer";
            cout << winner << " is the winner!" << endl;
            return true;
        }
    }

    // Check columns for a winner
    for (int i = 0; i < 3; i++) {
        if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[0][i] != ' ') {
            winner = (arr[0][i] == 'x') ? "Player" : "Computer";
            cout << winner << " is the winner!" << endl;
            return true;
        }
    }

    // Check the main diagonal for a winner
    if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != ' ') {
        winner = (arr[0][0] == 'x') ? "Player" : "Computer";
        cout << winner << " is the winner!" << endl;
        return true;
    }

    // Check the secondary diagonal for a winner
    if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[0][2] != ' ') {
        winner = (arr[0][2] == 'x') ? "Player" : "Computer";
        cout << winner << " is the winner!" << endl;
        return true;
    }

    return false; // No winner yet
}




bool tie(char arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] == ' ')
            { // If any cell is empty
                return false;
            }
        }
    }
    return true; // All cells are filled, return true for a tie
}
void game()
{
	int l=1;
    char arr[3][3];
    char input = 'o';
    fill(arr);
    int mode;
    cout << "\t\t\t\t\tWelcome to game" << endl;
    do{
	cout << "\t\t\t\t  Which mode you want to play\n\n1) 2 player\n2) With Computer  "<<"\n3) to exit" << endl<< endl;	
	cin >> mode;
	char input = 'o';
    fill(arr);
    string p = "Player 2 turn";
    system("cls");
    switch (mode)
    {
    case 1:
        while (!checker(arr, p))
        {
            string k = "x";
            if (p == "Player 2 turn")
            {
                cout << "\t\t\t\t\tPlayer 1 turn" << endl;
            }
            else
            {
                cout << "\t\t\t\t\tPlayer 2 turn" << endl;
            }

            if (tie(arr))
            {
                cout << "Its a tie" << endl;
                break;
            }
            display(arr);
            int i, j;
            cout << "Enter number of row : ";
            cin >> i;
            cout << "Enter number of column : ";
            cin >> j;

            if (i >= 0 && i <= 2 && j >= 0 && j <= 2)
            {
                if (arr[i][j] == ' ')
                {
                    if (input == 'o')
                    {
                        arr[i][j] = 'x';
                        input = 'x';
                    }
                    else if (input == 'x')
                    {
                        arr[i][j] = 'o';
                        input = 'o';
                    }
                }
                else
                {
                    k = "This place is already filled";
                    cout << "This place is already filled" << endl;
                }
            }
            else
            {
                k = "Input should be between 0 and 2 ";
                cout << "Input should be between 0 and 2 " << endl;
            }
            if (k != "x")
            {
                Sleep(3000);
                system("cls");
            }
            else
            {
                if (p == "Player 2 turn")
                {
                    p = "Player 1 turn";
                }
                else
                {
                    p = "Player 2 turn";
                }
            }

            system("cls");
        }
        display(arr);
        break;

case 2: {
    string p = "Player turn"; // Tracks current turn
    srand(time(0));           // Initialize random seed

    while (!checkercomput(arr, p)) {
        // Check for a tie
        if (tie(arr)) {
            cout << "It's a tie!" << endl;
            break;
        }

        display(arr);

        if (p == "Player turn") {
            // Player's move
            int i, j;
            cout << "Enter row and column (0-2): ";
            cin >> i >> j;

            if (i >= 0 && i <= 2 && j >= 0 && j <= 2 && arr[i][j] == ' ') {
                arr[i][j] = 'x';
                p = "Computer turn"; // Switch to Computer turn
            } else {
                cout << "Invalid move! Try again." << endl;
                Sleep(1500);
            }
        } else {
            // Computer's move (Improved logic for better gameplay)
            bool moveMade = false;

            // Block or Win logic: If a winning move or block is possible, make it
            for (int i = 0; i < 3 && !moveMade; i++) {
                for (int j = 0; j < 3 && !moveMade; j++) {
                    if (arr[i][j] == ' ') {
                        // Temporarily make a move
                        arr[i][j] = 'o';

                        if (checkercomput(arr, "Computer turn")) {
                            moveMade = true; // Computer wins
                        } else {
                            // Undo move
                            arr[i][j] = ' ';
                        }
                    }
                }
            }

            // Random move if no winning or blocking move is found
            if (!moveMade) {
                int i, j;
                do {
                    i = rand() % 3; // Random row
                    j = rand() % 3; // Random column
                } while (arr[i][j] != ' '); // Ensure position is empty

                arr[i][j] = 'o';
                cout << "Computer choose: " << i << ", " << j << endl;
                Sleep(1500);
            }

            p = "Player turn"; // Switch to Player turn
        }

        system("cls");
    }

    display(arr);
    break;
}

case 3:
		l=3;
	}
}while(l!=3);
}
int main()
{
    system("color 03");
    game();
}