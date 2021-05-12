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

        Node* prev = first;
        Node* current = first;
        Node* next = first->next;

        while ( first ) {

            if ( next == nullptr ) {
                last = current;
                break;
            } else if ( current->val == next->val ) {
                if ( current == first ) {
                    Node* temp = first;
                    first = next;
                    current = next;
                    prev = next;
                    next = next->next;
                    delete temp;
                } else {
                    Node* temp = current;
                    current = current->next;
                    prev->next = current;
                    next = current->next;
                    delete temp;
                }
            } else {
                prev = current;
                current = current->next;
                next = current->next;
            }
        }
    }

    void unique_s()
    {
        if ( is_empty() ) {
            return;
        }

        Node* prev = first;
        Node* next = first->next;
        Node* it2 = first;

        for ( Node* it = first; it != last; it = it->next ) {
            if ( ( next == last ) && ( next->val == it->val ) ) {
                Node* tempNext = next;
                it2->next = nullptr;
                next = it2;
                last = it2;
                last->next = nullptr;
//                std::cout << "delete: " << tempNext->val << std::endl;
                delete tempNext;
                return;
            }

            next = next->next;

            for ( it2 = it2->next; it2 != last;  ) {
                if ( ( it2->val == it->val ) ) {
                    Node* temp = it2;
                    prev->next = it2->next;

                    if ( ( next == last ) && ( next->val == it->val ) && ( next != it2 ) ) {
                        Node* tempNext = next;
                        last = it2;
                        it2->next = nullptr;
                        next = it2;

                        if ( first->next = last ) {
//                            first->next = nullptr;
                            last->next = nullptr;
                            return;
                        }

//                        std::cout << "delete: " << tempNext->val << std::endl;
                        delete  tempNext;
                    } else {
                        next = next->next;
                        it2 = it2->next;
                    }

//                    std::cout << "delete: " << temp->val << std::endl;
                    delete temp;
                } else {
                    if ( ( next == last ) && ( next->val == it->val ) ) {
                        Node* tempNext = next;
                        last = it2;
                        next = it2;
                        it2->next = nullptr;
//                        std::cout << "delete: " << tempNext->val << std::endl;
                        delete  tempNext;
                    } else {
                        next = next->next;
                        it2 = it2->next;
                        prev = prev->next;
                    }
                }
            }

            prev = it->next;
            it2 = it->next;
            next = it2->next;
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
