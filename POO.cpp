#include <iostream>
#include "System.hpp"

using namespace std;

class Menu {
    private:
        int op;
    public:
        void menu(){
            System::clean_console();

            cout<< "*         MENU          *" <<endl;
            cout<< "* [1] Insere no inicio  *" <<endl;
            cout<< "* [2] Insere no fim     *" <<endl;
            cout<< "* [3] Remove            *" <<endl;
            cout<< "* [4] Imprimir          *" <<endl;
            cout<< "* [5] Alterar           *" <<endl;
            cout<< "* [6] Ordenar           *" <<endl;
            cout<< "* [7] Limpar tela       *" <<endl;
            cout<< "* [0] Sair              *\n>>" <<endl;
            cin >> op;
        }
        void menu(int n){
        	System::clean_console();
        	cout<< "*         MENU          *" <<endl;
            cout<< "* [1] Insere            *" <<endl;
            cout<< "* [2] Remove            *" <<endl;
            cout<< "* [3] Imprimir          *" <<endl;
            cout<< "* [4] Alterar           *" <<endl;
            cout<< "* [5] Limpar tela       *" <<endl;
            cout<< "* [0] Sair              *\n>>" <<endl;
            cin >> op;
            switch(op){
        		case 2: op = 3; return;
				case 3: op = 4; return;
				case 4: op = 5; return;
				case 5: op = 7; return;	
			}
		}
        int getOp(){
            return op;
        }
};

class No{
    public:
        int id, value;
        No * next;
        No(){
            id = 0;
            value = 0;
            next = NULL;
        }
        No(int i, int v){
            id = i;
            value = v;
        }
};

class Lista{
    private:
        No * head;
    public:
        Lista(){
            head = NULL;
        }
        Lista(No *n){
            head = n;
        }
        No * noExiste(int i){
            No * aux = NULL;
            No * ptr = head;
            while(ptr != NULL){
                if(ptr->id == i){
                    aux = ptr;
                }
                ptr = ptr->next;
            } 
            return aux;
        }
        void insereFim(No * n){
            if(noExiste(n->id) != NULL){
                cout <<"FALHA AO CRIAR NÓ \n NÓ JÁ EXISTENTE !"<< endl;
            }else{
                if(head == NULL){
                    head = n;
                    cout <<"Inserido com sucesso !"<<endl;
                }else{
                    No * ptr = head;
                    while(ptr->next != NULL){
                        ptr = ptr->next;
                    }
                    ptr->next = n;
                    cout <<"Inserido com sucesso !" <<endl;
                }
            }
            system("PAUSE");
        }
        void insereInicio(No * n){
            if(noExiste(n->id) != NULL){
                cout <<"Falha ao criar novo No : No já existe !" << endl;
            }else{
                n->next = head;
                head = n;
                cout <<"Inserido com sucesso !\n  " <<endl;
            }
            system("PAUSE");
        }
        void removeNo(int i){
            if(head == NULL){
                cout <<"Falha ao remover Nó : Lista vazia\n" <<endl; 
            }else if(head != NULL){
                if(head->id == i ){
                    head = head->next;
                    cout <<"No removido com sucesso !\n" <<endl;
                }else{
                    No * aux = NULL;
                    No * ant = head;
                    No * ptr = head->next;
                    while(ptr != NULL){
                        if(ptr->id == i){
                            aux = ptr;
                            ptr = NULL;
                        }else{
                            ant = ant->next;
                            ptr = ptr->next;
                        }
                    }
                    if(aux != NULL){
                        ant->next = aux->next;
                        cout <<"No removido com sucesso !\n" <<endl;
                    }else{
                        cout <<"Falha ao remover No : No nao existe !\n" <<endl;
                    }
                }
            }
            system("PAUSE");
        }
        void removeNo(){
            if(head == NULL){
                cout <<"Falha ao remover Nó : Lista vazia\n" <<endl; 
            }else if(head != NULL){
                    No * aux = head->next;
					delete head;
					head = aux;
                    cout <<"No removido com sucesso !\n" <<endl;
            }
            system("PAUSE");
        }
        void alterar(int i, int v){
            No * ptr = noExiste(i);
            if(ptr != NULL){
                ptr->value = v;
                cout <<"Valor alterado com sucesso !\n" <<endl;
            }else{
                cout <<"Falha ao alterar valor: No nao existe !\n" <<endl;
            }
            system("PAUSE");
        }
        void imprime(){
            if (head == NULL) {
                cout <<"Falha ao imprimir: Lista vazia !\n" <<endl;
            } else {
                No * aux = head;
                while(aux != NULL){
                    cout <<" ID :"<< aux->id <<" | valor :"<< aux->value <<endl;
                    aux = aux->next;
                }
            }
            cout << "Aperte ENTER para continuar" << endl;
            cin;
        }
        No * ordena(){
			int comp = 0, swap = 0;
			No *p = head;
			while(p != NULL){
				No *p2 = p->next;
				while(p2 != NULL){
					if(p->value > p2->value){
						int aux = p->value;
						p->value = p2->value;
						p2->value = aux;
					}
					p2 = p2->next;
				}
				p = p->next;
			}
			return head;
		}
        void setHead(No * no){
			head = no;
		}
};

