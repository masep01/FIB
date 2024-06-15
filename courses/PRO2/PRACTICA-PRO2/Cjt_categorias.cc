/** @file Cjt_categorias.cc
  @brief Código de la clase Cjt_categorias
*/
#include "Cjt_categorias.hh"

Cjt_categorias::Cjt_categorias(){}
Cjt_categorias:: ~Cjt_categorias(){}

int Cjt_categorias::categoria_maxima() const
{
  return max_cat;
}

int Cjt_categorias::consultar_puntos(int cat,  int nivel) const
{
  return m_pts[cat-1][nivel];
}

string Cjt_categorias::consultar_nombre(int c) const
{
  return vcat[c-1];
}

void Cjt_categorias::listar_categorias() const
{
  // Se imprime C " " K
  cout << max_cat << " " << niveles << endl;

  for (int i = 0; i < max_cat; ++i)
  {
    // Se imprime el nombre de la categoria
    cout << vcat[i];

    // Se imprimen los puntos de cada nivel de la categoria
    for (int j = 0; j < niveles; ++j) cout << " " << m_pts[i][j];
    cout << endl;
  }
}

void Cjt_categorias::leer_cjt_categorias()
{
  cin >> max_cat >> niveles;
  vcat = vector<string>(max_cat);
  m_pts = Matriz(max_cat, vector<int>(niveles));

  // Leemos nombres
  for (int i = 0; i < max_cat; ++i) cin >> vcat[i];

  // Leemos tabla de puntos
  for (int j = 0; j < max_cat; j++)
  {
    for (int l = 0; l < niveles; l++) cin >> m_pts[j][l];
  }
}
