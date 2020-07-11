//
// Created by abahnasy on 04.07.20.
//


#include <bits/stdc++.h>

#define ALPHABET_SIZE 26

using namespace std;

typedef struct Node Node_t;



struct Node {
    struct Node *children [ALPHABET_SIZE];
    bool is_word;
    bool counted;

public:

    Node() {
        this->is_word = false;
        this->counted = false;
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            this->children[i] = NULL;
        }

    }
};



//Node_t * get_node() {
//    Node_t *pNode  = new Node();
//    pNode->is_word = false;
//    pNode->counted = false;
//    for (int i = 0; i < ALPHABET_SIZE; ++i) {
//        pNode->children[i] = NULL;
//    }
//    return pNode;
//}

void insert(Node_t *root, string key, int& ctr) {
    Node_t *pCrawl = root;
    bool part_of_word = true;
    for (int i = 0; i < key.length(); ++i) {
        int idx = 0;
        if(i == 0) {
            // handle capital letter
            idx = key[i] - 'A';
        } else {
            idx = key[i] - 'a';
        }
        if(!pCrawl->children[idx]) {
            pCrawl->children[idx] = new Node();
            part_of_word = false;
        }
        pCrawl = pCrawl->children[idx];
        // check if it is end of word
        if(pCrawl->is_word == true && pCrawl->counted == false) {
            ctr++;
            pCrawl->counted = true;
        }
    }
    pCrawl->is_word = true;
    if(part_of_word && pCrawl->counted == false){
        ctr++;
        pCrawl->counted = true;
    }

}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // redirect input stream to samples files
//    freopen("../../week_11/samples_11/contactlist/1.in", "r", stdin);
//    freopen("../../week_11/samples_11/contactlist/2.in", "r", stdin);
//    freopen("../../week_11/samples_11/contactlist/test.in", "r", stdin);

    int test_cases;
    cin >> test_cases;
    int n; // number of contacts
    for (int t = 1; t <= test_cases; ++t) {
        int ctr = 0;
        cin >> n;
        string line;
        getline(cin, line); //get empty string
        Node_t *root = new Node();

        for (int i = 0; i < n; ++i) {
            getline(cin, line);
            insert(root, line, ctr);
//            cout << line;

        }

        cout << "Case #" << t << ": " << ctr << "\n";

    }
}