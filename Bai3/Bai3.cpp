#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
#define MAX 100

int a[MAX][MAX];
int sodinh, socanh;


void inputDSKe(){
	ifstream filein("input1_1.txt");
	string str,str1;
	getline(filein,str);
	getline(filein,str1);
	istringstream buffer(str1);
	buffer>>sodinh>>socanh;
	for(int i=1;i<=sodinh;i++){
		for(int j=1;j<=sodinh;j++){
			a[i][j]=0;
		}
	}
	for(int i=1;i<=sodinh;i++){
		getline(filein, str);
		istringstream buffer(str);
		int j;
		while(!buffer.eof()){
			buffer>>j;
			a[i][j]=1;
		}	
	}
	filein.close();
}


int main(){
	inputDSKe();
	ofstream fileout("output1_1.txt");
	fileout<<"So dinh: "<<sodinh<<"\t"<<"So canh: "<<socanh<<endl;
	//MA TRAN KE
	fileout<<"\n---------Ma tran ke--------"<<endl;
	for(int i=1;i<=sodinh;i++){
		for(int j=1;j<=sodinh;j++){
			fileout<<a[i][j]<<"\t";
		}
		fileout<<endl;
	}
	
	//DANH SACH CANH
	fileout<<"\n--------DANH SACH CANH---------"<<endl;
	for(int i=1;i<=sodinh;i++){
		for(int j=i;j<=sodinh;j++){
			if(a[i][j]==1){
				fileout<<i<<"\t"<<j<<endl;
			}
			
		}
	}
	
	//BAC CUA TUNG DINH
	fileout<<"\n-------BAC CUA TUNG DINH------"<<endl;
	for(int i=1;i<=sodinh;i++){
		int deg = 0;
		for(int j=1;j<=sodinh;j++){
			if(a[i][j]==1) deg++;
		}
		fileout<<deg<<endl;
	}
	cout<<"output1_1.txt da duoc tao."<<endl;
	fileout.close();
	return 0;
}

