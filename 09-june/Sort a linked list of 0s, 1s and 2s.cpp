// Sort a linked list of 0s, 1s and 2s
// https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
    
    void insertNode(Node* &toAdd, Node* &head, Node* &tail){
        
        //case1 when head is empty
        if(head == NULL){
            head = toAdd;
            tail = toAdd;
        }else{
            tail->next = toAdd;
            tail = toAdd;
        }
        
    }
    
    Node* segregate(Node* head) {
        Node* headZero = NULL;
        Node* tailZero = NULL;
        
        Node* headOne = NULL;
        Node* tailOne = NULL;
        
        Node* headTwo = NULL;
        Node* tailTwo = NULL;
        
        Node* temp = head;
        
        while(temp != NULL){
            
            Node* toAdd = temp; //marking node
             temp = temp->next;
            toAdd->next = NULL;  // sepration of remain list
            
            switch(toAdd->data){
                
                case 0:
                    insertNode(toAdd,headZero,tailZero);break;
                case 1:
                    insertNode(toAdd,headOne,tailOne);break;
                case 2: 
                    insertNode(toAdd,headTwo,tailTwo);break;
            }
        }
        
        // now linking nodes
        
        if(headZero){
            //zero the
            if(headOne){
                //one bhi the aur zero bhi
                //one ko add kro phir two dekho
                tailZero->next = headOne; // zero se one done
            
                if(headTwo){
                    // means  one bhi two bhi and three bhi hai
                    tailOne->next = headTwo; // all three link
                    return headZero;
                    
                }else{
                    //two nahi h 0 and 1 hai
                    tailOne->next = NULL;
                    return headZero; 
                }
                
            }else{
                //one nahi h aut zero hai
                if(headTwo){
                     // one nahi two hai
                    tailZero->next = headTwo; // all three link
                    return headZero;
                }else{
                    //two nahi one bhi nahi
                    tailZero->next = NULL;
                    return headZero;
                }
            }
            
        }else{
             // 0 nahi hai 
            if(headOne){
                //one hai par zero nahi hai
                if(headTwo){
                     //zero nahi hai one and two hai
                    tailOne->next = headTwo; // all three link
                    return headOne;
                }else{
                    //zerobhi nahi two bhi nahi
                    tailOne->next = NULL;
                    return headOne;
                }
                
            }else{
                //one nahi hai zero bhi nahi hai
                if(headTwo){
                     //only two hai
                    tailTwo->next = NULL; // all three link
                    return headTwo;
                }else{
                    return NULL ;//kuch bhi nahi hai
                }
            }
            
        }
        
    }
};