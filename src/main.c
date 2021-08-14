// C program for linked list implementation of stack

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "readterminal.h"
#include "strsplit.h"
#include "stack.h"


int main(){
	struct StackNode* root = NULL;

	puts("Forth interpretáló -v.0.1");

	/*push(&root, 10);
	push(&root, 20);
	push(&root, 30);
	printf("%d popped from stack\n", pop(&root));
	printf("Top element is %d\n", peek(root));*/

	int tmp;
	int tmp2;
	int tmp3;

	while(1){
		char *str;
		str = read_string_from_terminal();
		size_t nb;
		char** arr = strsplit_count(str, " ", &nb );

		//printf("Size: %zu\n",nb);
		for(int i = 0; i<nb;i++) {
			//printf( "Elem: %s\n", arr[i] );
			if(isdigit(*arr[i])) {
				push(&root, atoi(arr[i]));
				//puts("pushed");
			}
			/* FIXME Negativ számokat nem ad hozzá a stack-hez!!! FIXME
			else if(isdigit(arr[i]->.lstrip('-'))){
				push(&root, atoi(arr[i]));
			}*/
			else {
				switch(*arr[i]){
					case '+':
						tmp = pop(&root)+pop(&root);
						push(&root, tmp);
						break;
					case '-':
						tmp = pop(&root);
						tmp = pop(&root)-tmp;
						push(&root, tmp);
						break;
					case '*':
						tmp = pop(&root)*pop(&root);
						push(&root, tmp);
						break;
					case '/':
						tmp = pop(&root);
						tmp = pop(&root)/tmp;
						push(&root, tmp);
						break;


					default:
						if(strcmp(arr[i], "emit")==0) {
							printf("%c",pop(&root));
						}
						else if(strcmp(arr[i], "cr")==0) {
							printf("\n");
						}
						else if(strcmp(arr[i], ".")==0) {
							printf("%d",pop(&root));
						}
						else if(strcmp(arr[i], "=")==0) {
							if(pop(&root)==pop(&root)){
								push(&root, -1);
							}
							else {
								push(&root, 0);
							}
						}
						else if(strcmp(arr[i], "<")==0) {
							if(pop(&root)>pop(&root)){
								push(&root, -1);
							}
							else {
								push(&root, 0);
							}
						}
						else if(strcmp(arr[i], ">")==0) {
							if(pop(&root)<pop(&root)){
								push(&root, -1);
							}
							else {
								push(&root, 0);
							}
						}
						else if(strcmp(arr[i], "and")==0) {
							tmp = pop(&root);
							tmp2 = pop(&root);
							if(tmp==-1 && tmp2==-1){
								push(&root, -1);
							}
							else {
								push(&root, 0);
							}
						}
						else if(strcmp(arr[i], "dup")==0) {
							push(&root, peek(root));
						}
						else if(strcmp(arr[i], "drop")==0) {
							pop(&root);
						}
						else if(strcmp(arr[i], "swap")==0) {
							tmp = pop(&root);
							tmp2 = pop(&root);
							push(&root, tmp);
							push(&root, tmp2);
						}
						else if(strcmp(arr[i], "over")==0) {
							tmp = pop(&root);
							tmp2 = peek(root);
							push(&root, tmp);
							push(&root, tmp2);
						}
						else if(strcmp(arr[i], "rot")==0) {
							tmp = pop(&root);
							tmp2 = pop(&root);
							tmp3 = pop(&root);
							push(&root, tmp2);
							push(&root, tmp);
							push(&root, tmp3);
						}
						else{
							printf("%s foo ?\n",arr[i]);
						}
						break;
				}
			}
			//printf("Top element is %d\n", peek(root));
		}
		free(arr);
		//free(str);
	}

	return 0;
}
