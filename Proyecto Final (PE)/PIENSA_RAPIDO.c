//////////////////////////////////////////////////////////////////////////////////////////
// PROYECTO FINAL DE PE "PIENSA RAPIDO"               FECHA DE INICIO: 05/06/2024       //
// PROGRAMADORES:                                     FECHA DE FINALIZACION: 11/06/2024 //
// 1.- LESLY GALLARDO GONZALEZ      MATRICULA: 370027                                   //
// 2.- RAUL ARAM VAZQUEZ FIGUEROA   MATRICULA: 370132                                   //
// DESCRIPCION: Juego tipo cuestionario sobre preguntas basicas de matematicas para     //
// niños de entre 8 a 10 años de edad.                                                  //
// El juego inicia al presionar "iniciar" en el menu, seguido de esto apareceran las    //
// instrucciones del juego y despues el contador comenzara. El participante tiene 1     //
// minuto para contestar  20 preguntas correctamente. Es un 1 punto por pregunta        //
// correcta. Trata de hacer la mayor cantidad de puntos posibles                        //
//////////////////////////////////////////////////////////////////////////////////////////

/////////// LIBRERIAS ///////////
#include "raylib.h"
#include <stdio.h>

////////// ENUMERACION DE PAGINAS ///////////
typedef enum 
{
    PAG1, PAG2, PAG3, PAG4, PAG5, PAG6, PAG7, PAG8, PAG9, PAG10,
    PAG11, PAG12, PAG13, PAG14, PAG15, PAG16, PAG17, PAG18, PAG19,
    PAG20, PAG21, PAG22, PAG23, PAG24, PAG25, PAG26, PAG27, PAG28, PAG29
} Pagina;

////////// TEXTURAS ///////////

// fondos //
Texture2D t_fondo_pag1;
Texture2D t_fondo_pag2;
Texture2D t_fondo_pag3;
Texture2D t_fondo_pag4;
Texture2D t_fondo_pag5;
Texture2D t_fondo_pag6;
Texture2D t_fondo_pag7;
Texture2D t_fondo_pag8_p1;
Texture2D t_fondo_pag9_p2;
Texture2D t_fondo_pag10_p3;
Texture2D t_fondo_pag11_p4;
Texture2D t_fondo_pag12_p5;
Texture2D t_fondo_pag13_p6;
Texture2D t_fondo_pag14_p7;
Texture2D t_fondo_pag15_p8;
Texture2D t_fondo_pag16_p9;
Texture2D t_fondo_pag17_p10;
Texture2D t_fondo_pag18_p11;
Texture2D t_fondo_pag19_p12;
Texture2D t_fondo_pag20_p13;
Texture2D t_fondo_pag21_p14;
Texture2D t_fondo_pag22_p15;
Texture2D t_fondo_pag23_p16;
Texture2D t_fondo_pag24_p17;
Texture2D t_fondo_pag25_p18;
Texture2D t_fondo_pag26_p19;
Texture2D t_fondo_pag27_p20;
Texture2D t_fondo_pag28;
Texture2D t_fondo_pag29;

// BOTONES//
Texture2D t_salir;
Texture2D t_jugar;
Texture2D t_regresar;
Texture2D t_continuar;
Texture2D t_seguro;

////////// VARIABLES GLOBALES ///////////
float tiempo = 0.0f; // tiempo de las paginas 4,5,6 y 7
float tiempo2 = 0.0f; // tiempo de la pagina 29
float cronometro = 0.0f; // tiempo del cronometro
const float tiempo_limite = 1.0f; // Límite de tiempo en cada página
const float tiempo_limite2 = 3.0f;
const float tiempo_umbral = 60.0f; // limite del cronometro
int puntaje = 0;
bool detener_cronometro = false; // control del cronometro

/////////// PROTOTIPOS DE FUNCIONES ///////////
void cargar_texturas(void);
void mostrar_paginas(Pagina pagina);
void n_aciertos (int puntaje);

void pagina1 (void);
void pagina2 (void);
void pagina3 (void);
void pagina4 (void);
void pagina5 (void);
void pagina6 (void);
void pagina7 (void);
void pagina8 (void);
void pagina9 (void);
void pagina10 (void);
void pagina11 (void);
void pagina12 (void);
void pagina13 (void);
void pagina14 (void);
void pagina15 (void);
void pagina16 (void);
void pagina17 (void);
void pagina18 (void);
void pagina19 (void);
void pagina20 (void);
void pagina21 (void);
void pagina22 (void);
void pagina23 (void);
void pagina24 (void);
void pagina25 (void);
void pagina26 (void);
void pagina27 (void);
void pagina28 (void);
void pagina29 (void);

