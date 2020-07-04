
#include "time.h"
#include "Node.h"
#include <iostream>
#include <cstdio>
#include <ctime>
#include <sstream>
#include <string>

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
	std::cout << "   1  2  3" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << (i+1) << " ";
		for (int j = 0; j < 3; j++)
		{
			if (matrix[i][j] == 'X' || matrix[i][j] == 'O')
				std::cout << " " << matrix[i][j] << " ";
			else
				std::cout << " - ";

		}
		std::cout << "\n";
	}
}
void  SorGeneralas(Node * node,std::vector<Node* > &c, std::vector <Node*> &a)
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
		if (index == 0)
		{
			node->SetLastNode(true);
			node->SetLastNodeValue('D');
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
			//std::cout << &children<<"  Eredeti:" << std::endl;
			//PrintMatrix(childrenmatrix);
			//int valami = freesquares[i][0];
			//int valami1 = freesquares[i][1];
			if (index % 2 == 0)
			{
				childrenmatrix[freesquares[i][0]][freesquares[i][1]] = 'O';
				bool vege = MatrixVege(childrenmatrix, 'O');
				if (vege)
				{
					children->SetLastNode(vege);
					children->SetLastNodeValue('O');
					//std::cout << "V�ge" << std::endl;
				}
			}
			else
			{
				childrenmatrix[freesquares[i][0]][freesquares[i][1]] = 'X';
				bool vege = MatrixVege(childrenmatrix, 'X');
				if (vege)
				{
					children->SetLastNode(vege);
					children->SetLastNodeValue('X');
					//std::cout << "V�ge" << std::endl;
				}
			}
			
			//std::cout << &children << "  X bejel�lve" << std::endl;
			//PrintMatrix(childrenmatrix);
			children->SetMatrix(childrenmatrix);
			
			
			childrens.push_back(children);
			c.push_back(children);
			a.push_back(children);
			node->PushBackChildren(children);
			if (i == 0)
				it = childrens.begin();
			//std::cout << std::endl;
			//std::cout << "         Children belerakva, m�trix kiirat�s" << std::endl;
			//children->PrintMatrix();
			childrenmatrix[freesquares[i][0]][freesquares[i][1]] = ' ';
			//std::cout << std::endl;
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
void Jatekeleje(char ** matrix)

{
	int X = 4;
	int Y = 4;
	std::string input = "";
	while (X > 3 || X < 1)
	{
		PrintMatrix(matrix);
		std::cout << "K�rem adjon meg egy v�zszintes koordin�t�t ahov� tenni akarja a jel�t!(X): " << std::endl;
		std::cin >> input;
		std::stringstream myStream(input);
		if (myStream >> X);
		system("cls");

	}
	while (Y > 3 || Y < 1)
	{
		std::cout << "V�zszintes: " << X << std::endl;;
		PrintMatrix(matrix);
		std::cout << "K�rem adjon meg egy f�gg�leges koordin�t�t ahov� tenni akarja a jel�t!(X): " << std::endl;
		std::cin >> input;
		std::stringstream myStream(input);
		if (myStream >> Y);
		system("cls");

	}
	matrix[(Y-1)][(X-1)] = 'X';
	if (matrix[1][1] != 'X')
	{
		matrix[1][1] = 'O';
	}

}
bool SameMatrix(char**matrix, Node * node)
{

	system("cls");
	PrintMatrix(matrix);
	char ** m = node->GetMatrix();
	PrintMatrix(m);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (matrix[i][j] != m[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	setlocale(LC_ALL, "");
	bool vege = false;
	int db = 0;
	std::vector<Node*> children;
	std::vector<Node*> allnode;
	char** matrix = new char*[3];
	for (int i = 0; i < 3; i++)
	{
		matrix[i] = new char[3];
		for (int j = 0; j < 3; j++)
			matrix[i][j] = ' ';
	}
	Jatekeleje(matrix);
	//matrix[0][0] = 'X';
	//matrix[1][1] = 'O';
	Node  *root= new Node(NULL, matrix);
	//children.push_back(root);
	root->SetPotentialchildren();
	root->Generatechildren( root);
	root->PrintMatrix();
	std::cout << std::endl;
	SorGeneralas(root,children,allnode);
	std::cout << std::endl;
	std::clock_t start;
	double duration;
	start = std::clock();
	while (children.size()!=0)
	{
		SorGeneralas(*children.begin(), children,allnode);
	//	std::cout << "Elem" <<*children.begin()<< std::endl;
		children.erase(children.begin());
		//std::cout << "Elem" << *children.begin() << std::endl;
		//std::cout << "Egy sor legener�lva" << std::endl;
		db++;
	}
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	std::cout << "printf: " << duration << '\n'; 
	std::cout << "db:" << db << std::endl;
	for (std::vector <Node*> ::reverse_iterator it = allnode.rbegin(); it != allnode.rend(); it++) {
		Node * parent = (*it)->GetParent();
		int * value = (*it)->GetNodeValue();
		int * parentvalue = parent->GetNodeValue();
		//std::cout << "\n";
		//std::cout << "value: " << *value << std::endl;
		//std::cout << "parentvalue: " << *parentvalue << std::endl;
		*parentvalue = *value + *parentvalue;
		//std::cout << "parentvalue: " << *parentvalue << std::endl;
		int * subtree = (*it)->GetTreeSize();
		int * parentsubtree = parent->GetTreeSize();
		*parentsubtree = *subtree + *parentsubtree + 1;
		//std::cout << "parentsubtree: " << *parentsubtree << std::endl;
	}
	int index = 0;
	
	char** actualmatrix = new char*[3];
	for (int i = 0; i < 3; i++)
	{
		actualmatrix[i] = new char[3];
		for (int j = 0; j < 3; j++)
		{
			actualmatrix[i][j] = matrix[i][j];
			if (actualmatrix[i][j] == ' ')
			{
				index++;
			}
		}
	}
	Node * actualnode = root;
	

	system("cls");
	while (!vege)
	{


		int X = 4;
		int Y = 4;
		std::string input = "";
		bool same = false;
		bool goodcoordinates = false;
		//PrintMatrix(actualmatrix);
		actualnode->PrintMatrix();
		while (!goodcoordinates)
		{
			while (X > 3 || X < 1)
			{
				//PrintMatrix(actualmatrix);
				actualnode->PrintMatrix();
				std::cout << "K�rem adjon meg egy v�zszintes koordin�t�t ahov� tenni akarja a jel�t!(X): " << std::endl;
				std::cin >> input;
				std::stringstream myStream(input);
				if (myStream >> X);
				system("cls");

			}
			while (Y > 3 || Y < 1)
			{
				std::cout << "V�zszintes: " << X << std::endl;;
				//PrintMatrix(actualmatrix);
				actualnode->PrintMatrix();
				std::cout << "K�rem adjon meg egy f�gg�leges koordin�t�t ahov� tenni akarja a jel�t!(X): " << std::endl;
				std::cin >> input;
				std::stringstream myStream(input);
				if (myStream >> Y);
				//system("cls");

			}
			if (actualmatrix[Y - 1][X - 1] != 'X'&&actualmatrix[Y - 1][X - 1] != 'O')
			{
				goodcoordinates = true;
				actualmatrix[Y - 1][X - 1] = 'X';
				
					
				

			}
			else
			{
				std::cout << "Rossz koordin�t�kat adott meg!" << std::endl;
			}
		}
		//valahova tesz az emberi j�t�kos



		//system("cls");
		PrintMatrix(actualmatrix);




		bool goodchild = false;

		std::vector<Node*> actualnodechildrens = actualnode->GetVect();
		for (std::vector <Node*> ::iterator it = actualnodechildrens.begin(); it != actualnodechildrens.end(); it++) {
			Node * temporarynode = (*it);
			same = SameMatrix(actualmatrix, temporarynode);
			
			if (same)
			{
				actualnode = (*it);
				//allnode.erase(allnode.begin(), allnode.begin() + (elem - 1));
				break;
			}

		}  
		std::cout << std::endl << "Valami" << std::endl;
		actualnode->PrintMatrix();
		PrintMatrix(actualmatrix);
		// megkeresi hova tett a j�t�kos

		bool win = false;
		int torlendochildren = 0;
		int elemszam = 0;;
		 actualnodechildrens = actualnode->GetVect();
		
		for (std::vector <Node*> ::iterator it = actualnodechildrens.begin(); it != actualnodechildrens.end(); ++it) {
			elemszam++;
			Node* nextnode = (*it);
			std::vector<Node*> nextnodechildrens = nextnode->GetVect();
			if ((*it)->GetLastNodeValue() == 2)
			{
				actualnode = (*it);
				vege = true;
				break;
			}
			else if ((*it)->GetLastNodeValue() == 1)
			{
				actualnode = (*it);
				vege = true;
				break;
			}
			if (nextnodechildrens.size() > 0)
			{
				for (std::vector <Node*> ::iterator itt = nextnodechildrens.begin(); itt != nextnodechildrens.end(); itt++) {

					if ((*itt)->GetLastNodeValue() == -1)
					{
						(*it)->SetClosedNode();
						break;
					}
				}
			}
			
			torlendochildren++;
		}

		
			
				actualnode->PrintMatrix();
				actualnode = *(actualnodechildrens.begin());
				actualnode->PrintMatrix();
				char** m = actualnode->GetMatrix();
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						actualmatrix[i][j] = m[i][j];

					}
				}

				if (!vege)
				{
					for (std::vector <Node*> ::iterator iter = actualnodechildrens.begin(); iter != actualnodechildrens.end(); iter++) {
						std::cout << "Ezt n�zd" << std::endl;
						(*iter)->PrintMatrix();
						//actualnode->PrintMatrix();
						std::cout << *((*iter)->GetNodeValue()) << std::endl;
						std::cout << *((*iter)->GetTreeSize()) << std::endl;
						double iternodevalue = (double)*((*iter)->GetNodeValue()) / (double)*((*iter)->GetTreeSize());
						//double actualnodevalue = actualnode->GetNodeValue() / actualnode->GetTreeSize();
						std::cout << iternodevalue << std::endl;
						//std::cout << actualnodevalue << std::endl;
						if (true)

						{


							if ((*iter)->GetClosedNode() != true)
							{
								actualnode = (*iter);
								char** m = actualnode->GetMatrix();
								for (int i = 0; i < 3; i++)
								{
									for (int j = 0; j < 3; j++)
									{
										actualmatrix[i][j] = m[i][j];

									}
								}
							}
						}


					}
					std::cout << "Kiirat�s" << std::endl;
					actualnode->PrintMatrix();
					PrintMatrix(actualmatrix);
				}
				



			
		
	}
				
				
			

			


	
	/*std::clock_t start;
	double duration;

	
	start = std::clock();
	for (int i = 0; i < ( 7*6 * 5 * 4 * 3 * 2 * 1); i++)
		Node * rootnode = new Node(NULL, matrix);
	duration = (std::clock() - start)/ (double)CLOCKS_PER_SEC;
	std::cout << "printf: " << duration << '\n';*/
	
	return 0;
}