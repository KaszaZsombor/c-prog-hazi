#include <stdio.h>
#include <stdlib.h>

enum{success = 0, fail = -1};

typedef struct { int kezdo_cs; int veg_cs; double ertek;} el;    
typedef struct { int elszam; int csucsszam; el elhalmaz[]; } graf;

/* Gráf megadása az alábbi módon <csúcsszám> <élszám> <él:csúcs1> <él:csúcs2> <él:érték> ... */
graf* load_graph_from_stdin()
{
    int n;
    if(scanf("%d", &n) != 1)return NULL;
    int e;
    if(scanf("%d", &e) != 1)return NULL;
    if( n < 0 || e < 0)return NULL;
    
    graf* g = (graf *)malloc(sizeof(graf) + e*sizeof(el));
    if(g == NULL)return NULL;

    g->elszam = e;
    g->csucsszam = n;

    for(int i = 0; i < e; i++)
    {
        int a,b;
        double c;
        if(scanf("%d%d%lf", &a, &b, &c) != 3 || a > n || b > n || a < 1 || b < 1 || c < 0)
        {
            free(g);
            return NULL;
        }
        else
        {
            g->elhalmaz[i].kezdo_cs = a - 1;
            g->elhalmaz[i].veg_cs = b - 1;
            g->elhalmaz[i].ertek = c;
        }
    }
    return g;
}

void printf_grafinfo(graf* input)
{
    printf("Csucsok: ");
    for(int i = 0; i < input->csucsszam; i++)
    {
        printf("%d ", i + 1);
    }
    printf("\nElek:\n");
    for(int i = 0; i < input->elszam; i++)
    {
        printf("%d. Start: %d, End: %d, Ertek %f\n", i + 1, input->elhalmaz[i].kezdo_cs + 1, input->elhalmaz[i].veg_cs + 1, input->elhalmaz[i].ertek);
    }
}


int main(void)
{

    graf* pg1 = load_graph_from_stdin();
    if(pg1 == NULL) return fail;

    printf_grafinfo(pg1);
    
    free(pg1);
    return success;
}