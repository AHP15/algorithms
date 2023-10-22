#include <cassert>

#include "LinkedList.h"

namespace LinkedListTest
{

    
    void testPushAndGet(LinkedList<int>& list)
    {
        list.push(1);
        assert(list.get(0) == 1 && "Push to empty list failed");

        list.push(2);
        assert(list.get(0) == 1 && "Push to one element List failed: expect list.get(0) == 1");
        assert(list.get(1) == 2 && "Push to one element List failed: expect list.get(1) == 2");

        list.push(3);
        assert(list.get(0) == 1 && "Push to list failed: expect list.get(0) == 1");
        assert(list.get(1) == 2 && "Push List failed: expect list.get(1) == 2");
        assert(list.get(2) == 3 && "Push List failed: expect list.get(2) == 3");
    }

    void testPop(LinkedList<int>& list)
    {
        list.push(1);
        assert(list.pop() == 1 && "Pop from one element list failed: expect list.pop() == 1");
        assert(list.getLength() == 0 && "Pop from one element list failed: element wasn't removed");

        list.push(1);
        list.push(2);
        assert(list.pop() == 2 && "Pop from list failed: expect list.pop() == 2");
    }

    void testUnshift(LinkedList<int>& list)
    {
        list.unshift(1);
        assert(list.get(0) == 1 && "Unshift to empty list failed: expect list.get(0) == 1");

        list.unshift(2);
        assert(list.get(0) == 2 && "Unshift to one element list failed: list.get(0) == 2");
        assert(list.get(1) == 1 && "Unshift to one element list failed: list.get(1) == 1");
    }

    void testShift(LinkedList<int>& list)
    {
        list.push(1);
        list.shift();
        assert(list.getLength() == 0 && "Shift to one element list failed");

        list.push(1);
        list.push(2);
        list.shift();
        assert(list.get(0) == 2 && "Shift to list failed");

        list.push(3);
        list.push(4);
        list.shift();
        assert(list.get(0) == 3 && "Shift to list failed");
    }

    void testRemoveAt(LinkedList<int> list)
    {
        list.push(1);
        list.push(2);
        list.push(3);

        list.removeAt(0);
        assert(list.get(0) == 2 && "Remove from list failed");

        list.push(4);
        list.removeAt(1);
        assert(list.get(1) == 4 && "Remove from list failed");

        list.push(5);
        list.removeAt(2);
        assert(list.get(1) == 4 && "Remove from list failed");
    }

    void test()
    {
        LinkedList<int> list1 {};
        testPushAndGet(list1);

        LinkedList<int> list2 {};
        testPop(list2);

        LinkedList<int> list3{};
        testUnshift(list3);

        LinkedList<int> list4{};
        testShift(list4);

        LinkedList<int> list5{};
        testRemoveAt(list5);
    }
}