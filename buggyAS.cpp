#include <iostream>
//add the std vector library
#include <vector>

//use the std namespace to avoid redundancy of std::
using namespace std;

class node {
//define the public portion of the class
public:	
 	int val;
 	node* next;
};

void create_LL(vector<node*>& mylist, int node_num){
    mylist.assign(node_num, NULL);

    //create a set of nodes
    //first error
    //allocate memory on heap for the mylist vector
    for (int i = 0; i < node_num; i++) {
        //Blank C
        //solved the first error
        mylist[i] = new node;
        //changed the . method to the ->
        //since each element in mylist is a object pointer and not an object
        mylist[i]->val = i;
        mylist[i]->next = NULL;
    }

    //create a linked list
    //second error
    //fixed the bounds of iteration because once the loop gets to the 
    //last index, it tries to assign nothing to the previous pointer
    //NOTE: addressSanitizer pointed out that I received an out of bounds error
    //got rid of lots of memory leaks "fa fa fa...""
    for (int i = 0; i < node_num - 1; i++) {
        //changed the . method to the ->
        //since each element in mylist is a object pointer and not an object
        mylist[i]->next = mylist[i+1];
    }
}

int sum_LL(node* ptr) {
    int ret = 0;
    while(ptr) {
        //changed the . method to the ->
        //since each element in mylist is a object pointer and not an object
        ret += ptr->val;
        ptr = ptr->next;
    }
    return ret;
}

int main(int argc, char ** argv){
    const int NODE_NUM = 3;
    vector<node*> mylist;

    create_LL(mylist, NODE_NUM);
    int ret = sum_LL(mylist[0]); 
    cout << "The sum of nodes in LL is " << ret << endl;

    //Step4: delete nodes
    //last error fixed
    //for loop acts a destructor to deallocate the memory after we manipulate it
    //got rid of the rest of my errors
    for(int i = 0; i < NODE_NUM; i++) {
        delete mylist[i];
    }
    //Blank D
}