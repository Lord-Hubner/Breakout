
//------------------------------------------------------------------------------------
// Bibliotecas e constantes
//------------------------------------------------------------------------------------

#include "raylib.h"
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define NUM_HIGHSCORES 5


//------------------------------------------------------------------------------------
// Estruturas
//------------------------------------------------------------------------------------

typedef struct tijolo{
    int x;
    int y;
    int largura;
    int altura;
    char cor;
    int flag;
    
} TIJOLO;

typedef struct jogador{
    char nome[40]; 
    int pontos; 
    tijolo raquete; 
} JOGADOR;

typedef struct bola{
    int x; 
    int y; 
    int velx; 
    int vely; 
    int raio;
    int cor;    
} BOLA;

typedef struct tipo_score{
    char nome[40];
    int score;
}TIPO_SCORE;

//é utilizada ainda a estrutura Vector2 do Raylib para as coordenadas da raquete



int retorna_menor_score (TIPO_SCORE highscores[]){
    int menor_valor = 1000, i = 0;

for(i=0;i<5;i++){
        if(highscores[i].score < menor_valor){
        menor_valor = highscores[i].score ;
        }
}
return menor_valor;
}


int retorna_j_menor_score (TIPO_SCORE highscores[]){
    int menor_valor = 1000, i = 0, j = 0;

for(i=0;i<5;i++){
        if(highscores[i].score < menor_valor){
        j = i;
        }
}
return j;
}



void atualiza_highscores(TIPO_SCORE highscores[NUM_HIGHSCORES], TIPO_SCORE gamer){
 int j;
 
 


    if  (gamer.score > highscores[0].score){
            highscores[4].score = highscores[3].score;
            strcpy(highscores[4].nome, highscores[3].nome);
            highscores[3].score = highscores[2].score;
            strcpy(highscores[3].nome, highscores[2].nome);
            highscores[2].score = highscores[1].score;
            strcpy(highscores[2].nome, highscores[1].nome);
            highscores[1].score = highscores[0].score;
            strcpy(highscores[1].nome, highscores[0].nome);
            highscores[0].score = gamer.score;
            strcpy(highscores[0].nome, gamer.nome);
        printf("\no valor atualizado e %d\n", gamer.score);
    }
    else if(gamer.score > highscores[1].score){
            highscores[4].score = highscores[3].score;
            strcpy(highscores[4].nome, highscores[3].nome);
            highscores[3].score = highscores[2].score;
            strcpy(highscores[3].nome, highscores[2].nome);
            highscores[2].score = highscores[1].score;
            strcpy(highscores[2].nome, highscores[1].nome);
            highscores[1].score = gamer.score;
            strcpy(highscores[1].nome, gamer.nome);
            printf("\no valor atualizado e %d\n", gamer.score);
    }

    else if(gamer.score > highscores[2].score){
            highscores[4].score = highscores[3].score;
            strcpy(highscores[4].nome, highscores[3].nome);
            highscores[3].score = highscores[2].score;
            strcpy(highscores[3].nome, highscores[2].nome);
            highscores[2].score = gamer.score;
            strcpy(highscores[2].nome, gamer.nome);
            printf("\no valor atualizado e %d\n", gamer.score);
    }
    else if(gamer.score > highscores[3].score){
            highscores[4].score = highscores[3].score;
            strcpy(highscores[4].nome, highscores[3].nome);
            highscores[3].score = gamer.score;
            strcpy(highscores[3].nome, gamer.nome);
            printf("\no valor atualizado e %d\n", gamer.score);
    }
    else if(gamer.score > highscores[4].score){
            highscores[3].score = gamer.score;
            strcpy(highscores[3].nome, gamer.nome);
            printf("\no valor atualizado e %d\n", gamer.score);
    }

    else printf("nenhum valor foi atualizado\n");

}


TIPO_SCORE le_score(char jogador[],int pontuacao){
    TIPO_SCORE gamer;

    strcpy(gamer.nome, jogador);
    gamer.score = pontuacao;

    return gamer;
}

void faz_bola (BOLA bola){
 //Desenha a bola na sua coordenada e faz ela se movimentar de acordo com as suas velocidades


    DrawCircle(bola.x, bola.y, bola.raio, BLUE);
    
    bola.x += bola.velx;
    bola.y += bola.vely;
    
}

void checa_vidas(int vidas, BOLA bola){
    if (bola.y > 400)
    // Caso a bola passe do vetor y da raquete
    {
        vidas -= 1; // perde uma vida
        bola.x = 375; //reseta as coordenadas da bola
        bola.y = 250;
      //  bball->velx = 5; // reseta a velocidade da bola
      //  bball->vely = -5;
    }
}

