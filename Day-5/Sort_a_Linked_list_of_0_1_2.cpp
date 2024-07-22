//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        Node*zero=NULL,*one=NULL,*two=NULL;
        Node*zeroH=NULL,*oneH=NULL,*twoH=NULL;
        
    
        while(head)
        {
            if(head->data==0){
                if(zeroH==NULL){
                    zeroH=head;
                    zero=head;
                }else{
                    zero->next=head;
                    zero=zero->next;
                }
            }else if(head->data==1){
                 if(oneH==NULL){
                    oneH=head;
                    one=head;
                }else{
                    one->next=head;
                    one=one->next;
                }
            }else{
                 if(twoH==NULL){
                    twoH=head;
                    two=head;
                }else{
                    two->next=head;
                    two=two->next;
                }
            }
            head=head->next;
        }
        
        if(zero!=NULL){
        if(oneH!=NULL)
        zero->next=oneH;
        else zero->next=twoH;
        }
        if(one!=NULL)
        one->next=twoH;
        if(two!=NULL)
        two->next=NULL;
        
        if(zeroH!=NULL) return zeroH;
        if(oneH!=NULL) return oneH;
        if(twoH!=NULL) return twoH;
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends
