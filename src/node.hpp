#pragma once
#include <cstddef>
template<class T>
class Node{
    private:
        T data;
        Node<T> *left;
        Node<T> *right;
        //use a pointer to a pointer so that we can dynamically
	    //create a 2d array for our matrix
	    int **matrix;
	    //if we do not use the above we would need to hardcode the
	    //size of the matrix into the declaration
	    //int matrix[SIZE][SIZE]

	    //signify if we have a directed graph or not
	    bool directed;
    public:
       Node(void);
       Node(T &data);
       void set_data(T &new_data);
       void set_left(Node<T> *left_node);
       void set_right(Node<T> *right_node);
       T get_data(void);
       Node<T> *get_left(void);
       Node<T> *get_right(void);
       //add graph
       graph();
	   graph(bool directed);
	   void add(int src, int dst);
	   void print();
};

graph::graph()
{
	//create an array of integer pointers, this takes care of 
	//the first pointer in our double pointer
	matrix = new int*[SIZE];
	//for each index in that array create an array of plain 
	//integers, not pointers to integers
	for(int i=0;i<SIZE;i++)
		matrix[i] = new int[SIZE];

	//initialize all of the elements in our matrix to 0
	for(int i=0;i<SIZE;i++)
		for(int x=0;x<SIZE;x++)
			matrix[i][x] = 0;
	
	//set directed to false
	directed = false;
}

graph::graph(bool dir)
{
	//overloaded constructor for use when we may have a directed graph
	graph();
	directed = dir;
}

void graph::add(int src, int dst)
{
	//set our edge
	matrix[src][dst] = 1;
	//if it is undirected set the implicit second edge
	if(!directed)
		matrix[dst][src] = 1;
}

void graph::print()
{
	cout<<"   ";
	for(int i=0; i<SIZE; i++)
		cout<<setw(3)<<i;
	cout<<endl;

	for(int i=0; i<SIZE; i++)
	{
		cout<<i<<" |";
		for(int x=0; x<SIZE; x++)
			cout<<setw(3)<<matrix[i][x];
		cout<<endl;
	}	
}

template<class T>
Node<T>::Node()
{
    data = 0;
    left = NULL;
    right = NULL;
}

template<class T>
Node<T>::Node(T &new_data)
{
    data = new_data;
    left = NULL;
    right = NULL;
}

template<class T>
void Node<T>::set_data(T &new_data)
{
    data = new_data;
}

template<class T>
T Node<T>::get_data()
{
    return data;
}

template<class T>
void Node<T>::set_left(Node<T> *left_node_ptr)
{
   left = left_node_ptr;
}

template<class T>
void Node<T>::set_right(Node<T> *right_node_ptr)
{
   right = right_node_ptr;
}

template<class T>
Node<T> *Node<T>::get_left()
{
    return left;
}

template<class T>
Node<T> *Node<T>::get_right()
{
    return right;
}
