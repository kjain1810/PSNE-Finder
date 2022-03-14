#include <bits/stdc++.h>

using namespace std;

class Game {
  public:
    Game() 
    {
      this->players = 0;
      this->Si = vector<int>();
      this->U = map<vector<int>, vector<int>> ();
      this->Ui = vector<vector<map<vector<int>, int>>> ();
      this->dominantStrategies = vector<vector<int>> ();
    }
    
    int players;
    vector<int> Si;
    map<vector<int>, vector<int>> U; 
    vector<vector<map<vector<int>, int>>> Ui;
    vector<vector<int>> dominantStrategies;
    
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
        U[new_strats] = here;
        return;
      }
      for(int a = 0; a < this->Si[player]; a++)
      {
        strats.push_back(a);
        recursive_strategy(player - 1, strats);
        strats.pop_back();
      }
    }

    void _buildUi(int c, int &tp, int &ts, vector<int> &strats)
    {
      if(c == tp)
      {
        strats.push_back(ts);
        this->_buildUi(c + 1, tp, ts, strats);
        strats.pop_back();
      }
      else if(c == this->players)
        this->Ui[tp][ts].insert({strats, this->U[strats][tp]});
      else
      {
        for(int a = 0; a < this->Si[c]; a++)
        {
          strats.push_back(a);
          this->_buildUi(c + 1, tp, ts, strats);
          strats.pop_back();
        }
      }
    }

    void buildUi()
    {
      for(int a = 0; a < this->players; a++)
      {
        vector<map<vector<int>, int>> vec;
        for(int b = 0; b < this->Si[a]; b++)
        {
          map<vector<int>, int> mep;
          vec.push_back(mep);
        }
        this->Ui.push_back(vec);
      }
      for(int a = 0; a < this->players; a++)
        for(int b = 0; b < this->Si[a]; b++)
        {
          vector<int> vec;
          this->_buildUi(0, a, b, vec);
        }
    }
    
    void checkUi()
    {
      for(int a = 0; a < this->players; a++)
        for(int b = 0; b < this->Si[a]; b++)
        {
          cout << "Player " << a << " Strategy " << b << " size is " << this->Ui[a][b].size() << endl;
          for(auto u: this->Ui[a][b])
          {
            cout << "Strategy set: ";
            for(auto s: u.first)
              cout << s << " ";
            cout << endl;
            cout << "Utility: " << u.second << endl;
          }
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
      for(auto it = this->U.begin(); it != this->U.end(); it++)
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

    bool checkDominance(int p, int s)
    {
      return false;
    }
};

int main()
{
  Game game;
  game.input();
  game.checkInput();
  game.buildUi();
  game.checkUi();
  return 0;
}
