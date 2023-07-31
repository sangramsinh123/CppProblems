class User{

    private final int userId;
    private final String email;

    private User(UserBuilder ub){
        // Initilaze
        this.userId = ub.userId;
        this.email = ub.email;
    }
    public int getUserId() {
        return userId;
    }
    public String getEmail() {
        return email;
    }


    @Override
    public String toString() {
        return "User [userId=" + userId + ", email=" + email + "]";
    }


    // inner class to create object
    static class UserBuilder{
        private  int userId;
        private String email;
        
        // Method chainig
        public UserBuilder setUserId(int userId) {
            this.userId = userId;
            return this;
        }
        public UserBuilder setEmail(String email) {
            this.email = email;
            return this;
        }

        public UserBuilder(){

        }

        public User build(){
            User user =  new User(this);
            return user;
        }
        
    }
}