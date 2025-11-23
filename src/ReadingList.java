//Katherine (Katie) Kilborn
public class ReadingList {
	String Name; 
	String Author;
	String Genre;
	int Priority;
	double Price;
	
	//default constructor
	ReadingList(){
		this.Name=null;
		this.Author=null;
		this.Genre=null;
		this.Priority=0;
		this.Price=0.0;
	}
	
	//parameterized constructor
	ReadingList(String name, String author, String genre, int priority, double price){
		this.Name = name;
		this.Author = author;
		this.Genre = genre;
		this.Priority = priority;
		this.Price=price;
	}
	//getters
	public String getName() {
		return Name;
	}
	public String getAuthor() {
		return Author;
	}
	public String getGenre() {
		return Genre;
	}
	public int getPriority() {
		return Priority;
	}
	public double getPrice() {
		return Price;
	}
	//setters
	public void setName(String n) {
		this.Name=n;
	}
	public void setAuthor(String a) {
		this.Author=a;
	}
	public void setGenre(String g) {
		this.Genre=g;
	}
	public void setPriority(int p) {
		this.Priority=p;
	}
	public void setPrice(double p) {
		this.Price=p;
	}
	//toString method
	@Override
	public String toString() {
		return "Book: " + Name + ", " + Author + ", " + Genre + " - " + Price + " - " + "(" + Priority + ")";
	}
}
