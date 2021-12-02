#include <iostream>
#include <list>

using namespace std;

int findThree(int[][] matrix) { //not sure if this is the right syntax
	int count = 0;

	for (int i = 0; i < 4, i++) {
		for (int j = 0; j < 4; j++) {
			if (matrix[i][j] == 1) {
				for (int k = 0; k < 4; k++) {
					if (i == k) break;
					if (j == k) break;
					if (matrix[j][k] == 1)
						for (int m = 0; m < 4; m++) {
							if (i == m) break;
							if (j == m) break;
							if (k == m) break;
							if (matrix[k][m] == 1)
								count++;
						}
				}
			}

		}

	}
	return count;
}

int main(int argc, char *arv[])
{
	string cmd;

	cout<<"Would you like a directed graph (D) or an undirected graph (U)?"<<endl;
	cout<<">>>";
	cin>>cmd;

	if(cmd=="D")
	{
		int dMatrix [4][4];

		dMatrix[0][0] = 0;
		dMatrix[0][1] = 1;
		dMatrix[0][2] = 0;
		dMatrix[0][3] = 1;

		dMatrix[1][0] = 0;
		dMatrix[1][1] = 0;
		dMatrix[1][2] = 1;
		dMatrix[1][3] = 0;

		dMatrix[2][0] = 1;
		dMatrix[2][1] = 0;
		dMatrix[2][2] = 0;
		dMatrix[2][3] = 0;

		dMatrix[3][0] = 0;
		dMatrix[3][1] = 0;
		dMatrix[3][2] = 1;
		dMatrix[3][3] = 0;
		
		cout<<endl<<"DIRECTED GRAPH"<<endl;
		cout<<"------------"<<endl;
		for (int row=0; row<4; row++)
		{
			for (int col=0; col<4; col++)
			{
				cout<<" "<<dMatrix[row][col]<<" ";
			}

			cout<<endl;
		}
		cout<<"------------"<<endl;
	}

	else if(cmd=="U")
	{
		int unMatrix [4][4];

		unMatrix[0][0] = 0;
		unMatrix[0][1] = 1;
		unMatrix[0][2] = 1;
		unMatrix[0][3] = 1;

		unMatrix[1][0] = 1;
		unMatrix[1][1] = 0;
		unMatrix[1][2] = 1;
		unMatrix[1][3] = 0;

		unMatrix[2][0] = 1;
		unMatrix[2][1] = 1;
		unMatrix[2][2] = 0;
		unMatrix[2][3] = 0;

		unMatrix[3][0] = 1;
		unMatrix[3][1] = 0;
		unMatrix[3][2] = 0;
		unMatrix[3][3] = 0;
		
		cout<<endl<<"UNDIRECTED GRAPH"<<endl;
		cout<<"------------"<<endl;
		for (int row=0; row<4; row++)
		{
			for (int col=0; col<4; col++)
			{
				cout<<" "<<unMatrix[row][col]<<" ";
			}

			cout<<endl;
		}
		cout<<"------------"<<endl;
	}

	else
	{
		cout<<"Error: Invalid command"<<endl;
	}
	

	return 0;
}