/////////// FUNCION PRINCIPAL (int main) ///////////
int main ()
{
    // titulo de la ventana y redimensionamiento
    InitWindow(1000, 630, "PIENSA RAPIDO");

    // inicializar audios
    InitAudioDevice ();

    // cargar texturas
    cargar_texturas();

    // cargar canciones
    Music c1 = LoadMusicStream ("IMGS_proyecto/MainMenu.mp3");
    Sound c2 = LoadSound ("IMGS_proyecto/Correcto.mp3");
    Sound c3 = LoadSound ("IMGS_proyecto/Incorrecto.mp3");
    Sound c4 = LoadSound ("IMGS_proyecto/boton parcial.mp3");
    Music c5 = LoadMusicStream ("IMGS_proyecto/Preparados.mp3");
    Music c6 = LoadMusicStream ("IMGS_proyecto/TLT.mp3");
    Sound c7 = LoadSound ("IMGS_proyecto/Resultado.mp3");

    // pagina principal
    Pagina pagina = PAG1;

    // validacion de avance de paginas
    bool click_pag8 = false;
    bool click_pag9 = false;
    bool click_pag10 = false;
    bool click_pag11 = false;
    bool click_pag12 = false;
    bool click_pag13 = false;
    bool click_pag14 = false;
    bool click_pag15 = false;
    bool click_pag16 = false;
    bool click_pag17 = false;
    bool click_pag18 = false;
    bool click_pag19 = false;
    bool click_pag20 = false;
    bool click_pag21 = false;
    bool click_pag22 = false;
    bool click_pag23 = false;
    bool click_pag24 = false;
    bool click_pag25 = false;
    bool click_pag26 = false;
    bool click_pag27 = false;

    // Ciclo para mantener la ventana abierta
    while (!WindowShouldClose())
    {
        // limpiar pantalla con cada iteracion, en este caso con color blanco
        ClearBackground(RAYWHITE);

        // actualizar buffer de musica
        UpdateMusicStream (c1);
        UpdateMusicStream (c5);
        UpdateMusicStream (c6);
        
        // aumentar el tiempo cada segundo
        tiempo = tiempo + GetFrameTime (); // tiempo de pags 4,5,6 y 7

        if (pagina >= PAG8 && pagina <= PAG28)
        {
            if (!detener_cronometro)
            {
                cronometro = cronometro + GetFrameTime ();
            }
        }

        mostrar_paginas(pagina);

        if (cronometro >= tiempo_umbral)
        {
            StopMusicStream (c6);
            detener_cronometro = true;
            pagina = PAG28;
        }

        if (pagina == PAG1) // menu principal
        {
            puntaje = 0;
            PlayMusicStream (c1);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                Vector2 mouse1 = GetMousePosition();
                if (CheckCollisionPointRec(mouse1, (Rectangle){320, 390, 340, 40}))
                {
                    PlaySound (c4);
                    pagina = PAG2;
                }
                else if (CheckCollisionPointRec(mouse1, (Rectangle){870, 15, 110, 100}))
                {
                    PlaySound (c4);
                    CloseWindow(); 
                }
            }
        }

        if (pagina == PAG2) // instrucciones
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                Vector2 mouse2 = GetMousePosition();
                if (CheckCollisionPointRec(mouse2, (Rectangle){320, 590, 340, 40}))
                {
                    PlaySound (c4);
                    pagina = PAG3;
                }
                else if (CheckCollisionPointRec(mouse2, (Rectangle){40, 30, 110, 50}))
                {
                    PlaySound (c4);
                    pagina = PAG1; 
                }
            }
        }

        if (pagina == PAG3) // preparacion
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                Vector2 mouse3 = GetMousePosition();
                if (CheckCollisionPointRec(mouse3, (Rectangle){360, 445, 240, 35}))
                {
                    PlaySound (c4);
                    pagina = PAG4;
                }
                else if (CheckCollisionPointRec(mouse3, (Rectangle){40, 30, 110, 50}))
                {
                    PlaySound (c4);
                    pagina = PAG2;
                }
            } 
            tiempo = 0.0f;
        }

        if (pagina == PAG4) // preparacion
        {
            StopMusicStream (c1);
            PlayMusicStream (c5);
            if (tiempo >= tiempo_limite)
            {
                tiempo = 0.0f;
                pagina = PAG5;
            }
        }

        if (pagina == PAG5) // preparacion
        {
            if (tiempo >= tiempo_limite)
            {
                tiempo = 0.0f;
                pagina = PAG6;
            }
        }

        if (pagina == PAG6) // preparacion
        {
            if (tiempo >= tiempo_limite)
            {
                tiempo = 0.0f;
                pagina = PAG7;
            }
        }

        if (pagina == PAG7) // preparacion
        {
            if (tiempo >= tiempo_limite)
            {
                tiempo = 0.0f;
                pagina = PAG8;
            }
        }

        if (pagina == PAG8 && !click_pag8) // pregunta 1
        {
            StopMusicStream (c5);
            PlayMusicStream (c6);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                Vector2 mousep1 = GetMousePosition();
                if (CheckCollisionPointRec(mousep1, (Rectangle){533, 328, 200, 35})) 
                {
                    PlaySound (c3);
                    pagina = PAG9;
                    click_pag8 = true; // Indica que se está procesando un clic en la página 8
                }
                else if (CheckCollisionPointRec(mousep1, (Rectangle){533, 430, 200, 35})) 
                {
                    PlaySound (c3);
                    pagina = PAG9;
                    click_pag8 = true; 
                }
                else if (CheckCollisionPointRec(mousep1, (Rectangle){263, 328, 200, 35})) // correcta
                {
                    PlaySound (c2);
                    puntaje = puntaje + 1;
                    pagina = PAG9;
                    click_pag8 = true;
                }
                else if (CheckCollisionPointRec(mousep1, (Rectangle){263, 430, 200, 35}))
                {
                    PlaySound (c3);
                    pagina = PAG9;
                    click_pag8 = true; 
                }
            }    
        }

        else if (pagina == PAG9 && !click_pag9) // pregunta 2
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                Vector2 mousep2 = GetMousePosition();
                if (CheckCollisionPointRec(mousep2, (Rectangle){533, 328, 200, 35})) 
                {
                    PlaySound (c3);
                    pagina = PAG10;
                    click_pag9 = true; 
                }
                else if (CheckCollisionPointRec(mousep2, (Rectangle){533, 430, 200, 35}))
                {
                    PlaySound (c3);
                    pagina = PAG10;
                    click_pag9 = true; 
                }
                else if (CheckCollisionPointRec(mousep2, (Rectangle){263, 328, 200, 35})) // correcta
                {
                    PlaySound (c2);
                    puntaje = puntaje + 1;
                    pagina = PAG10;
                    click_pag9 = true; 
                }
                else if (CheckCollisionPointRec(mousep2, (Rectangle){263, 430, 200, 35}))
                {
                    PlaySound (c3);
                    pagina = PAG10;
                    click_pag9 = true; 
                }
            }    
        }

        else if (pagina == PAG10 && !click_pag10) // pregunta 3
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                Vector2 mousep3 = GetMousePosition();
                if (CheckCollisionPointRec(mousep3, (Rectangle){533, 328, 200, 35})) // correcta
                {
                    PlaySound (c2);
                    puntaje = puntaje + 1;
                    pagina = PAG11;
                    click_pag10 = true;
                }
                else if (CheckCollisionPointRec(mousep3, (Rectangle){533, 430, 200, 35}))
                {
                    PlaySound (c3);
                    pagina = PAG11;
                    click_pag10 = true;
                }
                else if (CheckCollisionPointRec(mousep3, (Rectangle){263, 328, 200, 35})) 
                {
                    PlaySound (c3);
                    pagina = PAG11;
                    click_pag10 = true;
                }
                else if (CheckCollisionPointRec(mousep3, (Rectangle){263, 430, 200, 35}))
                {
                    PlaySound (c3);
                    pagina = PAG11;
                    click_pag10 = true;
                }
            } 
        }

        else if (pagina == PAG11 && !click_pag11) // pregunta 4
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                Vector2 mousep4 = GetMousePosition();
                if (CheckCollisionPointRec(mousep4, (Rectangle){533, 328, 200, 35}))
                {
                    PlaySound (c3);
                    pagina = PAG12;
                    click_pag11 = true;
                }
                else if (CheckCollisionPointRec(mousep4, (Rectangle){533, 430, 200, 35})) // correcta
                {
                    PlaySound (c2);
                    puntaje = puntaje + 1;
                    pagina = PAG12;
                    click_pag11 = true;
                }
                else if (CheckCollisionPointRec(mousep4, (Rectangle){263, 328, 200, 35})) 
                {
                    PlaySound (c3);
                    pagina = PAG12;
                    click_pag11 = true;
                }
                else if (CheckCollisionPointRec(mousep4, (Rectangle){263, 430, 200, 35}))
                {
                    PlaySound (c3);
                    pagina = PAG12;
                    click_pag11 = true;
                }
            } 
        }

        else if (pagina == PAG12 && !click_pag12) // pregunta 5
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                Vector2 mousep5 = GetMousePosition();
                if (CheckCollisionPointRec(mousep5, (Rectangle){533, 328, 200, 35})) 
                {
                    PlaySound (c3);
                    pagina = PAG13;
                    click_pag12 = true;
                }
                else if (CheckCollisionPointRec(mousep5, (Rectangle){533, 430, 200, 35}))
                {
                    PlaySound (c3);
                    pagina = PAG13;
                    click_pag12 = true;
                }
                else if (CheckCollisionPointRec(mousep5, (Rectangle){263, 328, 200, 35})) // correcta
                {
                    PlaySound (c2);
                    puntaje = puntaje + 1;
                    pagina = PAG13;
                    click_pag12 = true;
                }
                else if (CheckCollisionPointRec(mousep5, (Rectangle){263, 430, 200, 35}))
                {
                    PlaySound (c3);                    
                    pagina = PAG13;
                    click_pag12 = true;
                }
            } 
        }

        else if (pagina == PAG13 && !click_pag13) // pregunta 6
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                Vector2 mousep6 = GetMousePosition();
                if (CheckCollisionPointRec(mousep6, (Rectangle){533, 328, 200, 35}))
                {
                    PlaySound (c3);
                    pagina = PAG14;
                    click_pag13 = true;
                }
                else if (CheckCollisionPointRec(mousep6, (Rectangle){533, 430, 200, 35})) 
                {
                    PlaySound (c3);
                    pagina = PAG14;
                    click_pag13 = true;
                }
                else if (CheckCollisionPointRec(mousep6, (Rectangle){263, 328, 200, 35})) 
                {
                    PlaySound (c3);
                    pagina = PAG14;
                    click_pag13 = true;
                }
                else if (CheckCollisionPointRec(mousep6, (Rectangle){263, 430, 200, 35})) // correcta
                {
                    PlaySound (c2);
                    puntaje = puntaje + 1;
                    pagina = PAG14;
                    click_pag13 = true;
                }
            } 
        }

        else if (pagina == PAG14 && !click_pag14) // pregunta 7
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                Vector2 mousep7 = GetMousePosition();
                if (CheckCollisionPointRec(mousep7, (Rectangle){533, 328, 200, 35}))
                {
                    PlaySound (c3);
                    pagina = PAG15;
                    click_pag14 = true;
                }
                else if (CheckCollisionPointRec(mousep7, (Rectangle){533, 430, 200, 35}))
                {
                    PlaySound (c3);
                    pagina = PAG15;
                    click_pag14 = true;
                }
                else if (CheckCollisionPointRec(mousep7, (Rectangle){263, 328, 200, 35})) // correcta
                {
                    PlaySound (c2);
                    puntaje = puntaje + 1;
                    pagina = PAG15;
                    click_pag14 = true;
                }
                else if (CheckCollisionPointRec(mousep7, (Rectangle){263, 430, 200, 35})) 
                {
                    PlaySound (c3);
                    pagina = PAG15;
                    click_pag14 = true;
                }
            } 
        }

        else if (pagina == PAG15 && !click_pag15) // pregunta 8
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                Vector2 mousep8 = GetMousePosition();
                if (CheckCollisionPointRec(mousep8, (Rectangle){533, 328, 200, 35}))
                {
                    PlaySound (c3);
                    pagina = PAG16;
                    click_pag15 = true;
                }
                else if (CheckCollisionPointRec(mousep8, (Rectangle){533, 430, 200, 35}))
                {
                    PlaySound (c3);
                    pagina = PAG16;
                    click_pag15 = true;
                }
                else if (CheckCollisionPointRec(mousep8, (Rectangle){263, 328, 200, 35}))
                {
                    PlaySound (c3);
                    pagina = PAG16;
                    click_pag15 = true;
                }
                else if (CheckCollisionPointRec(mousep8, (Rectangle){263, 430, 200, 35})) // correcta
                {
                    PlaySound (c2);
                    puntaje = puntaje + 1;
                    pagina = PAG16;
                    click_pag15 = true;
                }
            } 
        }

        else if (pagina == PAG16 && !click_pag16) // pregunta 9
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                Vector2 mousep9 = GetMousePosition();
                if (CheckCollisionPointRec(mousep9, (Rectangle){533, 328, 200, 35})) // correcta
                {
                    PlaySound (c2);
                    puntaje = puntaje + 1;
                    pagina = PAG17;
                    click_pag16 = true;
                }
                else if (CheckCollisionPointRec(mousep9, (Rectangle){533, 430, 200, 35}))
                {
                    PlaySound (c3);
                    pagina = PAG17;
                    click_pag16 = true;
                }
                else if (CheckCollisionPointRec(mousep9, (Rectangle){263, 328, 200, 35})) 
                {
                    PlaySound (c3);
                    pagina = PAG17;
                    click_pag16 = true;
                }
                else if (CheckCollisionPointRec(mousep9, (Rectangle){263, 430, 200, 35}))
                {
                    PlaySound (c3);
                    pagina = PAG17;
                    click_pag16 = true;
                }
            } 
        }

        else if (pagina == PAG17 && !click_pag17) // pregunta 10
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                Vector2 mousep10 = GetMousePosition();
                if (CheckCollisionPointRec(mousep10, (Rectangle){533, 328, 200, 35})) 
                {
                    PlaySound (c3);
                    pagina = PAG18;
                    click_pag17 = true;
                }
                else if (CheckCollisionPointRec(mousep10, (Rectangle){533, 430, 200, 35}))
                {
                    PlaySound (c3);
                    pagina = PAG18;
                    click_pag17 = true;
                }
                else if (CheckCollisionPointRec(mousep10, (Rectangle){263, 328, 200, 35})) // correcta
                {
                    PlaySound (c2);
                    puntaje = puntaje + 1;
                    pagina = PAG18;
                    click_pag17 = true;
                }
                else if (CheckCollisionPointRec(mousep10, (Rectangle){263, 430, 200, 35}))
                {
                    PlaySound (c3);
                    pagina = PAG18;
                    click_pag17 = true;
                }
            } 
        }

        else if (pagina == PAG18 && !click_pag18) // pregunta 11
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                Vector2 mousep11 = GetMousePosition();
                if (CheckCollisionPointRec(mousep11, (Rectangle){533, 328, 200, 35})) 
                {
                    PlaySound (c3);
                    pagina = PAG19;
                    click_pag18 = true;
                }

                else if (CheckCollisionPointRec(mousep11, (Rectangle){533, 430, 200, 35}))
                {  
                    PlaySound (c3);
                    pagina = PAG19;
                    click_pag18 = true;
                }

                else if (CheckCollisionPointRec(mousep11, (Rectangle){263, 328, 200, 35})) // correcta
                {
                    PlaySound (c2);
                    puntaje = puntaje + 1;
                    pagina = PAG19;
                    click_pag18 = true;
                }

                else if (CheckCollisionPointRec(mousep11, (Rectangle){263, 430, 200, 35}))
                {
                    PlaySound (c3);
                    pagina = PAG19;
                    click_pag18 = true;
                }
            } 
        }

        else if (pagina == PAG19 && !click_pag19) // pregunta 12
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                Vector2 mousep12 = GetMousePosition();
                if (CheckCollisionPointRec(mousep12, (Rectangle){533, 328, 200, 35}))
                {
                    PlaySound (c3);
                    pagina = PAG20;
                    click_pag19 = true;
                }
                else if (CheckCollisionPointRec(mousep12, (Rectangle){533, 430, 200, 35})) // correcta
                {
                    PlaySound (c2);
                    puntaje = puntaje + 1;
                    pagina = PAG20;
                    click_pag19 = true;
                }
                else if (CheckCollisionPointRec(mousep12, (Rectangle){263, 328, 200, 35})) 
                {
                    PlaySound (c3);
                    pagina = PAG20;
                    click_pag19 = true;
                }
                else if (CheckCollisionPointRec(mousep12, (Rectangle){263, 430, 200, 35})) 
                {
                    PlaySound (c3);
                    pagina = PAG20;
                    click_pag19 = true;
                }
            } 
        }
        else if (pagina == PAG20 && !click_pag20) // pregunta 13
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                Vector2 mousep13 = GetMousePosition();
                if (CheckCollisionPointRec(mousep13, (Rectangle){533, 328, 200, 35}))
                {
                    PlaySound (c3);
                    pagina = PAG21;
                    click_pag20 = true;
                }
                else if (CheckCollisionPointRec(mousep13, (Rectangle){533, 430, 200, 35}))
                {
                    PlaySound (c3);
                    pagina = PAG21;
                    click_pag20 = true;
                }
                else if (CheckCollisionPointRec(mousep13, (Rectangle){263, 328, 200, 35})) 
                {
                    PlaySound (c3);
                    pagina = PAG21;
                    click_pag20 = true;
                }
                else if (CheckCollisionPointRec(mousep13, (Rectangle){263, 430, 200, 35})) // correcta
                {
                    PlaySound (c2);
                    puntaje = puntaje + 1;
                    pagina = PAG21;
                    click_pag20 = true;
                }
            } 
        }

        else if (pagina == PAG21 && !click_pag21) // pregunta 14
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                Vector2 mousep14 = GetMousePosition();
                if (CheckCollisionPointRec(mousep14, (Rectangle){533, 328, 200, 35})) 
                {
                    PlaySound (c3);
                    pagina = PAG22;
                    click_pag21 = true;
                }
                else if (CheckCollisionPointRec(mousep14, (Rectangle){533, 430, 200, 35}))
                {
                    PlaySound (c3);
                    pagina = PAG22;
                    click_pag21 = true;
                }
                else if (CheckCollisionPointRec(mousep14, (Rectangle){263, 328, 200, 35})) // correcta
                {
                    PlaySound (c2);
                    puntaje = puntaje + 1;
                    pagina = PAG22;
                    click_pag21 = true;
                }
                else if (CheckCollisionPointRec(mousep14, (Rectangle){263, 430, 200, 35}))
                {
                    PlaySound (c3);
                    pagina = PAG22;
                    click_pag21 = true;
                }
            } 
        }

        else if (pagina == PAG22 && !click_pag22) // pregunta 15
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                Vector2 mousep15 = GetMousePosition();
                if (CheckCollisionPointRec(mousep15, (Rectangle){533, 328, 200, 35}))
                {
                    PlaySound (c3);
                    pagina = PAG23;
                    click_pag22 = true;
                }
                else if (CheckCollisionPointRec(mousep15, (Rectangle){533, 430, 200, 35}))
                {
                    PlaySound (c3);
                    pagina = PAG23;
                    click_pag22 = true;
                }
                else if (CheckCollisionPointRec(mousep15, (Rectangle){263, 328, 200, 35})) 
                {
                    PlaySound (c3);
                    pagina = PAG23;
                    click_pag22 = true;
                }
                else if (CheckCollisionPointRec(mousep15, (Rectangle){263, 430, 200, 35})) // correcta
                {
                    PlaySound (c2);
                    puntaje = puntaje + 1;
                    pagina = PAG23;
                    click_pag22 = true;
                }
            } 
        }

        else if (pagina == PAG23 && !click_pag23) // pregunta 16
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                Vector2 mousep16 = GetMousePosition();
                if (CheckCollisionPointRec(mousep16, (Rectangle){533, 328, 200, 35}))
                {
                    PlaySound (c3);
                    pagina = PAG24;
                    click_pag23 = true;
                }
                else if (CheckCollisionPointRec(mousep16, (Rectangle){533, 430, 200, 35})) // correcta
                {
                    PlaySound (c2);
                    puntaje = puntaje + 1;
                    pagina = PAG24;
                    click_pag23 = true;
                }
                else if (CheckCollisionPointRec(mousep16, (Rectangle){263, 328, 200, 35})) 
                {
                    PlaySound (c3);
                    pagina = PAG24;
                    click_pag23 = true;
                }
                else if (CheckCollisionPointRec(mousep16, (Rectangle){263, 430, 200, 35})) 
                {
                    PlaySound (c3);
                    pagina = PAG24;
                    click_pag23 = true;
                }
            } 
        }

        else if (pagina == PAG24 && !click_pag24) // pregunta 17
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                Vector2 mousep17 = GetMousePosition();
                if (CheckCollisionPointRec(mousep17, (Rectangle){533, 328, 200, 35}))
                { 
                    PlaySound (c3);
                    pagina = PAG25;
                    click_pag24 = true;
                }
                else if (CheckCollisionPointRec(mousep17, (Rectangle){533, 430, 200, 35}))
                {
                    PlaySound (c3);
                    pagina = PAG25;
                    click_pag24 = true;
                }
                else if (CheckCollisionPointRec(mousep17, (Rectangle){263, 328, 200, 35})) // correcta
                {
                    PlaySound (c2);
                    puntaje = puntaje + 1;
                    pagina = PAG25;
                    click_pag24 = true;
                }
                else if (CheckCollisionPointRec(mousep17, (Rectangle){263, 430, 200, 35}))
                {
                    PlaySound (c3);
                    pagina = PAG25;
                    click_pag24 = true;
                }
            } 
        }

        else if (pagina == PAG25 && !click_pag25) // pregunta 18
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                Vector2 mousep18 = GetMousePosition();
                if (CheckCollisionPointRec(mousep18, (Rectangle){533, 328, 200, 35}))
                {
                    PlaySound (c3);
                    pagina = PAG26;
                    click_pag25 = true;
                }
                else if (CheckCollisionPointRec(mousep18, (Rectangle){533, 430, 200, 35}))
                {
                    PlaySound (c3);
                    pagina = PAG26;
                    click_pag25 = true;
                }
                else if (CheckCollisionPointRec(mousep18, (Rectangle){263, 328, 200, 35})) 
                {
                    PlaySound (c3);
                    pagina = PAG26;
                    click_pag25 = true;
                }
                else if (CheckCollisionPointRec(mousep18, (Rectangle){263, 430, 200, 35})) // correcta
                {
                    PlaySound (c2);
                    puntaje = puntaje + 1;
                    pagina = PAG26;
                    click_pag25 = true;
                }
            } 
        }

        else if (pagina == PAG26 && !click_pag26) // pregunta 19
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                Vector2 mousep19 = GetMousePosition();
                if (CheckCollisionPointRec(mousep19, (Rectangle){533, 328, 200, 35})) 
                {
                    PlaySound (c3);
                    pagina = PAG27;
                    click_pag26 = true;
                }
                else if (CheckCollisionPointRec(mousep19, (Rectangle){533, 430, 200, 35}))
                {
                    PlaySound (c3);
                    pagina = PAG27;
                    click_pag26 = true;
                }
                else if (CheckCollisionPointRec(mousep19, (Rectangle){263, 328, 200, 35})) // correcta
                {
                    PlaySound (c2);
                    puntaje = puntaje + 1;
                    pagina = PAG27;
                    click_pag26 = true;
                }
                else if (CheckCollisionPointRec(mousep19, (Rectangle){263, 430, 200, 35}))
                {
                    PlaySound (c3);
                    pagina = PAG27;
                    click_pag26 = true;
                }
            } 
        }

        else if (pagina == PAG27 && !click_pag27) // pregunta 20
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                Vector2 mousep20 = GetMousePosition();
                if (CheckCollisionPointRec(mousep20, (Rectangle){533, 328, 200, 35}))
                {
                    PlaySound (c3);
                    pagina = PAG28;
                    PlaySound (c7);
                    click_pag27 = true;
                }
                else if (CheckCollisionPointRec(mousep20, (Rectangle){533, 430, 200, 35}))
                {
                    PlaySound (c3);
                    pagina = PAG28;
                    PlaySound (c7);
                    click_pag27 = true;
                }
                else if (CheckCollisionPointRec(mousep20, (Rectangle){263, 328, 200, 35})) 
                {
                    PlaySound (c3);
                    pagina = PAG28;
                    PlaySound (c7);
                    click_pag27 = true;
                }
                else if (CheckCollisionPointRec(mousep20, (Rectangle){263, 430, 200, 35})) // correcta
                {
                    PlaySound (c2);
                    puntaje = puntaje + 1;
                    pagina = PAG28;
                    PlaySound (c7);
                    click_pag27 = true;
                }
            } 
        }

        else if (pagina == PAG28) // pagina de resultados
        {
            StopMusicStream (c6);
            n_aciertos (puntaje);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                Vector2 mouse2 = GetMousePosition();
                if (CheckCollisionPointRec(mouse2, (Rectangle){320, 590, 340, 40}))
                {
                    PlaySound (c4);
                    pagina = PAG29;
                }
            }
        }

        else if (pagina == PAG29) // pagina final
        {
            tiempo2 = tiempo2 + GetFrameTime ();
            if (tiempo2 >= tiempo_limite2)
            {
                tiempo2 = 0.0f;
                detener_cronometro = false;
                pagina = PAG1;
            }
        }

        ///// redefininedo los controladores de pagina /////
        if (pagina != PAG8)
        {
            click_pag8 = false;
        }

        if (pagina != PAG9)
        {
            click_pag9 = false;
        }

        if (pagina != PAG10)
        {
            click_pag10 = false;
        }

        if (pagina != PAG11)
        {
            click_pag11 = false;
        }

        if (pagina != PAG12)
        {
            click_pag12 = false;
        }

        if (pagina != PAG13)
        {
            click_pag13 = false;
        }

        if (pagina != PAG14)
        {
            click_pag14 = false;
        }

        if (pagina != PAG15)
        {
            click_pag15 = false;
        }

        if (pagina != PAG16)
        {
            click_pag16 = false;
        }

        if (pagina != PAG17)
        {
            click_pag17 = false;
        }

        if (pagina != PAG18)
        {
            click_pag18 = false;
        }

        if (pagina != PAG19)
        {
            click_pag19 = false;
        }

        if (pagina != PAG20)
        {
            click_pag20 = false;
        }

        if (pagina != PAG21)
        {
            click_pag21 = false;
        }

        if (pagina != PAG22)
        {
            click_pag22 = false;
        }

        if (pagina != PAG23)
        {
            click_pag23 = false;
        }

        if (pagina != PAG24)
        {
            click_pag24 = false;
        }

        if (pagina != PAG25)
        {
            click_pag25 = false;
        }

        if (pagina != PAG26)
        {
            click_pag26 = false;
        }

        if (pagina != PAG27)
        {
            click_pag27 = false;
        }

        EndDrawing ();
    }

    // liberar memoria
    UnloadMusicStream (c1);
    UnloadSound (c2);
    UnloadSound (c3);
    UnloadSound (c4);
    UnloadMusicStream (c5);
    UnloadMusicStream (c6);
    UnloadSound (c7);

    CloseAudioDevice ();
    CloseWindow();
    return 0;
}

