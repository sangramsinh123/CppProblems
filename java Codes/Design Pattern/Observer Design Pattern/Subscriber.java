public class Subscriber implements Observer {
    String name;
    Subscriber(String name){
        this.name = name;
    }
    @Override
    public void notified() {
        System.out.println(name+" New Video Uploaded");
        
    }
    
}
