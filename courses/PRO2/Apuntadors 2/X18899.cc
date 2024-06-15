void arbsuma(ArbreNari& asum) const
/* Pre: cert */
/* Post: asum és un arbre amb la mateixa estructura que el p.i.
         i cada node és la suma del node corresponent al p.i
         i tots els seus descendents al p.i. */
{
  asum.primer_node = sum(primer_node);
}

node_arbreNari* sum(node_arbreNari* node) const
{
  if (node != NULL)
  {
    node_arbreNari* root = new node_arbreNari;
    root->seg = vector<node_arbreNari*>(N);
    root->info = node->info;

    for(int i = 0; i < N; ++i)
    {
      if(node->seg[i] != NULL) root->seg[i] = sum(node->seg[i]);
      if(root->seg[i] != NULL) root->info += root->seg[i]->info;
    }
    return root;
  }
  else return node;
}
