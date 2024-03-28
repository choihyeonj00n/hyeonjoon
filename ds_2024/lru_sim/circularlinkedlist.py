class ListNode:
    def __init__(self, item, next_node):
        self.item = item
        self.next = next_node

class CircularLinkedListBasic:
    def __init__(self):
        self.__head = ListNode('dummy', None)
        self.__tail = self.__head
        self.__head.next = self.__head
        self.__numItems = 0

    def insert(self, i:int, newItem):
        if 0 <= i <= self.__numItems:
            prev = self.__getNode(i - 1)
            newNode = ListNode(newItem, prev.next)
            prev.next = newNode
            if prev == self.__tail:
                self.__tail = newNode
            self.__numItems += 1
        else:
            print("index", i, ": out of bound in insert()")

    def append(self, newItem):
        prev = self.__getNode(self.__numItems - 1)
        newNode = ListNode(newItem, self.__head)
        prev.next = newNode
        self.__tail = newNode
        self.__numItems += 1

    def pop(self, i:int):
        if 0 <= i <= self.__numItems - 1:
            prev = self.__getNode(i - 1)
            curr = prev.next
            if curr == self.__tail:
                self.__tail = prev
            prev.next = curr.next
            retItem = curr.item
            self.__numItems -= 1
            return retItem
        else:
            return None

    def remove(self, x):
        (prev, curr) = self.findNode(x)
        if curr != None:
            if curr == self.__tail:
                self.__tail = prev
            prev.next = curr.next
            self.__numItems -= 1
            return x
        else:
            return None

    def get(self, i:int):
        if self.isEmpty():
            return None
        if 0 <= i <= self.__numItems - 1:
            return self.__getNode(i).item
        else:
            return None

    def index(self, x) -> int:
        curr = self.__head.next
        for index in range(self.__numItems):
            if curr.item == x :
                return index
            else :
                curr = curr.next
        return -2

    def isEmpty(self) -> bool:
        return self.__numItems == 0

    def size(self) -> int:
        return self.__numItems

    def clear(self):
        self.__head = ListNode("dummy", None)
        self.__tail = self.__head
        self.__head.next = self.__head
        self.__numItems = 0

    def count(self, x) -> int:
        cnt = 0
        curr = self.__head.next
        while curr != self.__head:
            if curr.item == x:
                cnt += 1
            curr = curr.next
        return cnt

    def extend(self, a):
        for index in range(a.size()):
            self.append(a.get(index))

    def copy(self):
        a = CircularLinkedListBasic()
        for index in range(self.__numItems):
            a.append(self.get(index))
        return a

    def reverse(self):
        a = CircularLinkedListBasic()
        for index in range(self.__numItems):
            a.insert(0, self.get(index))
        self.clear()
        for index in range(a.size()):
            self.append(a.get(index))

    def sort(self):
        a = []
        for index in range(self.__numItems):
            a.append(self.get(index))
        a.sort()
        self.clear()
        for index in range(len(a)):
            self.append(a[index])

    def findNode(self, x):
        prev = self.__head
        curr = prev.next
        while curr != self.__head:
            if curr.item == x:
                return (prev, curr)
            else:
                prev = curr
                curr = curr.next
        return (None, None)

    def __getNode(self, i:int) -> ListNode:
        curr = self.__head
        for index in range(i+1):
            curr = curr.next
        return curr

    def printList(self):
        curr = self.__head.next
        while curr != self.__head:
            print(curr.item, end=' ')
            curr = curr.next
        print()

class CircularLinkedListIterator:
    def __init__(self, alist):
        self.__head = alist.__getNode(-1)
        self.iterPosition = self.__head.next

    def __next__(self):
        if self.iterPosition == self.__head:
            raise StopIteration
        else:
            item = self.iterPosition.item
            self.iterPosition = self.iterPosition.next
            return item

