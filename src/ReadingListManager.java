//Katherine (Katie) Kilborn
import java.util.Scanner;

	public class ReadingListManager {
		static Scanner keyboard;
		static Node head;
		static int LastSort; //1 by name, 2 by author, 3 by genre, 4 by price

		//gets length of the linked list
		public static int getListLength() {
			int count = 0;
			Node curr = head; 
			while (curr != null) {
				curr=curr.Next;
				count++;
			}
			return count;
		}
		
		//sorts alphabetically by name
		public static void sortByName() {
			int n = getListLength();
			//technically redundant because the j loop will not run if length is 1
			if (n<2)
				return; //already sorted
			//i represents the number of iterations
			for (int i=0; i<n; i++) {
				Node curr=head; //array[j]
				Node next = curr.Next; //array{j+1]
				for (int j=0; j<n-i-1; j++) {
					if (curr.Data.Name.compareToIgnoreCase(next.Data.Name)>0) {
						//curr.Data.Name > next.Data.Name, we need to swap
						ReadingList temp = curr.Data;
						curr.Data = next.Data;
						next.Data = temp;
					}
					curr = next; //traverse
					next = next.Next;
				}//inner loop
			}//outer loop
		}
		//sorts alphabetically by author
		public static void sortByAuthor() {
			int n = getListLength();
			if (n<2) {
				return;
			}
			for (int i=0; i<n; i++) {
				Node curr=head;
				Node next=curr.Next;
				for (int j=0; j<n-i-1; j++) {
					if (curr.Data.Author.compareToIgnoreCase(next.Data.Author)>0) {
						ReadingList temp = curr.Data;
						curr.Data = next.Data;
						next.Data = temp;
					}
					curr = next;
					next = next.Next;
				}
			}
		}
		//sort alphabetically by genre
		public static void sortByGenre() {
			int n = getListLength();
			if (n<2) {
				return;
			}
			for (int i=0; i<n; i++) {
				Node curr=head;
				Node next=curr.Next;
				for (int j=0; j<n-i-1; j++) {
					if (curr.Data.Genre.compareToIgnoreCase(next.Data.Genre)>0) {
						ReadingList temp = curr.Data;
						curr.Data = next.Data;
						next.Data = temp;
					}
					curr = next;
					next = next.Next;
				}
			}
		}
		//sorts by priority
		public static void sortByPriority() {
			int n = getListLength();
			if (n<2) {
				return;
			}
			for (int i=0; i<n; i++) {
				Node curr=head;
				Node next=curr.Next;
				for (int j=0; j<n-i-1; j++) {
					if (curr.Data.Priority > next.Data.Priority) {
						ReadingList temp = curr.Data;
						curr.Data = next.Data;
						next.Data = temp;
					}
					curr = next;
					next = next.Next;
				}
			}
		}
		//sorts by price
		public static void sortByPrice() {
			int n = getListLength();
			if (n<2) {
				return;
			}
			for (int i=0; i<n; i++) {
				Node curr=head;
				Node next=curr.Next;
				for (int j=0; j<n-i-1; j++) {
					if (curr.Data.Price > next.Data.Price) {
						ReadingList temp = curr.Data;
						curr.Data = next.Data;
						next.Data = temp;
					}
					curr = next;
					next = next.Next;
				}
			}
		}
		//prints all books or prints there are no books in the list if the list is empty
		public static void printBooks() {
			if (head==null) {
				System.out.println("There are no Books in the list.");
				System.out.println();
				return;
			}
			Node curr = head;
			String sortOrder = "";
			switch(LastSort) {
				case 1:
					sortOrder = "Name";
					break;
				case 2:
					sortOrder = "Author";
					break;
				case 3:
					sortOrder = "Genre";
					sortByGenre();
					break;
				case 4:
					sortOrder = "Price";
					sortByPrice();
					break;
				case 5:
					sortOrder = "Priority";
					sortByPriority();
					break;
				default:
					sortOrder = "Priority";
					
			}
			System.out.println("Current Books:");
			while (curr != null) {
				System.out.println(curr.Data);
				curr = curr.Next;
			}
			System.out.println();
		}
		//sorts the books by name, author, genre, price, or priority based on the users' input
		public static void sortBooks() {
			System.out.println("You can sort by name, author, genre, price, or priority");
			System.out.println("1) Name\n2) Author\n3) Genre\n4) Price\n5) Priority");
			int choice = keyboard.nextInt();
			switch (choice) {
				case 1: 
					sortByName();
					LastSort=1;
					printBooks();
					break;
				case 2:
					sortByAuthor();
					LastSort=2;
					printBooks();
					break;
				case 3:
					sortByGenre();
					LastSort=3;
					printBooks();
					break;
				case 4:
					sortByPrice();
					LastSort=4;
					printBooks();
					break;
				case 5:
					sortByPriority();
					LastSort=5;
					printBooks();
					break;
				default:
					System.out.println("Invalid option. Try again.");
			}
		}
		//adds a book based on user input and sorts the list based on the previous sorting method
		public static void addBook() {
			//prompt the user for the tasks details
			System.out.println("Enter the name of the book: ");
			String name = keyboard.nextLine();
			System.out.println("Enter the author: ");
			String author = keyboard.nextLine();
			System.out.println("Enter the genre: ");
			String genre = keyboard.nextLine();
			System.out.println("Enter the priority (enter a whole number): ");
			int priority = keyboard.nextInt();
			System.out.println("Enter the price: ");
			double price = keyboard.nextDouble();
			ReadingList newTask = new ReadingList(name, author, genre, priority, price);
			Node newNode = new Node(newTask, null);
			
			//traverse the list to find the tail
			Node curr = head;
			if (head == null) {
				head = newNode;
				return;
			}
			while (curr.Next != null) {
				curr = curr.Next;
			}
			//curr now points to the tail
			curr.Next = newNode;
			
			// sort the list
			if (LastSort ==1) 
				sortByName();
			else if (LastSort==2)
				sortByAuthor();
			else if (LastSort==3)
				sortByGenre();
			else if (LastSort==4)
				sortByPrice();
			else {
				sortByPriority();
				LastSort = 5;
			}
		}
		//shifts a book down(for the remove method)
		/*public static void shiftBookDown(int startIndex) {
			//start at startInndex
			//copy books from the right to the left, down 1 index (overwriting)
			//null out the last item
			Node curr=head;
			for (int i = startIndex; i<rl.length-1; i++) {
				rl[i] = rl[i+1]; //overwrite from the right
				if (rl[i+1]==null)
					break;
			}
			//null out the last item(in case the list is full)
			Node tail=null;
		}*/
		//removes a book that the user specifies
		public static void removeBook() {
			if (head == null) {
				System.out.println("Cannot delete from an empty list!");
				return;
			}
			System.out.println("Here is the current list of tasks:");
			Node curr = head;
			int i = 1;
			while (curr != null) {
				System.out.println(i + ": " + curr.Data.Name);
				curr = curr.Next;
				i++;
			}
			System.out.println("Enter the number beside the task that is complete");
			int taskNum = keyboard.nextInt();
			
			removeTaskAtIndex(taskNum-1);
		}
		//removes a task at specific index, assists the remove method
		public static void removeTaskAtIndex(int index) {
			Node curr = head;
			
			//traverse until one node before index
			while (index>1) {
				curr=curr.Next;
				index--;
			}
			
			//skip over the next node
			//it's possible for skipOne to be null, but curr.Next will not be null
			Node skipOne=curr.Next.Next;
			curr.Next = skipOne;
		}
		//edits a book based on user input
		public static void editBook() {
			if (head==null) {
				System.out.println("There are no books in the list. Please add a book to continue.");
				return;
			}
			//updates data at specific location
			System.out.println("Enter the number of the book you want to edit: ");
			int index=keyboard.nextInt()-1;
			keyboard.nextLine();
			//checks if the user enters valid data
			int i=0;
			Node curr=head;
			while (i<index) {
				curr=curr.Next;
				i++;
			}
			if (index < 0 || index >= getListLength() || curr==null) {
				System.out.println("Not a valid number. Please choose a different selection.");
				return;	
			}
			System.out.println("What data would you like to edit? (name, author, genre, price, priority)");
			String data = keyboard.nextLine();
			data.toLowerCase();
			//changes the data that the user specifies
			switch (data) {
			case "name":
				System.out.println("Enter a new title: ");
				String newName=keyboard.nextLine();
				curr.Data.Name=newName;
				sortByName();
				break;
			case "author":
				System.out.println("Enter a different author: ");
				String newAuthor=keyboard.nextLine();
				curr.Data.Author=newAuthor;
				sortByAuthor();
				break;
			case "genre":
				System.out.println("Enter a different genre: ");
				String newGenre=keyboard.nextLine();
				curr.Data.Genre=newGenre;
				sortByGenre();
				break;
			case "price":
				System.out.println("Enter a different price: ");
				double newPrice=keyboard.nextDouble();
				keyboard.nextLine();
				curr.Data.Price=newPrice;
				sortByPrice();
				break;
			case "priority":
				System.out.println("Enter a different priority level: ");
				int newPri=keyboard.nextInt();
				keyboard.nextLine();
				curr.Data.Priority=newPri;
				sortByPriority();
				break;
			default:
				System.out.println("Please enter one of the specified data types");
				}
			}
		//calculates the total cost
		public static void totalCost() {
			if (head==null) {
				System.out.println("There are no books in the list. Please add a book to continue");
				return;
			}
			//displays the total cost of all the books in the list
			Node curr=head;
			double totalCost=0.0;
			while (curr!=null) {
				totalCost+=curr.Data.Price;
				curr=curr.Next;
			}
			System.out.println("Total cost of books: ");
			System.out.println(totalCost);
		}
		//removes all the books from the list
		public static void clearBooks() {
			head=null;
		}
		
		public static void main(String[] args) {
			// scanner
			keyboard = new Scanner(System.in);
			// mock data, insert into the array
			Node node5=new Node(new ReadingList("Harry Potter", "J.K. Rowling", "Fantasy", 3, 14.99), null);
			Node node4=new Node(new ReadingList("Sunrise on the Reaping", "Suzanne Collins", "Fantasy", 1, 19.95), node5);
			Node node3=new Node(new ReadingList("Glorious Rivals", "Jennifer Lynn Barnes", "Fantasy", 2, 17.99), node4);
			Node node2=new Node(new ReadingList("Good Girl's Guide to Murder", "Holly Jackson", "Mystery", 5, 10.99), node3);
			Node node1=new Node(new ReadingList("Regretting You", "Colleen Hoover", "Romance", 4, 10.99), node2);
			head=node1;
			System.out.println("Welcome to the task manager!\nI have added some tasks to get you started");
			printBooks();
					
			// print the menu options
			while(true) {
				System.out.println("Here are the menu options:");
				System.out.println("1. Add a new book\n2. Mark a book read\n3. Sort the books\n4. Print the reading list\n5. Edit the Book data\n6. Find total cost\n7. Clear Books\n8. Exit");
				int choice = keyboard.nextInt();
				switch(choice) {
				case 1:
					keyboard.nextLine(); //flush the buffer
					addBook();
					printBooks();
					break;
				case 2:
					removeBook();
					printBooks();
					break;
				case 3:
					sortBooks();
					//printing happens in the sort method
					break;
				case 4:
					printBooks();
					break;
				case 5:
					keyboard.nextLine();
					editBook();
					printBooks();
					break;
				case 6:
					totalCost();
					break;
				case 7:
					clearBooks();
					printBooks();
					break;
				case 8:
					System.out.println("\nHave a nice day!");
					keyboard.close();
					return;
				default:
					System.out.println("Invalid option! Try again!");
				}
			}//end while
		}//end main

	}//end class