int main(){
    Lista l;
    Menu m;
    int id, value, controlador_de_menu;
    cout <<"Com qual elemento deseja trabalhar ?" <<endl;
    cout <<"[1] Lista Encadeada" <<endl;
    cout <<"[2] Pilha" <<endl;
    cin >> controlador_de_menu;
    if(controlador_de_menu == 1){
		m.menu();
	}else if(controlador_de_menu == 2){
		m.menu(0);
	}else{
		cout <<"IMPOSSIVEL COMPLEMENTAR EXECUCAO !" <<endl;
		system("PAUSE");
		System::clean_console();
		main();
	}
    while(m.getOp() != 0){
        No * novo = new No();
        int aux = m.getOp();
        switch(aux){
            case 1:
                System::clean_console();
                cout << "! Inserindo no Inicio !\n" <<endl;
                cout <<"Insira o ID e, em seguida, o valor \n>>" <<endl;
                cin >> id;
                cin >> value;
                novo->id = id;
                novo->value = value;
                l.insereInicio(novo);
                break;
            case 2:
                System::clean_console();
                cout << "! Inserindo no Fim !\n" <<endl; 
                cout <<"Insira o ID e, em seguida, o valor \n>>" <<endl;
                cin >> id;
                cin >> value;
                novo->id = id;
                novo->value = value;
                l.insereFim(novo);
                break;
            case 3:
                int aux;
                System::clean_console();
                if(controlador_de_menu == 2){
					cout << "! Removendo !" <<endl;
					l.removeNo();
				}else{
					cout << "! Removendo !" <<endl;
                	cout <<"Insira o ID do No que deseja excluir \n>>" <<endl;
                	cin >> aux;
                	l.removeNo(aux);
            	}
                break;
            case 4:
                System::clean_console();
                cout << "! Imprimindo !" << endl;
                l.imprime();
                break;
            case 5:
                System::clean_console();
                cout <<"! Alterando !" <<endl;
                cout <<"Digite o Id do No que deseja alterar e em seguida o novo valor \n>>" <<endl;
                cin >> id;
                cin >> value;
                l.alterar(id, value);
                break;
            case 6:
                System::clean_console();
                cout <<"Lista Ordenada :" <<endl;
                l.setHead(l.ordena());
                break;
            case 7:
                System::clean_console();
                break; 
            default:
                cout <<"OPERACAO INVALIDA !\n" <<endl;
        }
	    if(controlador_de_menu == 1){
			m.menu();
		}else if(controlador_de_menu == 2){
			m.menu(0);
		}
    }
    cout <<"PROGRAMA FINALIZADO!" <<endl;
    cout <<"\n" <<endl;
    return 0;
}