/////////// FUNCION PARA CARGAR Y CONFIGURAR LAS IMAGENES ///////////
void cargar_texturas(void)
{
    ///// cargar la magen /////

    // fondos //
    Image fondo_pag1 = LoadImage ("IMGS_proyecto/Menu_Principal.png");  // fondo del menu principal
    Image fondo_pag2 = LoadImage ("IMGS_proyecto/Instrucciones.png"); // fondo de la pagina 2
    Image fondo_pag3 = LoadImage ("IMGS_proyecto/Listo.png"); // fondo de la pagina 3
    Image fondo_pag4 = LoadImage ("IMGS_proyecto/n3.png"); // fondo de la pagina 4
    Image fondo_pag5 = LoadImage ("IMGS_proyecto/n2.png"); // fondo de la pagina 5
    Image fondo_pag6 = LoadImage ("IMGS_proyecto/n1.png"); // fondo de la pagina 6
    Image fondo_pag7 = LoadImage ("IMGS_proyecto/Go.png"); // fondo de la pagina 7
    Image fondo_pag8_p1 = LoadImage ("IMGS_proyecto/p1.png"); // fondo de la pagina 8
    Image fondo_pag9_p2 = LoadImage ("IMGS_proyecto/p2.png"); // fondo de la pagina 9
    Image fondo_pag10_p3 = LoadImage ("IMGS_proyecto/p3.png"); // fondo de la pagina 10
    Image fondo_pag11_p4 = LoadImage ("IMGS_proyecto/p4.png"); // fondo de la pagina 11
    Image fondo_pag12_p5 = LoadImage ("IMGS_proyecto/p5.png"); // fondo de la pagina 12
    Image fondo_pag13_p6 = LoadImage ("IMGS_proyecto/p6.png"); // fondo de la pagina 13
    Image fondo_pag14_p7 = LoadImage ("IMGS_proyecto/p7.png"); // fondo de la pagina 14
    Image fondo_pag15_p8 = LoadImage ("IMGS_proyecto/p8.png"); // fondo de la pagina 15
    Image fondo_pag16_p9 = LoadImage ("IMGS_proyecto/p9.png"); // fondo de la pagina 16
    Image fondo_pag17_p10 = LoadImage ("IMGS_proyecto/p10.png"); // fondo de la pagina 17
    Image fondo_pag18_p11 = LoadImage ("IMGS_proyecto/p11.png"); // fondo de la pagina 18
    Image fondo_pag19_p12 = LoadImage ("IMGS_proyecto/p12.png"); // fondo de la pagina 19
    Image fondo_pag20_p13 = LoadImage ("IMGS_proyecto/p13.png"); // fondo de la pagina 20
    Image fondo_pag21_p14 = LoadImage ("IMGS_proyecto/p14.png"); // fondo de la pagina 21
    Image fondo_pag22_p15 = LoadImage ("IMGS_proyecto/p15.png"); // fondo de la pagina 22
    Image fondo_pag23_p16 = LoadImage ("IMGS_proyecto/p16.png"); // fondo de la pagina 23
    Image fondo_pag24_p17 = LoadImage ("IMGS_proyecto/p17.png"); // fondo de la pagina 24
    Image fondo_pag25_p18 = LoadImage ("IMGS_proyecto/p18.png"); // fondo de la pagina 25
    Image fondo_pag26_p19 = LoadImage ("IMGS_proyecto/p19.png"); // fondo de la pagina 27
    Image fondo_pag27_p20 = LoadImage ("IMGS_proyecto/p20.png"); // fondo de la pagina 27
    Image fondo_pag28 = LoadImage ("IMGS_proyecto/Aciertos.png"); // fondo de la pantalla de resultados (28)
    Image fondo_pag29 = LoadImage ("IMGS_proyecto/Gracias.png"); // fondo de la pantalla final (29) 

    // botones //
    Image salir = LoadImage ("IMGS_boton/B_fuera.png"); // boton para salir
    Image jugar = LoadImage ("IMGS_boton/B_jugar.png"); // boton para jugar
    Image regresar = LoadImage ("IMGS_boton/B_regresar.png"); // boton regresar
    Image continuar = LoadImage ("IMGS_boton/B_continuar.png"); // boton continuar
    Image seguro = LoadImage ("IMGS_proyecto/B_confir.png"); // boton para confirmar

    ///// redimensionar la imagen manualmente /////

    // fondos //
    ImageResize (&fondo_pag1, 990, 620); 
    ImageResize (&fondo_pag2, 990, 620);
    ImageResize (&fondo_pag3, 990, 620);
    ImageResize (&fondo_pag4, 990, 620);
    ImageResize (&fondo_pag5, 990, 620);
    ImageResize (&fondo_pag6, 990, 620);
    ImageResize (&fondo_pag7, 990, 620);
    ImageResize (&fondo_pag8_p1, 990, 620);
    ImageResize (&fondo_pag9_p2, 990, 620);
    ImageResize (&fondo_pag10_p3, 990, 620);
    ImageResize (&fondo_pag11_p4, 990, 620);
    ImageResize (&fondo_pag12_p5, 990, 620);
    ImageResize (&fondo_pag13_p6, 990, 620);
    ImageResize (&fondo_pag14_p7, 990, 620);
    ImageResize (&fondo_pag15_p8, 990, 620);
    ImageResize (&fondo_pag16_p9, 990, 620);
    ImageResize (&fondo_pag17_p10, 990, 620);
    ImageResize (&fondo_pag18_p11, 990, 620);
    ImageResize (&fondo_pag19_p12, 990, 620);
    ImageResize (&fondo_pag20_p13, 990, 620);
    ImageResize (&fondo_pag21_p14, 990, 620);
    ImageResize (&fondo_pag22_p15, 990, 620);
    ImageResize (&fondo_pag23_p16, 990, 620);
    ImageResize (&fondo_pag24_p17, 990, 620);
    ImageResize (&fondo_pag25_p18, 990, 620);
    ImageResize (&fondo_pag26_p19, 990, 620);
    ImageResize (&fondo_pag27_p20, 990, 620);
    ImageResize (&fondo_pag28, 990, 620);
    ImageResize (&fondo_pag29, 990, 620);

    // botones //
    ImageResize (&salir, 110, 100);
    ImageResize (&jugar, 340, 40);
    ImageResize (&regresar, 110, 50);
    ImageResize (&continuar, 240, 35);
    ImageResize (&seguro, 250, 200);

    ///// convertir la imagen redimensionada en textura ////

    // fondos //
    t_fondo_pag1 = LoadTextureFromImage(fondo_pag1); 
    t_fondo_pag2 = LoadTextureFromImage(fondo_pag2); 
    t_fondo_pag3 = LoadTextureFromImage(fondo_pag3);
    t_fondo_pag4 = LoadTextureFromImage (fondo_pag4);
    t_fondo_pag5 = LoadTextureFromImage (fondo_pag5);
    t_fondo_pag6 = LoadTextureFromImage (fondo_pag6);
    t_fondo_pag7 = LoadTextureFromImage (fondo_pag7);
    t_fondo_pag8_p1 = LoadTextureFromImage (fondo_pag8_p1);
    t_fondo_pag9_p2 = LoadTextureFromImage (fondo_pag9_p2);
    t_fondo_pag10_p3 = LoadTextureFromImage (fondo_pag10_p3);
    t_fondo_pag11_p4 = LoadTextureFromImage (fondo_pag11_p4);
    t_fondo_pag12_p5 = LoadTextureFromImage (fondo_pag12_p5);
    t_fondo_pag13_p6 = LoadTextureFromImage (fondo_pag13_p6);
    t_fondo_pag14_p7 = LoadTextureFromImage (fondo_pag14_p7);
    t_fondo_pag15_p8 = LoadTextureFromImage (fondo_pag15_p8);
    t_fondo_pag16_p9 = LoadTextureFromImage (fondo_pag16_p9);
    t_fondo_pag17_p10 = LoadTextureFromImage (fondo_pag17_p10);
    t_fondo_pag18_p11 = LoadTextureFromImage (fondo_pag18_p11);
    t_fondo_pag19_p12 = LoadTextureFromImage (fondo_pag19_p12);
    t_fondo_pag20_p13 = LoadTextureFromImage (fondo_pag20_p13);
    t_fondo_pag21_p14 = LoadTextureFromImage (fondo_pag21_p14);
    t_fondo_pag22_p15 = LoadTextureFromImage (fondo_pag22_p15);
    t_fondo_pag23_p16 = LoadTextureFromImage (fondo_pag23_p16);
    t_fondo_pag24_p17 = LoadTextureFromImage (fondo_pag24_p17);
    t_fondo_pag25_p18 = LoadTextureFromImage (fondo_pag25_p18);
    t_fondo_pag26_p19 = LoadTextureFromImage (fondo_pag26_p19);
    t_fondo_pag27_p20 = LoadTextureFromImage (fondo_pag27_p20);
    t_fondo_pag28 = LoadTextureFromImage (fondo_pag28);
    t_fondo_pag29 = LoadTextureFromImage (fondo_pag29);

    // botones //
    t_salir = LoadTextureFromImage (salir);
    t_jugar = LoadTextureFromImage (jugar);
    t_regresar = LoadTextureFromImage (regresar);
    t_continuar = LoadTextureFromImage (continuar);
    t_seguro = LoadTextureFromImage (seguro);

    ///// liberar memoria //////

    // fondos //
    UnloadImage(fondo_pag1); 
    UnloadImage(fondo_pag2); 
    UnloadImage (fondo_pag3);
    UnloadImage(fondo_pag4); 
    UnloadImage(fondo_pag5);
    UnloadImage(fondo_pag6);
    UnloadImage (fondo_pag7);
    UnloadImage (fondo_pag8_p1);
    UnloadImage (fondo_pag9_p2);
    UnloadImage (fondo_pag10_p3);
    UnloadImage (fondo_pag11_p4);
    UnloadImage (fondo_pag12_p5);
    UnloadImage (fondo_pag13_p6);
    UnloadImage (fondo_pag14_p7);
    UnloadImage (fondo_pag15_p8);
    UnloadImage (fondo_pag16_p9);
    UnloadImage (fondo_pag17_p10);
    UnloadImage (fondo_pag18_p11);
    UnloadImage (fondo_pag19_p12);
    UnloadImage (fondo_pag20_p13);
    UnloadImage (fondo_pag21_p14);
    UnloadImage (fondo_pag22_p15);
    UnloadImage (fondo_pag23_p16);
    UnloadImage (fondo_pag24_p17);
    UnloadImage (fondo_pag25_p18);
    UnloadImage (fondo_pag26_p19);
    UnloadImage (fondo_pag27_p20);
    UnloadImage (fondo_pag28);
    UnloadImage (fondo_pag29);

    // botones //
    UnloadImage (jugar);
    UnloadImage (salir);
    UnloadImage (regresar);
    UnloadImage (continuar);
    UnloadImage (seguro);

}

