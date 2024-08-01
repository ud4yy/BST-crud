// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    struct Node *next;
    int data;
};

struct Node* arrtoLL(int *arr,int n){
    struct Node *temp= (struct Node*)malloc(sizeof(struct Node));
    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
    temp->next=t;
    for(int i=0;i<n;i++){
        struct Node* n =  (struct Node*)malloc(sizeof(struct Node));
        n->data=arr[i];
        n->next=NULL;
        t->next=n;
        t=t->next;
    }
    return temp->next->next;
}
struct Node* insertAtHead(struct Node *head,int val){
    if(head==NULL) return head;
    struct Node* h = (struct Node*) malloc(sizeof(struct Node));
    h->data=val;
    h->next = head;
    return h;
}

void printLL(struct Node* head){
printf("Printing Linked list \n");
printf("_______________________________________________ \n");
   while(head!=NULL){
        printf("%d \n",head->data);
        head=head->next;
    } 
}
void printRev(struct Node *h){
    if(h==NULL){
        return;
    }
  
    printRev(h->next);
    printf("%d \n",h->data);
}
struct Node *insertAtSpecific(struct Node *head,int pos,int x){
    if(pos==1){
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data=x; 
        newNode->next=head;
        return newNode;
    }
    if(head==NULL) return head;
    struct Node *temp = head;
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=x;
    int cnt=1;
    
    while(temp!=NULL && cnt<pos-1){
        temp=temp->next;
        cnt++;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    
    return head;
}
//Recurse and in base case return the Newhead last node
// back track change the links
struct Node *Reverse(struct Node* node){
    if(node->next==NULL){
        return node;
    }
    
    struct Node *newHead =  Reverse(node->next);
    struct Node *front  = node->next;
    front->next = node;
    node->next = NULL;
    return newHead;
}

struct Node *IterativeR(struct Node *head){
    struct Node *prev = NULL;
    struct Node *temp=head;
    
    while(temp!=NULL){
        struct Node* next = temp->next;
        temp->next=prev;
        prev = temp;
        temp = next;
    }
    return prev;
}
/* 
[1,2,3,4,5] middle = 3
[1,2,3,4] middle = 3
*/
struct Node* FindMiddle(struct Node *head){
    struct Node *fast = head;
    struct Node *slow = head;
    
    while(fast!=NULL && fast->next==NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

bool isLoop(struct Node *head){
    struct Node *slow=head;
    struct Node *fast=head;
    
    while(fast!=NULL && fast->next!=NULL){
        if(fast==slow) return true;
        slow=slow->next;
        fast=fast->next->next;
    }
    return false;
}
void LoopNode(struct Node *head){
    if(head==NULL) return;
    struct Node *slow=head;
    struct Node *fast=head;
    
    while(fast!=NULL && fast->next!=NULL){
        if(fast==slow){
            struct Node *temp=head;
            while(slow!=head){
                slow=slow->next;
                head=head->next;
            }
            if(slow==head){
                printf("Here the loop started %d",slow->data);
            }
            break;
        }
        slow=slow->next;
        fast=fast->next->next;
    }
    
    
}

void LoopLength(struct Node *head){
    if(head==NULL) return;
    struct Node *slow=head;
    struct Node *fast=head;
    
    while(fast!=NULL && fast->next!=NULL){
        if(fast==slow){
            struct Node *temp=slow;
            temp=temp->next;
            int cnt=1;
            while(slow!=temp){
                temp=temp->next;
                cnt++;
            }
            if(slow==temp) printf("\nLoop Length is %d",cnt);
            break;
        }
        slow=slow->next;
        fast=fast->next->next;
    }
    
    
}
int main() {
    // Write C code here
    struct Node *head= (struct Node*)malloc(sizeof(struct Node));
    int arr[]={1,2,3,4,5,6};
    
    int n = sizeof(arr)/sizeof(arr[0]);
    
    head = arrtoLL(arr,n);
    
    printLL(head);
    head=insertAtHead(head,10);
    printLL(head);
    
    head=insertAtSpecific(head,1,3);
    printLL(head);
    printf("Printing reverse \n");
    printRev(head);
    head = Reverse(head);
    printf("Reversing the LL and printing new LL \n");  
    printLL(head);
    printf("Reversing Iteratively \n");
    head=IterativeR(head);
    printLL(head);
    
    printf("printing Middle element \n");
    struct Node *mid = FindMiddle(head);
    printf("%d \n",mid->data);
    
    //detecting Loop
    struct Node *head1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *head2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *head3 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *head4 = (struct Node*)malloc(sizeof(struct Node));

    head1->data=1;
    head2->data=2;
    head3->data=3;
    head4->data=4;
    
    head1->next=head2;
    head2->next=head3;
    head3->next=head4;
    head4->next=head1;
    
    if(isLoop(head1)){
        printf("Loop detected \n");
    }
    
    LoopNode(head1);
    LoopLength(head1);
    return 0;
}
