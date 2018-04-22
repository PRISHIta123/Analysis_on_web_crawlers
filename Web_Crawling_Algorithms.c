#include <stdio.h>
#include <string.h>
#include <process.h>
#include <malloc.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#include "ccache.h"
#define MAX_LIMIT 50

struct WebSite
{
    char link[200];
    char title[200];
    char text[200];
    int no;
    float prev_rank;
    float rank;
    struct WebSite *next[5];
};
typedef struct WebSite website;
website *A=0,*B=0,*C=0,*D=0,*E=0,*F=0,*G=0,*H=0,*I=0,*J=0,*K=0,*L=0,*M=0,*N=0,*O=0,*P=0,*Q=0,*D1=0,*D2=0,*E1=0,*E2=0,*F1=0,*G1=0,*G2=0,*I1=0,*K1=0,*K2=0,*L1=0,*L2=0,*M1=0,*N1=0,*N2=0,*O1=0,*P1=0,*D21=0,*D22=0,*E21=0;
struct Node
{
    website *w;
    struct Node *link;
};
typedef struct Node node;
node *Front,*Rear,*newptr,*prev,*temp=0,*next_node;

website *STACK[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, *IR_VISITED[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int TOP=-1, COUNT;
website *stack[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, *DFS_visited[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int top=-1;
website *queue[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, *BFS_visited[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int front=-1, rear=-1;
website *par[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, *STACK1[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, *FP_VISITED[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, *lookfor, *root_fp;
int TOP1=-1;
website *STACK2[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, *PR_VISITED[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int TOP2=-1;
website *STACK3[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, *UP_VISITED[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int TOP3=-1;
website *STACK4[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, *AP_VISITED[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, *sorted_rank[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int TOP4=-1, strk=-1;

void initialise_next(website *W);
void initialise_no(website *W);
void Assign();
int search(char query[50],char line[200]);
int search_node(char query[50],website *W);
website * root_assign(char query[50],website *X);
int Check(char query[20],website *x);
void Output(website *W);
void DFS (website *W, char query[50]);
void BFS (website *W, char query[50]);
void find_parents(website *W);
void ranking(website *W);
void update_prev(website *W);
void iteration_pagerank(website *W);
void array_pr(website *W);
void page_rank(website *W, char query[50]);
void Pop(int top,website *stack[]);
int relevancy(char query[50],website *w);
int goal_rel(char query[50]);
void A_Star(website *seed,int n,char query[50]);
void Adaptive_A_Star(website *seed,int n,int size,char query[50]);
int check(website *x);
void QInsert(website *W);
void Cache_Control(website *W);

int main()
{
	Assign();
	char query[50];
	int ch;
	do
	{
fflush(stdin);
printf("Enter the search query: ");
fgets(query,MAX_LIMIT,stdin);
printf("The entered search query is: %s\n\n",query);
website *ROOT[4]={0,0,0,0};
website *root=0;
ROOT[0]=(website*)malloc(sizeof(website));
ROOT[1]=(website*)malloc(sizeof(website));
ROOT[2]=(website*)malloc(sizeof(website));
ROOT[3]=(website*)malloc(sizeof(website));
initialise_next(ROOT[0]);
initialise_next(ROOT[1]);
initialise_next(ROOT[2]);
initialise_next(ROOT[3]);

website *check[4];
check[0]=A;
check[1]=B;
check[2]=C;
check[3]=Q;
int i,flag=0;
for(i=0;i<4;i++)
ROOT[i]=root_assign(query,check[i]);

for (i=0;i<4;i++)
{
if (ROOT[i]!=0)
flag=1;
}
if (flag==0)
{
printf("\nNO RESULTS FOUND\n");
continue;
}
printf("\n***DETAILS OF THE ROOTS***\n\n");
int max=0,chk;
for(i=0;i<4;i++)
{
if(ROOT[i]!=0)
{
Output(ROOT[i]);
printf("\n");
}
}
printf("\n\n------------------------\n");
printf("\n***DEPTH FIRST SEARCH***\n");
printf("\n------------------------\n\n");
clock_t begin=clock();
for (i=0;i<4;i++)
{
if (ROOT[i]!=0)
{
int g;
for (g=0;g<15;g++)
{
stack[g]=0;
DFS_visited[g]=0;
}
top=-1;
DFS(ROOT[i], query);
}
}
clock_t end = clock();
double time_spent = (double)(end - begin);
printf("\nTime Taken:%lf",time_spent) ;
MEMORYSTATUSEX memInfo;
memInfo.dwLength= sizeof(MEMORYSTATUSEX);
GlobalMemoryStatusEx(&memInfo);
DWORDLONG totalVirtualMem=memInfo.ullTotalPageFile;
DWORDLONG virtualMemUsed=memInfo.ullTotalPageFile - memInfo.ullAvailPageFile;
printf("\nMemory Usage:%ld Bytes",virtualMemUsed);

printf("\n\n--------------------------\n");
printf("\n***BREADTH FIRST SEARCH***\n");
printf("\n--------------------------\n\n");
begin=clock();
for (i=0;i<4;i++)
{
if (ROOT[i]!=0)
{
int g;
for (g=0;g<15;g++)
{
queue[g]=0;
BFS_visited[g]=0;
}
front=-1;
rear=-1;
BFS(ROOT[i], query);
}
}
end = clock();
time_spent = (double)(end - begin);
printf("\nTime Taken:%lf",time_spent) ;
memInfo.dwLength= sizeof(MEMORYSTATUSEX);
GlobalMemoryStatusEx(&memInfo);
totalVirtualMem=memInfo.ullTotalPageFile;
virtualMemUsed=memInfo.ullTotalPageFile - memInfo.ullAvailPageFile;
printf("\nMemory Usage:%ld Bytes",virtualMemUsed);

printf("\n\n--------------------------\n");
printf("\n***PAGE RANK ALGORITHM***\n");
printf("\n--------------------------\n\n");
begin=clock();
for (i=0;i<4;i++)
{
Pop(TOP,STACK);
Pop(TOP,IR_VISITED);
TOP=-1;
Pop(TOP1,par);
Pop(TOP1,STACK1);
Pop(TOP1,FP_VISITED);
free(lookfor);
free(root_fp);
TOP1=-1;
Pop(TOP2,STACK2);
Pop(TOP2,PR_VISITED);
TOP2=-1;
Pop(TOP3,STACK3);
Pop(TOP3,UP_VISITED);
TOP3=-1;
Pop(TOP4,STACK4);
Pop(TOP4,AP_VISITED);
Pop(TOP4,sorted_rank);
TOP4=-1, strk=-1;
if (ROOT[i]!=0)
page_rank(ROOT[i], query);
}
end = clock();
time_spent = (double)(end - begin);
printf("\nTime Taken:%lf",time_spent) ;
memInfo.dwLength= sizeof(MEMORYSTATUSEX);
GlobalMemoryStatusEx(&memInfo);
totalVirtualMem=memInfo.ullTotalPageFile;
virtualMemUsed=memInfo.ullTotalPageFile - memInfo.ullAvailPageFile;
printf("\nMemory Usage:%ld Bytes",virtualMemUsed);

int n;
printf("\n\n-------------------\n");
printf("\n***A STAR SEARCH***\n");
printf("\n-------------------\n\n");
begin=clock();
for(i=0;i<4;i++)
{
if(ROOT[i]!=0)
{
if(ROOT[i]==A)
{
n=12;
A_Star(ROOT[i],n,query);
}
else if(ROOT[i]==B)
{
n=8;
A_Star(ROOT[i],n,query);
}
else if(ROOT[i]==C)
{
n=9;
A_Star(ROOT[i],n,query);
}
else if(ROOT[i]==Q)
{
n=8;
A_Star(ROOT[i],n,query);
}
}
}
end = clock();
time_spent = (double)(end - begin);
printf("\nTime Taken:%lf",time_spent) ;
memInfo.dwLength= sizeof(MEMORYSTATUSEX);
GlobalMemoryStatusEx(&memInfo);
totalVirtualMem=memInfo.ullTotalPageFile;
virtualMemUsed=memInfo.ullTotalPageFile - memInfo.ullAvailPageFile;
printf("\nMemory Usage:%ld Bytes",virtualMemUsed);

int size;
printf("\n\n----------------------------\n");
printf("\n***ADAPTIVE A STAR SEARCH***\n");
printf("\n----------------------------\n\n");
begin=clock();
for(i=0;i<4;i++)
{
if(ROOT[i]!=0)
{
if(ROOT[i]==A)
{
n=12;
size=11;
Adaptive_A_Star(ROOT[i],n,size,query);
}
else if(ROOT[i]==B)
{
n=8;
size=7;
Adaptive_A_Star(ROOT[i],n,size,query);
}
else if(ROOT[i]==C)
{
n=9;
size=8;
Adaptive_A_Star(ROOT[i],n,size,query);
}
else if(ROOT[i]==Q)
{
n=8;
size=7;
Adaptive_A_Star(ROOT[i],n,size,query);
}
}
}
end = clock();
time_spent = (double)(end - begin);
printf("\nTime Taken:%lf",time_spent) ;
memInfo.dwLength= sizeof(MEMORYSTATUSEX);
GlobalMemoryStatusEx(&memInfo);
totalVirtualMem=memInfo.ullTotalPageFile;
virtualMemUsed=memInfo.ullTotalPageFile - memInfo.ullAvailPageFile;
printf("\nMemory Usage:%ld Bytes",virtualMemUsed);

printf("\n\nWant to search again? 1 for yes 0 for no.\n");
scanf("%d",&ch);
printf("\n");

	}while(ch!=0);
	getch();
	return 0;
}

void initialise_next(website *W)
{
    int i;
    for (i=0;i<5;i++)
    {
        W->next[i]=0;
    }
}

void  initialise_no(website *W)
{
    int i=0, j=0;
    ++TOP;
    STACK[TOP]=W;
    for (j=0;IR_VISITED[j]!=0;j++);
    IR_VISITED[j]=W;
    while (TOP>-1)
    {
        ++COUNT;
        for (i=0; i<5; i++)
        {
            if (W->next[i]==0)
            {
                W->no=i;
                --TOP;
                return;
            }
            for (j=0;IR_VISITED[j]!=0;j++)
                if (IR_VISITED[j]==W->next[i])
                   return;
            STACK[TOP]=W->next[i];
            initialise_no(STACK[TOP]);
        }
    }

}

void Assign()
{
    A=(website*)malloc(sizeof(website));
    B=(website*)malloc(sizeof(website));
    C=(website*)malloc(sizeof(website));
    D=(website*)malloc(sizeof(website));
    E=(website*)malloc(sizeof(website));
    F=(website*)malloc(sizeof(website));
    G=(website*)malloc(sizeof(website));
    H=(website*)malloc(sizeof(website));
    I=(website*)malloc(sizeof(website));
    J=(website*)malloc(sizeof(website));
    K=(website*)malloc(sizeof(website));
    L=(website*)malloc(sizeof(website));
    M=(website*)malloc(sizeof(website));
    N=(website*)malloc(sizeof(website));
    O=(website*)malloc(sizeof(website));
    P=(website*)malloc(sizeof(website));
    Q=(website*)malloc(sizeof(website));
    D1=(website*)malloc(sizeof(website));
    D2=(website*)malloc(sizeof(website));
    E1=(website*)malloc(sizeof(website));
    E2=(website*)malloc(sizeof(website));
    F1=(website*)malloc(sizeof(website));
    G1=(website*)malloc(sizeof(website));
    G2=(website*)malloc(sizeof(website));
    I1=(website*)malloc(sizeof(website));
    K1=(website*)malloc(sizeof(website));
    K2=(website*)malloc(sizeof(website));
    L1=(website*)malloc(sizeof(website));
    L2=(website*)malloc(sizeof(website));
    M1=(website*)malloc(sizeof(website));
    N1=(website*)malloc(sizeof(website));
    N2=(website*)malloc(sizeof(website));
    O1=(website*)malloc(sizeof(website));
    P1=(website*)malloc(sizeof(website));
    D21=(website*)malloc(sizeof(website));
    D22=(website*)malloc(sizeof(website));
    E21=(website*)malloc(sizeof(website));

    initialise_next(A);
    initialise_next(B);
    initialise_next(C);
    initialise_next(D);
    initialise_next(E);
    initialise_next(F);
    initialise_next(G);
    initialise_next(H);
    initialise_next(I);
    initialise_next(J);
    initialise_next(K);
    initialise_next(L);
    initialise_next(M);
    initialise_next(N);
    initialise_next(O);
    initialise_next(P);
    initialise_next(Q);
    initialise_next(D1);
    initialise_next(D2);
    initialise_next(E1);
    initialise_next(E2);
    initialise_next(F1);
    initialise_next(G1);
    initialise_next(G2);
    initialise_next(I1);
    initialise_next(K1);
    initialise_next(K2);
    initialise_next(L1);
    initialise_next(L2);
    initialise_next(M1);
    initialise_next(N1);
    initialise_next(N2);
    initialise_next(O1);
    initialise_next(P1);
    initialise_next(D21);
    initialise_next(D22);
    initialise_next(E21);

    strcpy(A->link,"https://www.foodsource.com");
    strcpy(A->title,"Food Mania:The Best Restaurant Recommender");
    strcpy(A->text,"Popular places- TACO BELL,BURGER KING,MC DONALDS,LASSI SHOP");

    strcpy(B->link,"https://www.allitebooks.com");
    strcpy(B->title,"All IT Ebooks:Get Free Ebooks on all Topics");
    strcpy(B->text,"Best Selling Books- The FlyCatcher,Insurgent,The Fault in Our Stars");

    strcpy(C->link,"https://www.AllMart.com/home");
    strcpy(C->title,"AllMart:Your one Stop Shop for the Best Deals!");
    strcpy(C->text,"Buy the Latest Brands of fashion,footwear,clothes and accesories");

    strcpy(Q->link,"https://www.ezone.com/welcome");
    strcpy(Q->title,"Ezone:The electronics zone for phones,laptops,tv");
    strcpy(Q->text,"Available product releases IPhone8,Macbook Pro Plus,Lenovo Ideapad 500,Windows 10 Updates,Sony LCD Bravia");

    strcpy(D->link,"https://www.IndianKhanaHouse.in");
    strcpy(D->title,"Indian Khana House:Your favourite Indian restaurants under one roof");
    strcpy(D->text,"Our most visited restaurants: Punjabi Dhaba, Earth Platter, Kabab Studio");

    strcpy(E->link,"https://www.ChungWah.ch");
    strcpy(E->title,"ChungWah!:The best Chinese food restaurant locator");
    strcpy(E->text,"Most Visited: Chungs,Beijing Bites,WOW! momos");

    strcpy(F->link,"https://www.ItalianConnection.com/home");
    strcpy(F->title,"Italian Connection:For all Italian Food Lovers");
    strcpy(F->text,"Our most Visited Restaurants: Au Bon Pain, Gelato:Italiano, Casa Piccola");

    strcpy(G->link,"https://www.allitebooks.com/fiction");
    strcpy(G->title,"All IT Ebooks:Get Free Ebooks on all Topics");
    strcpy(G->text,"Best Selling Books- The Invisible Man,Journey to the Center of The Earth");

    strcpy(H->link,"https://www.allitebooks.com/adventure");
    strcpy(H->title,"All IT Ebooks:Get Free Ebooks on all Topics");
    strcpy(H->text,"Best Selling Books- Famous Five,Catching Fire,Treasure Island");

    strcpy(I->link,"https://www.allitebooks.com/thriller");
    strcpy(I->title,"All IT Ebooks:Get Free Ebooks on all Topics");
    strcpy(I->text,"Best Selling Books- Gone Girl,Into the Water,The Da Vinci Code");

    strcpy(H->link,"https://www.allitebooks.com/adventure");
    strcpy(H->title,"All IT Ebooks:Get Free Ebooks on all Topics");
    strcpy(H->text,"Best Selling Books- Famous Five,Catching Fire,Treasure Island");

    strcpy(J->link,"https://www.allitebooks.com/drama");
    strcpy(J->title,"All IT Ebooks:Get Free Ebooks on all Topics");
    strcpy(J->text,"The following books are available:Pride and Prejudice,Silas Marner,As You Like It ");

    strcpy(K->link,"https://www.AllMart.com/dresses");
    strcpy(K->title,"AllMart:Your one Stop Shop for the Best Deals!");
    strcpy(K->text,"Most popular:T-Shirts,Gowns,Cold Shoulder,Suits,Jeans");

    strcpy(L->link,"https://www.AllMart.com/makeup");
    strcpy(L->title,"AllMart:Your one Stop Shop for the Best Deals!");
    strcpy(L->text,"Most popular:Eyeliner,foundation,Kohl");

    strcpy(M->link,"https://www.AllMart.com/Shoes");
    strcpy(M->title,"AllMart:Your one Stop Shop for the Best Deals!");
    strcpy(M->text,"Most Popular:Stilletos,Sports Shoes,Canvas");

    strcpy(N->link,"https://www.ezone.com/laptops");
    strcpy(N->title,"Ezone:The electronics zone");
    strcpy(N->text,"Available newly released models:Apple Macbook Pro,Lenovo IdeaPad 700");

    strcpy(O->link,"https://www.ezone.com/phones");
    strcpy(O->title,"Ezone:The electronics zone");
    strcpy(O->text,"Available newly released models:IPhone 8,Samsung Galaxy Note 5");

    strcpy(P->link,"https://www.ezone.com/TV");
    strcpy(P->title,"Ezone:The electronics zone");
    strcpy(P->text,"Available newly released models:Sony Bravia 5 3D,Videocon Ultra Resolution");

    strcpy(D1->link,"https://www.IndianKhanaHouse.in/north_indian");
    strcpy(D1->title,"Indian Khana House:Your favourite Indian restaurants under one roof");
    strcpy(D1->text,"Our most visited restaurants: Punjabi Dhaba,Copper Plate,Paradise");

    strcpy(D2->link,"https://www.IndianKhanaHouse.in/south_indian");
    strcpy(D2->title,"Indian Khana House:Your favourite Indian restaurants under one roof");
    strcpy(D2->text,"Our most visited restaurants: Shiv Sagar,Earth Platter,UpSouth");

    strcpy(E1->link,"https://www.ChungWah.ch/noodles");
    strcpy(E1->title,"ChungWah!:The best Chinese restaurant locator");
    strcpy(E1->text,"Most Visited: Chungs,Beijing Bites,Mainland China");

    strcpy(E2->link,"https://www.ChungWah.ch/dimsum");
    strcpy(E2->title,"ChungWah!:The best Chinese restaurant locator");
    strcpy(E2->text,"Most Visited: WOW! momos,ping pong,Harima");

    strcpy(F1->link,"https://www.ItalianConnection.com/pizzas");
    strcpy(F1->title,"Italian Connection:For all Italian Food Lovers");
    strcpy(F1->text,"Our most Visited Restaurants: Casa Piccola,Piazzo,The Italian House");

    strcpy(G1->link,"https://www.allitebooks.com/fiction/sci_fi");
    strcpy(G1->title,"All IT Ebooks:Get Free Ebooks on all Topics");
    strcpy(G1->text,"Best Selling Books- The Invisible Man,Dune,Neuromancer");

    strcpy(G2->link,"https://www.allitebooks.com/fiction/normal_fi");
    strcpy(G2->title,"All IT Ebooks:Get Free Ebooks on all Topics");
    strcpy(G2->text,"Best Selling Books- The Great Gatsby,Journey to the Center of The Earth");

    strcpy(I1->link,"https://www.allitebooks.com/thriller/horror");
    strcpy(I1->title,"All IT Ebooks:Get Free Ebooks on all Topics");
    strcpy(I1->text,"Best Selling Books- Dracula,Goosebumps");

    strcpy(K1->link,"https://www.AllMart.com/dresses/men");
    strcpy(K1->title,"AllMart:Your one Stop Shop for the Best Deals!");
    strcpy(K1->text,"Most popular:T-Shirts,Suits,Jeans");

    strcpy(K2->link,"https://www.AllMart.com/dresses/women");
    strcpy(K2->title,"AllMart:Your one Stop Shop for the Best Deals!");
    strcpy(K2->text,"Most popular:Crop Tops,Gowns,Cold Shoulders,Jeans");

    strcpy(L1->link,"https://www.LakmeIndia.in/home");
    strcpy(L1->title,"Lakme:Because Your Worth It!");
    strcpy(L1->text,"Kohl|LipStick|EyeShadow");

    strcpy(L2->link,"https://www.MaybellineNewYork.ny/india");
    strcpy(L2->title,"Maybelline:New York");
    strcpy(L2->text,"Collosal Kajal|Pearl Radiance");

    strcpy(M1->link,"https://www.Liberty.com");
    strcpy(M1->title,"Liberty Shoes");
    strcpy(M1->text,"Chappals|Heels|Boots");

    strcpy(N1->link,"https://www.Apple.com/india/laptops");
    strcpy(N1->title,"Apple:Think Different");
    strcpy(N1->text,"MacBook Pro5|iPad Mini|MacBook Pro 5 Plus");

    strcpy(N2->link,"https://www.lenovo.com/india/laptops");
    strcpy(N2->title,"Lenovo");
    strcpy(N2->text,"Lenovo IdeaPad 700|Lenovo IdeaPad 710");

    strcpy(O1->link,"https://www.Samsung.us/phones");
    strcpy(O1->title,"Samsung:phones");
    strcpy(O1->text,"Galaxy Note 5|Myriad 20");

    strcpy(P1->link,"https://www.Sony.com/home");
    strcpy(P1->title,"SONY");
    strcpy(P1->text,"Sony Bravia 10|Sony LED ColorMax");

    strcpy(D21->link,"https://www.IndianKhanaHouse.in/south_indian/buffet");
    strcpy(D21->title,"Indian Khana House:Your favourite Indian restaurants under one roof");
    strcpy(D21->text,"Our most visited restaurants: Nandini,Earth Platter");

    strcpy(D22->link,"https://www.IndianKhanaHouse.in/south_indian/a_la_carte");
    strcpy(D22->title,"Indian Khana House:Your favourite Indian restaurants under one roof");
    strcpy(D22->text,"Our most visited restaurants: Shiv Sagar,Karavalli");

    strcpy(E21->link,"https://www.ChungWah.ch/dimsum/momos");
    strcpy(E21->title,"ChungWah!:The best Chinese food restaurant locator");
    strcpy(E21->text,"Most Visited: WOW! momos,ping pong");

    A->next[0]=D;
    A->next[1]=E;
    A->next[2]=F;

    D->next[0]=D1;
    D->next[1]=D2;

    D2->next[0]=D21;
    D2->next[1]=D22;

    E->next[0]=E1;
    E->next[1]=E2;

    E2->next[0]=E21;

    F->next[0]=F1;

    B->next[0]=G;
    B->next[1]=H;
    B->next[2]=I;
    B->next[3]=J;

    G->next[0]=G1;
    G->next[1]=G2;

    I->next[0]=I1;

    C->next[0]=K;
    C->next[1]=L;
    C->next[2]=M;

    K->next[0]=K1;
    K->next[1]=K2;

    L->next[0]=L1;
    L->next[1]=L2;

    M->next[0]=M1;

    Q->next[0]=N;
    Q->next[1]=O;
    Q->next[2]=P;

    N->next[0]=N1;
    N->next[1]=N2;

    O->next[0]=O1;

    P->next[0]=P1;

    COUNT=0;
    int i;
    for (i=0;i<15;i++)
    {
        STACK[i]=0;
        IR_VISITED[i]=0;
    }
    TOP=-1;
    initialise_no(A);
    A->prev_rank=1/(float)COUNT;
    D->prev_rank=1/(float)COUNT;
    E->prev_rank=1/(float)COUNT;
    F->prev_rank=1/(float)COUNT;
    D1->prev_rank=1/(float)COUNT;
    D2->prev_rank=1/(float)COUNT;
    E1->prev_rank=1/(float)COUNT;
    E2->prev_rank=1/(float)COUNT;
    F1->prev_rank=1/(float)COUNT;
    D21->prev_rank=1/(float)COUNT;
    D22->prev_rank=1/(float)COUNT;
    E21->prev_rank=1/(float)COUNT;
    COUNT=0;
    for (i=0;i<15;i++)
    {
        STACK[i]=0;
        IR_VISITED[i]=0;
    }
    TOP=-1;
    initialise_no(B);
    B->prev_rank=1/(float)COUNT;
    G->prev_rank=1/(float)COUNT;
    H->prev_rank=1/(float)COUNT;
    I->prev_rank=1/(float)COUNT;
    J->prev_rank=1/(float)COUNT;
    G1->prev_rank=1/(float)COUNT;
    G2->prev_rank=1/(float)COUNT;
    I1->prev_rank=1/(float)COUNT;
    COUNT=0;
    for (i=0;i<15;i++)
    {
        STACK[i]=0;
        IR_VISITED[i]=0;
    }
    TOP=-1;
    initialise_no(C);
    C->prev_rank=1/(float)COUNT;
    K->prev_rank=1/(float)COUNT;
    L->prev_rank=1/(float)COUNT;
    M->prev_rank=1/(float)COUNT;
    K1->prev_rank=1/(float)COUNT;
    K2->prev_rank=1/(float)COUNT;
    L1->prev_rank=1/(float)COUNT;
    L2->prev_rank=1/(float)COUNT;
    M1->prev_rank=1/(float)COUNT;
    COUNT=0;
    for (i=0;i<15;i++)
    {
        STACK[i]=0;
        IR_VISITED[i]=0;
    }
    TOP=-1;
    initialise_no(Q);
    Q->prev_rank=1/(float)COUNT;
    N->prev_rank=1/(float)COUNT;
    O->prev_rank=1/(float)COUNT;
    P->prev_rank=1/(float)COUNT;
    N1->prev_rank=1/(float)COUNT;
    N2->prev_rank=1/(float)COUNT;
    O1->prev_rank=1/(float)COUNT;
    P1->prev_rank=1/(float)COUNT;

}

int search(char query[50],char line[200])
{
    char words[10][10];
    int i,j=0,ctr=0;
    for(i=0;i<strlen(query);i++)
    {
        if((query[i]==' ')||(query[i]=='\n')||(query[i]==',')||(query[i]=='?')||(query[i]=='-')||(query[i]==':'))
        {
            words[ctr][j]='\0';
            ctr++;
            j=0;
        }
        else
        {
            words[ctr][j]=query[i];
            j++;
        }
    }
    int cnt1=0;
    for(i=0;i<ctr;i++)
    {
        if(strstr(strlwr(line), strlwr(words[i])) != NULL)
        {
            cnt1++;
        }
    }
    if(cnt1==0)
    return 0;
    else
    return 1;
}

website * root_assign(char query[20],website *X)
{
    website *W;
    W=(website *)malloc(sizeof(website));
    initialise_next(W);

    int flag1,flag2,flag3,success;

    flag1=search(query,X->link);
    flag2=search(query,X->title);
    flag3=search(query,X->text);

    if((flag1==1)||(flag2==1)||(flag3==1))
    W=X;
    else if((flag1==0)&&(flag2==0)&&(flag3==0))
    W=0;
    return W;
}

int Check(char query[20],website *X)
{
    int flag1,flag2,flag3;

    flag1=search(query,X->link);
    flag2=search(query,X->title);
    flag3=search(query,X->text);

    int cnt=flag1+flag2+flag3;
    return cnt;
}

int search_node(char query[50],website *W)
{
    if (search(query,W->link)==1 || search(query,W->title)==1 || search(query,W->text)==1)
        return 1;
    else
        return 0;
}

int relevancy(char query[50],website *w)
{
    char words[10][10];
    char line[200];
    int i,j=0,ctr=0;
    for(i=0;i<strlen(query);i++)
    {
        if((query[i]==' ')||(query[i]=='\n')||(query[i]==',')||(query[i]=='?')||(query[i]=='-')||(query[i]==':'))
        {
            words[ctr][j]='\0';
            ctr++;
            j=0;
        }
        else
        {
            words[ctr][j]=query[i];
            j++;
        }
    }
    int cnt1=0,cnt2=0,cnt3=0;
    strcpy(line,w->link);
    for(i=0;i<ctr;i++)
    {
        if(strstr(strlwr(line), strlwr(words[i])) != NULL)
        {
            cnt1++;
        }
    }
    strcpy(line,w->title);
    for(i=0;i<ctr;i++)
    {
        if(strstr(strlwr(line), strlwr(words[i])) != NULL)
        {
            cnt2++;
        }
    }
    strcpy(line,w->text);
    for(i=0;i<ctr;i++)
    {
        if(strstr(strlwr(line), strlwr(words[i])) != NULL)
        {
            cnt3++;
        }
    }
    int mx;
    mx=cnt1+cnt2+cnt3;
    return mx;
}

int goal_rel(char query[50])
{
    char words[10][10];
    int i,j=0,ctr=0;
    for(i=0;i<strlen(query);i++)
    {
        if((query[i]==' ')||(query[i]=='\n')||(query[i]==',')||(query[i]=='?')||(query[i]=='-')||(query[i]==':'))
        {
            words[ctr][j]='\0';
            ctr++;
            j=0;
        }
        else
        {
            words[ctr][j]=query[i];
            j++;
        }
    }
    ctr=ctr*3;
    return ctr;
}

void QInsert(website *W)
{
	newptr=(node*)malloc(sizeof(node));
	newptr->w=W;
	if(Front==0)
	{
		Front=newptr;
	}
	else
	{
		Rear->link=newptr;
	}
	newptr->link=0;
	Rear=newptr;
	fflush(stdin);
	printf("\n");
}

int check(website *x)
{
    int flag=0;
	temp=Front;
	int cnt=0;
	while (temp != 0)
	{
        if(x==temp->w)
        return 1;
        else
        {
        temp = temp -> link;
        cnt++;
        }
	}
	return 0;
}

void Cache_Control(website *W)
{
    clock_t begin;
    clock_t end;
    int flag;
    flag=check(W);
    if(flag==0)
    {
    QInsert(W);
    begin=clock();
    date();
    expires();
    long age=0;
    cache_control(age);
    }
    else
    {
    printf("\n");
    end=clock();
    unsigned long time_spent = (long)(end - begin);
    last_modified();
    expires();
    cache_control(time_spent);
    }
    range();
    content_encoding();
    content_type();
    long l1=length_calc(W->title);
    long l2=length_calc(W->text);
    long l=l1+l2;
    content_length(l);
}

void Output(website *W)
{
	printf("Link:%s\n",W->link);
	printf("Title:%s\n",W->title);
	printf("Text:%s\n",W->text);
	Cache_Control(W);
	printf("---------------------------------------------------------------------------\n");
}

void DFS (website *W, char query[50])
{
    int i=0, j=0;
    ++top;
    stack[top]=W;
    for (j=0;DFS_visited[j]!=0;j++);
    DFS_visited[j]=W;
    while (top>-1)
    {
        if (search_node(query, W)==1)
            Output(W);
        for (i=0; i<5; i++)
        {
            if (W->next[i]==0)
            {
                --top;
                return;
            }
            for (j=0;DFS_visited[j]!=0;j++)
                if (DFS_visited[j]==W->next[i])
                   return;
            stack[top]=W->next[i];
            DFS(stack[top],query);
        }
    }
}

void BFS (website *W, char query[50])
{
    int i, j;
    if (front==-1)
    {
        ++front;
        ++rear;
    }
    else
        ++rear;
    queue[rear]=W;
    for (j=0; BFS_visited[j]!=0; j++);
    BFS_visited[j]=W;
    while (front<=rear)
    {
        website *V = queue[front];
        if (search_node(query, queue[front])==1)
            Output(queue[front]);
        ++front;
        for (i=0; V->next[i]!='\0'; i++)
        {
            int flag=0;
            for (j=0; BFS_visited[j]!=0; j++)
            {
                if (BFS_visited[j]==V->next[i])
                    flag=1;
            }
            if (flag==0)
            {
                ++rear;
                queue[rear]=V->next[i];
            }
            BFS_visited[j]=V->next[i];
        }
    }
}

void  find_parents(website *W)
{
    int i=0, j=0;
    ++TOP1;
    STACK1[TOP1]=W;
    for (j=0;FP_VISITED[j]!=0;j++);
    FP_VISITED[j]=W;
    while (TOP1>-1)
    {
        for (i=0; i<5; i++)
        {
            if (W->next[i]==lookfor)
            {
                for(j=0;par[j]!=0;j++);
                par[j]=W;
            }
            if (W->next[i]==0)
            {
                --TOP1;
                return;
            }
            for (j=0;FP_VISITED[j]!=0;j++)
                if (FP_VISITED[j]==W->next[i])
                   return;
            STACK1[TOP1]=W->next[i];
            find_parents(STACK1[TOP1]);
        }
    }
}

void ranking(website *W)
{
    if (TOP2==-1)
        root_fp=W;
    int i=0, j=0;
    ++TOP2;
    STACK2[TOP2]=W;
    for (j=0;PR_VISITED[j]!=0;j++);
    PR_VISITED[j]=W;
    while (TOP2>-1)
    {
        int k;
        for (k=0;k<15;k++)
        {
            par[k]=0;
            STACK1[k]=0;
            FP_VISITED[k]=0;
        }
        TOP1=-1;
        lookfor=W;
        find_parents(root_fp);
        if (par[0]==0)
        {
            W->rank=W->prev_rank;
        }
        else
        {
            W->rank=0;
            for (j=0;par[j]!=0;j++)
            {
                W->rank+=(par[j]->prev_rank)/((float)par[j]->no);
            }
        }
        for (i=0; i<5; i++)
        {
            if (W->next[i]==0)
            {
                --TOP2;
                return;
            }
            for (j=0;PR_VISITED[j]!=0;j++)
                if (PR_VISITED[j]==W->next[i])
                   return;
            STACK2[TOP2]=W->next[i];
            ranking(STACK2[TOP2]);
        }
    }
}

void update_prev(website *W)
{
    int i=0, j=0;
    ++TOP3;
    STACK3[TOP3]=W;
    for (j=0;UP_VISITED[j]!=0;j++);
    UP_VISITED[j]=W;
    while (TOP3>-1)
    {
        W->prev_rank=W->rank;
        for (i=0; i<5; i++)
        {
            if (W->next[i]==0)
            {
                --TOP3;
                return;
            }
            for (j=0;UP_VISITED[j]!=0;j++)
                if (UP_VISITED[j]==W->next[i])
                   return;
            STACK3[TOP3]=W->next[i];
            update_prev(STACK3[TOP3]);
        }
    }
}

void iteration_pagerank(website *W)
{
    int ipr=round(1/W->prev_rank);
    int i, j;
    for (i=0;i<ipr-1;i++)
    {
        for (j=0;j<15;j++)
        {
            STACK2[j]=0;
            PR_VISITED[j]=0;
            STACK3[j]=0;
            UP_VISITED[j]=0;
            par[j]=0;
        }
        TOP2=-1;
        TOP3=-1;
        ranking(W);
        update_prev(W);
    }
}

void array_pr(website *W)
{
    int i=0, j=0, k=0, l=0;
    ++TOP4;
    STACK4[TOP4]=W;
    for (j=0;AP_VISITED[j]!=0;j++);
    AP_VISITED[j]=W;
    while (TOP4>-1)
    {
        ++strk;
        sorted_rank[strk]=W;
        for (i=0; i<5; i++)
        {
            if (W->next[i]==0)
            {
                --TOP4;
                return;
            }
            for (j=0;AP_VISITED[j]!=0;j++)
                if (AP_VISITED[j]==W->next[i])
                   return;
            STACK4[TOP4]=W->next[i];
            array_pr(STACK4[TOP4]);
        }
    }
}

void page_rank(website *W, char query[50])
{
    int i, j, key, length;
    website *temp;
    for (i=0;i<15;i++)
    {
        STACK4[i]=0;
        AP_VISITED[i]=0;
        sorted_rank[i]=0;
    }
    TOP4=-1;
    iteration_pagerank(W);
    array_pr(W);
    for(length=0;sorted_rank[length]!=0;length++);
    for (i=0;i<length-1;i++)
    {
        key=i;
        for (j=i+1;j<length;j++)
        {
            if (sorted_rank[j]<sorted_rank[key])
                key=j;
        }
        temp=sorted_rank[key];
        sorted_rank[key]=sorted_rank[i];
        sorted_rank[i]=temp;
    }
    for (i=0;sorted_rank[i]!=0;i++)
    {
        if (search_node(query, sorted_rank[i])==1)
        {
            printf("Rank:%f\n",sorted_rank[i]->rank);
            Output(sorted_rank[i]);
        }
    }
}

void Pop(int top,website *stack[15])
{
    int i;
    for(i=0;i<15;i++)
    {
        stack[i]=0;
    }
}

void A_Star(website *seed,int n,char query[50])
{
    Output(seed);
    website *frontier[n];
    int g[5];
    int h[5];
    int f[5];
    int pos[0];
    int front=-1;
    int rear=-1;

    frontier[1]=seed;
    rear=1;
    front=1;

    website *w;

    int i;
    int goal=goal_rel(query);
    while((rear!=-1)||(front<=rear))
    {
        w=frontier[front];
        front++;
        int max=0,j=0,pos;
        for(i=0;i<5;i++)
        {
            if(w->next[i]!=0)
            {
                g[i]=relevancy(query,w->next[i]);
                h[i]=goal-g[i];
                f[i]=g[i]+h[i];
                if(g[i]>max)
                {
                max=g[i];
                }
            }
        }
        if(max!=0)
        {
            for(i=0;i<5;i++)
            {
                if(g[i]==max)
                {
                 rear++;
                 frontier[rear]=w->next[i];
                 if(w->next[i]!=NULL)
                 Output(w->next[i]);
                 else
                 break;
                }
            }
        }
        else
        break;
    }
}

void Adaptive_A_Star(website *seed,int n,int size,char query[50])
{
    int b=log(size);
    int k;
    website *frontier[n];
    int g[5];
    int h[5];
    int f[5];
    int pos[0];
    int front=-1;
    int rear=-1;
    frontier[1]=seed;
    Output(seed);

    website *w;
    int i;
    int goal=goal_rel(query);
    for(k=0;k<b;k++)
    {
        rear=1;
        front=1;
        while((rear!=-1)||(front<=rear))
        {
            w=frontier[front];
            front++;
            int max=0,j=0,pos;
            for(i=0;i<5;i++)
            {
                if(w->next[i]!=0)
                {
                    g[i]=relevancy(query,w->next[i]);
                    h[i]=goal-g[i];
                    f[i]=g[i]+h[i];
                    if(g[i]>max)
                    {
                    max=g[i];
                    }
                }
            }
            if((max!=0)&&(k==b-1))
            {
                for(i=0;i<5;i++)
                {
                    if(g[i]==max)
                    {
                     rear++;
                     frontier[rear]=w->next[i];
                     if(w->next[i]!=NULL)
                     Output(w->next[i]);
                     else
                     break;
                    }
                }
            }
            else
            break;
        }
    }
}

Cache Control Header File- “ccache.h”:

#include <Windows.h>
#include <stdio.h>
#include <string.h>

void range()
{
  printf("accept-ranges: bytes\n");
}

void date()
{
	SYSTEMTIME str_t;
	GetSystemTime(&str_t);

	printf("date: %d-%d-%d %d:%d:%d GMT\n",str_t.wDay,str_t.wMonth,str_t.wYear,str_t.wHour,str_t.wMinute,str_t.wSecond);

}

void expires()
{
	SYSTEMTIME str_t;
	GetSystemTime(&str_t);
	printf("expires: %d-%d-%d %d:%d:%d GMT\n",str_t.wDay,str_t.wMonth,str_t.wYear+1,str_t.wHour,str_t.wMinute,str_t.wSecond);

}

void last_modified()
{
	SYSTEMTIME str_t;
	GetSystemTime(&str_t);

	printf("last-modified: %d-%d-%d %d:%d:%d GMT\n",str_t.wDay,str_t.wMonth,str_t.wYear,str_t.wHour,str_t.wMinute,str_t.wSecond);

}

void cache_control(unsigned long age)
{
    printf("cache-control: public,max-age= %u\n",age);
}

void content_encoding()
{
    printf("content-encoding: gzip\n");
}

void content_type()
{
    printf("content-type: charset=UTF-8\n");
}

long length_calc(char str[])
{
    long l;
    l=strlen(str);
    return l;
}

void content_length(long l)
{
    printf("content-length: %ld\n",l);
}
