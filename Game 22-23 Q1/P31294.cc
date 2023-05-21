#include "Player.hh"
#include <queue>

/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME BenjiTron


struct PLAYER_NAME : public Player {

  /**
   * Factory: returns a new instance of this class.
   * Do not modify this function.
   */
  static Player* factory () {
    return new PLAYER_NAME;
  }

  /**
   * Types and attributes for your player can be defined here.
  */
  typedef vector<bool> vBool;
  typedef vector<vBool> mBool;

  typedef vector<Pos> vPos;
  typedef vector<vPos> mPos;

  const Pos NULL_POS = Pos(-1,-1);
  const vector<Dir> Dirs = {Left, Right, Up, Down};
  const vector<Dir> Diags = {RU, UL, DR, LD};
  
  void log(string s)
  {
    cerr << s << endl;
  }

  bool check_target(Pos p)
  {
    int idUnit = cell(p).id;
    
    if(cell(p).food) return true;                                   // Busco menjar
    if(idUnit != -1 and unit(idUnit).type == Zombie) return true;   // Ataco zombie

    // if(idUnit != -1 
    //     and unit(idUnit).type == Alive
    //     and unit(idUnit).player != me()) return true;                             // Si em trobo un enemic l'ataco
    return false;   
  }
  
  bool dead_body(Pos p)
  {
    if(not pos_ok(p)) return false;
    int id = cell(p).id;
    return id != -1 and unit(id).type == Dead;
  }

  bool teammate(Pos p)
  {
    if(not pos_ok(p)) return false;
    int id = cell(p).id;
    if((id != -1) and (unit(id).type == Alive) and (unit(id).player == me())) 
    {
      return true;
    }
    return false;
  }

  bool check_zombi(int id)
  {
    return (id != -1) and (unit(id).type == Zombie);
  }

  bool check_zombies_diag(Pos p)
  {
    bool f = false;
    for(auto d : Diags) 
    {
      if(pos_ok(p+d)) f = check_zombi(cell(p+d).id);
    }
    return f;
  }

  bool check_enemy(int id)
  {
    return ((id != -1) and (unit(id).type == Alive) and (unit(id).player != me()));
  }

  Pos BFS(Pos p, mPos &prev)
  {
    if(not pos_ok(p) or cell(p).type == Waste) return NULL_POS;

    int steps = 0;
    int nodes_left = 1;
    int nodes_next = 0;
    queue<Pos> Q;
    bool found = false;

    mBool vis(board_rows(),vBool(board_cols()));
    
    Q.push(p);
    vis[p.i][p.j] = true;
    if(pos_ok(p) and check_target(p)) found = true;
    
    while((Q.size() > 0) and (not found))
    {
      p = Q.front(); Q.pop();
      if(check_target(p)) found = true;
      else 
      {
        Pos pp;
        for(int i = 0; i < 4; ++i)
        {
          pp = p + Dirs[i];
          if(pos_ok(pp) and (not vis[pp.i][pp.j]) and (cell(pp).type != Waste))
          {
            Q.push(pp);
            prev[pp.i][pp.j] = p;
            vis[pp.i][pp.j] = true;
            ++nodes_next;
          }
        }
        --nodes_left;
        if(nodes_left==0)
        {
          nodes_left = nodes_next;
          nodes_next = 0;
          ++steps;
        }
      }
    }
    if(found) return p;
    return NULL_POS;
  }
  
  void move_anywhere(int id)
  {
    Pos p = unit(id).pos;
    for (auto d : Dirs)
    {
      if(pos_ok(p+d) and not dead_body(p+d) and not (cell(p+d).type == Waste)) 
      {
        move(id,d);
        return;
      }
    }
  }

  void first_step(const mPos &prev, int id, Pos food)
  {
    if(food == NULL_POS) return;

    // Calculem cap a quina posició ens hem de moure
    Pos me = unit(id).pos;
    Pos res;
    while(food != me)
    {
      res = food;
      food = prev[food.i][food.j];
    }

    // Trobem la direcció a prendre
    bool t = false;
    int m = 0;
    while(not t and m < 4)
    {
      Pos pN = me + Dirs[m];
      if(res == pN and not dead_body(pN)) t = true;
      else ++m;
    }

    // Si l'ha trobat (perque no es nul·la) ens movem cap alla. En cas contrari, cap a on sigui
    if(t) move(id,Dirs[m]);
    else move_anywhere(id);
  }
  
  bool try_move(int id_unit, Dir d)
  {
    Pos p = unit(id_unit).pos;
    bool done = false;
    if(pos_ok(p+d) 
         and not dead_body(p+d) 
         and not (cell(p+d).type == Waste)
         and not check_zombi(cell(p+d).id)
         and not check_zombies_diag(p+d)) {move(id_unit,d); done = true;}
    return done;
  }

