#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node {
    int coeff;  // Coefficient
    int exp;    // Exponent
    struct Node* next; // Pointer to the next term
};

// Function to create a new node
struct Node* createNode(int coeff, int exp) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->coeff = coeff;
    temp->exp = exp;
    temp->next = NULL;
    return temp;
}

// Function to insert a new term into the polynomial
struct Node* insertTerm(struct Node* head, int coeff, int exp) {
    struct Node* temp = createNode(coeff, exp);
    if (head == NULL) {
        head = temp;
    } else {
        struct Node* ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
    return head;
}

// Function to add like terms in the resulting polynomial
struct Node* addLikeTerms(struct Node* head) {
    struct Node* ptr1 = head;
    while (ptr1 != NULL && ptr1->next != NULL) {
        struct Node* ptr2 = ptr1;
        while (ptr2->next != NULL) {
            if (ptr1->exp == ptr2->next->exp) { // Combine like terms
                ptr1->coeff += ptr2->next->coeff;
                struct Node* temp = ptr2->next;
                ptr2->next = temp->next;
                free(temp);
            } else {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
    return head;
}

// Function to multiply two polynomials
struct Node* multiplyPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node* ptr1 = poly1;
    struct Node* ptr2 = poly2;

    while (ptr1 != NULL) {
        ptr2 = poly2;
        while (ptr2 != NULL) {
            int coeff = ptr1->coeff * ptr2->coeff;
            int exp = ptr1->exp + ptr2->exp;
            result = insertTerm(result, coeff, exp);
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }

    result = addLikeTerms(result); // Combine like terms
    return result;
}

// Function to print the polynomial
void printPolynomial(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->next != NULL) {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() 
{
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;

    // Polynomial 1: 3x^2 + 5x^1 + 6
    poly1 = insertTerm(poly1, 3, 2);
    poly1 = insertTerm(poly1, 5, 1);
    poly1 = insertTerm(poly1, 6, 0);
}

    // Polynomial 2: 6x^1 + 8

