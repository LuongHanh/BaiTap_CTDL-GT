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

void Chenketiep(node &P, short value){
	node tmp = Tao(value);
	if(P == nullptr) P = tmp;
	else {
		node p = P;
		while(p->link != nullptr){
			p = p->link;
		}
		p->link = tmp;
	}
}

void Del(node &P, node &M){
	node p = P;
	while(p->link != M){
		p = p->link;
	}
	p->link = M->link;
}

void In(node a, node &M) {
	int cnt = 0;
	cout<<"--------------------------LIST-----------------------------------\n";
	while(a != nullptr) {
		cout<<"STT "<<++cnt<<"   Data: "<<a->data<<"   Link: "<<a->link<<endl;
		if(cnt == 3) M = a->link; //Phep thu voi M la phan tu thu 4
		a=a->link;
	}
	cout<<"-------------------------------------------------------------\n";
}

int main(){
	node P = nullptr, M = nullptr;
	int n,n1;
	short value;
	cout<<"n = ";cin>>n; n1=n;
	while(n1--){
		cout<<"STT : "<<n-n1;
		cout<<"		value = ";cin>>value;
		Chenketiep(P,value);
	}
	In(P, M);
	cout<<M;
	Del(P, M);
	cout<<"\nSAU KHI XOA DIA CHI M";
	In(P, M);
}