int freq(const T& x) const
/* Pre: cert */
/* Post: el resultat indica el nombre d'aparicions de x en el p.i. */
{
    int f = 0; 
    search(primer_node, x, f);
    return f;
}

void search(node_arbreGen* n, const T& x, int &f) const
{
    if(n != NULL)
    {
        if(n->info == x) ++f;
        for(int i = 0; i < n->seg.size(); ++i) search(n->seg[i], x, f);
    }
}