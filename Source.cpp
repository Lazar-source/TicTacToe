
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
			node->SetDrawNode();
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
					children->SetWinNode();
					
					//std::cout << "Vége" << std::endl;
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
					children->SetLostNode();
					
					//std::cout << "Vége" << std::endl;
				}
			}
			
			//std::cout << &children << "  X bejelölve" << std::endl;
			//PrintMatrix(childrenmatrix);
			children->SetMatrix(childrenmatrix);
			
			
			childrens.push_back(children);
			c.push_back(children);
			a.push_back(children);
			node->PushBackChildren(children);
			if (i == 0)
				it = childrens.begin();
			//std::cout << std::endl;
			//std::cout << "         Children belerakva, mátrix kiiratás" << std::endl;
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
		//std::cout << "Egy sor legenerálva" << std::endl;
		db++;
	}
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	std::cout << "printf: " << duration << '\n'; 
	std::cout << "db:" << db << std::endl;
	for (std::vector <Node*> ::reverse_iterator it = allnode.rbegin(); it != allnode.rend(); it++) {
		Node * parent = (*it)->GetParent();
		int * value = (*it)->GetNodeValue();
		int * parentvalue = parent->GetNodeValue();
		int * winvalue = (*it)->GetWinNode();
		int * drawvalue = (*it)->GetDrawNode();
		int* lostvalue = (*it)->GetLostNode();
		int * parentwinvalue = parent->GetWinNode();
		int * parentdrawvalue = parent->GetDrawNode();
		int* parentlostvalue = parent->GetLostNode();
		//std::cout << "\n";
		//std::cout << "value: " << *value << std::endl;
		//std::cout << "parentvalue: " << *parentvalue << std::endl;
		*parentvalue = *value + *parentvalue;
		*parentwinvalue = *winvalue + *parentwinvalue;
		*parentdrawvalue = *drawvalue + *parentdrawvalue;
		*parentlostvalue = *lostvalue + *parentlostvalue;

		//std::cout << "parentvalue: " << *parentvalue << std::endl;
		int * subtree = (*it)->GetTreeSize();
		int * parentsubtree = parent->GetTreeSize();
		*parentsubtree = *subtree + *parentsubtree + 1;
		//std::cout << "parentsubtree: " << *parentsubtree << std::endl;
		if ((*it)->GetLastNodeValue() == -3)
		{
			
			(*it)->SetClosedNode();
			parent->SetClosedNode();
			
		}
		//std::vector<Node*> nodes = (*it)->GetVect();
		/*if (nodes.size() > 0)
		{
			for (std::vector <Node*> ::iterator itt = nodes.begin(); itt != nodes.end(); itt++)
			{
				if (((*itt)->GetClosedNode()) == true)
				{
					(*it)->SetClosedNode();
					if (parent != NULL)
					{
						parent->SetClosedNode();
					}
					break;
				}
			}
		}*/
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
	bool elso = true;
	while (!vege)
	{

		bool nyertesx = MatrixVege(actualmatrix, 'X');
		bool nyerteso = MatrixVege(actualmatrix, 'O');
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


			int X{ 4 };
			int Y{ 4 };
			std::string input = "";
			bool same = false;
			bool goodcoordinates = false;
			//PrintMatrix(actualmatrix);
			actualnode->PrintMatrix();
			if (index % 2 == 1)
			{
				while (!goodcoordinates)
				{
					X = 4;
					Y = 4;
					while (X > 3 || X < 1)
					{
						//PrintMatrix(actualmatrix);
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
						//PrintMatrix(actualmatrix);
						actualnode->PrintMatrix();
						std::cout << "Kérem adjon meg egy függõleges koordinátát ahová tenni akarja a jelét!(X): " << std::endl;
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
						std::cout << "Rossz koordinátákat adott meg!" << std::endl;
					}
				}
				index--;
			}

			//valahova tesz az emberi játékos



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
			// megkeresi hova tett a játékos

			bool win{ false };
			int torlendochildren{ 0 };
			int elemszam{ 0 };
			actualnodechildrens = actualnode->GetVect();
			if (actualnodechildrens.size() > 0)
			{
				for (std::vector <Node*> ::iterator it = actualnodechildrens.begin(); it != actualnodechildrens.end(); ++it) {
					elemszam++;
					Node* nextnode = (*it);
					std::vector<Node*> nextnodechildrens = nextnode->GetVect();
					int lastnodevalue = (*it)->GetLastNodeValue();
					char** m = (*it)->GetMatrix();
					if (lastnodevalue == 3)
					{
						


							std::cout << lastnodevalue << "ez" << std::endl;
							actualnode = (*it);
							vege = true;
							break;
							actualnode->PrintMatrix();
							nyerteso = MatrixVege(m,'O');
						
					}
					else if (lastnodevalue == 2)
					{
						actualnode = (*it);
						vege = true;
						break;
					}
					/*if (nextnodechildrens.size() > 0)
					{
						for (std::vector <Node*> ::iterator itt = nextnodechildrens.begin(); itt != nextnodechildrens.end(); itt++) {

							Node * nextnextnode = (*itt);
							std::vector<Node*> nextnextnodechildrens = nextnextnode->GetVect();
							for (std::vector<Node*>::iterator ittt = nextnextnodechildrens.begin(); ittt != nextnextnodechildrens.end(); ittt++)
							{


							}
						}
					}*/

					torlendochildren++;
				}


				if (!vege)
				{
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

				
					for (std::vector <Node*> ::iterator iter = actualnodechildrens.begin(); iter != actualnodechildrens.end(); iter++) {
						char ** m = (*iter)->GetMatrix();
						int db{ 0 };

						std::cout << "Ezt nézd" << std::endl;
						bool valami = (*iter)->GetClosedNode();
						std::cout << "iter" << std::endl;
						(*iter)->PrintMatrix();
						std::cout << "actualnode" << std::endl;
						actualnode->PrintMatrix();
						std::cout << "iternodevalue" << std::endl;

						std::cout << *((*iter)->GetNodeValue()) << std::endl;
						std::cout << "itertreesize" << std::endl;
						std::cout << *((*iter)->GetTreeSize()) << std::endl;
						std::cout << "actualnodevalue" << std::endl;
						std::cout << *(actualnode->GetNodeValue()) << std::endl;
						//std::cout << valami << std::endl;
						/*std::cout << *((*iter)->GetWinNode()) << std::endl;
						std::cout << *((*iter)->GetDrawNode()) << std::endl;
						std::cout << *((*iter)->GetLostNode()) << std::endl;*/

						double iternodevalue = *((*iter)->GetNodeValue());
						double actualnodevalue = *(actualnode->GetNodeValue());
						std::cout << iternodevalue << std::endl;
						std::cout << actualnodevalue << std::endl;

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
						std::cout << "Kiiratás" << std::endl;
						actualnode->PrintMatrix();
						PrintMatrix(actualmatrix);

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
				
	
	bool nyertesx = MatrixVege(actualmatrix, 'X');
	bool nyerteso = MatrixVege(actualmatrix, 'O');
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
	return 0;
}