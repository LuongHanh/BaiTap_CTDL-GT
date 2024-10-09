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

void Chenketiep(node &Q, short value){
	node tmp = Tao(value);
	if(Q == nullptr) Q = tmp;
	else {
		node p = Q;
		while(p->link != nullptr){
			p = p->link;
		}
		p->link = tmp;
	}
}

void Bosung(node &Q, node &M, short value){
	node tmp = Tao(value);
	if(Q == nullptr) Q = tmp;
	else {
		node p = Q;
		while(p->link != M){
			p = p->link;	//Tim duoc M
		}
		p = p->link; //dich den M
		tmp->link = M->link;
		M->link = tmp;
	}
}

void In(node a, node &M) {
	int cnt = 0;
	cout<<"--------------------------LIST-----------------------------------\n";
	while(a != nullptr) {
		cout<<"STT "<<++cnt<<"   Data: "<<a->data<<"   Link: "<<a->link<<endl;
		if(cnt==3) M = a->link; //Phep thu voi M la phan tu thu 4
		a=a->link;
	}
	cout<<"-------------------------------------------------------------\n";
}

int main(){
	node Q = nullptr, M = nullptr;
	int n,n1;
	short value;
	cout<<"n = ";cin>>n; n1=n;
	while(n1--){
		cout<<"STT : "<<n-n1;
		cout<<"		value = ";cin>>value;
		Chenketiep(Q,value);
	}
	In(Q, M);
	cout<<M;
	Bosung(Q, M, 10);
	cout<<"\nSAU KHI THEM DIA CHI M";
	In(Q, M);
}