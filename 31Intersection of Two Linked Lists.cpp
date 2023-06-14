

#include <unordered_set>

Node* findIntersection(Node *firstHead, Node *secondHead)
{

    Node *firstHeadTmp = firstHead;

    // Set to store reference of first list.
    unordered_set<Node *> referenceSet;

    // Traverse the first list and store the reference in the set.
    while (firstHeadTmp != NULL)
    {
        referenceSet.insert(firstHeadTmp);
        firstHeadTmp = firstHeadTmp->next;
    }

    Node *secondHeadTmp = secondHead;

    // Traverse second list, check if the reference of current node is present or not.
    // If it is present then return the data of that node.
    while (secondHeadTmp != NULL)
    {
        if (referenceSet.find(secondHeadTmp) != referenceSet.end())
        {
            return secondHeadTmp;
        }
        secondHeadTmp = secondHeadTmp->next;
    }

    return NULL;
}