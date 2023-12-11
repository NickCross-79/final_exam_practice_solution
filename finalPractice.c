// Ordered Doubly-LinkedList
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node_struct
{
    char string[16]; // String with length of 15
    struct Node_struct *nextNode;   // Link to the next node
    struct Node_struct *lastNode;   // Link to the previous node
} Node;
// Two global pointer variables to keep the start and end of the list, initialized with
Node *start = NULL;
Node *end = NULL;
// Selection menu (This function has already been developed)
void menu(void);
/*************
 * Develop this function at the bottom of this program
 * Print the list.
 */
void printList();
/*************
 * Develop this function at the bottom of this program
 * Check if the list is empty.
 */
int isEmpty();
/*************
 * Develop this function at the bottom of this program
 * Set the node's data, using a string value.
 */
void setData(Node *node, char *value);
/*************
 * Develop this function at the bottom of this program
 * Insert a new node into the list in its correct location.
 */
void insert(Node *newPtr);
/*************
* Develop this function at the bottom of this program
* It recieves a string to delete the very first node equal to it, if found.
* If found, it returns the string value of the deleted node, Otherwise, returns ""
(empty string).
*/
char *delete(char *value);
/*************
* Develop this function at the bottom of this program
* Print the list in the reverse order (from the end of the list to the beginning of
the list).
*/
void printListReverse();
/*************
 * Read some words from an input file and insert them to the list.
 */
void readData();
/*************
 * Write the list into an output file.
 */
void writeData();
/*************
 * Develop this function at the bottom of this program
 * Safely make a linked list empty.
 */
void emptyList();
// main function
int main(void)
{
    Node *newPtr = NULL;
    char item[15];
    // Creating the starting/ending node.
    start = (Node *)malloc(sizeof(Node));
    setData(start, "#");
    end = start;
    puts("An empty ordered Doubly-LinkedList created.");
    puts("********************************************");
    menu();
    printf("%s", "? ");
    unsigned int choice; // user's choice
    scanf("%u", &choice);
    fflush(stdin);
    while (choice != 8)
    {
        switch (choice)
        {
        case 1:
            /*************
             * Complete this part:
             * 1- Prompt the user to input a character.
             * 2- Read the user's input.
             * 3- Insert the input character into the list.
             * 4- Print the linkedlist.
             */
            printf("%s", "Enter a name (Maximum 14 characters): ");
            fgets(item, 15, stdin);
            if (item[strlen(item) - 1] == '\n')
                item[strlen(item) - 1] = '\0';
            newPtr = (Node *)malloc(sizeof(Node)); // create node
            setData(newPtr, item);
            insert(newPtr); // insert item in list
            printList();
            break;
        case 2:
            /*************
             * Complete this part:
             * 1- If the list is empty, print out a proper message and skip this case.
             * Otherwise, prompt the user to input a string.
             * 2- Read the user's input.
             * 3- Delete the node that has the input string from the list,
             * and Print the linkedlist. If not found, show a proper message.
             */
            if (!isEmpty())
            {
                printf("%s", "Enter character to be deleted: ");
                fgets(item, 15, stdin);
                if (item[strlen(item) - 1] == '\n')
                    item[strlen(item) - 1] = '\0';
                char *found = delete (item);
                if (strcmp(found, "") != 0)
                {
                    printf("%s deleted.\n", item);
                    printList();
                }
                else
                    printf("%s not found.\n\n", item);
            }
            else
                puts("List is empty.\n");
            break;
        case 3:
            /*************
             * Complete this part:
             * 1- If the list is empty, print out a proper message,
             * Otherwise, print the linkedlist from the BEGINNING of the list.
             */
            if (!isEmpty())
                printList();
            else
                puts("List is empty.\n");
            break;
        case 4:
            /*************
             * Complete this part:
             * 1- If the list is empty, print out a proper message,
             * Otherwise, print the linkedlist from the END of the list.
             */
            if (!isEmpty())
                printListReverse();
            else
                puts("List is empty.\n");
            break;
        case 5:
            /*************
             * Complete this part:
             * Call the proper fnnction to read from an input file.
             */
            readData();
            break;
        case 6:
            /*************
             * Complete this part:
             * Call the proper fnnction to write the list into a file.
             */
            if (!isEmpty())
                writeData();
            else
                puts("List is empty.\n");
            break;
        // Handling invalid choice
        case 7:
            /*************
             * Complete this part:
             * Call the proper fnnction to empty the list.
             */
            if (!isEmpty())
                emptyList();
            puts("List is empty.\n");
            break;
        default:
            puts("Invalid choice.\n");
            break;
        } // end switch
        menu();
        printf("%s", "? ");
        scanf("%u", &choice);
        fflush(stdin);
    }
    puts("End of run.");
}
// Display the menu options.
void menu(void)
{
    puts("Enter your choice:\n"
         " 1 to insert an element into the list.\n"
         " 2 to delete an element from the list.\n"
         " 3 to print the list from the beginning.\n"
         " 4 to print the list from the end.\n"
         " 5 Read some words from input file and insert them to the list.\n"
         " 6 Write the list into the output file.\n"
         " 7 Empty the list.\n"
         " 8 to end.");
}
// Print the list
void printList()
{
    Node *node = start;
    printf("NULL<-->");
    while(node != NULL){
        printf("%s<-->", node->string);
        node = node->nextNode;
    }
    printf("NULL\n");
}
// Return 1 if the list is empty, 0 otherwise
int isEmpty()
{
    return (start == NULL && end == NULL) ? 1 : 0; 
}
/*************
 * Develop function setData.
 */
