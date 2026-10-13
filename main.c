#include <stdio.h>
#include <stdlib.h>
enum{success = 0, fail = -1};

typedef struct { int kezdo_cs; int veg_cs; } el;    
typedef struct { int elszam; int csucsszam; el elhalmaz[]; } graf;


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
        if(scanf("%d%d", &a, &b) != 2 || a > n || b > n || a < 1 || b < 1)
        {
            free(g);
            return NULL;
        }
        else
        {
            g->elhalmaz[i].kezdo_cs = a - 1;
            g->elhalmaz[i].veg_cs = b - 1;
        }
    }
    return g;
}



int main(void)
{
    graf* g1 = load_graph_from_stdin();

    if(g1 == NULL) return fail;

    for(int i = 0;i < g1->elszam; i++)
    {
        printf("%d %d\n", g1->elhalmaz[i].kezdo_cs + 1, g1->elhalmaz[i].veg_cs + 1);
    }

    free(g1);
    return success;
}