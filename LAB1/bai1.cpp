/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include<iostream>
#include<vector>
using namespace std;

//###INSERT CODE HERE -
void inputGraph(vector<vector<int> > &G ,int v,int e){
	G=vector<vector<int>>(v,vector<int>(v,0));
	int a,b;
	for (int i=0;i<e;i++){
		cin>>a>>b;
		G[a-1][b-1]=1;
	}
}

void process(vector<vector<int> > G ,int v,int n){
	for (int i=0;i<n;i++){
		int choice;
		cin>>choice;
		switch(choice){
			case 1:
			{
				int u,i;
				cin>>u>>i;
				if (G[u-1][i-1]==1){
					cout<<"TRUE"<<endl;
				}
				else {
					cout<<"FALSE"<<endl;
				}
				break;

			}
			case 2:{
				int u;
				cin>>u;
				bool flag=false;
				for (int i=0;i<v;i++){	
					if(G[u-1][i]==1){
						flag=true;
						cout<<i+1<<" ";
					}
				}
			if(flag==false){
				cout<<"NONE";
			}
			cout<<endl;
			}
		}
	}
}
int main()
{

	int v, e, n;
	cin >> v >> e >> n; //v: số đỉnh, e: số cạnh, n: số thao tác
	vector<vector<int> > G;

	inputGraph(G,v,e);
    process(G,v,n);

	return 0;
}
