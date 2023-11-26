//------------------------------------librerias-----------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
//------------------------------------funciones-----------------------------------------------------------

//Limpia la el Buffer
void limpiarBuffer();

//Limpia la pantalla
void erase();

// Espera hasta que se presione "Enter" o se alcance el final del archivo
void precionar_enter();

//Subprograma que genrera el menu, para que el usuario navegue
void menu();

//Subprograma del juego
void juegar(); 

void clasico();

void arcade();

void star_classico(int eleccion);

char palabra[50]; // variable global, para usar en todos los modos de juego

void Perdiste();

void victoria();







void Normal(); // <<<<<<<<<------------------------------- Eliminar


void explicación();


void puntuacion();


void ObtenerPalabra(int tag);


char* espacios();


int dificultad();



//------------------------------------main-----------------------------------------------------------
int main(){

    erase();
    menu();

    return 0;

    /*char nombre[50]; ///POOOOOOPPPPPPPPPPOOOOOOOOOOPPPPPPPP*/

    /*printf("Porfavor ingresa tu nombre.\n");*/

    /*scanf("%s",nombre); ///POOOOOOPPPPPPPPPPOOOOOOOOOOPPPPPPPP*/

}


//------------------------------------funciones_desarrolladas-----------------------------------------------------------















//Limpia la pantalla
void erase(){
   printf("\033[2J"); // Borra la pantalla
   printf("\033[H");  // Mueve el cursor al principio
}


//Limpia la el Buffer
void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


// Espera hasta que se presione "Enter" o se alcance el final del archivo
void precionar_enter(){
   int c;
   do {
      c = getchar();
   } while (c != '\n'); 
}


//Subprograma que genrera el menu, para que el usuario navegue
void menu(){

   int elecion = 0;
   /*texto_menu(); //Animacion de texto*/
   
   printf("\n\n");
   printf("    \033[38;2;251;229;173m|============================================================|\n");
   printf("    \033[38;2;251;229;173m|                                                            \033[38;2;251;229;173m|\n");
   printf("    \033[38;2;251;229;173m|                  \033[38;2;230;126;34m|| Ahorcado ||                    \033[38;2;251;229;173m|\n");
   printf("    \033[38;2;251;229;173m|                                                            |\n");
   printf("    \033[38;2;251;229;173m|============================================================|\n");
   printf("    \033[38;2;251;229;173m|    1- Jugar.                                              \033[38;2;251;229;173m|\n");
   printf("    \033[38;2;251;229;173m|    2- Reglas.                                               \033[38;2;251;229;173m|\n");
   printf("    \033[38;2;251;229;173m|    3- Ranking.                                             \033[38;2;251;229;173m|\n");
   printf("    \033[38;2;251;229;173m|------------------------------------------------------------|\n");
   printf("    \033[38;2;251;229;173m|    0- Salir.                                               \033[38;2;251;229;173m|\n");
   printf("    \033[38;2;251;229;173m|============================================================|\n\n\033[0m"); 
   usleep(70000); // Pausa de 7 milisegundos (70000 microsegundos)

   printf(" Ingrese un numero para hacer una eleccion.\n");
   printf(" Su elecion es: "); 

   scanf("%d", &elecion);

   switch (elecion) {
   case 1:
      erase();
      limpiarBuffer();
      juegar();
      break;

   case 2:
      erase();
      limpiarBuffer();
      //reglas();
      break;

   case 3:
      erase();
      limpiarBuffer();
      //record(); 
      break;

   case 0:
      erase();
      //texto_salida();
      exit(0); // Cierra el programa con código de salida 0
   break;

   default:
      erase();
      printf("\n\n Elección no válida. Por favor, intente nuevamente.\n");
      menu();
   }
}
















