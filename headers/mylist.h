#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>

struct Node {
    int val;
    Node* next;

    Node( int val ) : val( val ), next( nullptr ) {}
};

struct myList {
    Node* first;
    Node* last;

    myList() : first( nullptr ), last( nullptr ) {}

    bool is_empty()
    {
        return first == nullptr;
    }

    void push_back( int val )
    {
        Node* p = new Node( val );

        if ( is_empty() ) {
            first = p;
            last = p;
            return;
        }

        last->next = p;
        last = p;
    }

    void print()
    {
        if ( is_empty() ) {
            return;
        }

        Node* p = first;

        while ( p ) {
            std::cout << p->val << " ";
            p = p->next;
        }

        std::cout << std::endl;
    }

    void remove_first()
    {
        if ( is_empty() ) {
            return;
        }

        Node* p = first;
        first = p->next;
        delete p;
    }

    void remove_last()
    {
        if ( is_empty() ) {
            return;
        }

        if ( first == last ) {
            remove_first();
            return;
        }

        Node* p = first;

        while ( p->next != last ) {
            p = p->next;
        }

        p->next = nullptr;
        delete last;
        last = p;
    }

    void unique()
    {
        if ( is_empty() ) {
            return;
        }

        while ( first != last ) {
            if ( first->next->val == first->val ) {
                remove( first->val );
            } else {
                first-> next = first->next;
            }
        }
    }

    void remove( int val )
    {
        if ( is_empty() ) {
            return;
        }

        if ( first->val == val ) {
            remove_first();
            return;
        } else if ( last->val == val ) {
            remove_last();
            return;
        }

        Node* slow = first;
        Node* fast = first->next;

        while ( fast && fast->val != val ) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = fast->next;
        delete fast;
    }

    Node* operator[] ( const int index )
    {
        if ( is_empty() ) {
            return nullptr;
        }

        Node* p = first;

        for ( int i = 0; i < index; i++ ) {
            p = p->next;

            if ( !p ) {
                return nullptr;
            }
        }

        return p;
    }
};

#endif // MYLIST_H
