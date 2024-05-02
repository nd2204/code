/*
B32: Cài đặt một cấu trúc hàng đợi, với các thao tác:
1) Khởi tạo hàng đợi; 2) Kiểm tra hàng đợi rỗng; 3) Kiểm tra hàng đợi đầy;
4) Đưa một phần tử vào hàng đợi; 5) Lấy một phần tử ra khỏi hàng đợi (5 điểm).

- Chương trình chính: Sử dụng các thao tác đã cài đặt để:
+ Nhập vào một số nguyên dương N bất kỳ
+ Sử dụng cấu trúc hàng đợi để tính tổng các chữ số của N (5 điểm).
Ví dụ: N = 1996 => Tổng = 1 + 9 + 9 + 6 = 25.
*/

#include <iostream>

using namespace std;

typedef int data_t;

struct queue {
    enum { MAX_SIZE = 8 };
    int front, rear;
    data_t arr[MAX_SIZE];
};

// Khoi tao hang doi
void init(queue& q) {
    q.front = q.rear = -1;
}

// Ktra hang doi rong
bool isEmpty(const queue& q) {
    return (q.front == -1 || q.rear == -1)
        || ((q.rear + 1) % q.MAX_SIZE == q.front);
}

// Ktra hang doi day
bool isFull(const queue& q) {
    return (q.rear + 2) % q.MAX_SIZE == q.front;
}

// Lay phan tu ra khoi hang doi
data_t dequeue(queue& q) {
    if (!isEmpty(q)) {
        data_t d = q.arr[q.front];
        q.front = (q.front + 1) % q.MAX_SIZE;
        return d;
    }
    cout << "Queue is empty\n";
    return 0;
}

// Them phan tu vao hang doi
void enqueue(queue& q, const data_t& d) {
    if (isEmpty(q)) {
        q.front = 0;
    }
    else if (isFull(q)) {
        cout << "Queue is full\n";
        return;
    }
    q.rear = (q.rear + 1) % q.MAX_SIZE;
    q.arr[q.rear] = d;
}

int main() {
    int N;
    cout << "Nhap N:"; cin >> N;

    queue q;
    init(q);
    for (; N > 0; N /= 10) {
        enqueue(q, N % 10);
    }

    data_t sum = 0;
    while (!isEmpty(q)) {
        sum += dequeue(q);
    }
    cout << sum;

    return 0;
}
