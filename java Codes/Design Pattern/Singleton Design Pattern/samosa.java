class Samosa{
    // Lazy way to have Singleton design pattern
    private static Samosa s1;
    private Samosa(){

    }

    public static Samosa getSamosa(){
        if(s1 == null){
            s1 =  new Samosa();
        }
        else{

        }
        return s1;
    }
}