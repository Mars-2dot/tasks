#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
#include <list>

struct Node {
    int val;
    Node* next;

    Node( int val ) : val( val ), next( nullptr ) {}
};

struct myList {
    Node* first;
    Node* last;

    myList() : first( nullptr ), last( nullptr ) {}

    ~myList()
    {
        this->clear();
    }

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

        for ( Node* it = first; it != last; it = it->next ) {
            Node* prev = it;

            for ( Node* it2 = it->next; it2 != last; it2 = it2->next ) {
CHECK_NEXT:

                if ( it2 == nullptr ) {
                    break;
                }

                if ( it2->val == it->val ) {
                    Node* temp = it2;
                    prev->next = it2->next;
                    it2 = it2->next;
                    delete  temp;
                    goto CHECK_NEXT;
                } else if ( it2->next == last && it2->next->val == it->val ) {
                    Node* temp = it2->next;
                    it2->next = nullptr;
                    last = it2;
                    delete temp;
                    prev = it;
                    break;
                } else if ( it2->next == nullptr ) {
                    if ( it->next == last ) {
                        return;
                    }

                    prev = it;
                    break;
                } else {
                    prev = prev->next;
                }
            }

            if ( it->next == nullptr ) {
                break;
            }

            if ( ( it->next->val == it->val ) && ( it->next == last ) ) {
                Node* temp = it->next;
                it->next = nullptr;
                last = it;
                delete temp;
                return;
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

    void clear()
    {
        if ( is_empty() ) {
            return;
        }

        Node* p;

        while ( first != last ) {
            p = first;
            first = first->next;
            delete p;
        }

        p = last;
        last = nullptr;
        first = nullptr;
        delete  p;
    }

    int size()
    {
        if ( is_empty() ) {
            return 0;
        }

        int size = 0;
        Node* p = first;

        while ( p != last ) {
            size++;
            p = p->next;
        }

        return ++size;
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
    void operator= ( std::list<int>* stdList )
    {
        for ( auto i = stdList->begin(); i != stdList->end(); i++ ) {
            this->push_back( *i );
        }
    }
};

#endif // MYLIST_H
