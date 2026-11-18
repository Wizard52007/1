class MediaItem:
    def __init__(self, id, title):
        self.__id = id
        self._title = title
        self.available = True

    def get_id(self):
        return self.__id

    def display(self):
        print(self._title)

    def issue(self):
        if self.available:
            self.available = False
            print("Issued successfully")
        else:
            print("Already issued")


class Book(MediaItem):
    def __init__(self, id, title, author):
        super().__init__(id, title)
        self.author = author

    def display(self):
        print("Book:", self._title, "| Author:", self.author)


class Magazine(MediaItem):
    def __init__(self, id, title, issue):
        super().__init__(id, title)
        self.issue = issue

    def display(self):
        print("Magazine:", self._title, "| Issue:", self.issue)


items = []

while True:
    print("\n1.Add Book  2.Add Magazine")
    print("3.Display  4.Issue  5.Exit")

    try:
        ch = int(input("Enter choice: "))

        if ch == 1:
            id = int(input("Enter ID: "))
            title = input("Enter title: ")
            author = input("Enter author: ")
            items.append(Book(id, title, author))

        elif ch == 2:
            id = int(input("Enter ID: "))
            title = input("Enter title: ")
            issue = input("Enter issue number: ")
            items.append(Magazine(id, title, issue))

        elif ch == 3:
            for item in items:
                item.display()

        elif ch == 4:
            id = int(input("Enter ID: "))
            found = False

            for item in items:
                if item.get_id() == id:
                    item.issue()
                    found = True
                    break

            if not found:
                print("Item not found")

        elif ch == 5:
            break

        else:
            print("Invalid choice")

    except ValueError:
        print("Invalid input")