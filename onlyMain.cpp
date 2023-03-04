#include <iostream>
using namespace std;

// definisi struct Node
struct Node {
    int data;           // data yang disimpan di node
    Node* next;         // pointer ke node berikutnya
};

int main() {
    // inisialisasi pointer head dan tail dengan null
    Node* head = NULL;
    Node* tail = NULL;

    // tambah data pada linked list
    Node* newNode = new Node();     // alokasi memori untuk node baru
    newNode->data = 10;             // isi data pada node
    newNode->next = NULL;           // pointer next diisi null karena ini node terakhir
    if (head == NULL) {             // jika linked list masih kosong
        head = newNode;             // node baru menjadi head
        tail = newNode;             // node baru menjadi tail
    } else {                        // jika linked list sudah ada isinya
        tail->next = newNode;       // node baru menjadi node terakhir, next dari tail menunjuk ke node baru
        tail = newNode;             // node baru menjadi tail
    }

    // tambah data lain pada linked list
    newNode = new Node();
    newNode->data = 20;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }

    // hapus data dari linked list
    Node* temp = head;              // pointer untuk mencari node yang akan dihapus
    Node* prev = NULL;              // pointer untuk menyimpan node sebelum node yang akan dihapus
    int target = 10;                // data yang ingin dihapus
    while (temp != NULL) {          // lakukan pencarian data
        if (temp->data == target) { // jika data ditemukan
            if (prev == NULL) {     // jika node yang dihapus adalah head
                head = temp->next;  // head menjadi node setelah node yang dihapus
            } else {                // jika node yang dihapus bukan head
                prev->next = temp->next; // next dari node sebelum node yang dihapus menunjuk ke node setelah node yang dihapus
            }
            delete temp;            // hapus node yang dihapus
            break;                  // keluar dari loop karena data sudah ditemukan dan dihapus
        } else {                    // jika data belum ditemukan
            prev = temp;            // node saat ini menjadi node sebelumnya
            temp = temp->next;      // lanjut ke node berikutnya
        }
    }

    // cetak isi linked list
    cout << "Isi linked list: ";
    temp = head;                    // pointer untuk mencetak isi linked list
    while (temp != NULL) {          // lakukan pencetakan isi linked list
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
