#include<stdio.h>
#include<conio.h>

struct leaf {
	char data[16]; /* string data */
	struct leaf* next; /* pointer to the next leaf */
};

struct el {
	char data2[16]; /* string data */
	struct el* next2; /* pointer to the next leaf */
};


struct leaf* addLeaf(char*, struct leaf*);
void printLeaves(struct leaf* p);
void freeLeaves(struct leaf* p);




int main()
{
	
	struct leaf* top; /* top of the leaves */
	struct el* newleaf = (struct el*)malloc(sizeof(struct el));
	char* fruits[3] = { "apple", "orange", "banana" };
	char element4[] = { "grape" };
	
	top = NULL;
	top = addLeaf(fruits[0], top);
	top = addLeaf(fruits[1], top);
	top = addLeaf(fruits[2], top);

	newleaf = addLeaf(element4, newleaf);
	newleaf->next2=top->next;
	top->next = newleaf->data2;
	
	
	
	printLeaves(top); /* print elements*/
	freeLeaves(top); /* delete all elements */
	_getch();
	return 0;
}
void printLeaves(struct leaf* pL)
{
	while (pL != NULL) {
		printf("%s\n", pL->data);
		pL = pL->next;
	}
}
struct leaf* addLeaf(char* data, struct leaf* top)
{
	struct leaf* pL;
	pL = (struct leaf*) malloc(sizeof(struct leaf));
	strcpy(pL->data, data);
	/* change pointer to the top */
	pL->next = top; /* Old top is new leaf's next */
	top = pL;/* New top is new leaf's address */
	return top;
}
void freeLeaves(struct leaf* pL)
{
	struct leaf* pLnext;
	while (pL != NULL) {
		pLnext = pL->next;
		free(pL);
		pL = pLnext;
	}
}