public class Main {
    public static void main(String[] args) {
        Samosa s1 = Samosa.getSamosa();
        Samosa s2 = Samosa.getSamosa();
        System.out.println(s1.hashCode());
        System.out.println(s2.hashCode());
    }
}
