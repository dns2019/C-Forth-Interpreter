#ifndef STACK_H
#define STACK_H

// Functions for stack handling
//struct StackNode;
struct StackNode* newNode(int data);
int isEmpty(struct StackNode* root);
void push(struct StackNode** root, int data);
int pop(struct StackNode** root);
int peek(struct StackNode* root);

#endif /* STACK_H */
