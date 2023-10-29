#include<stdio.h>
#include<stdlib.h>

struct node

{
 
 int data;

 struct node *next;
 

};

//Head Tail

struct node *head = NULL;
struct node *tail = NULL;

//Add Node

int addNode(int data) // fonskiyondan gelen data

{
      // linked list is empty

        if(head == NULL)

        {
            
            // Bellekte yer ayrÄ±ldÄ±
            struct node *new = (struct node*)malloc(sizeof(struct node)); 

            new->data = data; // struct node iÃ§indeki data ya fonskiyondan gelen data atandÄ±

            new->next = NULL; // next null olarak atandÄ± 

            head = tail = new;

            // listenin baÅŸÄ± ve sonu yeni eklenen elemanÄ± gÃ¶stericek




        }

        else 

        {
             
             struct node *new = (struct node*)malloc(sizeof(struct node));

             new -> data = data;

             new -> next = NULL;

             tail -> next = new;
 
             tail = new;

                

            
        }

}

int addNodeHead(int data)

{

    if(head==NULL)

    {

        struct  node *new = (struct node*)malloc(sizeof(struct node));

        new -> data = data;

        new -> next = NULL;

        head = tail = new;
    }

    // Linked list's not empty

    else 

    {

        struct node *new = (struct node*)malloc(sizeof(struct node));

        new -> data = data;

        new -> next = head;

        head = new;




    }
}


// print listeyi yazdırma 

   int print ()

   {
   

    printf("Linked List\n");

    struct node *index = head;

    while (index != NULL)

    {

        printf("%d\n",index->data);

        index = index->next;
        
    }

    printf("End of Linked List\n");


    return 1;

   }
 

 // delete node

   int delete(int data)

   {

    struct node *prev = NULL;

    struct node *index = head;

    // linked list is empty
    

    if (head==NULL)

    {
        
        printf("Linked list is empty\n");

        return 1;
    }

    if(head->data==data)

    {
        
        struct node *t = head;

        head = head->next;

        free(t);

        return 1;

    }


    while (index!=NULL && index->data!=data)

    {

        prev = index;

        index = index->next;

        
    }

      if (index==NULL)

      {
          
          printf("Node not found\n");

          return 1;
      }
     
      prev->next = index->next;

      if (tail->data==data)

      {

            tail = prev;
        
      }

      free(index);

      return 1;

   }

int main()

{
     
     system("color 0A");

    addNode(10);
    addNode(20);
    addNode(30);
    addNode(40);


    addNodeHead(7);
    addNodeHead(8);


    print();

    delete(30);
    print();

    delete(7);
    print();






    return 1;
}