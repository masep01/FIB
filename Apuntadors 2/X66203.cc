T maxim() const
/* Pre: el p.i. no és buit */
/* Post: el resultat indica el valor més gran que conté el p.i. */
{
  T max = primer_node->info;
  maxi(primer_node, N, max);
  return max;
}

static void maxi(node_arbreNari* n, int mida, T &max)
{
  if(n != NULL)
  {
    T aux = n->info;
    for(int i = 0; i < mida; ++i)
    {
      maxi(n->seg[i], mida, aux);

      if(aux > max) max = aux;
    }
  }
}
