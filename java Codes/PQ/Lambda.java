// Online Java Compiler
// Use this editor to write, compile and run your Java code online

import java.util.*;

class student{
    int maths;
    int physics;
    // implement getters and setters according to our need
    public student(int maths , int physics){
        this.maths = maths;
        this.physics = physics;
    }
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
        PriorityQueue<student> pq= new PriorityQueue<>((s1,s2) -> 
        {
            if(s1.maths == s2.maths){
                return s1.physics-s2.physics;
            }
            return s1.maths-s2.maths;
        }
        
        );
        for(student s : ls){
            pq.add(s);
        }
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







