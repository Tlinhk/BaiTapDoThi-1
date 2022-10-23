#include<iostream>
#include<fstream>
using namespace std;
#define MAX 100

int a[MAX][MAX];
int socanh = 0, sodinh;

void inputMTK(){
	ifstream filein("input1.txt");
	filein>>sodinh;
	for(int i=1;i<=sodinh;i++){
		for(int j=1;j<=sodinh;j++){
			filein>>a[i][j];
			if(a[i][j]==1) socanh++;
		}
	}
	socanh=socanh/2;
	filein.close();
}
void DScanh(){
	ofstream fileout("input1_2.txt");
	fileout<<"--------DANH SACH CANH----------"<<endl;
	fileout<<sodinh<<"\t"<<socanh<<endl;
	for(int i=1;i<=sodinh;i++){
		for(int j=i;j<=sodinh;j++){
			if(a[i][j]==1)
			{
				fileout<<i<<"\t"<<j<<endl;
			}
		}
	}
	cout<<"Danh sach canh da duoc tao trong input1_2.txt"<<endl;
	fileout.close();
}

void DSke(){
	ofstream fileOut("input1_1.txt");
	fileOut<<"---------DANH SACH KE---------"<<endl;
	fileOut<<sodinh<<"\t"<<socanh<<endl;
	for(int i=1;i<=sodinh;i++){
		for(int j=1;j<=sodinh;j++){
			if(a[i][j]==1){
				fileOut<<j<<"\t";
			}
		}
		fileOut<<endl;
	}
	cout<<"Danh sach ke da duoc tao trong input1_1.txt"<<endl;
	fileOut.close();
}

int main(){
	inputMTK();
	DScanh();
	DSke();
	return 0;
}