void juegar() {
    
    int elecion = 0;

    printf("\n\n");
    printf("    \033[38;2;251;229;173m|============================================================|\n");
    printf("    \033[38;2;251;229;173m|                                                            \033[38;2;251;229;173m|\n");
    printf("    \033[38;2;251;229;173m|                  \033[38;2;230;126;34m|| Modo de juego ||                    \033[38;2;251;229;173m|\n");
    printf("    \033[38;2;251;229;173m|                                                            |\n");
    printf("    \033[38;2;251;229;173m|============================================================|\n");
    printf("    \033[38;2;251;229;173m|    1- Clasico.                                              \033[38;2;251;229;173m|\n");
    printf("    \033[38;2;251;229;173m|    2- Arcade.                                              \033[38;2;251;229;173m|\n");
    printf("    \033[38;2;251;229;173m|------------------------------------------------------------|\n");
    printf("    \033[38;2;251;229;173m|    0- Atras.                                               \033[38;2;251;229;173m|\n");
    printf("    \033[38;2;251;229;173m|============================================================|\n\n\033[0m"); 

    printf(" Ingrese un numero para hacer una eleccion.\n");
    printf(" Su elecion es: "); 

    scanf("%d", &elecion);

    switch (elecion) {
    case 1:
        erase();
        limpiarBuffer();
        clasico();
        break;
      
    case 2:

        erase();
        limpiarBuffer();
        arcade();
        break;

    case 0:
        erase();
        limpiarBuffer();
        menu(); 
        break;

    default:
        erase();
        printf("\n\n Elección no válida. Por favor, intente nuevamente.\n");
        juegar();
    }
}

















void clasico(){

    int elecion = 0;
    int tag = 0;
    srand(time(NULL));
    
    printf("\n\n");
    printf("    \033[38;2;251;229;173m|============================================================|\n");
    printf("    \033[38;2;251;229;173m|                                                            \033[38;2;251;229;173m|\n");
    printf("    \033[38;2;251;229;173m|                  \033[38;2;230;126;34m|| Modo de juego 'Classico' ||                    \033[38;2;251;229;173m|\n");
    printf("    \033[38;2;251;229;173m|                                                            |\n");
    printf("    \033[38;2;251;229;173m|============================================================|\n");
    printf("    \033[38;2;251;229;173m|    Elija su dificultad:                                    |\n");
    printf("    \033[38;2;251;229;173m|    1- Facil. (4 a 5 letras)                                              \033[38;2;251;229;173m|\n");
    printf("    \033[38;2;251;229;173m|    2- Media. (6 a 9 letras)                                             \033[38;2;251;229;173m|\n");
    printf("    \033[38;2;251;229;173m|    3- Dificil. (10 a 13)                                             \033[38;2;251;229;173m|\n");   
    printf("    \033[38;2;251;229;173m|------------------------------------------------------------|\n");
    printf("    \033[38;2;251;229;173m|    0- Atras.                                               \033[38;2;251;229;173m|\n");
    printf("    \033[38;2;251;229;173m|============================================================|\n\n\033[0m"); 

    printf(" Ingrese un numero para hacer una eleccion.\n");
    printf(" Su elecion es: "); 

    scanf("%d", &elecion);

    switch (elecion) {
    case 1:
        erase();
        limpiarBuffer();
        tag = rand() % 36;
        ObtenerPalabra(tag); // Llamar a ObtenerPalabra con el array local
        star_classico(elecion);
        break;
      
    case 2:
        erase();
        limpiarBuffer();
        tag = 36 + rand() % 36;
        ObtenerPalabra(tag); // Llamar a ObtenerPalabra con el array local
        star_classico(elecion);
        break;

     case 3:
        erase();
        limpiarBuffer();
        tag = 71 + rand() % 36;;
        ObtenerPalabra(tag); // Llamar a ObtenerPalabra con el array local

                // Imprimir la palabra
                printf("%s\n", palabra);

        star_classico(elecion);
        break;

    case 0:
        erase();
        limpiarBuffer();
        menu(); 
        break;

    default:
        erase();
        printf("\n\n Elección no válida. Por favor, intente nuevamente.\n");
        juegar();
    }
}