  bool avoid_zombies(int id)
  {
    Pos p = unit(id).pos;

    int id_R = -1;            // Mirem diagonal Down-Right
    int id_U = -1;            // Mirem diagonal Right-Up
    int id_L = -1;            // Mirem diagonal Up-Left
    int id_D = -1;            // Mirem diagonal Left-Down

    if(pos_ok(p+Right)) id_R = cell(p+Right).id;
    if(pos_ok(p+Up)) id_U = cell(p+Up).id;
    if(pos_ok(p+Left)) id_L = cell(p+Left).id;
    if(pos_ok(p+Down)) id_D = cell(p+Down).id;

    // Si esta abaix-dreta, ens movem a dalt o esquerra
    if(check_zombi(id_R)) {move(id,Right); return true;}
    // Si esta adalt-dreta, ens movem a baix o esquerra
    else if(check_zombi(id_U)) {move(id,Up); return true;}
    // Si esta adalt-esquerra, ens movem a baix o dreta
    else if(check_zombi(id_L)) {move(id,Left); return true;}
    // Si esta abaix-esquerra, ens movem a baix o dreta
    else if(check_zombi(id_D)) {move(id,Down); return true;}

    int id_DR = -1;            // Mirem diagonal Down-Right
    int id_RU = -1;            // Mirem diagonal Right-Up
    int id_UL = -1;            // Mirem diagonal Up-Left
    int id_LD = -1;            // Mirem diagonal Left-Down

    if(pos_ok(p+DR)) id_DR = cell(p+DR).id;
    if(pos_ok(p+RU)) id_RU = cell(p+RU).id;
    if(pos_ok(p+UL)) id_UL = cell(p+UL).id;
    if(pos_ok(p+LD)) id_LD = cell(p+LD).id;

    // Si esta abaix-dreta, ens movem a dalt o esquerra
    if(check_zombi(id_DR))
    {
      if(try_move(id,Up)) return true;
      else if(try_move(id,Left)) return true;
    }
    // Si esta adalt-dreta, ens movem a baix o esquerra
    else if(check_zombi(id_RU))
    {
      if(try_move(id,Down)) return true;
      else if(try_move(id,Left)) return true;
    }
    // Si esta adalt-esquerra, ens movem a baix o dreta
    else if(check_zombi(id_UL))
    {
      if(try_move(id,Down)) return true;
      else if(try_move(id,Right)) return true;
    }
    // Si esta abaix-esquerra, ens movem a baix o dreta
    else if(check_zombi(id_LD))
    {
      if(try_move(id,Up)) return true;
      else if(try_move(id,Right)) return true;
    }

    int id_UU = -1;            
    int id_DD = -1;           
    int id_LL = -1;            
    int id_RR = -1;            
    
    if(pos_ok(p+Up+Up)) id_UU = cell(p+Up+Up).id;
    if(pos_ok(p+Down+Down)) id_DD = cell(p+Down+Down).id;
    if(pos_ok(p+Left+Left)) id_LL = cell(p+Left+Left).id;
    if(pos_ok(p+Right+Right)) id_RR = cell(p+Right+Right).id;

    if(check_zombi(id_UU))
    {
      if(try_move(id,Right)) return true;
      else if(try_move(id,Left)) return true;
      else if(try_move(id,Down)) return true;
    }
    else if(check_zombi(id_DD))
    {
      if(try_move(id,Right)) return true;
      else if(try_move(id,Left)) return true;
      else if(try_move(id,Up)) return true;
    }
    else if(check_zombi(id_LL))
    {
      if(try_move(id,Up)) return true;
      else if(try_move(id,Down)) return true;
      else if(try_move(id,Right)) return true;
    }
    else if(check_zombi(id_RR))
    {
      if(try_move(id,Up)) return true;
      else if(try_move(id,Down)) return true;
      else if(try_move(id,Left)) return true;
    }

    int id_L_UL = -1;            
    int id_L_LD = -1;           
    int id_U_UL = -1;     
    int id_U_RU = -1;        
    int id_R_RU = -1; 
    int id_R_DR = -1; 
    int id_D_DR = -1; 
    int id_D_LD = -1; 

    if(pos_ok(p+Left+UL)) id_L_UL = cell(p+Left+UL).id;
    if(pos_ok(p+Left+LD)) id_L_LD = cell(p+Left+LD).id;

    if(pos_ok(p+Up+RU)) id_U_RU = cell(p+Up+RU).id;
    if(pos_ok(p+Up+UL)) id_U_UL = cell(p+Up+UL).id;

    if(pos_ok(p+Right+RU)) id_R_RU = cell(p+Right+RU).id;
    if(pos_ok(p+Right+DR)) id_R_DR = cell(p+Right+DR).id;

    if(pos_ok(p+Down+DR)) id_D_DR = cell(p+Down+DR).id;
    if(pos_ok(p+Down+LD)) id_D_LD = cell(p+Down+LD).id;

    if(check_zombi(id_L_UL) or check_zombi(id_L_LD))
    {
      if(try_move(id,Up)) return true;
      else if(try_move(id,Down)) return true;
      else if(try_move(id,Right)) return true;
    }
    else if(check_zombi(id_R_RU) or check_zombi(id_R_DR))
    {
      if(try_move(id,Up)) return true;
      else if(try_move(id,Down)) return true;
      else if(try_move(id,Left)) return true;
    }
    else if(check_zombi(id_U_RU) or check_zombi(id_U_UL))
    {
      if(try_move(id,Down)) return true;
      else if(try_move(id,Right)) return true;
      else if(try_move(id,Left)) return true;
    }
    else if(check_zombi(id_D_DR) or check_zombi(id_D_LD))
    {
      if(try_move(id,Up)) return true;
      else if(try_move(id,Right)) return true;
      else if(try_move(id,Left)) return true;
    }
    
    return false;
  }
  
