public class Jalebi {

    // Eager way to have Singleton design pattern
    /*
     * DISADVANTAGE:
     * 
     * If client dost need jalebi obj although it will create 
     * 
    */
    private static Jalebi j1 = new Jalebi();
    public static Jalebi getJalebi(){
        return j1;
    }
}
