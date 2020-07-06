
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
		
		char**matrix = node->GetMatrix();
		int freesquares[9][2];				 
		std::vector<Node*>::iterator it;
		std::vector<Node*>::iterator next;
		int index{ 0 };
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
			
			char**matrix = node->GetMatrix();
			Node *children= new Node(node, matrix);
			
			char** childrenmatrix = new char*[3];

			for (int i = 0; i < 3; i++)
			{
				childrenmatrix[i] = new char[3];
				for (int j = 0; j < 3; j++)
					childrenmatrix[i][j] = matrix[i][j];
			}
			
			if (index % 2 == 0)
			{
				childrenmatrix[freesquares[i][0]][freesquares[i][1]] = 'O';
				bool vege = MatrixVege(childrenmatrix, 'O');
				if (vege)
				{
					children->SetLastNode(vege);
					children->SetLastNodeValue('O');
					
					
					
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
					
					
					
				}
			}
			
			children->SetMatrix(childrenmatrix);
			childrens.push_back(children);
			c.push_back(children);
			a.push_back(children);
			node->PushBackChildren(children);
			if (i == 0)
				it = childrens.begin();
			
			childrenmatrix[freesquares[i][0]][freesquares[i][1]] = ' ';
			


		}
		node->SetChildrenVector(childrens);
		node->SetSorGeneralas();

	}
}
void Jatekeleje(char ** matrix)