void desenha_tijolo (TIJOLO (*bricks)[10])
// função que, a partir da cor da estrutura do tijolo, desenha um tijolo na tela
// se a flag do tijolo for diferente de 1 a partir da cor
{
    int i,j;
    for (i=0;i<5;i++)
        {
             for (j=0;j<10;j++)
                {
                    if (bricks[i][j].flag != 1)
                        {
                            switch (toupper(bricks[i][j].cor))
                            {
                                case 'R': DrawRectangle(bricks[i][j].x, bricks[i][j].y, bricks[i][j].largura, bricks[i][j].altura, RED);
                                            break;
                                case 'G': DrawRectangle(bricks[i][j].x, bricks[i][j].y, bricks[i][j].largura, bricks[i][j].altura, GREEN);
                                            break;
                                case 'B': DrawRectangle(bricks[i][j].x, bricks[i][j].y, bricks[i][j].largura, bricks[i][j].altura, BLUE);
                                            break;
                                case 'Y': DrawRectangle(bricks[i][j].x, bricks[i][j].y, bricks[i][j].largura, bricks[i][j].altura, YELLOW);
                                            break;
                                case 'X': DrawRectangle(bricks[i][j].x, bricks[i][j].y, bricks[i][j].largura, bricks[i][j].altura, PURPLE);
                                            break;
                            }
                        }
                }
        }
}



void set_tijolo (TIJOLO (*bricks)[10])
// Define as coordenadas dos tijolos
{
    int i,j;
        for (i=0;i<5;i++)
    {
        for (j=0;j<10;j++)
        {
            bricks[i][j].largura= 65;
            bricks[i][j].altura= 10;
        }
    }
    for (i=0;i<5;i++)
    {
            for (j=0;j<10;j++)
            {
            if (i==0)
            {
                bricks[i][j].y = 20;
                if (j==0)
                {
                    bricks[i][j].x = 20;
                }else
                {
                    bricks[i][j].x = bricks[i][j-1].x + bricks[i][j].largura + 8;
                }

            }
            if (i != 0)
            {
                    bricks[i][j].y = bricks[i-1][j].y + bricks[i][j].altura + 8;
                    if (j == 0)
                    {
                        bricks[i][j].x = 20;
                    }else                {
                        bricks[i][j].x = bricks[i][j-1].x + bricks[i][j].largura + 8;
                }
            }
        }
    }
}

int nivel (int nivel, TIJOLO bricks[5][10]){
    char c, *token;
    int i=0, j=0, blocos=0;
    FILE *level;

    switch (nivel)
    {
    case 1:
        level = fopen("nivel1.txt", "r");
        break;
    case 2:
        level = fopen("nivel2.txt", "r");
        break;
    }
    if (level == NULL){
        printf("ERRO!\n");
    }

    for(i=0;i<5;i++){
        for(j=0;j<10;j++){
            do{
                c = fgetc(level);
                bricks[i][j].cor = c;
            }while(c == '\n');
        }
    }
    fclose(level);
    return blocos;
}


