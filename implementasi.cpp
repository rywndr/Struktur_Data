#include <iostream>
using namespace std;

// deklarasi struct untuk setiap node dalam linked list
struct Node {
    int data;
    Node* next;
};

// fungsi untuk menambahkan node pada awal linked list
void insertNode(Node** head_ref, int new_data) {
    // alokasi memori untuk node baru
    Node* new_node = new Node();
    // masukkan data baru ke dalam node
    new_node->data = new_data;
    // jadikan node baru sebagai head
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// fungsi untuk menghapus node dari linked list
void deleteNode(Node** head_ref, int key) {
    // inisialisasi node yang akan dihapus dan node sebelumnya
    Node* temp = *head_ref;
    Node* prev = nullptr;

    // jika head node berisi data yang sesuai dengan key
    if (temp != nullptr && temp->data == key) {
        *head_ref = temp->next; // ganti head dengan node berikutnya
        delete temp; // hapus node
        return;
    }

    // cari node yang akan dihapus
    while (temp != nullptr && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // jika node tidak ditemukan
    if (temp == nullptr) {
        cout << "Node tidak ditemukan." << endl;
        return;
    }

    // lewati node yang akan dihapus
    prev->next = temp->next;
    // hapus node
    delete temp;
}

// fungsi untuk mencari node dalam linked list
void searchNode(Node* head, int key) {
    // inisialisasi variabel untuk node saat ini
    Node* current = head;

    // traverse linked list hingga node dengan data yang sesuai ditemukan
    while (current != nullptr) {
        if (current->data == key) {
            cout << "Node dengan data " << key << " ditemukan." << endl;
            return;
        }
        current = current->next;
    }

    // jika node tidak ditemukan
    cout << "Node dengan data " << key << " tidak ditemukan." << endl;
}

// fungsi untuk menampilkan semua node dalam linked list
void traverseList(Node* node) {
    // traverse linked list hingga akhir list tercapai
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// fungsi main untuk melakukan operasi pada linked list
int main() {
    Node* head = nullptr;

    // tambahkan node pada awal linked list
    insertNode(&head, 3);
    insertNode(&head, 1);
    insertNode(&head, 7);
    insertNode(&head, 5);

    // tampilkan semua node dalam linked list
    cout << "Linked List: ";
    traverseList(head);

    // hapus node dengan data 7
    deleteNode(&head, 7);
    cout << "Node dengan data 7 telah dihapus." << endl;

    // tampilkan semua node dalam linked list
    cout << "Linked List: ";
    traverseList(head);

    // cari node dengan data 5
    searchNode(head, 5);

    return 0;
}
