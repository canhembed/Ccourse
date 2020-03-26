#include<stdio.h>
#include<conio.h>
#include<string.h>

struct leaf {
	char data[16]; /* string data */
	struct leaf* next; /* pointer to the next leaf */
};
struct leaf* addLeaf(char*, struct leaf*);
void printLeaves(struct leaf* p);
void freeLeaves(struct leaf* p);

int main()
{
	int number;
	char name[] = {""};
	struct leaf* top; /* top of the leaves */

	printf("insert number : ");
	scanf("%d", &number);
	top = NULL;
	for (int i = 0; i < number; i++)
	{
		printf("Insert fruit name: ");
		scanf("%s",&name );

		top = addLeaf(name, top);
	}
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