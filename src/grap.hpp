#pragma once

// include this library to use NULL, otherwise use nullptr instead
#include <cstddef>
#include <iostream>
#include "node.hpp"

#define RIGHT 1
#define LEFT 0

using namespace std;

template<class T>
class BST{
public:
    // Constructor for the BST class, creates an empty tree
    BST(void);
    // Destructor for the BST class, destroys the tree
    ~BST(void);
    // Inserts data into the tree
    // param: The data to be inserted into the tree
    void insert(T);
    // Removes data from the tree
    // param: The data to be removed from the tree
    void remove(T);
    // Performs an inorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *inorder(void);
    std::vector<T> *inorder_helper(Node<T> *n);
    // Performs an postorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *postorder(void);
    std::vector<T> *postorder_helper(Node<T> *n);
    // Performs an preorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *preorder(void);
    std::vector<T> *preorder_helper(Node<T> *n);
    // Searches the tree for a given value
    // param: the data to search for
    // returns: a pointer to the node containing the data or NULL if the data
    //          was not found
    Node<T> *search(T);
    Node<T> *get_root();
    // Gets the current number of nodes in the tree
    // returns: the number of nodes in the tree
    int get_size(void);

    // add graph interfaces
    bool empty(T);
    std::vector<T> djikstra(T source, T destination);

    
private:
    // the root node of the tree
    Node<T> *root;
    // the number of nodes in the tree
    int node_count;
};

template<class T>
bool BST<T>::empty(vector<T> set)
 {
     for (int i = 0; i < set.size(); i++)
     {
            if (set[i] == false)
                return false;
     }
     return true;
 }

 template<class T>
void BST<T>::djikstra(T source, T destination)
 {
     vector<bool> vertexSet;
     int distances [nodeCount];
     int min Node;
     int minDistance;

     for (int i = 0; i < nodeCount; i++)
     {
         distances[i] INFINITY;
         vertexSet.push_back(false);
     }

     distances[source] = 0;

     while(!empty(vertexSet))
     {
         minNode = INFINITY;
         minDistance = INFINITY;
         for (int vert = 0; vert < nodeCount; vert++)
         {
             if (vertexSet[vert] == false && distances[vert] <= minDistance)
             {
                 minDistance = distance[vert];
                 minNode = vert;
             }
         }

         vertexSet[minNode] = true;

         for (int vert = 0; vert < nodeCount; vert++)
         {
             if (vertexSet[vert] == false && matrix[minNode][vert])
             {
                 if (distance[minNode] != INFINITY && distances[minNode] + matrix[minNode][vert] < distances[vert])
                 {
                     distances[vert] = distances[minNode] + matrix[minNode][vert];
                 }
             }
         }
     }

    cout<<"Distance from "<< source << " to "<< destination <<" : " << distances[destination] << endl;
 }

template<class T>
BST<T>::BST()
{
    root = NULL;
    node_count = 0;
}

template<class T>
BST<T>::~BST()
{
    root = NULL;
    while(root != NULL)
    {
        remove(root->get_data());
    }
}

template<class T>
 std::vector<T> * BST<T>::inorder()
{
    // return inorder_helper
    return inorder_helper(root);
}

template<class T>
 std::vector<T> * BST<T>::inorder_helper(Node<T> *n)
{
    std::vector<T> *vec = new std::vector<T>;
    std::vector<T> *ret = new std::vector<T>;

    // check if n is null the return
    if (n == NULL) { return NULL;}

    // recur to the left subtree
    ret = inorder_helper(n->get_left());

    if(ret != NULL) 
        vec->insert(vec->end(), ret->begin(), ret->end());

    //THEN GET CURRENT
    vec->push_back(n->get_data());

    // then recur to the right subtree
    ret = inorder_helper(n->get_right());

    if(ret != NULL)
        vec->insert(vec->end(), ret->begin(), ret->end());
    
    return vec;
}

template<class T>
 std::vector<T> * BST<T>::preorder()
{
    // call preorder_helper and return vec
    return preorder_helper(root);
}

template<class T>
 std::vector<T> * BST<T>::preorder_helper(Node<T> *n)
{
    std::vector<T> *vec = new std::vector<T>;
    std::vector<T> *ret = new std::vector<T>;

    if (n == NULL) { return NULL;}

    // first print the data
    // cout <<  n->get_data() << " ";
    vec->push_back(n->get_data());

    // then recur to the left subtree
    ret = preorder_helper(n->get_left());

    if(ret != NULL)
        vec->insert(vec->end(), ret->begin(), ret->end());

    // then recur to the right subtree
    ret = preorder_helper(n->get_right());

    if(ret != NULL)
        vec->insert(vec->end(), ret->begin(), ret->end());
    
    return vec;
}

template<class T>
 std::vector<T> * BST<T>::postorder()
{
    // call and return postorder_heper and return vec
    return postorder_helper(root);
}

template<class T>
 std::vector<T> * BST<T>::postorder_helper(Node<T> *n)
{
    std::vector<T> *vec = new std::vector<T>;
    std::vector<T> *ret = new std::vector<T>;

    if (n == NULL) {return NULL; }

    // recur to the left subtree
    ret = postorder_helper(n->get_left());

    if(ret != NULL)
        vec->insert(vec->end(), ret->begin(), ret->end());

    // recur to the right subtree
    ret = postorder_helper(n->get_right());

    if(ret != NULL)
        vec->insert(vec->end(), ret->begin(), ret->end());

    // NOW THE POST ORDER
    vec->push_back(n->get_data());
    
    return vec;
}

