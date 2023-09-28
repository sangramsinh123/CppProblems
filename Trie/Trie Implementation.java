class Trie {

    class Node{
        Node[] children;
        boolean isEnd;

        public Node(){
            children = new Node[26];
        }
    }

    Node root ;
    public Trie() {
        root = new Node();
    }
    
    public void insert(String s) {
        int n = s.length();
        Node curr = root;
        for(int i = 0;i<n;i++){
            char ch = s.charAt(i);
            if(curr.children[ch-'a'] != null){
                // dont do anything 
            } 
            else{
                curr.children[ch-'a'] = new Node();
            }
            curr = curr.children[ch-'a'];
        }
        curr.isEnd = true;
    }
    
    public boolean search(String s) {
        int n = s.length();
        Node curr = root;
        for(int i = 0;i<n;i++){
            char ch = s.charAt(i);
            if(curr.children[ch-'a'] != null){
                // continue;
            }
            else{
                return false;
            }
            curr = curr.children[ch-'a'];
        }

        if(curr.isEnd){
            return true;
        }
        return false;   
    }
    
    public boolean startsWith(String prefix) {
        int n = prefix.length();
        Node curr = root;
        for(int i = 0;i<n;i++){
            char ch = prefix.charAt(i);
            if(curr.children[ch-'a'] != null){
                // continue;
            }
            else{
                return false;
            }
            curr = curr.children[ch-'a'];
        }
        return true;
    }
}