void mostrar_paginas(Pagina pagina)
{
    if (pagina == PAG1)
    {
        pagina1();
    }
    else if (pagina == PAG2)
    {
        pagina2();
    }
    else if (pagina == PAG3)
    {
        pagina3();
    }
    else if (pagina == PAG4)
    {
        pagina4 ();
    }
    else if (pagina == PAG5)
    {
        pagina5 ();
    }
    else if (pagina == PAG6)
    {
        pagina6 ();
    }
    else if (pagina == PAG7)
    {
        pagina7 ();
    }
    else if (pagina == PAG8)
    {
        pagina8 ();
    }
    else if (pagina == PAG9)
    {
        pagina9 ();
    }
    else if (pagina == PAG10)
    {
        pagina10 ();
    }
    else if (pagina == PAG11)
    {
        pagina11 ();
    }
    else if (pagina == PAG12)
    {
        pagina12 ();
    }
    else if (pagina == PAG13)
    {
        pagina13 ();
    }
    else if (pagina == PAG14)
    {
        pagina14 ();
    }
    else if (pagina == PAG15)
    {
        pagina15 ();
    }
    else if (pagina == PAG16)
    {
        pagina16 ();
    }
    else if (pagina == PAG17)
    {
        pagina17 ();
    }
    else if (pagina == PAG18)
    {
        pagina18 ();
    }
    else if (pagina == PAG19)
    {
        pagina19 ();
    }
    else if (pagina == PAG20)
    {
        pagina20 ();
    }
    else if (pagina == PAG21)
    {
        pagina21 ();
    }
    else if (pagina == PAG22)
    {
        pagina22 ();
    }
    else if (pagina == PAG23)
    {
        pagina23 ();
    }
    else if (pagina == PAG24)
    {
        pagina24 ();
    }
    else if (pagina == PAG25)
    {
        pagina25 ();
    }
    else if (pagina == PAG26)
    {
        pagina26 ();
    }
    else if (pagina == PAG27)
    {
        pagina27 ();
    }
    else if (pagina == PAG28)
    {
        pagina28 ();
    }
    else if (pagina == PAG29)
    {
        pagina29 ();
    }
}

