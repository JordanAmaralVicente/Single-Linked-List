#include<iostream>
using namespace std;

class Menu{
    private:
        int op;
    public:
        void menu(){
            cout<< "MENU" <<endl;
            cout<< "Insere no inicio : 1" <<endl;
            cout<< "Insere no fim : 2" <<endl;
            cout<< "Remove : 3" <<endl;
            cout<< "Imprimir : 4" <<endl;
            cout<< "Alterar : 5" <<endl;
            cout<< "Ordenar : 6" <<endl;
            cout<< "Sair : 0\n>>" <<endl;
            cin >> op;
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

    public:
        No * head;
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
        }
        void insereInicio(No * n){
            if(noExiste(n->id) != NULL){
                cout <<"FALHA AO CRIAR NÓ \n NÓ JÁ EXISTENTE !" << endl;
            }else{
                n->next = head;
                head = n;
                cout <<"Inserido com sucesso !" <<endl;
            }
        }
        void removeNo(int i){
            if(head == NULL){
                cout <<"Falha ao remover Nó : Lista vazia" <<endl; 
            }else if(head != NULL){
                if(head->id == i ){
                    head = head->next;
                    cout <<"No removido com sucesso ! \n" <<endl;
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
                        cout <<"No nao existe !" <<endl;
                    }
                }
            }
        }
        void alterar(int i, int v){
            No * ptr = noExiste(i);
            if(ptr != NULL){
                ptr->value = v;
                cout <<"Valor alterado com sucesso !\n" <<endl;
            }else{
                cout <<"Nao foi possivel alterar valor: No nao existe !\n" <<endl;
            }
        }
        void imprime(){
            if(head == NULL){
                cout <<"Nao foi possivel imprimir: Lista vazia !\n" <<endl;
            }else{
                No * aux = head;
                while(aux != NULL){
                    cout <<" ID :"<< aux->id <<" | valor :"<< aux->value <<endl;
                    aux = aux->next;
                }
            }
        }
        //falta implementar
        void ordena();
};

int main(){
    Lista l;
    Menu m;
    int id, value;

    m.menu();
    while(m.getOp() != 0){
        No * novo = new No();
        int aux = m.getOp();
        switch(aux){
            case 1:
                cout << "Inserindo no Inicio \n" <<endl;
                cout <<"Insira o ID e, em seguida, o valor \n>>" <<endl;
                cin >> id;
                cin >> value;
                novo->id = id;
                novo->value = value;
                l.insereInicio(novo);
                break;
            case 2:
                cout << "Inserindo no Fim \n" <<endl; 
                cout <<"Insira o ID e, em seguida, o valor \n>>" <<endl;
                cin >> id;
                cin >> value;
                novo->id = id;
                novo->value = value;
                l.insereFim(novo);
                break;
            case 3:
                int aux;
                cout << "Remover : Insira o ID do No que deseja excluir \n>>" <<endl;
                cin >> aux;
                l.removeNo(aux);
                break;
            case 4:
                cout <<"\n" <<endl;
                l.imprime();  
                break;
            case 5:
                cout <<"Alterar: Digite o Id do No que deseja alterar e em seguida o novo valor \n>>" <<endl;
                cin >> id;
                cin >> value;
                l.alterar(id, value);
                break;
            case 6:
                cout <<"Lista Ordenada :" <<endl;
                break;
            default:
                cout <<"OPERACAO INVALIDA !\n" <<endl;
        }
        m.menu();
    }
    cout <<"PROGRAMA FINALIZADO!" <<endl;
    cout <<"\n" <<endl;
    return 0;
}
