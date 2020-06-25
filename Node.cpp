#include "Node.h"
#include <iostream>
void Node::SetPotentialchildren()
{
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{

			if (Node::matrix[i][j] == ' ')
			{
				potentialchildren++;
			}
		}
	}
	std::cout << "potentialchildren: " << potentialchildren << std::endl;
}

void Node::Generatechildren(Node * par)
{
	for (int i = 0; i < Node::potentialchildren; i++)
	{
	
		Node * childrennode = new Node(par,matrix);
		children.push_back(childrennode);
		it = children.begin();
		//std::cout << childrennode << " " << i << std::endl;

	}

}
Node * Node::GetChildren()
{
	
	if (db!=potentialchildren)
	{
		it++;
		db++;
		return (*it);
	}
	else
	{
		return nullptr;
	}
	
	
		

}
char ** Node::GetMatrix()
{
	return matrix;
}
int  Node::GetPotentialChildren()
{
	std::cout << "potentialchildren: " << potentialchildren << std::endl;
	return potentialchildren;
}
void Node::SetMatrix(char ** m)
{
	matrix = m;

}
void Node::PrintMatrix()
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
void Node::PushBackChildren(Node * c)
{
	children.push_back(c);
}
void Node::SetChildrenVector(std::vector<Node*> c)
{
	children = c;
}
void Node::SetSorGeneralas()
{
	sorgeneralas = true;
}
void Node::SetNextNode(Node * nn)
{
	nextnode = nn;
}
void Node::SetLastNode()
{
	lastnode = true;
}
bool Node::GetLastNode()
{
	return lastnode;
}
Node::Node(Node * p, char** m )
{
	Node::parent = p;
	Node::matrix = m;
	Node::potentialchildren = 0;
	Node::db = 0;
	Node::sorgeneralas = false;
	nextnode = nullptr;
	lastnode = false;
	
}
