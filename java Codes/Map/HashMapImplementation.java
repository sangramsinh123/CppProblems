import java.util.LinkedList;

public class myHashMap 
{

    class Node{
        String key;
        int value;

        Node(String key , int value){
            this.key = key;
            this.value = value;
        }
    }

    LinkedList<Node>[] bucket; // length = N
    int size; // n
    /*
     * Load Factor = Lambda = (n/N)
     * 
    */
    public myHashMap() {
        initBuckets(4);
        size = 0;
    }

    void initBuckets(int N){
        bucket = new LinkedList[N];
        for(int bi=0;bi<bucket.length;bi++){
            bucket[bi] = new LinkedList<>();
        }
    }

    public void insert(String key, int value) {// PUT Method
        int bi = hashFun(key);
        int di = getIndexWithinBucket(key , bi);
        
        if(di != -1){// key is present in bucket[bi]
            Node node = bucket[bi].get(di);
            node.value = value;
        }
        else{
            // insert
            Node node = new Node(key,value);
            bucket[bi].add(node);
            size++;
        }
        double lambda = ((size*1.0)/(bucket.length*1.0));
        if(lambda > 2){
            rehash();
        }
    }

    private void rehash(){
        LinkedList<Node>[] oba = bucket;
        initBuckets(oba.length*2);
        size = 0;
        for(int bi = 0;bi<oba.length;bi++){
            for(Node node : oba[bi]){
                insert(node.key, node.value);
            }
        }

    }

    int hashFun(String key){
        int hashCode = key.hashCode();// It could be anything +ve,-ve , large , small
        return Math.abs(hashCode)%bucket.length;
    }

    private int getIndexWithinBucket(String key, int bi){
        int di = 0;
        for(Node node : bucket[bi]){
            if(node.key.equals(key)){
                return di;
            }
            di++;
        }

        return -1;
    }

    public int get(String key) {
        int bi = hashFun(key);
        int di = getIndexWithinBucket(key , bi);
        
        if(di != -1){// key is present in bucket[bi]
            Node node = bucket[bi].get(di);
            return node.value;
        }
        return -1;
    }

    public void remove(String key) {
        int bi = hashFun(key);
        int di = getIndexWithinBucket(key , bi);
        
        if(di != -1){// key is present in bucket[bi]
            Node node = bucket[bi].remove(di);
            size--;
        }
        
    }

    public boolean search(String key) {
        int bi = hashFun(key);
        int di = getIndexWithinBucket(key , bi);
        
        if(di != -1){// key is present in bucket[bi]
            return true;
        }
        return false;
    }

    public int getSize() {
        return size;
    }

    public boolean isEmpty() 
    {
        if(size == 0){
            return true;
        }

        return false;
    }

}