  bool kill_enemy(int id)
  {
    Pos p = unit(id).pos;
    int id_R = -1;            // Mirem diagonal Down-Right
    int id_U = -1;            // Mirem diagonal Right-Up
    int id_L = -1;            // Mirem diagonal Up-Left
    int id_D = -1;            // Mirem diagonal Left-Down

    if(pos_ok(p+Right)) id_R = cell(p+Right).id;
    if(pos_ok(p+Up)) id_U = cell(p+Up).id;
    if(pos_ok(p+Left)) id_L = cell(p+Left).id;
    if(pos_ok(p+Down)) id_D = cell(p+Down).id;

    // Si esta abaix-dreta, ens movem a dalt o esquerra
    if(check_enemy(id_R)) {move(id,Right); return true;}
    // Si esta adalt-dreta, ens movem a baix o esquerra
    else if(check_enemy(id_U)) {move(id,Up); return true;}
    // Si esta adalt-esquerra, ens movem a baix o dreta
    else if(check_enemy(id_L)) {move(id,Left); return true;}
    // Si esta abaix-esquerra, ens movem a baix o dreta
    else if(check_enemy(id_D)) {move(id,Down); return true;}
    return false;
  }

  pair<bool,Dir> dis2(int id)
  {
    Pos p = unit(id).pos;
    int id_UU = -1;            
    int id_DD = -1;           
    int id_LL = -1;            
    int id_RR = -1;            
    
    if(pos_ok(p+Up+Up)) id_UU = cell(p+Up+Up).id;
    if(pos_ok(p+Down+Down)) id_DD = cell(p+Down+Down).id;
    if(pos_ok(p+Left+Left)) id_LL = cell(p+Left+Left).id;
    if(pos_ok(p+Right+Right)) id_RR = cell(p+Right+Right).id;

    // Si esta abaix-dreta, ens movem a dalt o esquerra
    if(check_enemy(id_UU)) { return {true, Up};}
    // Si esta adalt-dreta, ens movem a baix o esquerra
    else if(check_enemy(id_DD)) { return {true, Down};}
    // Si esta adalt-esquerra, ens movem a baix o dreta
    else if(check_enemy(id_LL)) { return {true, Left};}
    // Si esta abaix-esquerra, ens movem a baix o dreta
    else if(check_enemy(id_RR)) { return {true, Right};}

    return {false,Up};
  }

  bool perim_dead(int id)
  {
    Pos p = unit(id).pos;
    return dead_body(p+Up) or dead_body(p+Down) or dead_body(p+Left) or dead_body(p+Right);
  }
  /**
   * Play method, invoked once per each round.
   */
  virtual void play()
  {
    if (status(me()) >= 0.9) return;

    vector<int> alive = alive_units(me());
    int n = alive.size();
    vector<bool> moved(n, false);
    vector<pair<bool,Dir>> d2(n, {false, Up});
    for(int i = 0; i < n; ++i)
    {
      int id = alive[i];
      pair<bool,Dir> papo = dis2(id);
      if(papo.first) 
      {
        d2[i] = papo;
      }
      else if(kill_enemy(id)) moved[i] = true;
    }
    
    for(int i = 0; i < n; ++i)
    {
      int id = alive[i];
      
      if(not moved[i] and not avoid_zombies(id) and not d2[i].first and not perim_dead(id))
      {
        Pos p = unit(id).pos;
        mPos prev(board_rows(), vPos(board_cols(), NULL_POS));
        Pos target = BFS(p, prev);
        first_step(prev,id,target);
        moved[i] = true;
      }
    }

    for(int i = 0; i < n; ++i)
    {
      if(d2[i].first) 
      {
        move(alive[i],d2[i].second);
        moved[i] = true;
      }
    }
    return;
  }
};

/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);