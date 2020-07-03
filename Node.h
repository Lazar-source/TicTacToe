#pragma once
#include <string>
#include <vector>

class Node
{
	private:	
		char ** matrix;
		Node * parent;
		std::vector<Node*> children;
		int potentialchildren;
		std::vector<Node*>::iterator it;
		int db;
		bool sorgeneralas;
		Node* nextnode;
		bool lastnode;
		int lastnodevalue;
		int nodevalue;
		int subtreesize;
	

	public:
		Node(Node * p, char ** m);
		void SetPotentialchildren();
		void Generatechildren(Node * par);
		char** GetMatrix();
		int GetPotentialChildren();
		void SetMatrix(char ** m);
		void PrintMatrix();
		void PushBackChildren(Node * c);
		void SetChildrenVector(std::vector<Node*> c);
		void SetSorGeneralas();
		void SetNextNode(Node * nn);
		void SetLastNode(bool vege);
		bool GetLastNode();
		void SetLastNodeValue(char c);
		Node * GetParent();
		int* GetNodeValue();
		int * GetTreeSize();
		std::vector<Node*> GetVect();
		int GetLastNodeValue();


};

