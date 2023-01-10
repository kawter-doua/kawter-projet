#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>

struct contact
{    int nt;
    char nom[100];
    char pr[20];
    char adr[50];
    char nrs[50];
};
int main()
{
    gotoxy(15,8);
printf("\t\t\t\t********** gestion des contacts **********\n");
    gotoxy(19,15);
printf("Appuyez sur n'importe quelle touche pour continuer");
    getch();
    menu();
    return 0;
}
void menu()
{
    int choix;
    system("cls");
    gotoxy(10,3);
    printf("\t\t\t\t********** La liste **********\n");
    gotoxy(10,5);
    printf("Entrez le numéro approprié pour effectuer la tâche suivante");
    gotoxy(10,7);
    printf("1 : ajouter un contact.");
    gotoxy(10,8);
    printf("2 : afficher la liste des contact.");
    gotoxy(10,9);
    printf("3 : chercher un contact.");
    gotoxy(10,10);
    printf("4 : modifier les information d'un contact.");
    gotoxy(10,11);
    printf("5 : supprimer.");
    gotoxy(10,12);
    printf("6 : Exit.");
    gotoxy(10,15);
    printf("Entrer votre choix.");
    scanf("%d",&choix);
    switch(choix)
    {
    case 1:
        ajouter();
        break;

    case 2:
        afficher();
        break;

    case 3:
        chercher();
        break;

    case 4:
        modifier();
        break;

    case 5:
        supprimer();
        break;

    case 6:
        exit(1);
        break;

    default:
        gotoxy(10,17);
        printf("ce choix n'existe pas.");
    }
}
void ajouter()
{
    FILE *fp;
    struct contact con;
    char autre ='y';
    system("cls");

    fp = fopen("contact.txt","ab+");
    if(fp == NULL){
        gotoxy(10,5);
        printf("Error");
        exit(1);
    }
    fflush(stdin);
    while(autre == 'y')
    {
        gotoxy(10,3);
 printf("\t\t\t\t-----------ajouter un contact-----------\n");
        gotoxy(10,5);
        printf("\nEntrer les information de votre contact.");
        gotoxy(10,7);

        printf("\nEntrer le nom : ");
        gets(con.nom);
        gotoxy(10,8);

        printf("\nEntrer le prénom : ");
        gets(con.pr);
        gotoxy(10,9);

        printf("\nEntrer le numéro de téléphone : ");
        scanf("%d",&con.nt);
        fflush(stdin);
        gotoxy(10,10);

        printf("\nEntrer l'adress email : ");
        gets(con.adr);
        gotoxy(10,11);

        printf("e nom d'un réseau social : ");
        gets(con.nrs);
        gotoxy(10,12);

        fwrite(&con,sizeof(con),1,fp);
        gotoxy(10,15);

        printf("Vous souhaitez ajouter un autre contact? 'y'ou'n'.");
        fflush(stdin);

        autre = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    gotoxy(10,18);
    printf("Appuyez sur n'importe quelle touche pour continuer");
    getch();
    menu();
}
void afficher()
{
    FILE *fp;
    int i=1,j;
    struct contact con;
    system("cls");
    gotoxy(10,3);
    printf("\t\t\t\t-----------afficher la liste-----------\n");
    gotoxy(10,5);
    printf("       nom       prénom     n-télephone     adress          n-réseau-s");
    gotoxy(10,6);
    printf("     --------------------------------------------------------------------");
    fp = fopen("contact.txt","rb+");
    if(fp == NULL){
        gotoxy(10,8);
        printf("Error");
        exit(1);
    }
    j=8;
    while(fread(&con,sizeof(con),1,fp) == 1){
        gotoxy(10,j);
        printf("%-7d%-12s%-12s%-19d%-18s%-6s",i,con.nom,con.pr,con.nt,con.adr,con.nrs);
        i++;
        j++;
    }
    fclose(fp);
    gotoxy(10,j+3);
    printf("Appuyez sur n'importe quelle touche pour continuer");
    getch();
    menu();
}
void chercher()
{
    FILE *fp;
    struct contact con;
    char cnom[20];
    system("cls");
    gotoxy(10,3);
 printf("\t\t\t\t-----------chercher un contact-----------\n");
    gotoxy(10,5);
    printf("Entrer le nom de contact pour chercher : ");
    fflush(stdin);
    gets(cnom);
    fp = fopen("contact.txt","rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error ");
        exit(1);
    }
    while(fread(&con,sizeof(con),1,fp ) == 1){
        if(strcmp(cnom,con.nom) == 0){
            gotoxy(10,8);
            printf("Nom : %s",con.nom);
            gotoxy(10,9);
            printf("Le prénom : %s",con.pr);
            gotoxy(10,10);
            printf("Le numéreau de télephone : %d",con.nt);
            gotoxy(10,11);
            printf("L'adresse email : %s",con.adr);
            gotoxy(10,12);
            printf("Le nom dans un réseau social : %s",con.nrs);
        }
    }
    fclose(fp);
    gotoxy(10,16);
    printf("Appuyez sur n'importe quelle touche pour continuer.");
    getch();
    menu();
}
void modifier()
{
    char cnom[20];
    FILE *fp;
    struct contact con;
    system("cls");
    gotoxy(10,3);
 printf("\t\t\t\t-----------modifier les informations d'un contact-----------\n");
    gotoxy(10,5);
    printf("Entrer le nom de contact pour chercher et modifier: ");
    fflush(stdin);
    gets(cnom);
    fp = fopen("contact.txt","rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error ");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    while(fread(&con,sizeof(con),1,fp) == 1)
    {
        if(strcmp(cnom,con.nom) == 0){
            gotoxy(10,7);
            printf("Entrer le nom: ");
            gets(con.nom);
            gotoxy(10,8);
            printf("Entrer le prénom : ");
            gets(con.pr);
            gotoxy(10,9);
            printf("Entrer le numéro de téléphone : ");
            scanf("%d",&con.nt);
            gotoxy(10,10);
            printf("Entrer l'adresse email: ");
            fflush(stdin);
            gets(con.adr);
            gotoxy(10,11);
            printf("Entrer Le nom dans un réseau social : ");
            fflush(stdin);
            gets(con.nrs);
            fseek(fp ,-sizeof(con),SEEK_CUR);
            fwrite(&con,sizeof(con),1,fp);
            break;
        }
    }
    fclose(fp);
    gotoxy(10,16);
    printf("Appuyez sur n'importe quelle touche pour continuer");
    getch();
    menu();
}
void supprimer()
{
    char cnom[20];
    FILE *fp,*ft;
    struct contact con;
    system("cls");
    gotoxy(10,3);
     printf("\t\t\t\t-----------supprimer la liste d'un contact-----------\n");
    gotoxy(10,5);
    printf("Entrer le nom de contact pour supprimer leurs informations : ");
    fflush(stdin);
    gets(cnom);
    fp = fopen("contact.txt","rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error");
        exit(1);
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL){
        gotoxy(10,6);
        printf("Error");
        exit(1);
    }
    while(fread(&con,sizeof(con),1,fp) == 1){
        if(strcmp(cnom,con.nom)!=0)
            fwrite(&con,sizeof(con),1,ft);
    }
    fclose(fp);
    fclose(ft);
    remove("contact.txt");
    rename("temp.txt","contact.txt");
    gotoxy(10,10);
    printf("\n\n\tAppuyez sur n'importe quelle touche pour continuer .");
    getch();
    menu();
}
void gotoxy(int x,int y)
{
        COORD c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
