#include "SLList.h"

SLList* SLList::addElement(int data) noexcept
{
    auto next = m_nextElem;
    auto current = this;
    while (next)
    {
        current = next;
        next = next->m_nextElem;
    }
    current->m_nextElem = new SLList(data);
    return m_nextElem;
}

void SLList::removeNext() noexcept
{
    auto current = this;
    auto toRemove = current->next();
    if (toRemove)
    {
        current->m_nextElem = toRemove->next();
        toRemove->m_nextElem = nullptr;
        delete toRemove;
    }
}