void ObtenerPalabra(int tag) {
    size_t maxLength = 50;
    FILE* filePointer;
    filePointer = fopen("Palabras.dat", "r");

    if (filePointer == NULL) {
        printf("Error al abrir el archivo.\n");
        clasico();
    }

    // Busca la línea correspondiente al tag
    for (int i = 0; i < tag; ++i) {
        if (fgets(palabra, maxLength, filePointer) == NULL) {
            printf("Error: No se encontró la palabra para el tag %d.\n", tag);
            fclose(filePointer);
            clasico();
        }
    }

    // Elimina el salto de línea al final de la palabra
    size_t length = strlen(palabra);
    if (length > 0 && palabra[length - 1] == '\n') {
        palabra[length - 1] = '\0';
    }

    fclose(filePointer);
    // No es necesario devolver la palabra, ya que se está modificando directamente en la función.
}
    


void star_classico(int eleccion) {

    srand(time(NULL)); //Se inicializa el tiempo para es programa
    
    int contador = 0, verificador = 0, aux = 0,aux_2 = 0; // una variable de contador , otra que verifica si el usuario acerto la letra y suma de aciertos que cuenta si el usuario completo la palabra
    int cantidadElementos = strlen(palabra); // consigue la cantidad de elemntos de "palabra"
    int palabra_comparativa [cantidadElementos]; // un aaray vacio con la misma cantidad de espacios que la palabra misteriosa
    char palabra_del_usuario [50];
    char letra_jugador = '\0';
    char abecedario [27] = {0}; // sirve de registro para las letras que ya se acertaron Y usaron
    int suma_aciertos = cantidadElementos - 1; // otra variable con la cantidad de elemntos de "palabra"





    // Inicializa palabra_comparativa, rellenado todo los espacios con 0
    for (int i = 0; i < cantidadElementos; i++) {
        palabra_comparativa[i] = 0;
    }

    do{
        for (int k = 0; k < cantidadElementos-1; k++) {  //For que se repite tantas veces como letras tenga palabra

            if (palabra_comparativa[k] == 1){       //
            printf("%c ", palabra[k]);              // Imprime la letra si está adivinada
            }                                       //
                                                      
            else{
                printf("_ "); // Imprime un _ si la letra aun no se adivino
            }
        }


        printf("\n\nSuma %d", suma_aciertos); // <==================================== eliminar 
        printf("\n\nAhorcado: numero de intento %d", contador); // <==================================== Codificar para que sea un tipito que muere xd 

        do{
            printf("\n\nIngresa una letra o la palabra: "); 
            printf("\n\ncantidadElementos = %d ", cantidadElementos-1 ); 
            scanf("%s", &palabra_del_usuario);   // usuario igresa una letra o palabra (la palabra solo cuenta si es igual de larga que la palabra el juego)
            printf("\n\n strlen(palabra_del_usuario) = %d ", strlen(palabra_del_usuario) ); 
               
               if   ((strlen(palabra_del_usuario))   ==   (cantidadElementos-1)) { // Verifica si la entrada es una palabra es tan larga como la cantidad de letras de la palabra del juego

                    if ((strcmp(palabra, palabra_del_usuario)) == 0){ //compara las cadenas(palabra del usuario, con la palabra del juego) y ve si son iguales

                            //<================== poner un mensaje que le diga al usuario que apriente enter para continuar
                            suma_aciertos = 0;
                            
                        victoria(); //<__________________ programar
                    }
                    else {
                        contador++; //si erro la palabra le suma 1 error
                        printf("\n\nfallaste.\n"); // el mensaje
                        break;
                    }
                }

                else if ((strlen(palabra_del_usuario))   <  (cantidadElementos-1) || (strlen(palabra_del_usuario))   >  (cantidadElementos-1)) // si el usuario ingreso 2 o mas letras por error y no queria enviar una palabra le envia un mensaje de error
                {
                    printf("\n\nPor favor, ingresa solo una letra.\n"); // el mensaje
                }

                if ((strlen(palabra_del_usuario)) == 1) //verifica que el array tenga un solo elemnto
                {
                    letra_jugador = palabra_del_usuario[0]; // guarda el elemento el la variable letrajugador
                }

                size_t longitud = sizeof(palabra_del_usuario) / sizeof(palabra_del_usuario[0]);// Obtener la longitud del array
                memset(palabra_del_usuario, '\0', longitud);// Vaciar el array estableciendo todos los elementos en '\0'

        }while (!isalpha(letra_jugador)); //verifica que el jugador ingrese una sola letra
    
        verificador = 0;

        for (int i = 0; i < cantidadElementos; i++) {                //For que se repite tantas veces como letras tenga palabra
            if (tolower(palabra[i]) == tolower(letra_jugador)) {     //verifica si el usuario ingreso una letra que se encuetra en "palabra"
                if (palabra_comparativa[i] == 0) {                   //si en el arreglo palabra_comparativa[i] esta en cero le guardo un 1, claro esto si la letra se encuientra en palabra,
                    palabra_comparativa[i] = 1;                      // esto solo se va a hacer una sola vez y sirve para no hacer multiples decrementos en suma_aciertos
                    suma_aciertos--;
                    verificador = 1;
                } else {
                    printf("\n\nYa has ingresado esta letra antes.\n");    // Si el usuario ingresa 2 veces la misma letra el if de arriba "if (palabra_comparativa[i] == 0)" va a ser falso
                    verificador = 2;
                }
            }
        }

        if (verificador != 2) { // Si el usuario ingreso 2 veces la misma letra se almacenara para que no pueda repetirla
            abecedario[aux_2] = tolower(letra_jugador);// <======================================== poner que muestre en pantalla las letras que el usuari ya ingreso xd
            aux_2++;
        }


      if (verificador == 0){
        contador++;
      }

    

    }  while (contador <= 7 && suma_aciertos > 0);





    if (contador == 8){
        Perdiste(); //<__________________ programar
    }

    else {
            for (int k = 0; k < cantidadElementos-1; k++){  //For que se repite tantas veces como letras tenga palabra
            printf("%c ", palabra[k]);
            }

            //<================== poner un mensaje que le diga al usuario que apriente enter para continuar
        victoria(); //<__________________ programar
    }

} 




