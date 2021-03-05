#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
using namespace std;

struct Player
{   
    int x,y;  
    char nome;
    int life;
    int golpe;
};

Player inimigo[5];
Player jogador;
int cont =0;

char mapa[10][10];

void Ini(){
    srand(time(0));
    for(int i = 0;i<10;i++){
        for(int j = 0; j< 10; j++){
            mapa[i][j]='.';
        }
        
    }
    for(int i = 0; i<5;i++){
        inimigo[i].x=rand() %10;
        inimigo[i].y=rand() %10;
        inimigo[i].life= 100;
        inimigo[i].nome = 'I';
    }

    jogador.x = rand() %10;
    jogador.y = rand() %10;
    jogador.nome = 'P'; 
    jogador.life= 100;

    
}

void menu(){
    int x=0;
    char tecla;
    while (x==0)
    {
        cout <<"-------- INSTRUCOES ---------" << endl;
        cout << "1- Aperte as setas do teclado para movimentar o personagem" << endl;
        cout << "2- Ao ficar em frente do inimgo voce vai ter 2 opcoes Atacar/Defender" <<endl;
        cout << "3- Ao atacar voce tira 20 a 50 de vida do inimigo" << endl;
        cout << "4- Ao defender voce recupera 50 de vida" << endl;
        cout << "5- so pode recuperar a vida se tiver com menos de 60" << endl;
        cout << "6- Inimigos podem te atacar tirando ate 40 de vida" << endl;
        cout << "-----------------------------" << endl;
        cout << "Pressione ESPACO para continuar" << endl;
        tecla=getch();

        if(tecla == 32){
            x=1;
            return;
        }
    }
        
}
void AtualizarMapa(){
    system("cls");
    
    mapa[jogador.x][jogador.y]=jogador.nome;
    for(int i = 0;i<10;i++){
            for(int j = 0; j< 10; j++){
                cout << mapa[i][j] << " ";
            }
             cout << endl; 
        }
}

void Perdeu(){
    system("cls");
    cout << "Voce Perdeu" << endl;
    system("pause");
    exit(0);
     
}
int Fight(int vida2){
    int x=0;
    int tecla;
    int golpe;
    int golpe2;
    while(x==0){
        system("cls");
        AtualizarMapa();
        cout << "Faca sua acao" << endl; 
        cout << "E-Attack           Q-Defender" << endl;
        
        tecla= getch();
        switch (tecla)
        {
        case 101:
            golpe = 20 + rand()%(50 -20);
            cout <<"Voce deu " << golpe << " de dano" << endl;
            golpe2 = 10 + rand()%(40-10);
            vida2 = vida2 - golpe;
            jogador.life = jogador.life - golpe2;
            cout << "O inimigo deu " << golpe2 << " de dano" << endl;
            cout << "Vida do inimigo " << vida2 << endl;
            cout << "Sua vida " << jogador.life << endl;
            if (vida2 <= 0){ 
                cont ++;// contador de morte de enimigos
                return(vida2);
                x=1;
                
            }
            if (jogador.life <=0){ 
                Perdeu();
            }
            system("pause");
            break;
        case 113:
            if(jogador.life <60){
                jogador.life=jogador.life + 50;
                cout << "Voce Recupreou 50 de HP" << endl;
                system("pause"); 
            }
            break;
        default:
            break;
        }
        
    }   
    
     
            

}

void Fim(){ // Acaba o game
    system("cls");
    cout << "PARABENS VC COMPLETOU O JOGO TUTS TUTS" << endl;
    system("pause");
    exit(0);
}
void Moviment(){
    int tecla;
    cout << "Faca Sua Acao" << endl;
    tecla =_getch();
        if(tecla == 0 ||tecla == 224){
        switch (getch())
    {
        case 72:// para cima
            mapa[jogador.x][jogador.y]='.';
            jogador.x = jogador.x -1;
            break;
        case 80:// para baixo
            mapa[jogador.x][jogador.y]='.';
            jogador.x = jogador.x +1;
            
            break;
        case 75:// para esquerda
            mapa[jogador.x][jogador.y]='.';
            jogador.y = jogador.y -1;
            
            break;
        case 77:// para direita
            mapa[jogador.x][jogador.y]='.';
            jogador.y = jogador.y +1;
               
        default:
            break;
    }
        for(int i=0;i<5;i++){
           if(jogador.x == inimigo[i].x -1 && jogador.y == inimigo[i].y){
                AtualizarMapa(); // uma funcao para ficar atualizando o mapa sem usar o return
                inimigo[i].life= Fight(inimigo[i].life);
                system("pause");
                 
                if(inimigo[i].life == 0){
                    
                    return; // retorna para o exir mapa para atualizar o mapa sem o inimigo que morreu
                    
                }
            }
            if (jogador.x == inimigo[i].x +1 && jogador.y == inimigo[i].y){
                AtualizarMapa(); // uma funcao para ficar atualizando o mapa sem usar o return
                inimigo[i].life= Fight(inimigo[i].life);
                system("pause");
                
                 
                if(inimigo[i].life == 0){
                    
                    return; // retorna para o exir mapa para atualizar o mapa sem o inimigo que morreu
                    
                }
            }
            if (jogador.x == inimigo[i].x && jogador.y == inimigo[i].y -1){
                AtualizarMapa();
                inimigo[i].life= Fight(inimigo[i].life);
                system("pause");
                if(inimigo[i].life == 0){
                    
                    return;
                    
                }
            }
            if (jogador.x == inimigo[i].x && jogador.y == inimigo[i].y +1){
                AtualizarMapa(); // uma funcao para ficar atualizando o mapa sem usar o return
                inimigo[i].life= Fight(inimigo[i].life);
                system("pause");
                if(inimigo[i].life == 0){
                    
                    return;
                    
                }
            }
            
        }
        if(cont ==5){
            Fim();
        }
    }
     
}




void ExibirMapa(){
    int tecla;
    int x=0;
    while(x==0){
       mapa[jogador.x][jogador.y]=jogador.nome;
        system("cls");
        for(int i = 0;i<5;i++){
            if(inimigo[i].life <= 0){
                
                mapa[inimigo[i].x][inimigo[i].y]='.';
                inimigo[i].x = 30;
                inimigo[i].y = 30;
               
               
            }
            mapa[inimigo[i].x][inimigo[i].y]=inimigo[i].nome;
        }
        for(int i = 0;i<10;i++){
            for(int j = 0; j< 10; j++){
                cout << mapa[i][j] << " ";
            }
             cout << endl; 
        }
        Moviment();
        
    } 
}


int main()
{
    
    
    Ini();
    menu();
    ExibirMapa();
    

    system("pause");
    return 0;
}