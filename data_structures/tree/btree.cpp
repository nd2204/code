#include<iostream>
#include<string>

using namespace std;

struct SinhVien {
  int maSV;
  string tenSV;
  string lop;
  float tongKet;
  string hanhKiem;
};

typedef SinhVien TypeOfData;

TypeOfData inputData() {
  TypeOfData data;

  cout << " - Ma sinh vien: ";
  cin >> data.maSV;
  getchar();

  cout << " - Ten sinh vien: ";
  getline(cin >> ws, data.tenSV);

  cout << " - Lop: ";
  getline(cin >> ws, data.lop);

  cout << " - Diem tong ket: ";
  cin >> data.tongKet;
  getchar();

  cout << " - Hanh kiem: ";
  getline(cin >> ws, data.hanhKiem);

  return data;
}

///// In thông tin của một nút
void printData(TypeOfData data) {
  cout << " - Ma SV: " << data.maSV 
    << "; Ten SV: " << data.tenSV
    << "; Lop: " << data.lop
    << "; Diem TK: " << data.tongKet
    << "; Hanh kiem: " << data.hanhKiem
    << endl;
}

struct TypeOfNode {
  TypeOfData data;
  struct TypeOfNode *left;
  struct TypeOfNode *right;
};

typedef struct TypeOfNode *BinaryTree;
typedef struct TypeOfNode *NodePtr;

///// In thông tin của một nút
void printNode(NodePtr pnode) {
  printData(pnode->data);
}

///// Khởi tạo
void initialize(BinaryTree &T) {
  T = NULL;
}

///// Tạo một nút
NodePtr createNode(TypeOfData data) {
  NodePtr newNode = new TypeOfNode;
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->data = data;
  return newNode;
}

NodePtr insertToTree(NodePtr root, TypeOfData data) {
  if (root == NULL)
    root = createNode(data);
  else if (data.maSV < root->data.maSV)
    root = insertToTree(root->left, data);
  else if (data.maSV > root->data.maSV)
    root = insertToTree(root->right, data);
  return root;
}

typedef void (*traverseCB)(BinaryTree);

void preOrder(BinaryTree T, traverseCB f) {
  if (T != NULL) {
    f(T);
    preOrder(T->left, f);
    preOrder(T->right, f);
  }
}

void inOrder(BinaryTree T, traverseCB f) {
  if (T != NULL) {
    inOrder(T->left, f);
    f(T);
    inOrder(T->right, f);
  }
}

void postOrder(BinaryTree T, traverseCB f) {
  if (T != NULL) {
    postOrder(T->left, f);
    postOrder(T->right, f);
    f(T);
  }
}

NodePtr search(TypeOfData data, BinaryTree T) {
  NodePtr p;
  p = T;
  if (p != NULL) {
    if (data.maSV < p->data.maSV)
      return search(data, p->left);
    else if (data.maSV > p->data.maSV)
      return search(data, p->right);
    else return p;
  }
  else return NULL;
}


NodePtr searchByMaSV(int maSV, BinaryTree T) {
  NodePtr p;
  p = T;
  if (p != NULL)
  {
    if (maSV < p->data.maSV)
      return searchByMaSV(maSV, p->left);
    else if (maSV > p->data.maSV)
      return searchByMaSV(maSV, p->right);
    else return p;
  }

  else return NULL;
}

void print(BinaryTree T) {
  printNode(T);
}

void print_on_condition(BinaryTree T) {
  if (T->data.tongKet >= 8.5 && T->data.hanhKiem == "tot")
    printNode(T);
}

TypeOfNode* findMin(NodePtr node) {
  if (node == NULL) return node;
  if (node->left == NULL) return node;
  return findMin(node->left);
}

NodePtr deleteFromTree(BinaryTree &root, TypeOfData data) {
  if (root == NULL) return root;
  if (data.maSV < root->data.maSV) deleteFromTree(root->left, data);
  else if (data.maSV > root->data.maSV) deleteFromTree(root->right, data);
  else {
    NodePtr temp;
    if (root->left == NULL && root->right == NULL) {
      delete root;
      root = NULL;
    }
    else if (root->left == NULL) {
      temp = root;
      root = root->right;
      delete temp;
    }
    else if (root->right == NULL) {
      temp = root;
      root = root->left;
      delete temp;
    }
    else {
      temp = findMin(root->right);
      root->data = temp->data;
      root->right = deleteFromTree(root->right, temp->data);
    }
  }
  return root;
}

int main() {
  BinaryTree T;
  initialize(T);

  ///// Cau 3:
  cout << "===== NHAP DANH SACH SINH VIEN VAO CAY =====" << endl;
  int n;
  cout << "Nhap so luong sinh vien: ";
  cin >> n;
  getchar();
  for (int i = 0; i < n; i++) {
    cout << "Nhap sinh vien " << i + 1 << ":" << endl;
    TypeOfData data = inputData();
    insertToTree(T, data);
  }

  ///// Cau 4:
  cout << "===== DANH SACH TAT CA SINH VIEN CO TRONG CAY =====" << endl;
  cout << "===> Danh sach PreOder: " << endl;

  preOrder(T, print);
  cout << endl << "===> Danh sach InOder: " << endl;
  inOrder(T, print);
  cout << endl << "===> Danh sach PostOder: " << endl;
  postOrder(T, print);

  ///// Cau 5:
  cout << "===== TIM KIEM THEO MA SINH VIEN =====" << endl;
  int maSV;

  cout << "Nhap Ma sinh vien de tim kiem: ";
  cin >> maSV;
  NodePtr found = searchByMaSV(maSV, T);
  if (found == NULL) cout << "Khong co sinh vien voi Ma SV " << maSV << " trong cay" << endl;
  else {
    cout << "Sinh vien can tim la: " << endl;
    printNode(found);
  }

  ///// Cau 6:
  cout << "===== DANH SACH CAC SINH VIEN CO DIEM TK >= 8.5 VA HANH KIEM TOT =====" << endl;
  cout << "===> Danh sach PreOder: " << endl;
  preOrder(T, print_on_condition);
  cout << endl << "===> Danh sach InOder: " << endl;
  inOrder(T, print_on_condition);
  cout << endl << "===> Danh sach PostOder: " << endl;
  postOrder(T, print_on_condition);

  getchar();
}
