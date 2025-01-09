Nomes: André e Náthali

//------------------------------------------------------------------------------------
// Estruturas utilizadas
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

//estruturas do Raylib
typedef struct Vector2  {
    int x;
    int y;
}VECTOR2;



Explicação:
O menu inicial não mostra todas as opções de primeira, apertando up ou down aparece cada opção. Pressione enter para acessar a desejada.
A raquete é contralada para a direita por A o seta direita, e para a esquerda por A ou seta esquerda.
As ordens das opções estão como exigidas, porem não conseguimos implementar a funcionalidade de carregar um jogo salvo.
Usamos o nível que tava no Moodle como nível1, mas não têm nível2.
O ranking mostra o ranking que foi utilizado nas práticas