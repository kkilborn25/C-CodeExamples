//Katherine (Katie) Kilborn
public class Node {
	public ReadingList Data;
	public Node Next;
	
	//Node constructor
	public Node(ReadingList d, Node n) {
		this.Data = d;
		this.Next = n;
	}
}
