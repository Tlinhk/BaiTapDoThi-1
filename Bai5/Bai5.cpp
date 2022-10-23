#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
#define MAX 100

int a[MAX][MAX];
int sodinh, socanh=0;

void nhapMTK()
{
	ifstream filein("input2.txt");
	filein>>sodinh;
	for(int i=1;i<=sodinh;i++){
		for(int j=1;j<=sodinh;j++){
			filein>>a[i][j];
			if(a[i][j]==1) socanh++;
		}
	}
	filein.close();
}

void xuatDSC(){
	ofstream fileout("input2_2.txt");
	fileout<<"-----DANH SACH CANH-----"<<endl;
	fileout<<sodinh<<"\t"<<socanh<<endl;
	for(int i=1;i<=sodinh;i++){
		for(int j=1;j<=sodinh;j++){
			if(a[i][j]==1)
			{
				fileout<<i<<"\t"<<j<<endl;
			}
		}
	}
	cout<<"Danh sach canh da duoc tao trong input2_2.txt"<<endl;
	fileout.close();
	
}

void xuatDSK(){
	ofstream fileOut("input2_1.txt");
	fileOut<<"-------DANH SACH KE---------"<<endl;
	fileOut<<sodinh<<"\t"<<socanh<<endl;
	for(int i=1;i<=sodinh;i++){
		for(int j=1;j<=sodinh;j++){
			if(a[i][j]==1){
				fileOut<<j<<"\t";
			}
		}
		fileOut<<endl;
	}
	cout<<"Danh sach ke da duoc tao trong input2_1.txt"<<endl;
	fileOut.close();
}
int main(){
	nhapMTK();
	xuatDSK();
	xuatDSC();
	return 0;
}