void pagina1(void)
{
    DrawTexture(t_fondo_pag1, 4, 4, WHITE);
    DrawTexture(t_salir, 870, 15, WHITE); 
    DrawTexture(t_jugar, 320, 390, WHITE);
}

void pagina2(void)
{
    DrawTexture(t_fondo_pag2, 4, 4, WHITE);
    DrawTexture(t_regresar, 40, 30, WHITE); 
    DrawTexture(t_continuar, 368, 575, WHITE);
}

void pagina3 (void)
{
    DrawTexture (t_fondo_pag3, 4, 4, WHITE);
    DrawTexture (t_regresar, 40, 30, WHITE); 
    DrawTexture (t_continuar, 360, 445, WHITE);
}

void pagina4 (void)
{
    DrawTexture (t_fondo_pag4, 4, 4, WHITE);
}

void pagina5 (void)
{
    DrawTexture (t_fondo_pag5, 4, 4, WHITE);
}

void pagina6 (void)
{
    DrawTexture (t_fondo_pag6, 4, 4, WHITE);
}

void pagina7 (void)
{
    DrawTexture (t_fondo_pag7, 4, 4, WHITE);
}

void pagina8 (void)
{
    DrawTexture (t_fondo_pag8_p1, 4, 4, WHITE);
    char texto_tiempo[20];
    snprintf(texto_tiempo, 20, "%.2f", cronometro);
    DrawText(texto_tiempo, 840, 95, 35, BLACK);
}

