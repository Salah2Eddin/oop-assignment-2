#include <bits/stdc++.h>
using namespace std;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};


class Universe{
private:
    vector<vector<char>>grid;
public:
    Universe();
    void initialize(int row, int col);
    void reset();
    int count_neighbors(int row, int col);
    void next_generation();
    void display();
    void run(int turns);

};

Universe :: Universe(){

    cout << "Welcome to Game of Life !" << endl;

    int row, col;

    cout << "Please Enter number of Rows : ";
    cin >> row;

    cout << "Please Enter number of Columns : ";
    cin >> col;

    initialize(row,col);
}

void Universe :: initialize(int row, int col){
    grid.resize(row);
    for(int i = 0; i < row; ++i){
        grid[i].resize(col);
    }
    srand(time(0));
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            (rand() % 2 ? grid[i][j] = char(254u) : grid[i][j] = ' ');
        }
    }
}


void Universe :: reset(){
    for(auto & i : grid){
        for(char& j : i){
            j = 0;
        }
    }
}


int Universe :: count_neighbors(int row, int col){
    int cnt = 0;
    for(int i = 0; i < 8; ++i){
        if(row + dx[i] >= 0 && col + dy[i] >= 0 && row + dx[i] < grid.size() && col + dy[i] < grid[0].size()){
            if(grid[row+dx[i]][col+dy[i]] == char(254u)){
                cnt++;
            }
        }
    }
//
//     int res = grid[row][col];
//     for(int i = row-1; i <= row + 1; ++i){
//        for(int j = col - 1; j <= col + 1; ++j){
//            res += grid[i][j];
//        }
//     }
//     return res;

    return cnt;
}

void Universe :: next_generation(){
    vector<vector<char>>tempGrid = grid;
    int sz1 = grid.size();
    int sz2 = grid[0].size();

    for(int i = 0; i < sz1; ++i){
        for(int j = 0; j < sz2; ++j){
            int cntAlive = count_neighbors(i,j);
            if(cntAlive < 2 || cntAlive > 3){
                tempGrid[i][j] = false;
            }
            else{
                (cntAlive == 3 ? tempGrid[i][j] = char(254u) : tempGrid[i][j] = grid[i][j]);
            }
        }
    }

    for(int i = 0; i < sz1; ++i){
        for(int j = 0; j < sz2; ++j){
            grid[i][j] = tempGrid[i][j];
        }
    }
}

void Universe :: display(){
    for(auto & i : grid){
        for(char& j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}

void Universe :: run(int turns){
    for(int k = 0; k < turns; ++k) {
        system("cls");
        cout<<"Generation of " << k+1<<" \n";
        display();
        next_generation();
        std::chrono::seconds duration(1);
        std::this_thread::sleep_for(duration);
    }

}


int main() {
    Universe game;
    game.run(500);
    return 0;
}
