public class Client {
    public static void main(String[] args) {
        YoutubeChannel youtubeChannel = new YoutubeChannel();
        Subscriber aman = new Subscriber("Aman");
        Subscriber sam = new Subscriber("sam");
        youtubeChannel.subscribe(aman);
        youtubeChannel.subscribe(sam);
        youtubeChannel.notifyChanges();
    }
}
