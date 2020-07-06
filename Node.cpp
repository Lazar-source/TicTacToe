#include "Node.h"
#include <iostream>




char ** Node::GetMatrix()
{
	return matrix;
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
	std::cout << "   1  2  3" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << (i + 1) << " ";
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
		lastnodevalue=-3 ;
	}
	else if (c == 'O')
	{
		lastnodevalue=3 ;
	}
	else if (c == 'D')
	{
		lastnodevalue = 2;
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


std::vector<Node*> Node::GetVect()
{
	
		return children;
	

	
}
int Node::GetLastNodeValue()
{
	return lastnodevalue;
}
void Node::SetClosedNode()
{
	closednode = true;
}
bool Node::GetClosedNode()
{
	return closednode;
}



Node::Node(Node * p, char** m ): parent(p)
{
	
	
	Node::db= 0 ;
	Node::sorgeneralas = false;
	Node:: matrix=new char*[3];
	lastnode = false;
	for (int i = 0; i < 3; i++)
	{
		matrix[i] = new char[3];
		for (int j = 0; j < 3; j++)
		{
			matrix[i][j] = m[i][j];
		}
	}
	
}

