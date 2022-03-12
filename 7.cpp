#include <bits/stdc++.h>

using namespace std;

class Game {
  public:
    Game() 
    {
      this->players = 0;
      Si = vector<int>();
      Ui = map<vector<int>, vector<int>> ();
    }
    int players;
    vector<int> Si;
    map<vector<int>, vector<int>> Ui; 

    void recursive_strategy(int player, vector<int> &strats)
    {
      if(player == -1)
      {
        vector<int> here(this->players, 0);
        for(int a = 0; a < this->players; a++)
          cin >> here[a];
        vector<int> new_strats;
        for(int a = this->players - 1; a >= 0; a--)
          new_strats.push_back(strats[a]);
        Ui[new_strats] = here;
        return;
      }
      for(int a = 0; a < this->Si[player]; a++)
      {
        strats.push_back(a);
        recursive_strategy(player - 1, strats);
        strats.pop_back();
      }
    }

    void input()
    {
      cin >> this->players;
      this->Si = vector<int>(this->players, 0);
      for(int a = 0; a < this->players; a++)
        cin >> this->Si[a];
      vector<int> tmp;
      this->recursive_strategy(this->players - 1, tmp);
    }

    void checkInput()
    {
      for(auto it = this->Ui.begin(); it != this->Ui.end(); it++)
      {
        cout << "Strategies: ";
        for(auto f: it->first)
          cout << f << " ";
        cout << "\nUtilities: ";
        for(auto f: it->second)
          cout << f << " ";
        cout << "\n";
      }
    }
};

int main()
{
  Game game;
  game.input();
  game.checkInput();
  return 0;
}
