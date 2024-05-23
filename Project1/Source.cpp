#include <iostream>

struct Node {
    int data;
    Node* next;
};

void splitList(Node* head, Node* p, Node*& list1, Node*& list2) {
    // Nếu danh sách rỗng hoặc p là NULL
    if (head == nullptr || p == nullptr) {
        list1 = nullptr;
        list2 = nullptr;
        return;
    }

    // Khởi tạo list1 bắt đầu từ head
    list1 = head;
    Node* current = head;

    // Duyệt danh sách để tìm nút có con trỏ p
    while (current != nullptr && current != p) {
        current = current->next;
    }

    // Nếu không tìm thấy p trong danh sách
    if (current == nullptr) {
        list1 = head;
        list2 = nullptr;
        return;
    }

    // Chia danh sách tại p
    list2 = current->next;  // list2 bắt đầu từ nút sau p
    current->next = nullptr; // Ngắt kết nối tại p

    // list1 vẫn bắt đầu từ head
}

// Hàm để in danh sách liên kết
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// Hàm để thêm nút vào danh sách liên kết
void append(Node*& head, int data) {
    Node* newNode = new Node{ data, nullptr };
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int main() {
    Node* head = nullptr;
    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 4);
    append(head, 5);

    // Giả sử p là con trỏ tới nút có giá trị 3
    Node* p = head->next->next;

    Node* list1 = nullptr;
    Node* list2 = nullptr;

    splitList(head, p, list1, list2);

    std::cout << "List 1: ";
    printList(list1);
    std::cout << "List 2: ";
    printList(list2);

    return 0;
}