void setData(Node *node, char *value)
{
    strcpy(node->string, value);
}
/*************
 * Develop function insert.
 */
void insert(Node *newPtr)
{
    Node *node;

    /** 
     * If the two pointer variables (start and end) were left as null instead of the
     * '#' character being set in the main function, then this if statment would just 
     * be 'if(start == NULL)', but the instructions say 'Dont change any code', so oh well I guess
    */
    if( start == NULL || strcmp(start->string,"#") == 0){
        newPtr->lastNode = NULL;
        newPtr->nextNode = NULL;
        start = newPtr;
        
        return;
    }

    node = start;

    while(node != NULL){
        int nodeStringCheck = strcasecmp(newPtr->string, node->string);
        
        if(nodeStringCheck <= 0){
            newPtr->nextNode = node;
            newPtr->lastNode = node->lastNode;
            if(node->lastNode != NULL){
                node->lastNode->nextNode = newPtr;  
            }
            node->lastNode = newPtr;
            start = newPtr->lastNode == NULL ? newPtr : start;
            return;
        }else if(node->nextNode == NULL){
            newPtr->lastNode = node;
            newPtr->nextNode = NULL;
            node->nextNode = newPtr;
            end = newPtr;
            return;
        }

        node = node->nextNode;
    }
}
/*************
 * Develop function delete.
 */
char *delete(char *value)
{
    Node *node;
    node = start;

    while(node != NULL && strcmp(node->string, value) != 0){
        node = node->nextNode;
    }

    if(node == NULL){
        return "\0";
    }

    if(node == start){
        start = node->nextNode;
        if(start != NULL){
            start->lastNode = NULL;
        }
        free(node);
        return value;
    }

    if(node == end){
        end = node->lastNode;
        if(end != NULL){
            end->nextNode = NULL;
        }
        free(node);
        return value;
    }

    node->lastNode->nextNode = node->nextNode;
    node->nextNode->lastNode = node->lastNode;
    free(node);
    return value;

}
/*************
 * Develop function printListReverse.
 */
void printListReverse()
{
    Node *node;
    node = end;
    printf("NULL<-->");
    while(node != NULL){
        printf("%s<-->",node->string);
        node = node->lastNode;
    }
    printf("NULL\n");
}
/*************
 * Develop function readData.
 */
void readData()
{
    FILE *input = fopen("input.txt","r");
    if(input == NULL){
        return;
    }

    char word[15];

    while(fscanf(input, "%s", word) != EOF){
        Node *node = (Node*)malloc(sizeof(Node));
        setData(node, word);
        insert(node);
    }
    fclose(input);
}
/*************
 * Develop function writeData.
 */
void writeData()
{
    FILE *output = fopen("output.txt", "w");
    if(output == NULL){
        return;
    }
    
    Node *node = start;

    while(node != NULL){
        fprintf(output, "%s\n",node->string);
        node = node->nextNode;
    }
    fclose(output);
}
/*************
 * Develop function emptyList.
 */
void emptyList()
{
    Node *node = start;

    while(node != start){
        Node *current = node;
        node = node->nextNode;
        free(current);
    }

    start = NULL;
    end = start;
}