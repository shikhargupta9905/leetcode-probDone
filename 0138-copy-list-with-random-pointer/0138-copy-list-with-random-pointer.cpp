class Solution {
private:
    void insertCopyInBetween(Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            Node* copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = copyNode->next;
        }
    }

    void connectRandomList(Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            Node* copyNode = temp->next;
            if (temp->random) {
                copyNode->random = temp->random->next;
            } else {
                copyNode->random = NULL;
            }
            temp = copyNode->next;
        }
    }

    Node* getDeepCopyList(Node* head) {
        Node* temp = head;
        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;

        while (temp != NULL) {
            res->next = temp->next;
            res = res->next;

            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummyNode->next;
    }

public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        
        insertCopyInBetween(head);
        connectRandomList(head);
        return getDeepCopyList(head);
    }
};