int main()
{
    // Inicialização
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;      
    int menor_valor, i, j, pontuacao;
    int vidas = 5;
    FILE *arq;
    int op = 0; // operador para entrar em cada opção do jogo
    bool acessa = false; //Booleano indicando se entra no jogo em si ou não
                    
    
    
    //definição estruturas
    TIJOLO raquete = {100, 15, 350, 400, 'R', 0}; //raquete para rebater a bola
    TIJOLO bricks[5][10]; //tijolos que compoem a parte superior da tela
    JOGADOR jogador = {"placeholder", 0, raquete}; //jogador, tem o nome inserido pelo próprio jogador
    TIPO_SCORE highscores[5] = { {"Super Mario", 450}, {"Zelda", 400}, {"Ratchet", 380},{"Snake", 350}, {"Duke Nukem", 300}}; //highscores prévios
    BOLA bola = {375, 250, 3, 3, 5, 'B'}; //bola do jogo
    Vector2 raq = { (float)350, (float)400 }; //vetor da raquete
    arq = fopen("highscores.bin", "rb");
    fclose(arq);
    nivel(1,bricks);
    
 

    InitWindow(screenWidth, screenHeight, "BreakoutINF");
       
    SetTargetFPS(60);             

    // Loop principal do jogo
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
       
        
        if (IsKeyPressed(KEY_DOWN))
            {
                op++;
                
            }
        else if (IsKeyPressed(KEY_UP))
            {
                op--;
            }
        if (IsKeyPressed(KEY_ENTER))
            {
                acessa = true;
            }
        if (IsKeyPressed(KEY_BACKSPACE))
            {
                acessa = false;
            }
            
            
        
        BeginDrawing();
            ClearBackground(BLACK);
            if (acessa == false)
            DrawText("BREAKOUT\n    INF", 310, 80, 40, GOLD);
            
            if ((op % 4) == 0 && acessa == false)
                DrawText( "1.Novo jogo", 320 , 250, 30,  DARKBLUE);
                
            if ((op % 4) == 0 && acessa == true)
            {
                    
                
                DrawText(TextFormat("Vidas:%d", vidas), 710, 400, 20, RED);
                DrawText(TextFormat("Pontos:%d", jogador.pontos), 10, 400, 20, GOLD);
                desenha_tijolo (bricks);
                set_tijolo(bricks);
                        
                        
                faz_bola(bola);
                bola.x += bola.velx;
                bola.y += bola.vely;
                        
                        //Colisão em X
                if (bola.x + bola.raio >= GetScreenWidth() || bola.x < 0)
                    bola.velx *= -1; // inverte a velocidade y
                //Colisão em Y
                if (bola.y <= 0)
                    bola.vely *= -1;  // inverte a velocidade y
                //Colisão com a raquete do jogador
                if (((bola.x + bola.raio) > (raq.x)) &&
                    ((bola.x + bola.raio) < (raq.x + (jogador.raquete.largura / 4))) &&
                    ((bola.y + bola.raio) > (raq.y)))
                {
                    bola.vely *= -1;  // inverte a velocidade y
                    }
                //Colisão com os tijolos e aumenta os pontos caso tocar em um tijolo;
                for (i=0;i<5;i++)
                {
                    for (j=0;j<10;j++)
                    {
                        if (bricks[i][j].flag != 1)
                            
                            if ((bola.x < (bricks[i][j].x + bricks[i][j].largura)) &&
                            ((bola.x + bola.raio) > bricks[i][j].x) &&
                            (bola.y < bricks[i][j].y + bricks[i][j].altura) &&
                            ((bola.y + bola.raio) > (bricks[i][j].y)))
                            {
                                bola.vely *= -1;  // inverte a velocidade y
                                bricks[i][j].flag = 1;  // acende a flag de destruição
                                jogador.pontos += 20;  // aumenta a quantia de pontos do jogador
                            }
                    }
                }
                if (bola.y > screenHeight)
                // Caso a bola passe da raquete
                {
                    vidas -= 1; 
                    bola.x = 350; //reseta as coordenadas da bola
                    bola.y = 225;
                    bola.velx = 3; // reseta a velocidade da bola
                    bola.vely = 3;
                }
                        
                        
                        DrawRectangle(raq.x, raq.y, 100, 15, RED);
                        
                        //Mover a raquete
                        if (IsKeyDown(KEY_RIGHT) || IsKeyDown (KEY_D))
                        
                        // Se não passar do tamanho da tela à direita, move nessa direção
                        if ((raq.x + (raquete.largura / 4)  ) >= GetScreenWidth())
                            raq.x = GetScreenWidth() - (raquete.largura / 4);
                        else raq.x += 10.0f;
                        
                        if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
                        // Se não passar do tamanho da tela à esquerda, move nessa direção
                            if (raq.x <= 0)
                                raq.x = 0;
                            else raq.x -= 10.0f;
                            
                        checa_vidas(vidas, bola);
                        
                        if (vidas == 0)
                        {
                            menor_valor = retorna_menor_score(highscores);
                            j = retorna_j_menor_score(highscores);
                            
                            TIPO_SCORE gamer;
                            strcpy(gamer.nome, jogador.nome);
                            gamer.score = jogador.pontos;
                            atualiza_highscores(highscores, gamer);
                            return 0;
                        }
                         
            }
            
            
            if ((op % 4) == 1 && acessa == false)
                DrawText( "2.Carregar jogo", 320 , 250, 30, DARKBLUE);
            if ((op % 4) == 1 && acessa == true)
                return 0;
            
            
            if ((op % 4) == 2 && acessa == false)   
                DrawText( "3.Highscores", 320, 250, 30, DARKBLUE);
            if ((op % 4) == 2 && acessa == true)
            {
                DrawText("lista dos highscores:", 250, 100, 40, GOLD);
                DrawText(TextFormat("%s            %d", highscores[0].nome, highscores[0].score), 280, 160, 20, DARKGRAY);
                DrawText(TextFormat("%s            %d", highscores[1].nome, highscores[1].score), 280, 200, 20, DARKGRAY);
                DrawText(TextFormat("%s            %d", highscores[2].nome, highscores[2].score), 280, 240, 20, DARKGRAY);
                DrawText(TextFormat("%s            %d", highscores[3].nome, highscores[3].score), 280, 280, 20, DARKGRAY);
                DrawText(TextFormat("%s            %d", highscores[4].nome, highscores[4].score), 280, 320, 20, DARKGRAY);
            }
            if ((op % 4) == 3 && acessa == false)
                DrawText( "4.Sair :(", 320, 250, 30, DARKBLUE);
            
            if ((op % 4) == 3 && acessa == true)
                return 0;
                
                
        EndDrawing();
 
    }


    CloseWindow();        
    return 0;
}