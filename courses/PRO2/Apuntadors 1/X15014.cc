void arb_sumes(Arbre<int> &asum) const
/* Pre: cert */
/* Post: l'arbre asum és l'arbre suma del p.i. */
{
  asum.primer_node = sum(primer_node);
}

node_arbre* sum(node_arbre* node) const
{
  if (node != NULL)
  {
    node_arbre* root = new node_arbre;
    root->segE = sum(node->segE);
    root->segD = sum(node->segD);
    root->info = node->info;
    if(root->segE != NULL) root->info += root->segE->info;
    if(root->segD != NULL) root->info += root->segD->info;
    return root;
  }
  else return node;

}
