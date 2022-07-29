#include "BST.h"
#include <time.h>

int main()
{
    srand(time(0));
    Tree tree;


    for (int i = 0; i < 20; i++)
    {
        int key = rand() % 100 + 1;
        tree.Insert(key);
        system("cls");
        tree.InOrder(tree.pRoot);

        cout << "\n\n\n";
        cout << key << " inserted\n";
        getchar();
    }


    return 0;
}