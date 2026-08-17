struct Node {
    string url;
    Node* prev;
    Node* next;
    Node(string url) : url(url), prev(nullptr), next(nullptr) {}
};

class BrowserHistory {
private:
    Node* currPage;

public:
    BrowserHistory(string homepage) {
        currPage = new Node(homepage);
    }
    
    void visit(string url) {
        Node* newNode = new Node(url);
        currPage->next = newNode;
        newNode->prev = currPage;
        currPage = newNode; // Clears forward history by overwriting next
    }
    
    string back(int steps) {
        while (steps > 0 && currPage->prev != nullptr) {
            currPage = currPage->prev;
            steps--;
        }
        return currPage->url;
    }
    
    string forward(int steps) {
        while (steps > 0 && currPage->next != nullptr) {
            currPage = currPage->next;
            steps--;
        }
        return currPage->url;
    }
};