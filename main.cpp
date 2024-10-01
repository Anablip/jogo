#include <iostrem>
#include <string>
#include <cstdlib>
#include <time>

 using namespace std;
 
 struct tamagotchi {
     string nome;
     int fome;
     int felicidade;
     int energia;
 }
 
 tamagotchi  criartamagotchi(string nome){
     tamagotchi bichinho
     bichinho.nome = nome;
     bichinho.fome = 0;
     bichinho.felicidade = 100;
     bichinho.energia = 100;
     return bichinho;
 }
 void mostraropcoes(){
     cout << "Escolha o seu bichinho virtual:"<< endl;
     cout << "1.Gato:"<< endl;
     cout << " /\_/\\"<< endl;
     cout << "( o.o )"<< endl;
     cout << " > ^ <"<< endl;
     cout << "2.cachorro"<< endl;
     cout << " /\_/\\"<< endl;
     cout << " \o.o/\\"<< endl;
     cout << "  \_/  "<< endl;
     cout << "3. Coelho "<< endl;
     cout << " (\_/) "<< endl;
     cout << " (o.o) "<< endl;
     cout << " (> <) "<< endl;
 }
 int escolhabichinho(){
     int escolha;
     mostraropcoes();
     cin >> escolha;
     return escolha;
 }void alimentar(Tamagotchi &bichinho) {
    if (bichinho.fome > 0) {
        bichinho.fome -= 20;
        if (bichinho.fome < 0) bichinho.fome = 0;
        cout << bichinho.nome << " foi alimentado e está com menos fome!" << endl;
    } else {
        cout << bichinho.nome << " não está com fome agora." << endl;
    }
}void brincar(Tamagotchi &bichinho) {
    if (bichinho.felicidade < 100 && bichinho.energia > 10) {
        bichinho.felicidade += 20;
        bichinho.energia -= 10;
        cout << bichinho.nome << " se divertiu bastante!" << endl;
    } else if (bichinho.energia <= 10) {
        cout << bichinho.nome << " está cansado e precisa descansar antes de brincar." << endl;
    } else {
        cout << bichinho.nome << " já está muito feliz!" << endl;
    }
}void descansar(Tamagotchi &bichinho) {
    bichinho.energia += 30;
    if (bichinho.energia > 100) bichinho.energia = 100;
    cout << bichinho.nome << " tirou uma soneca e está mais descansado!" << endl;
}
void atualizarEstado(Tamagotchi &bichinho) {
    // A fome aumenta com o tempo
    bichinho.fome += 10;
    if (bichinho.fome > 100) bichinho.fome = 100;

    // A energia diminui lentamente, a menos que esteja descansando
    bichinho.energia -= 5;
    if (bichinho.energia < 0) bichinho.energia = 0;
}
int main() {
    srand(time(0)); // Inicializando o sistema randômico

    string nome;
    cout << "Digite o nome do seu bichinho: ";
    cin >> nome;

    // Cria o Tamagotchi com o nome fornecido
    Tamagotchi meuBichinho = criarTamagotchi(nome);

    int escolha = escolherBichinho();
    cout << "Você escolheu o bichinho número " << escolha << endl;

    int acao;
    do {
        atualizarEstado(meuBichinho);

        cout << "\\nO que você quer fazer com " << meuBichinho.nome << "?" << endl;
        cout << "1. Alimentar" << endl;
        cout << "2. Brincar" << endl;
        cout << "3. Descansar" << endl;
        cout << "4. Sair do jogo" << endl;
        cin >> acao;

        switch (acao) {
            case 1:
                alimentar(meuBichinho);
                break;
            case 2:
                brincar(meuBichinho);
                break;
            case 3:
                descansar(meuBichinho);
                break;
            case 4:
                cout << "Até a próxima!" << endl;
                break;
            default:
                cout << "Escolha inválida!" << endl;
        }

        // Exibe o estado atual do Tamagotchi
        cout << "\\nEstado atual do " << meuBichinho.nome << ":" << endl;
        cout << "Fome: " << meuBichinho.fome << endl;
        cout << "Felicidade: " << meuBichinho.felicidade << endl;
        cout << "Energia: " << meuBichinho.energia << endl;

    } while (acao != 4);

    return 0;
}



     