/*
- Modo arcade:
         - Contra reloj
         - Hoyo en uno
         - Boos Rush

- Una estructura de usuario 
- Medir el Tiempo
- Ranking


- Despues queda en belleser el programa, pero eso lo hago yo*/
























void arcade(){
      //break;
}

void Perdiste(){
        printf(" \033[38;2;251;229;173mPerdiste\n");
}

void victoria(){
        printf(" \033[38;2;251;229;173mGanaste\n");
}


/*

void arcade(){
        int elecion = 0;

    printf("\n\n");
    printf("    \033[38;2;251;229;173m|============================================================|\n");
    printf("    \033[38;2;251;229;173m|                                                            \033[38;2;251;229;173m|\n");
    printf("    \033[38;2;251;229;173m|                  \033[38;2;230;126;34m|| Modo de juego ||                    \033[38;2;251;229;173m|\n");
    printf("    \033[38;2;251;229;173m|                                                            |\n");
    printf("    \033[38;2;251;229;173m|============================================================|\n");
    printf("    \033[38;2;251;229;173m|    1- Clasico.                                              \033[38;2;251;229;173m|\n");
    printf("    \033[38;2;251;229;173m|    2- Arcade.                                              \033[38;2;251;229;173m|\n");
    printf("    \033[38;2;251;229;173m|------------------------------------------------------------|\n");
    printf("    \033[38;2;251;229;173m|    0- Atras.                                               \033[38;2;251;229;173m|\n");
    printf("    \033[38;2;251;229;173m|============================================================|\n\n\033[0m"); 

    printf(" Ingrese un numero para hacer una eleccion.\n");
    printf(" Su elecion es: "); 

    scanf("%d", &elecion);

    switch (elecion) {
    case 1:
        erase();
        limpiarBuffer();
        clasico();
        break;
      
    case 2:

        erase();
        limpiarBuffer();
        arcade();
        break;

    case 0:
        erase();
        menu(); // Cierra el programa con código de salida 0
        break;

    default:
        erase();
        printf("\n\n Elección no válida. Por favor, intente nuevamente.\n");
        juegar();
    }
}

//dificultad devuelve el tag de la palabra que se va a usar en el juego
*/
/*

//__________Interfaz principal_______________

void Normal(){

//------------------elección de dificultad------------------
    int tag = dificultad();
    char* palabra = ObtenerPalabra(tag);
//------------------elección de dificultad------------------

//------------------imprimir espacio vacios------------------
    printf("mi tag es: %d, y mi palabra es: %s",tag, palabra);
//------------------imprimir espacio vacios------------------
}
*/

