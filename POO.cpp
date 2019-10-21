#include<iostream>
using namespace std;

class Menu{
    private:
        int op;
    public:
        void menu(){
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
        int tamanho(){
            int cont = 0;
            if(head == NULL){
                return 0;
            }else{
                No * aux = head;
                while(aux != NULL){
                    cont++;
                    aux = aux->next;
                }
            }
            return cont;
        } 
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
        }
        void insereInicio(No * n){
            if(noExiste(n->id) != NULL){
                cout <<"Falha ao criar novo No : No já existe !" << endl;
            }else{
                n->next = head;
                head = n;
                cout <<" Inserido com sucesso !\n  " <<endl;
            }
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
        }
        void alterar(int i, int v){
            No * ptr = noExiste(i);
            if(ptr != NULL){
                ptr->value = v;
                cout <<"Valor alterado com sucesso !\n" <<endl;
            }else{
                cout <<"Falha ao alterar valor: No nao existe !\n" <<endl;
            }
        }
        void imprime(){
            if(head == NULL){
                cout <<"falha ao imprimir: Lista vazia !\n" <<endl;
            }else{
                No * aux = head;
                while(aux != NULL){
                    cout <<" ID :"<< aux->id <<" | valor :"<< aux->value <<endl;
                    aux = aux->next;
                }
            }
        }
        void ordena(){
            No * aux = head;
            int count;
            for (size_t i = 0; i < count; i++)
            {
                /* CODE */
                
            }
            
        }
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
                system("clear");
                cout << "! Inserindo no Inicio !\n" <<endl;
                cout <<"Insira o ID e, em seguida, o valor \n>>" <<endl;
                cin >> id;
                cin >> value;
                novo->id = id;
                novo->value = value;
                l.insereInicio(novo);
                break;
            case 2:
                system("clear");
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
                system("clear");
                cout << "! Removendo !" <<endl;
                cout <<"Insira o ID do No que deseja excluir \n>>" <<endl;
                cin >> aux;
                l.removeNo(aux);
                break;
            case 4:
                system("clear");
                cout <<"! Imprimindo !" <<endl;
                l.imprime();  
                break;
            case 5:
                system("clear");
                cout <<"! Alterando !" <<endl;
                cout <<"Digite o Id do No que deseja alterar e em seguida o novo valor \n>>" <<endl;
                cin >> id;
                cin >> value;
                l.alterar(id, value);
                break;
            case 6:
                system("clear");
                cout <<"Lista Ordenada :" <<endl;
                break;
            case 7:
                system("clear");
                //system("cls");
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
