#include<iostream>

using namespace std;

struct Node{
	short data;
	Node* link;
};

typedef struct Node* node;

node Tao(short value){
	node tmp = new Node();
	tmp->data = value;
	tmp->link = nullptr;
	return tmp;
}

void Chenketiep(node &L, short value){
	node tmp = Tao(value);
	if(L == nullptr) L = tmp;
	else {
		node p = L;
		while(p->link != nullptr){
			p = p->link;
		}
		p->link = tmp;
	}
}

void Tach(node &L,node &L1, node &L2, int n){
	node p = L;
	while(n--){
		if(p->data %2 == 0) Chenketiep(L2, p->data);
		else Chenketiep(L1, p->data);
		p = p->link;
	}
}

void In(node a) {
	cout<<"--------------------------LIST-----------------------------------\n";
	while(a != nullptr) {
		cout<<"   Data: "<<a->data<<"   Link: "<<a->link<<endl;
		a=a->link;
	}
	cout<<"-------------------------------------------------------------\n";
}

int main(){
	node L = nullptr, L1 = nullptr, L2 = nullptr;
	int n,n1;
	short value;
	cout<<"n = ";cin>>n; n1=n;
	while(n1--){
		cout<<"STT : "<<n-n1;
		cout<<"		value = ";cin>>value;
		Chenketiep(L,value);
	}
	In(L);
	Tach(L, L1, L2, n);
	cout<<"\nTHUC HIEN TACH ===";
	cout<<"\nDS SO NGUYEN DUONG LE";
	In(L1);
	cout<<"\nDS SO NGUYEN DUONG CHAN";
	In(L2);
}