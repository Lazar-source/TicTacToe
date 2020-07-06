#pragma once
#include <string>
#include <vector>

class Node
{
	private:	
		char ** matrix;
		Node * parent;
		std::vector<Node*> children;
		std::vector<Node*>::iterator it;
		int db;
		bool sorgeneralas;
		bool lastnode;
		int lastnodevalue;
		int nodevalue;
		bool closednode;	
	public:
		Node(Node * p, char ** m);
		char** GetMatrix();
		void SetMatrix(char ** m);
		void PrintMatrix();
		void PushBackChildren(Node * c);
		void SetChildrenVector(std::vector<Node*> c);
		void SetSorGeneralas();
		void SetLastNode(bool vege);
		bool GetLastNode();
		void SetLastNodeValue(char c);
		Node * GetParent();
		int* GetNodeValue();
		std::vector<Node*> GetVect();
		int GetLastNodeValue();
		void SetClosedNode();
		bool GetClosedNode();

};

