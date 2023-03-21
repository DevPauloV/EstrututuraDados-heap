  #include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void heapify(vector<int>& heap, int i, int n) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;
    if (left < n && heap[left] < heap[smallest]) {
        smallest = left;
    }
    if (right < n && heap[right] < heap[smallest]) {
        smallest = right;
    }
    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        heapify(heap, smallest, n);
    }
}

void build_heap(vector<int>& heap) {
    int n = heap.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(heap, i, n);
    }
    }

void heap_push(vector<int>& heap, int x) {
    heap.push_back(x);
    int i = heap.size() - 1;
    int parent = (i - 1) / 2;
    while (i > 0 && heap[parent] > heap[i]) {
        swap(heap[i], heap[parent]);
        i = parent;
        parent = (i - 1) / 2;
    }
    }

int heap_top(vector<int>& heap) {
    return heap[0];
    }

void heap_pop(vector<int>& heap) {
    int n = heap.size() - 1;
    heap[0] = heap[n];
    heap.pop_back();
    heapify(heap, 0, n);
     }

 void heap_remove(vector<int>& heap, int x) {
    int n = heap.size();
    int i = find(heap.begin(), heap.end(), x) - heap.begin();
    heap[i] = heap[n - 1];
    heap.pop_back();
    if (i < n - 1) {
        heapify(heap, i, n - 1);
    }
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
   }

void display_heap(vector<int>& heap) {
      int n = heap.size();
      int level = 0;
      int i = 0;
    while (i < n) {
      int end = min(i + (1 << level), n);
    for (int j = i; j < end; j++) {
    cout << heap[j] << " ";
}
    cout << endl;
      i = end;
      level++;
}
}

int main() {
vector<int> heap;
int n;
cout << "Quantos elementos iniciais deseja inserir? ";
cin >> n;
cout << "Insira " << n << " elementos:" << endl;
for (int i = 0; i < n; i++) {
int x;
cin >> x;
heap.push_back(x);
}
build_heap(heap);
while (true) {
         cout << endl;
         cout << "Escolha uma opcao:" << endl;
         cout << "1. Inserir elemento" << endl;
         cout << "2. Recuperar minimo" << endl;
         cout << "3. Extrair minimo" << endl;
         cout << "4. Remover elemento" << endl;
         cout << "5. Exibir elementos da heap " << endl;
         cout << "6. Sair..." << endl;
    int op;
cin >> op;
  if (op == 1) {
    int x;
cout << "Insira um elemento: ";
cin >> x;
heap_push(heap, x);
cout << "Elemento inserido." << endl;
} else if (op == 2) {
if (heap.empty()) {
cout << "Heap vazia." << endl;
} else {
cout << "Minimo: " << heap_top(heap) << endl;
}
} else if (op == 3) {
if (heap.empty()) {
cout << "Heap vazia." << endl;
} else {
heap_pop(heap);
cout << "Minimo extraido." << endl;
}
} else if (op == 4) {
if (heap.empty()) {
cout << "Heap vazia." << endl;
} else {
int x;
cout << "Insira um elemento para remover: ";
cin >> x;
if (find(heap.begin(), heap.end(), x) != heap.end()) {
heap_remove(heap, x);
cout << "Elemento removido." << endl;
} else {
cout << "Elemento nao encontrado na heap." << endl;
}
     }
} else if (op == 5) {
if (heap.empty()) {
cout << "Heap vazia." << endl;
} else {
display_heap(heap);
   }
} else if (op == 6) {
break;
} else {
cout << "Opcao invalida." << endl;
}
      }
return 0;
   }