{
	int X{ 4 };
	int Y{ 4 };
	std::string input = "";
	while (X > 3 || X < 1)
	{
		PrintMatrix(matrix);
		std::cout << "Kérem adjon meg egy vízszintes koordinátát ahová tenni akarja a jelét!(X): " << std::endl;
		std::cin >> input;
		std::stringstream myStream(input);
		if (myStream >> X);
		system("cls");

	}
	while (Y > 3 || Y < 1)
	{
		std::cout << "Vízszintes: " << X << std::endl;;
		PrintMatrix(matrix);
		std::cout << "Kérem adjon meg egy függõleges koordinátát ahová tenni akarja a jelét!(X): " << std::endl;
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

	
	char ** m = node->GetMatrix();
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
	int db{ 0 };
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
	
	Node  *root= new Node(NULL, matrix);
	
	SorGeneralas(root,children,allnode);
	while (children.size()!=0)
	{
		SorGeneralas(*children.begin(), children,allnode);
		children.erase(children.begin());
		db++;
	}
	for (std::vector <Node*> ::reverse_iterator it = allnode.rbegin(); it != allnode.rend(); it++) {
		Node * parent = (*it)->GetParent();
		int * value = (*it)->GetNodeValue();
		int * parentvalue = parent->GetNodeValue();
		
		*parentvalue = *value + *parentvalue;
		

		
		if ((*it)->GetLastNodeValue() == -3)
		{
			
			(*it)->SetClosedNode();
			parent->SetClosedNode();
			
		}
		
	}
	int index{ 0 };
	
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
	bool nyertesx = MatrixVege(actualmatrix, 'X');
	bool nyerteso = MatrixVege(actualmatrix, 'O');

	system("cls");
	bool elso{ true };
	while (!vege)
	{

		
		if (nyertesx)
		{
			vege = true;
			system("cls");
			std::cout << "Gratulálok ön Nyert!" << std::endl;
		}
		else if (nyerteso)
		{
			vege = true;
			system("cls");
			std::cout << "Sajnos most a gép nyert!" << std::endl;
		}
		else
		{

			system("cls");
			int X{ 4 };
			int Y{ 4 };
			std::string input = "";
			bool same = false;
			bool goodcoordinates = false;
			actualnode->PrintMatrix();
			if (index % 2 == 1)
			{
				while (!goodcoordinates)
				{
					X = 4;
					Y = 4;
					while (X > 3 || X < 1)
					{
						actualnode->PrintMatrix();
						std::cout << "Kérem adjon meg egy vízszintes koordinátát ahová tenni akarja a jelét!(X): " << std::endl;
						std::cin >> input;
						std::stringstream myStream(input);
						if (myStream >> X);
						system("cls");

					}
					while (Y > 3 || Y < 1)
					{
						std::cout << "Vízszintes: " << X << std::endl;;
						actualnode->PrintMatrix();
						std::cout << "Kérem adjon meg egy függõleges koordinátát ahová tenni akarja a jelét!(X): " << std::endl;
						std::cin >> input;
						std::stringstream myStream(input);
						if (myStream >> Y);
						

					}
					if (actualmatrix[Y - 1][X - 1] != 'X'&&actualmatrix[Y - 1][X - 1] != 'O')
					{
						goodcoordinates = true;
						actualmatrix[Y - 1][X - 1] = 'X';




					}
					else
					{
						system("cls");
						std::cout << "Rossz koordinátákat adott meg!" << std::endl;
					}
				}
				index--;
			}
			bool goodchild = false;

			std::vector<Node*> actualnodechildrens = actualnode->GetVect();
			for (std::vector <Node*> ::iterator it = actualnodechildrens.begin(); it != actualnodechildrens.end(); it++) {
				Node * temporarynode = (*it);
				same = SameMatrix(actualmatrix, temporarynode);

				if (same)
				{
					actualnode = (*it);
					break;
				}

			}

			bool win{ false };
			
			actualnodechildrens = actualnode->GetVect();
			if (actualnodechildrens.size() > 0)
			{
				for (std::vector <Node*> ::iterator it = actualnodechildrens.begin(); it != actualnodechildrens.end(); ++it) {
					
					Node* nextnode = (*it);
					std::vector<Node*> nextnodechildrens = nextnode->GetVect();
					int lastnodevalue = (*it)->GetLastNodeValue();
					char** m = (*it)->GetMatrix();
					if (lastnodevalue == 3)
					{
							actualnode = (*it);
							vege = true;
							actualnode->PrintMatrix();
							nyerteso = MatrixVege(m,'O');
							break;
						
					}
					else if (lastnodevalue == 2)
					{
						actualnode = (*it);
						vege = true;
						break;
					}
					

					
				}


				if (!vege)
				{
					actualnode = *(actualnodechildrens.begin());
					char** m = actualnode->GetMatrix();
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							actualmatrix[i][j] = m[i][j];

						}
					}

				
					for (std::vector <Node*> ::iterator iter = actualnodechildrens.begin(); iter != actualnodechildrens.end(); iter++) {
						char ** m = (*iter)->GetMatrix();
						int iternodevalue{ *((*iter)->GetNodeValue()) };
						int actualnodevalue{ *(actualnode->GetNodeValue()) };

						if (elso)
						{

							if ((100 - abs(iternodevalue)) > (100 - abs(actualnodevalue)))

							{


								if (((*iter)->GetClosedNode()) != true)
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

						else
						{
							if (iternodevalue > actualnodevalue)

							{
								std::vector<Node*> iterchildrens = (*iter)->GetVect();
								bool end = false;
								for (std::vector <Node*> ::iterator itter = iterchildrens.begin(); itter != iterchildrens.end(); itter++)
								{
									if ((*itter)->GetClosedNode() == true)
									{
										end = true;
									}
								}
								if (!end)
								{

									if (((*iter)->GetClosedNode()) != true)
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
						}

					}
					elso = false;
					index--;
				}

			}
			else
			{
				vege = true;


			}


		}
			
		
	}
				
	
	if (nyertesx)
	{
		system("cls");
		std::cout << "Gratulálok ön Nyert!" << std::endl;
	}
	else if (nyerteso)
	{
		system("cls");
		std::cout << "Sajnos most a gép nyert!" << std::endl;
	}
	else
	{
		system("cls");
		std::cout << "A játék döntetlennel zárult!" << std::endl;
	}
	return 0;
}