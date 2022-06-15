#include "monty.h"
/**
 * pchar - print top of stack as char
 * @head: stack top
 * @linum: line number
 */
void pchar(stack_t **head, unsigned int linum)
{
	int tmp;

	if (!head || !(*head))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", linum);
		if (line)
			free(line);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->n;
	if (tmp  < 0 || tmp > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", linum);
		if (line)
			free(line);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}
/**
 * pstr - print stack as string
 * @head: stack top
 * @linum: line number
 */
void pstr(stack_t **head, unsigned int __attribute__((unused))linum)
{
	stack_t *cur;
	int val;

	cur = *head;
	val = (*head)->n;
	while (cur && val >= 0 && val <= 127)
	{
		printf("%c", cur->n);
		if (cur->n == 0)
			break;
		cur = cur->next;
		val = cur->n;
	}
	printf("\n");
}
/**
 * rotl - rotate left
 * @head: stack top
 * @linum: line number
 */
void rotl(stack_t **head, unsigned int __attribute__((unused))linum)
{
	int data;

	if (!(!(*head) || !((*head)->next)))
	{
		data = (*head)->n;
		pop(head, linum);
		add_end(head, data, linum);
	}
}
/**
 * rotr - rotate right
 * @head: stack top
 * @linum: line number
 */
void rotr(stack_t **head, unsigned int __attribute__((unused))linum)
{
	int data;
	stack_t *cur;

	if (!(!(*head) || !((*head)->next)))
	{
		cur = *head;
		while (cur->next)
			cur = cur->next;
		data = cur->n;
		(cur->prev)->next = NULL;
		free(cur);
		push(head, data, linum);
	}
}
/**
 * pall - print all stack data
 * @head: stack top
 * @linum: line number
 */
void pall(stack_t **head, unsigned int __attribute__((unused))linum)
{
	stack_t *cur;

	cur = *head;
	while (cur)
	{
		printf("%d\n", cur->n);
		cur = cur->next;
	}
}
