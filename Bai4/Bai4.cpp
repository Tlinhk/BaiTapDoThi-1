#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
#define MAX 100

int a[MAX][MAX];
int sodinh, socanh;

void inputDSC(){
	ifstream filein("input1_2.txt");
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
	for(int i=1;i<=socanh;i++){
		getline(filein,str);
		istringstream buffer(str);
		int x,y;
		buffer>>x>>y;
		a[x][y]=a[y][x]=1;
	}
	filein.close();
}

int main(){
	inputDSC();
	ofstream fileout("output1_2.txt");
	fileout<<"So dinh: "<<sodinh<<"\t"<<"So canh: "<<socanh<<endl;
	
	//MA TRAN KE
	fileout<<"\n----------MA TRAN KE----------"<<endl;
	for(int i=1;i<=sodinh;i++){
		for(int j=1;j<=sodinh;j++){
			fileout<<a[i][j]<<"\t";
		}
		fileout<<endl;
	}
	
	//DANH SACH KE
	fileout<<"\n------DANH SACH KE-------"<<endl;
	for(int i=1;i<=sodinh;i++){
		for(int j=1;j<=sodinh;j++){
			if(a[i][j]==1){
				fileout<<j<<"\t";
			}
		}
		fileout<<endl;
	}
	
	//BAC CUA TUNG DINH
	fileout<<"\n------BAC CUA TUNG DINH--------"<<endl;
	for(int i=1;i<=sodinh;i++){
		int deg=0;
		for(int j=1;j<=sodinh;j++){
			if(a[i][j]==1) deg++;
		}
		fileout<<deg<<endl;
	}
	cout<<"output1_2.txt da duoc tao."<<endl;
	fileout.close();
	return 0;
}

