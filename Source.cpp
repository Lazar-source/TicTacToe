
#include "time.h"
#include "Node.h"
#include <iostream>
#include <cstdio>
#include <ctime>
bool MatrixVege(char ** matrix,char j)
{

	if ( (matrix[0][0] == j && matrix[0][1] == j && matrix[0][2] == j)||
		 (matrix[1][0] == j && matrix[1][1] == j && matrix[1][2] == j)|| 
		 (matrix[2][0] == j && matrix[2][1] == j && matrix[2][2] == j)|| 
		 (matrix[0][0] == j && matrix[1][1] == j && matrix[2][2] == j)||
		 (matrix[2][0] == j && matrix[1][1] == j && matrix[0][2] == j)  )
	{
		return true;
	}
	else
	{
		return false;
	}
}
void PrintMatrix(char ** matrix)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << " " << matrix[i][j] << " ";
		}
		std::cout << "\n";
	}
}
void  SorGeneralas(Node * node)
{
	if (node->GetLastNode == false)
	{
		std::vector<Node*> childrens;
		char**matrix = node->GetMatrix();
		char** childrenmatrix = new char*[3];
		Node *children;
		for (int i = 0; i < 3; i++)
		{
			childrenmatrix[i] = new char[3];
			for (int j = 0; j < 3; j++)
				childrenmatrix[i][j] = ' ';
		}
		int freesquares[9][2];				 
		std::vector<Node*>::iterator it;
		std::vector<Node*>::iterator next;
		int index = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (matrix[i][j] == ' ')
				{
					freesquares[index][0] = i;
					freesquares[index][1] = j;
					index++;
				}
			}
		}

		for (int i = 0; i < index; i++)
		{

			children = new  Node(node, matrix);
			std::cout << children << std::endl;
			childrens.push_back(children);
			node->PushBackChildren(children);
			if (i == 0)
				it = childrens.begin();


			childrenmatrix[freesquares[i][0]][freesquares[i][1]] = 'X';

			children->SetMatrix(childrenmatrix);
			bool vege = MatrixVege(childrenmatrix, 'X');
			if (vege)
			{
				children->SetLastNode();
			}
			//std::cout <<"Elõtte"<< std::endl;
			//children->PrintMatrix();
			//std::cout <<" Matrix"<< std::endl;


			//PrintMatrix(matrix); 
			//std::cout <<"Childrenmatrix"<< std::endl;
			//children->PrintMatrix();

			std::cout << std::endl;

			//childrenmatrix = matrix;




			std::cout << "Valami" << std::endl;
			children->PrintMatrix();
			childrenmatrix[freesquares[i][0]][freesquares[i][1]] = ' ';
			std::cout << std::endl;
			children->PrintMatrix();


		}
		for (it = childrens.begin(); it != childrens.end(); ++it)
		{
			if ((it++) != childrens.end())
			{
				next = it++;
				(*it)->SetNextNode(*next);
			}
		}
		node->SetChildrenVector(childrens);
		node->SetSorGeneralas();

	}
}
int main()
{
	char** matrix = new char*[3];
	for (int i = 0; i < 3; i++)
	{
		matrix[i] = new char[3];
		for (int j = 0; j < 3; j++)
			matrix[i][j] = ' ';
	}
	
	Node * root = new Node(NULL, matrix);
	root->SetPotentialchildren();
	root->Generatechildren(root);
	root->PrintMatrix();
	std::cout << std::endl;
	SorGeneralas(root);

	/*std::clock_t start;
	double duration;

	
	start = std::clock();
	for (int i = 0; i < ( 7*6 * 5 * 4 * 3 * 2 * 1); i++)
		Node * rootnode = new Node(NULL, matrix);
	duration = (std::clock() - start)/ (double)CLOCKS_PER_SEC;
	std::cout << "printf: " << duration << '\n';*/
	
	return 0;
}