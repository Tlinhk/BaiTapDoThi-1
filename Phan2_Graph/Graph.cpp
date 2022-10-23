#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

#define MAX 100

using namespace std;

class Graph
{
	private:
		int** arr;
		int n;
		int socanh;
	public:
		Graph();
		void inputMaTranKe(char*);
		void inputDanhSachKe(char*);
		void inputDanhSachCanh(char*);
		int getDeg(int);
		void danhsachke(int);
		void print();
};
Graph::Graph(){
	n = socanh =0;
	arr=NULL;
}

void Graph::inputMaTranKe(char filename[]){
	ifstream filein(filename);
	filein>>n;
	arr = new int*[n];
	for(int k=1;k<=n;k++){
		arr[k]= new int[n];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			filein>>arr[i][j];
			if(arr[i][j]==1) socanh++;
		}
	}
	socanh = socanh/2;
	filein.close();
}

void Graph:: inputDanhSachCanh(char filename[]){
	ifstream filein(filename);
	string str;
	getline(filein,str);
	istringstream buffer(str);
	buffer>>n>>socanh;
	arr = new int*[n];
	for(int k=1;k<=n;k++){
		arr[k]= new int[n];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			arr[i][j]=0;
		}
	}
	for(int i=1;i<=socanh;i++ ){
		getline(filein, str);
		istringstream buffer(str);
		int x,y;
		buffer>>x>>y;
		arr[x][y]=arr[y][x]=1;
	}
	filein.close();
}

void Graph:: inputDanhSachKe(char filename[]){
	ifstream  filein(filename);
	string str;
	getline(filein,str);
	istringstream buffer(str);
	buffer>>n>>socanh;
	arr = new int*[n];
	for(int k=1;k<=n;k++){
		arr[k]= new int[n];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			arr[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		getline(filein,str);
		istringstream buffer(str);
		int j;
		while(!buffer.eof()){
			buffer>>j;
			arr[i][j]=1;
		}
	}
	filein.close();
}

int Graph::getDeg(int vertex){
	int deg = 0;
	for(int i=1;i<=n;i++){
		if(arr[vertex][i]==1) deg++;
	}
	return deg;
}

void Graph::danhsachke(int vertex){
	for(int i=1;i<=n;i++){
		if(arr[vertex][i]==1){
			cout<<i<<"\t";
		}
	}
	cout<<endl;
}

void Graph::print(){
	cout<<"Do thi co "<<this->n<<" dinh "<<" va co "<<this->socanh<<" canh"<<endl;
}

int main(){
	Graph A,B,C;
	A.inputMaTranKe("matranke.txt");
	B.inputDanhSachKe("danhsachke.txt");
	C.inputDanhSachCanh("danhsachcanh.txt");
	
	cout<<"Graph A:"<<endl;
	A.print();
	cout<<"Cac dinh ke cua dinh 2: ";
	A.danhsachke(2);
	cout<<"Bac cua dinh 2 la: "<<A.getDeg(2)<<endl;
	
	cout<<"----------------------"<<endl;
	cout<<"Graph B:"<<endl;
	B.print();
	cout<<"Cac dinh ke cua dinh 3 la: ";
	B.danhsachke(3);
	cout<<"Bac cua dinh 3 la: "<<B.getDeg(3)<<endl;
	
	cout<<"----------------------"<<endl;
	cout<<"Graph C:"<<endl;
	C.print();
	cout<<"Cac dinh ke cua dinh 4 la: ";
	C.danhsachke(4);
	cout<<"Bac cua dinh 4 la: "<<C.getDeg(4);
	return 0;
}

