// Online Java Compiler
// Use this editor to write, compile and run your Java code online

import java.util.*;

class student implements Comparable<student>{
    int maths;
    int physics;
    // implement getters and setters according to our need
    public student(int maths , int physics){
        this.maths = maths;
        this.physics = physics;
    }
    
    public int compareTo(student other){
        
        // 3 CASES
        if(this.maths < other.maths){
            return -1;
        }
        
        else if(this.maths > other.maths){
            return 1;
        }
        
        else{
            return this.physics-other.physics;
        }
        
    }
    
    // OR 
    // public int compareTo(student o){
    //     return this.maths-o.maths;
    // }
    
}

class HelloWorld {
    public static void main(String[] args) {
        // System.out.println("Hello, World!");
        
        List<student> ls = new ArrayList<>();
        ls.add(new student(70,80));
        ls.add(new student(80,90));
        ls.add(new student(50,60));
        ls.add(new student(60,40));
        ls.add(new student(50,80));
        PriorityQueue<student> pq= new PriorityQueue<>(ls);
        int k = 3;
        while(true){
            if(k==0){
                break;
            }
            student s1 = pq.remove();
            System.out.println(s1.maths +"-" + s1.physics);
            k--;
        }
        
    }
}









