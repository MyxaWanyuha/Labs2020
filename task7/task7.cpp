#include <iostream>
#include "SLList.h"

void printSLList(const SLList* list)
{
    while (list)
    {
        std::cout << list->getData() << ' ';
        list = list->next();
    }
    std::cout << '\n';
}

void removeDuplicates(SLList* start)
{
    while (start && start->hasNext())
    {
        auto current = start;
        while (current->hasNext())
            if (start->getData() == current->next()->getData())
                current->removeNext();
            else
                current = current->next();
        start = start->next();
    }
}

SLList* findElemFromEnd(SLList* start, uint32_t k)
{
    if (!start) return nullptr;

    auto last = start;
    auto count = 0;
    while (last && last->next())
    {
        count++;
        last = last->next();
    }

    count -= k;
    last = start;
    while (last && last->next() && count)
    {
        count--;
        last = last->next();
    }

    return last;
}

int main()
{
    constexpr uint8_t maxRand = 5 + 1;
    auto list = SLList::beginList(rand() % maxRand);

    for (int i = 0; i < 9; i++)
        list->addElement(rand() % maxRand);

    printSLList(list);

    for (int k = 0; k < 10; k++)
        std::cout << "k = " << k << "\tElem from end = " << findElemFromEnd(list, k)->getData() << '\n';

    removeDuplicates(list);
    printSLList(list);

    delete list;
    
    return 0;
}