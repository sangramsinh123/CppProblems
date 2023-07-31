import java.util.ArrayList;
import java.util.List;

public class YoutubeChannel implements Subject {
    List<Observer> ls = new ArrayList<>();
    @Override
    public void subscribe(Observer ob) {
        this.ls.add(ob);
    }

    @Override
    public void unsubscribe(Observer ob) {
        this.ls.remove(ob);
    }

    @Override
    public void notifyChanges() {
        for(Observer ob : this.ls){
            ob.notified();
        }
    }
}
