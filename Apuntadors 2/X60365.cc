bool buscar(const T& x) const
/* Pre: cert */
/* Post: el resultat indica si x es troba al p.i. o no */
{
    bool b = false;
    search(primer_node, x, b);
    return b;
}

void search(node_arbreGen* n, const T& x, bool &b) const
{
    if(b == false and n != NULL)
    {
        if(n->info == x) b = true;
        else 
        {
            for(int i = 0; i < n->seg.size(); ++i) search(n->seg[i], x, b);
        }
    }
}
