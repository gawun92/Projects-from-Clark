

public class TNode {
	String data;
	TNode left;
	TNode right;
	

	TNode(String data){
		this.data = data;
		this.left = null;
		this.right = null;
	}
	
	TNode(String data, TNode left, TNode right){
		this.data = data;
		this.left = left;
		this.right = right;
	}
}
