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

void Bosungcuoi(node &P, short value){
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

void In(node a, short &x) {
	int cnt = 0;
	cout<<"--------------------------LIST-----------------------------------\n";
	while(a != nullptr) {
		cout<<"STT "<<++cnt<<"   Data: "<<a->data<<"   Link: "<<a->link<<endl;
		a=a->link;
	}
	cout<<"-------------------------------------------------------------\n";
}

int main(){
	node P = nullptr;
	int n,n1;
	short value, x;
	cout<<"n = ";cin>>n; n1=n;
	while(n1--){
		cout<<"STT : "<<n-n1;
		cout<<"		value = ";cin>>value;
		Bosungcuoi(P,value);
	}
	In(P, x);
}