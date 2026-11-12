#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// Nodo de un árbol binario: máximo dos hijos (izquierdo y derecho)
struct NodoBinario {
    int dato;
    NodoBinario* izq;
    NodoBinario* der;
    NodoBinario(int d) : dato(d), izq(nullptr), der(nullptr) {}
};

// Insertar (árbol binario de búsqueda)
NodoBinario* insertar(NodoBinario* nodo, int valor) {
    if (nodo == nullptr) return new NodoBinario(valor);
    if (valor < nodo->dato) nodo->izq = insertar(nodo->izq, valor);
    else nodo->der = insertar(nodo->der, valor);
    return nodo;
}

// Buscar un valor
bool buscar(NodoBinario* nodo, int valor) {
    if (nodo == nullptr) return false;
    if (nodo->dato == valor) return true;
    return valor < nodo->dato ? buscar(nodo->izq, valor)
                              : buscar(nodo->der, valor);
}

// Contar nodos
int contar(NodoBinario* nodo) {
    if (nodo == nullptr) return 0;
    return 1 + contar(nodo->izq) + contar(nodo->der);
}

// Altura (número de niveles)
int altura(NodoBinario* nodo) {
    if (nodo == nullptr) return 0;
    return 1 + max(altura(nodo->izq), altura(nodo->der));
}

// Preorden: Raíz -> Izquierda -> Derecha
void preorden(NodoBinario* nodo) {
    if (nodo == nullptr) return;
    cout << nodo->dato << " ";
    preorden(nodo->izq);
    preorden(nodo->der);
}

// Inorden: Izquierda -> Raíz -> Derecha
void inorden(NodoBinario* nodo) {
    if (nodo == nullptr) return;
    inorden(nodo->izq);
    cout << nodo->dato << " ";
    inorden(nodo->der);
}

// Postorden: Izquierda -> Derecha -> Raíz
void postorden(NodoBinario* nodo) {
    if (nodo == nullptr) return;
    postorden(nodo->izq);
    postorden(nodo->der);
    cout << nodo->dato << " ";
}

// Liberar la memoria del árbol
void liberar(NodoBinario* nodo) {
    if (nodo == nullptr) return;
    liberar(nodo->izq);
    liberar(nodo->der);
    delete nodo;
}

int main() {
    NodoBinario* raiz = nullptr;
    int valores[] = {10, 5, 15, 3, 7, 12, 20};
    for (int v : valores) raiz = insertar(raiz, v);

    cout << "Nodos: " << contar(raiz) << endl;
    cout << "Altura: " << altura(raiz) << endl;
    cout << "Existe 7? " << (buscar(raiz, 7) ? "si" : "no") << endl;

    cout << "Preorden:  "; preorden(raiz);  cout << endl;
    cout << "Inorden:   "; inorden(raiz);   cout << endl;
    cout << "Postorden: "; postorden(raiz); cout << endl;

    liberar(raiz);
    return 0;
}
