public class Main {
    public static void main(String[] args) {
        User u1 = new User.UserBuilder().setUserId(12).setEmail("sam@gmail.com").build();

        System.out.println(u1);
    }
}