template<class T>
void BST<T>::insert(T new_data)
{
    // node count to count number of insertion
    node_count++;
    Node<T> *data = new Node<T>;

    //check if root is null then insert
    if(root == NULL)
    {
        root = new Node<T>;
        root->set_data(new_data);
    }

    //else use while to check that root is not null then insert
    else
    {
        Node<T>* runner = root;

        while(runner != NULL)
        {
            if(new_data > runner->get_data())
            {
                if(runner->get_right() == NULL)
                {
                    //auto n = new Node<T>;
                    data->set_data(new_data);
                    runner->set_right(data);
                    break;
                }
                else
                {
                    runner = runner->get_right();
                }
            }
            else
            {
                if(runner->get_left() == NULL)
                {
                    //auto n = new Node<T>;
                    data->set_data(new_data);
                    runner->set_left(data);
                    break;
                }
                else
                {
                    runner = runner->get_left();
                }
            }
        }
    }
}


template<class T>
Node<T> *BST<T>::search(T val)
{
    // set runner to root and use it to is not null then search
    Node<T>* runner = root;

    while(runner != NULL)
    {
        T tmp = runner->get_data();
        if(tmp == val)
            return runner;
        else if(val > tmp)
            runner = runner->get_right();
        else
            runner = runner->get_left();
    }

    return NULL;
}

template<class T>
Node<T> *BST<T>::get_root()
{
    //return root
    return root;
}



template<class T>
void BST<T>::remove(T val)
{
    //SO WE FIRST HAVE TO FIND THE NODE POINTER AND ALSO WE HAVE TO KEEP TRACK OF THE PARENT
    //IF IT HAS 2 CHILDREN, THEN ONE CHILD RIGHT, THEN ALL THE WAY LEFT TAKES ITS SPOT
    //IF IT HAS 1 CHILD, THEN THE CHILD TAKES ITS PLACE
    //IF IT HAS NO CHILDREN, THEN WE SET NULL

    //FIND THE NODE
    node_count--;
    Node<T>* runner = root;
    Node<T>* parent = runner;
    T new_root = 0;

    while(runner != NULL)
    {
        T tmp = runner->get_data();
        if(tmp == val)
            break;

        //SET THE PARENT TO HOLD ON
        parent = runner;

        if(val > tmp)
            runner = runner->get_right();
        else
            runner = runner->get_left();
    }

    if(runner == NULL)
        return;

    if(runner == root)
        new_root = 1;

    //CHECK IF IT IS LEFT OR RIGHT OF THE PARENT (0 for left 1 for right)
    int dir = runner->get_data() > parent->get_data() ? RIGHT : LEFT;
    //IF THERE ARE NO CHILDREN
    if(runner->get_left() == NULL && runner->get_right() == NULL)
    {
        //IF THIS IS THE ROOT
        if(new_root)
            root = NULL;
        else
        {
            if(dir == RIGHT)
                parent->set_right(NULL);
            else if(dir == LEFT)
                parent->set_left(NULL);
        }

        delete(runner);
    }

    //IF THERE IS 1 RIGHT CHILD
    else if(runner->get_right() != NULL && runner->get_left() == NULL)
    {
        //IF WE DELETED THE ROOT
        if(new_root)
            root = runner->get_right();
        else
        {
            if(dir == RIGHT)
                parent->set_right(runner->get_right());
            else if(dir == LEFT)
                parent->set_left(runner->get_right());
         }

        delete(runner);
    }

    //IF THERE IS 1 LEFT CHILD
    else if(runner->get_left() != NULL && runner->get_right() == NULL)
    {
        //IF WE DELETED THE ROOT
        if(new_root)
            root = runner->get_left();
        else
        {
            if(dir == RIGHT)
                parent->set_right(runner->get_left());
            else if(dir == LEFT)
                parent->set_left(runner->get_left());
        }

        delete(runner);
    }

    //IF THERE ARE 2 CHILDREN
    else
    {
        //FIND THE SMALLEST VAL BIGGER THAN OUR RUNNER
        Node<T>* smallest_bigger_child = runner->get_right();
        int mov_val = -1;

        //CHECK IF JUST ONE DEEP
        if(smallest_bigger_child->get_left() == NULL)
        {
            mov_val = smallest_bigger_child->get_data();
            runner->set_data(mov_val);
            runner->set_right(smallest_bigger_child->get_right());

            delete(smallest_bigger_child);
        }
        //OTHERWISE WE CAN KEEP GOING LEFT
        else
        {
            //WALK TO THE BOTTOM
            while(smallest_bigger_child->get_left()->get_left() != NULL)
                smallest_bigger_child = smallest_bigger_child->get_left();

            //HOLD PARENT OF FINAL LEFTMOST NODE
            Node<T>* new_found_parent = smallest_bigger_child;
            smallest_bigger_child = new_found_parent->get_left();

            //FIX THE RIGHT NOW
            new_found_parent->set_left(smallest_bigger_child->get_right());

            //SET THE CORRECT VAL INTO THE RUNNER
            mov_val = smallest_bigger_child->get_data();
            runner->set_data(mov_val);
            delete(smallest_bigger_child);
        }
    }

    return;
}

template<class T>
int BST<T>::get_size()
{
    return node_count;  
}