void pagina9 (void)
{
    DrawTexture (t_fondo_pag9_p2, 4, 4, WHITE);
    char texto_tiempo[20];
    snprintf(texto_tiempo, 20, "%.2f", cronometro);
    DrawText(texto_tiempo, 840, 95, 35, BLACK);
}

void pagina10 (void)
{
    DrawTexture (t_fondo_pag10_p3, 4, 4, WHITE);
    char texto_tiempo[20];
    snprintf(texto_tiempo, 20, "%.2f", cronometro);
    DrawText(texto_tiempo, 840, 95, 35, BLACK);
}

void pagina11 (void)
{
    DrawTexture (t_fondo_pag11_p4, 4, 4, WHITE);
    char texto_tiempo[20];
    snprintf(texto_tiempo, 20, "%.2f", cronometro);
    DrawText(texto_tiempo, 840, 95, 35, BLACK);
}

void pagina12 (void)
{
    DrawTexture (t_fondo_pag12_p5, 4, 4, WHITE);
    char texto_tiempo[20];
    snprintf(texto_tiempo, 20, "%.2f", cronometro);
    DrawText(texto_tiempo, 840, 95, 35, BLACK);
}

void pagina13 (void)
{
    DrawTexture (t_fondo_pag13_p6, 4, 4, WHITE);
    char texto_tiempo[20];
    snprintf(texto_tiempo, 20, "%.2f", cronometro);
    DrawText(texto_tiempo, 840, 95, 35, BLACK);
}

