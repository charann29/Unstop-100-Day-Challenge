#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
        int data;
        Node *left, *right;
};

Node *newNode(int item)
{
        Node *temp = new Node();
        temp->data = item;
        temp->left = temp->right = NULL;
       return temp;
}

Node *insert(Node *node, int data)

{
        if (node == NULL)
        return newNode(data);
        if (data <= node->data)
        node->left = insert(node->left, data);
        else         node->right = insert(node->right, data);
        return node;
}
int sum;
void inorder(Node *root, int start, int end)
{
    if (root == NULL)
        return;
        else    
    {
                inorder(root->left, start, end);
                if (root->data >= start && root->data <= end)
            sum += (root->data);
                inorder(root->right, start, end);
           
    }
}

int sumofvalofgivenrange(Node *root, int start, int end)
{
            sum = 0;
       inorder(root, start, end);
            return sum;
}

int main()
{
        Node *root = NULL;
        int n;
        cin >> n;
        int k;
      cin >> k;
        root = insert(root, k);
        for (int i = 1; i < n; i++)
   
    {
                cin >> k;
                insert(root, k);
           
    }

        int start, end;
        cin >> start >> end;
        int ans = sumofvalofgivenrange(root, start, end);
        cout << ans;
        return 0;
}