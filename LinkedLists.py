class Node:
    def __init__(self, data=None, next=None):
        self.data = data
        self.next = next


class linkedList:
    def __init__(self):
        self.head = None
    def Insert_at_begining(self, data):
        node = Node(data, self.head)
        self.head = node
    def print(self):
        if self.head is None:
            print("LL is empty")
            return
        
        itr = self.head
        llstr =''
        while itr:
            llstr += str(itr.data) + " -> "
            itr = itr.next
        llstr += "NULL"
        print(llstr)



if __name__ == '__main__':
    ll = linkedList()
    ll.Insert_at_begining(5)
    ll.Insert_at_begining(89)
    ll.Insert_at_begining(7)
    ll.print()
