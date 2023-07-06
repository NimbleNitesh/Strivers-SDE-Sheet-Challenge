/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

class node{
    public:
    bool endOfWrd;
    node* ar[26];
    node()
    {
        endOfWrd=false;
        for(int i=0;i<26;i++)
            ar[i]=NULL;
    }
};
class Trie {

public:
    
    /** Initialize your data structure here. */
    node* root;
    Trie() {
        root=new node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        node* temp=root;
        for(auto ch: word)
        {
            int index=ch-'a';
            if(temp->ar[index]==NULL)
            {
                node* cur=new node();
                temp->ar[index]=cur;
            }
            temp=temp->ar[index];
        }
        temp->endOfWrd=true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        node* temp=root;
        for(auto ch: word)
        {
            int index=ch-'a';
            if(temp->ar[index]==NULL)
                return false;
            temp=temp->ar[index];
        }
        // cout << "hi ";
        return temp->endOfWrd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        node* temp=root;
        for(auto ch: prefix)
        {
            int index=ch-'a';
            if(temp->ar[index]==NULL)
                return false;
            temp=temp->ar[index];
        }
        return true;
    }
};