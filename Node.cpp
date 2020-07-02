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
	for (int  i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrix[i][j] = m[i][j];
		}
	}
	

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
void Node::SetLastNode(bool vege)
{
	lastnode = vege;
}
bool Node::GetLastNode()
{
	return lastnode;
}
void Node::SetLastNodeValue(char c)
{
	if (c == 'X')
	{
		lastnodevalue = -1;
	}
	else if (c == 'O')
	{
		lastnodevalue = 2;
	}
	else if (c == 'D')
	{
		lastnodevalue = 1;
	}
	nodevalue = lastnodevalue;

}
Node * Node::GetParent()
{
	return parent;
}
int *Node::GetNodeValue()
{
	return &nodevalue;
}
int * Node::GetTreeSize()
{
	return &subtreesize;
}
Node * Node::GetMuchValueChild()
{
	
	Node * Child = *(children.begin());
	for( it = children.begin(); it != children.end(); it++)
	{
		
		if (((*it)->GetNodeValue()) > (Child->GetNodeValue()))
		{
			Child = (*it);
		}
		


	}
	
	return Child ;
}
std::vector<Node*> Node::GetVect()
{
	return children;
}
int Node::GetLastNodeValue()
{
	return lastnodevalue;
}
Node::Node(Node * p, char** m )
{
	Node::parent = p;
	Node::potentialchildren = 0;
	Node::db = 0;
	Node::sorgeneralas = false;
	Node:: matrix=new char*[3];
	nextnode = nullptr;
	lastnode = false;
	for (int i = 0; i < 3; i++)
	{
		matrix[i] = new char[3];
		for (int j = 0; j < 3; j++)
		{
			matrix[i][j] = m[i][j];
		}
	}
	subtreesize = 0;
	
}