void pagina14 (void)
{
    DrawTexture (t_fondo_pag14_p7, 4, 4, WHITE);
    char texto_tiempo[20];
    snprintf(texto_tiempo, 20, "%.2f", cronometro);
    DrawText(texto_tiempo, 840, 95, 35, BLACK);
}

void pagina15 (void)
{
    DrawTexture (t_fondo_pag15_p8, 4, 4, WHITE);
    char texto_tiempo[20];
    snprintf(texto_tiempo, 20, "%.2f", cronometro);
    DrawText(texto_tiempo, 840, 95, 35, BLACK);
}

void pagina16 (void)
{
    DrawTexture (t_fondo_pag16_p9, 4, 4, WHITE);
    char texto_tiempo[20];
    snprintf(texto_tiempo, 20, "%.2f", cronometro);
    DrawText(texto_tiempo, 840, 95, 35, BLACK);
}

void pagina17 (void)
{
    DrawTexture (t_fondo_pag17_p10, 4, 4, WHITE);
    char texto_tiempo[20];
    snprintf(texto_tiempo, 20, "%.2f", cronometro);
    DrawText(texto_tiempo, 840, 95, 35, BLACK);
}

void pagina18 (void)
{
    DrawTexture (t_fondo_pag18_p11, 4, 4, WHITE);
    char texto_tiempo[20];
    snprintf(texto_tiempo, 20, "%.2f", cronometro);
    DrawText(texto_tiempo, 840, 95, 35, BLACK);
}

