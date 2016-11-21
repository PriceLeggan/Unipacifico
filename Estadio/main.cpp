#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <string>
#include <cctype>
#include <windows.h>
/////////////LIBRERIAS
using namespace std;
//////////////////////////Estructuras .
struct User{
	char nombre[30];
	char cc[30];
	char telefono[30];
}Puser;

struct config{
	char evento[30];
	int  boleta;
}Pconfig;
////////////////////////////////////////////////77
void AltEnter();
void GUI();
void Configuracion();
void RegistroBoleta();
void  ComprobarArchivo();
//////////////PROTOTIPO DE FUNCION
FILE *Bd;
FILE *User;
FILE *Config;

///////Apuntadores de Archivo txt /////////

////////////////Variables Globales;
int SurPiso1   = 1 , SurPiso2=SurPiso1+((SurPiso1*15)/100);
int NortePiso1 = SurPiso1+((SurPiso1*35)/100) , NortePiso2 = SurPiso1+((SurPiso1*25)/100);
int Oriente1   = SurPiso1+((SurPiso1*60)/100) , Oriente2=SurPiso1+((SurPiso1*45)/100);
int Occident1  = SurPiso1+((SurPiso1*80)/100) , Occidente2=SurPiso1+((SurPiso1*70)/100);
//////////////////////////////////////////////////////////////
int main(int argc, char *argv[])
{
   ComprobarArchivo();
   cout<<""<<endl;
   
   AltEnter();//Pantalla Completa
   GUI();//Carga Gui Principal
   system("PAUSE");
   return EXIT_SUCCESS;
}

void AltEnter()
{
    keybd_event(VK_MENU,0x38,0,0);
    keybd_event(VK_RETURN, 0x1c,0, 0);
    keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
    keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
    for(int i=0;i<=100;i++) {
      system ("color f2");
      cout<<"\n\n\n\n\t\t\t\tCARGANDO ESPERE\n\t\t\t\t\t"<<i<<"%"<<endl;
      system("cls");
      Sleep(10*100/80);}
      cout<<endl;
    return;
}
void GUI()
    { int op = 0;
     system("cls");
     cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
     cout<<"°                                                °"<<endl;
     cout<<"°    1 - INICIO DE SESION ADMINISTRADOR          °"<<endl;
     cout<<"°                                                °"<<endl;
     cout<<"°    2 - REGISTRO DE ADMINISTRADOR UNICO         °"<<endl;
     cout<<"°                                                °"<<endl;
     cout<<"°    3 - RECUPERACION DE CONTRASENA Y USUARIO !  °"<<endl;
     cout<<"°                                                °"<<endl;
     cout<<"°    4 - ELIMINACION DE USUARIO POR CODIGO UNICO °"<<endl;
     cout<<"°                                                °"<<endl;
     cout<<"°    5 - SALIR                                   °"<<endl;
     cout<<"°                                                °"<<endl;
     cout<<"°    0 - Configuracion                           °"<<endl;
     cout<<"°                                                °"<<endl;
     cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
     cout<<endl;
     cout<<"-> ";
     cin>>op;
     cout<<endl;
      switch (op)
      {
      	case 0: Configuracion();  break;
        case 1:                   break;
        case 2:                   break;
        case 3:                   break;
        case 4:                   break;
        case 5: exit(0);          break;}
         }//GUI
void Configuracion(){
     int op = 0;
     system("cls");
     cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
     cout<<"°                                                °"<<endl;
     cout<<"°    1 - REGISTRAR BOLETA BASE.                  °"<<endl;
     cout<<"°                                                °"<<endl;
     cout<<"°    2 - LISTADO DE PRECIOS MODIFICADOS SEGUN    °"<<endl;
     cout<<"°        VALOR BASE BOLETA.                      °"<<endl;
     cout<<"°                                                °"<<endl;
     cout<<"°    0 - REGRESAR.                               °"<<endl;
     cout<<"°                                                °"<<endl;
     cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
     cout<<endl;
     cout<<"-> ";
     cin>>op;
     cout<<endl;
      switch (op)
      {
      	case 0:  GUI();            break;
        case 1:  RegistroBoleta(); break;
        case 2:                    break;}
}

void RegistroBoleta()
   {
     int con = 0;
     system("cls");
     cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
     cout<<"°                                      °"<<endl;
     cout<<"°                                      °"<<endl;
     cout<<"° REGISTRO DE VALOR BOLETA BASE        °"<<endl;
     cout<<"°                                      °"<<endl;
     cout<<"°                                      °"<<endl;
     cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
     cout<<endl;
     Config = fopen("c:\\Config.txt","w+");
     if( Config == NULL){
        cout<<"\a ERROR EN LA CREACION DEL ARCHIVO INTERNO \n ";
        getch();}
        
     fflush(stdin);
     cout<<"INGRESE EVENTO: ";
     gets(Pconfig.evento);
     cout<<endl;
     fflush(stdin);
     cout<<"INGRESE VALOR DE BOLETA BASE: ";
     cin>>Pconfig.boleta;
     cout<<endl;
     cout<<Pconfig.boleta<<endl;
     cout<<"VERIFICA Y CONFIRMA LOS DATOS \n\n 1 - CONFIRMAR Y GUARDAR \n\n 2 - VOLVER A REGISTRAR DISPOSITIVO \n\n 3 - RETORNAR MENU PRINCIPAL"<<endl;
                          cout<<endl;
                          cout<<"-> ";
                          cin>>con;
                          cout<<endl;
                          switch(con)
                          {
                                   case 1:
                                        cout<<endl;

                                        cout<<"DATOS CONFIRMADOS  "<<endl;
                                        system("PAUSE");
                                        fwrite(&Pconfig, sizeof(Pconfig),1,Config);
                                        fclose(Config);
                                        Configuracion();

                                        break;

                                        case 2:
                                             system("cls");
                                             cout<<"RETORNANDO REGISTRO DE VALOR BOLETA BASE  "<<endl;
                                             system("PAUSE");
                                             RegistroBoleta();
                                             break;

                                             case 3:
                                                  GUI;
                                                  break;
                                        }

    } 
void  ComprobarArchivo(){
	
	 FILE* archivo = fopen("c:\\Config.txt","r");
	 if (archivo) {
        
		printf("Carga de Archivo de Configuracion Usuario\n");
		printf("Espere");
		fclose(archivo);
        Sleep(10*100000/80);
         } else {
          printf("Carga de Archivos de Configuracion  Por Defecto\n");
          printf("Espere");
          Sleep(10*100000/80);}

}
         
         
