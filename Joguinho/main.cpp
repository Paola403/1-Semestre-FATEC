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

    cout << "Voc� tem " << maxTentativas << " tentativas para adivinhar o n�mero!" << endl;


    for (int i = 0; i < maxTentativas; i++) {
        cout << "Tentativa " << (i + 1) << "/" << maxTentativas << ": ";
        cin >> numeroEscolhido;

        if (numeroEscolhido < numeroAleatorio) {
            cout << "O n�mero � maior!" << endl;
        } else if (numeroEscolhido > numeroAleatorio) {
            cout << "O n�mero � menor!" << endl;
        } else {
            cout << "Parab�ns! Voc� acertou o n�mero!" << endl;
            credito += 10;
            return;
        }

        credito -= 2;
    }

    cout << "Voc� n�o conseguiu acertar o n�mero. O n�mero era " << numeroAleatorio << endl;
}

void menu() {
    int credito = 10;
    int opcao = 0;
    int dificuldade = 0;

    while (true) {
        cout << "\n***** MENU *****\n";
        cout << "1. Jogar\n";
        cout << "2. Consultar cr�ditos\n";
        cout << "3. Adicionar cr�dito manualmente\n";
        cout << "4. Sair\n";
        cout << "Escolha uma op��o: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                if (credito <= 0) {
                    cout << "Voc� n�o tem cr�ditos suficientes para jogar.\n";
                } else {
                    cout << "Escolha o n�vel de dificuldade:\n";
                    cout << "1. F�cil (10 tentativas)\n";
                    cout << "2. M�dio (7 tentativas)\n";
                    cout << "3. Dif�cil (5 tentativas)\n";
                    cout << "Escolha: ";
                    cin >> dificuldade;
                    if (dificuldade < 1 || dificuldade > 3) {
                        cout << "Op��o inv�lida! Tentando novamente...\n";
                    } else {
                        jogar(dificuldade, credito);
                    }
                }
                break;

            case 2:
                cout << "Cr�ditos dispon�veis: " << credito << endl;
                break;

            case 3:
                int valorAdicional;
                cout << "Digite o valor que deseja adicionar aos cr�ditos: ";
                cin >> valorAdicional;
                if (valorAdicional > 0) {
                    credito += valorAdicional;
                    cout << "Cr�ditos adicionados! Total de cr�ditos: " << credito << endl;
                } else {
                    cout << "Valor inv�lido! Adicione um valor positivo.\n";
                }
                break;

            case 4:
                cout << "Saindo do jogo...\n";
                return;

            default:
                cout << "Op��o inv�lida! Tente novamente.\n";
                break;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    menu();
    return 0;
}

