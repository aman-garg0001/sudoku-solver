#include<bits/stdc++.h>
using namespace std;

#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL)

bool btrack(map<pair<int, char>, int> &m, map<pair<int, char>, int> &mr, map<pair<int, char>, int> &mc, vector<vector<char>>& board)
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(board[i][j] == '.')
            {
                for(char k = '1'; k <= '9'; k++)
                {
                    int region = 3*(i/3) + (j/3);
                    if(mr[{i, k}] == 0 and mc[{j, k}] == 0 and m[{region, k}] == 0)
                    {
                        //cout << i << " " <<  j << " " << k << endl;
                        board[i][j] = k;
                        mr[{i, k}]++;
                        mc[{j, k}]++;
                        m[{region, k}]++;
                        if(btrack(m, mr, mc, board))
                            return 1;
                        else
                        {
                            mr[{i, k}] = 0;
                            mc[{j, k}]= 0;
                            m[{region, k}] = 0;  
                            board[i][j] = '.';
                        }
                    }
                }
                return 0;
            }
            
        }
    }
    return 1;
}

bool solveSudoku(vector<vector<char>>& board) {
    map<pair<int, char>, int> mr, mc, m;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            int k = 3*(i/3) + (j/3);
            if(board[i][j] == '.')
            {
                continue;
            }
            mr[{i, board[i][j]}]++;
            mc[{j, board[i][j]}]++;
            
            m[{k, board[i][j]}]++;
        }
    }
    if(btrack(m, mr, mc, board))
        return 1;
    else
    {
        cout << "Can't solve...Sudoku invalid!!!!";
        return 0;
    }
    
}


int main()
{
    fast();
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt","w",stdout);
    #endif
    vector<vector<char>> board;
    for(int i = 0; i < 9; i++)
    {
        std::vector<char> v;
        for(int j = 0; j < 9; j++)
        {
            char b;
            cin >> b;
            v.push_back(b);
        }
        board.push_back(v);
    }
    if(solveSudoku(board))
    {
        for(int i = 0; i < 9; i++)
        {
            cout << "| ";
            for(int j = 0; j < 9; j++)
            {
                cout << board[i][j] << " | ";
            }
            cout << endl;
            for(int k = 0; k < 9; k++)
            {
                cout << "----";
            }
            cout << endl;
        }
    }
    return 0;
}