/*
void explicación(){
    system("cls");
    int salir;
    do
    {
        printf("1. ¿Cómo jugar al ahorcado?\n");
        printf("2. ¿Cómo es el sistema de puntos?\n");
        printf("3. Volver a pantalla de incio.\n");
        printf("Seleccione opción: ");
        scanf("%d", &salir);
        switch (salir)
        {
        case 1:
            system("cls");
            printf("La premisa es sencilla. Debes de adivinar la palabra ingresando letra a letra (pueden repetirse letras y no se toman en cuenta los acentos),\n");
            printf("¡pero atención! que si te equivocas se va a ir formando un dibujo simulando las oportunidades\n");
            printf("que tienes. Son un total de 6 oportunidades de adivinar la palabra, si ves este dibujo, ¡se acabo el juego!\n");
            printf("___\n");
            printf("|       O\n");
            printf("|      /|\\\n");
            printf("|      / \\\n");
            printf("|\n");
            printf("\n");
            break;
        case 2:
            system("cls");
            printf("¡La forma de conseguir puntos es sencilla!, pero atención la forma de puntaje cambia según la dificultad del juego.\n");
            printf("Facil:\n");
            printf("-Por cada letra que adivines se va a sumar un +1\n");
            printf("-Si adivinas la palabra sin errores +5\n");
            printf("-Si adivinas la palabra en menos de 15 segundos +10\n");
            printf("\n");
            printf("Medio:\n");
            printf("-Por cada letra que adivines se va a sumar un +1\n");
            printf("-Si adivinas la palabra sin errores +12\n");
            printf("-Si adivinas la palabra en menos de 30 segundos +15\n");
            printf("\n");
            printf("Dificil:\n");
            printf("-Por cada letra que adivines se va a sumar un +1\n");
            printf("-Si adivinas la palabra sin errores +30\n");
            printf("-Si adivinas la palabra en menos de 50 segundos +25\n");
            printf("\n");
            break;
        default:
            system("cls");
            printf("seleccione una opción valida.\n");
            break;
        }
    } while (salir != 3);
    system("cls");
}



void puntuacion(){
    system("cls");
    printf("Funciona eleccion 2\n");
    system("cls");
}


*/







































/*
int dificultad() {
    bool salir = false;
    int eleccion, tag;
    system("cls");
    //Escanea la eleccion del usuario y devuelva el tag de la palabra que se usara
    do
    {
        printf("Dificultad: \n");
        printf("1. Fácil: de 4 a 5 letras.\n");
        printf("2. Medio: de 6 a 9 letras.\n");
        printf("3. Difícil: de 10 a 13 letras.\n");
        printf("Seleccione dificultad: ");
        scanf("%d", &eleccion);
        switch (eleccion)
        {
        case 1:
            tag = rand() % 36; 
            salir = true;
            break;
        case 2:
            tag = 36 + rand() % 36;
            salir = true;
            break;
        case 3:
            tag = 71 + rand() % 36;
            salir = true;
            break;
        default:
            system("cls");
            printf("Opción no válida.\n");
            break;
        }
    //fin de escaneo
    } while (salir != true);

    system("cls");
    return tag;
}

//char* palabra(char* palabra){
//    printf("mi palabra es %s", palabra);
//}



void texto_menu() {}//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Este void solo trae una animacion >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/