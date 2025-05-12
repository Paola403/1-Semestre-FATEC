#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale>

using namespace std;



void jogar(int dificuldade, int &credito) {
    int maxTentativas = 0;
    int numeroAleatorio = 0;
    int tentativa = 0;
    int numeroEscolhido = 0;

    switch (dificuldade) {
        case 1:
            maxTentativas = 10;
            break;
        case 2:
            maxTentativas = 7;
            break;
        case 3:
            maxTentativas = 5;
            break;
    }


    srand(time(0));
    numeroAleatorio = rand() % 100 + 1;

    cout << "Você tem " << maxTentativas << " tentativas para adivinhar o número!" << endl;


    for (int i = 0; i < maxTentativas; i++) {
        cout << "Tentativa " << (i + 1) << "/" << maxTentativas << ": ";
        cin >> numeroEscolhido;

        if (numeroEscolhido < numeroAleatorio) {
            cout << "O número é maior!" << endl;
        } else if (numeroEscolhido > numeroAleatorio) {
            cout << "O número é menor!" << endl;
        } else {
            cout << "Parabéns! Você acertou o número!" << endl;
            credito += 10;
            return;
        }

        credito -= 2;
    }

    cout << "Você não conseguiu acertar o número. O número era " << numeroAleatorio << endl;
}

void menu() {
    int credito = 10;
    int opcao = 0;
    int dificuldade = 0;

    while (true) {
        cout << "\n***** MENU *****\n";
        cout << "1. Jogar\n";
        cout << "2. Consultar créditos\n";
        cout << "3. Adicionar crédito manualmente\n";
        cout << "4. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                if (credito <= 0) {
                    cout << "Você não tem créditos suficientes para jogar.\n";
                } else {
                    cout << "Escolha o nível de dificuldade:\n";
                    cout << "1. Fácil (10 tentativas)\n";
                    cout << "2. Médio (7 tentativas)\n";
                    cout << "3. Difícil (5 tentativas)\n";
                    cout << "Escolha: ";
                    cin >> dificuldade;
                    if (dificuldade < 1 || dificuldade > 3) {
                        cout << "Opção inválida! Tentando novamente...\n";
                    } else {
                        jogar(dificuldade, credito);
                    }
                }
                break;

            case 2:
                cout << "Créditos disponíveis: " << credito << endl;
                break;

            case 3:
                int valorAdicional;
                cout << "Digite o valor que deseja adicionar aos créditos: ";
                cin >> valorAdicional;
                if (valorAdicional > 0) {
                    credito += valorAdicional;
                    cout << "Créditos adicionados! Total de créditos: " << credito << endl;
                } else {
                    cout << "Valor inválido! Adicione um valor positivo.\n";
                }
                break;

            case 4:
                cout << "Saindo do jogo...\n";
                return;

            default:
                cout << "Opção inválida! Tente novamente.\n";
                break;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    menu();
    return 0;
}

