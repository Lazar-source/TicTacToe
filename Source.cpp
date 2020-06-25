
#include "time.h"
#include "Node.h"
#include <iostream>
#include <cstdio>
#include <ctime>
bool MatrixVege(char ** matrix,char j)
{

	if (matrix[0][0] == j && matrix[0][1] == j && matrix[0][2] == j)
	{return true;} 
	else if (matrix[1][0] == j && matrix[1][1] == j && matrix[1][2] == j)
	{return true;}
	else if (matrix[2][0] == j && matrix[2][1] == j && matrix[2][2] == j)
	{return true;}
	else if (matrix[0][0] == j && matrix[1][0] == j && matrix[2][0] == j)
	{return true;}
	else if (matrix[0][1] == j && matrix[1][1] == j && matrix[2][1] == j)
	{return true;}
	else if (matrix[0][2] == j && matrix[1][2] == j && matrix[2][2] == j)
	{return true;}
	else if (matrix[0][0] == j && matrix[1][1] == j && matrix[2][2] == j)
	{return true;}
	else if(matrix[2][0] == j && matrix[1][1] == j && matrix[0][2] == j) 
	{return true;}
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
void  SorGeneralas(Node * node,std::vector<Node* > &c)
{
	bool lastnode = node->GetLastNode();
	if (lastnode == false)
	{
		std::vector<Node*> childrens;
		
		//std::cout << matrix << std::endl;
		char**matrix = node->GetMatrix();
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
			/*for (int j  = 0; j < 9; j++)
			{
				for (int  k = 0; k < 2; k++)
				{
					std::cout << freesquares[j][k] << std::endl;
				}
			}*/
			char**matrix = node->GetMatrix();
			Node *children= new Node(node, matrix);
			
			char** childrenmatrix = new char*[3];

			for (int i = 0; i < 3; i++)
			{
				childrenmatrix[i] = new char[3];
				for (int j = 0; j < 3; j++)
					childrenmatrix[i][j] = matrix[i][j];
			}
			std::cout << &children<<"  Eredeti:" << std::endl;
			PrintMatrix(childrenmatrix);
			int valami = freesquares[i][0];
			int valami1 = freesquares[i][1];
			childrenmatrix[freesquares[i][0]][freesquares[i][1]] = 'X';
			std::cout << &children << "  X bejel�lve" << std::endl;
		//	PrintMatrix(childrenmatrix);
			children->SetMatrix(childrenmatrix);
			bool vege = MatrixVege(childrenmatrix, 'X');
			if (vege)
				{
					children->SetLastNode(vege);
					std::cout << "V�ge" << std::endl;
				}
			childrens.push_back(children);
			c.push_back(children);
			node->PushBackChildren(children);
			if (i == 0)
				it = childrens.begin();
			std::cout << std::endl;
			std::cout << "         Children belerakva, m�trix kiirat�s" << std::endl;
			children->PrintMatrix();
			childrenmatrix[freesquares[i][0]][freesquares[i][1]] = ' ';
			std::cout << std::endl;
	//		children->PrintMatrix();


		}
		/*for (it = childrens.begin(); it != childrens.end(); it++)
		{
			if ((it++) != childrens.end())
			{
				next = it++;
				(*it)->SetNextNode(*next);
			}
		}*/
		node->SetChildrenVector(childrens);
		node->SetSorGeneralas();

	}
}
int main()
{
	std::vector<Node*> children;
	char** matrix = new char*[3];
	for (int i = 0; i < 3; i++)
	{
		matrix[i] = new char[3];
		for (int j = 0; j < 3; j++)
			matrix[i][j] = ' ';
	}
	
	Node  *root= new Node(NULL, matrix);
	//children.push_back(root);
	root->SetPotentialchildren();
	root->Generatechildren( root);
	root->PrintMatrix();
	std::cout << std::endl;
	SorGeneralas(root,children);
	std::cout << std::endl;
	std::clock_t start;
	double duration;
	start = std::clock();
	while (children.size()!=0)
	{
		SorGeneralas(*children.begin(), children);
	//	std::cout << "Elem" <<*children.begin()<< std::endl;
		children.erase(children.begin());
		//std::cout << "Elem" << *children.begin() << std::endl;
		//std::cout << "Egy sor legener�lva" << std::endl;
	}
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	std::cout << "printf: " << duration << '\n'; 
	/*std::clock_t start;
	double duration;

	
	start = std::clock();
	for (int i = 0; i < ( 7*6 * 5 * 4 * 3 * 2 * 1); i++)
		Node * rootnode = new Node(NULL, matrix);
	duration = (std::clock() - start)/ (double)CLOCKS_PER_SEC;
	std::cout << "printf: " << duration << '\n';*/
	
	return 0;
}