void pagina19 (void)
{
    DrawTexture (t_fondo_pag19_p12, 4, 4, WHITE);
    char texto_tiempo[20];
    snprintf(texto_tiempo, 20, "%.2f", cronometro);
    DrawText(texto_tiempo, 840, 95, 35, BLACK);
}

void pagina20 (void)
{
    DrawTexture (t_fondo_pag20_p13, 4, 4, WHITE);
    char texto_tiempo[20];
    snprintf(texto_tiempo, 20, "%.2f", cronometro);
    DrawText(texto_tiempo, 840, 95, 35, BLACK);
}

void pagina21 (void)
{
    DrawTexture (t_fondo_pag21_p14, 4, 4, WHITE);
    char texto_tiempo[20];
    snprintf(texto_tiempo, 20, "%.2f", cronometro);
    DrawText(texto_tiempo, 840, 95, 35, BLACK);
}

void pagina22 (void)
{
    DrawTexture (t_fondo_pag22_p15, 4, 4, WHITE);
    char texto_tiempo[20];
    snprintf(texto_tiempo, 20, "%.2f", cronometro);
    DrawText(texto_tiempo, 840, 95, 35, BLACK);
}

void pagina23 (void)
{
    DrawTexture (t_fondo_pag23_p16, 4, 4, WHITE);
    char texto_tiempo[20];
    snprintf(texto_tiempo, 20, "%.2f", cronometro);
    DrawText(texto_tiempo, 840, 95, 35, BLACK);
}

void pagina24 (void)
{
    DrawTexture (t_fondo_pag24_p17, 4, 4, WHITE);
    char texto_tiempo[20];
    snprintf(texto_tiempo, 20, "%.2f", cronometro);
    DrawText(texto_tiempo, 840, 95, 35, BLACK);
}

void pagina25 (void)
{
    DrawTexture (t_fondo_pag25_p18, 4, 4, WHITE);
    char texto_tiempo[20];
    snprintf(texto_tiempo, 20, "%.2f", cronometro);
    DrawText(texto_tiempo, 840, 95, 35, BLACK);
}

void pagina26 (void)
{
    DrawTexture (t_fondo_pag26_p19, 4, 4, WHITE);
    char texto_tiempo[20];
    snprintf(texto_tiempo, 20, "%.2f", cronometro);
    DrawText(texto_tiempo, 840, 95, 35, BLACK);
}

void pagina27 (void)
{
    DrawTexture (t_fondo_pag27_p20, 4, 4, WHITE);
    char texto_tiempo[20];
    snprintf(texto_tiempo, 20, "%.2f", cronometro);
    DrawText(texto_tiempo, 840, 95, 35, BLACK);
}

void pagina28 (void)
{
    DrawTexture (t_fondo_pag28, 4, 4, WHITE);
}

void pagina29 (void)
{
    DrawTexture (t_fondo_pag29, 4, 4, WHITE);
    cronometro = 0.0f;
}

void n_aciertos (int puntaje)
{
    char aciertos [20];
    sprintf(aciertos, "%d", puntaje); // convertir el valor entero a caracter

    DrawText(aciertos, 256, 250, 65, BLACK); // texto en pantalla (aciertos)
}