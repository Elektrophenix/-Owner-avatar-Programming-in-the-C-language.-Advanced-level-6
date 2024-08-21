#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STR_SIZE 2000

typedef struct list
{
	char* word;
	struct list *next;
}list;

list* insert2(char* value,list *head);
void print_list(list * head);
void delete_list(list *head);
void print_first_last(struct list * e);
 
int main(int argc, char** argv){
list *w_list=NULL;
char word[STR_SIZE]="";
int ch = ' ';
int i=0;
	while (EOF != (ch = getchar())){
		switch (ch){
			case '.':
			case ' ':
				word[i] = '\0';
				w_list = insert2(word, w_list);
				i=0;
			break;
			default:
				word[i++] = ch;
				if(i>=STR_SIZE)
					i=0;
		}
		if('.' == ch)
			break;
	}

#ifdef DEBUG
	print_list(w_list);
#endif
	print_first_last(w_list);
	delete_list(w_list);
	return 0;
}
void delete_list(list * l){
list * c =l;
list * n;
	while(c != NULL)
	{
		n = c->next;
		free (c->word);
		c = n;
	}
}

list* insert2(char* value,list *head) {
	list *res = (list*)calloc(1,sizeof(list));
	int len = strlen(value); 
	res->word = malloc (len+1);
	strcpy(res->word, value);
	res->next = head;
	return res;
}

void print_list(list * head)
{
	for (list* i = head; i!=NULL; i=i->next)
		printf("%s ", i->word);
	putchar('\n');
}

void print_first_last(struct list * e)
{
struct list *l = e;
	while(l->next != (struct list *)NULL)
		l = l->next;
	printf("%s ", l->word); 
	printf("%s\n", e->word);
}
