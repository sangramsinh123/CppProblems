public class AdaptorCharger implements AppleCharger {

    private AndriodCharger andriodCharger;
    
    public AdaptorCharger(AndriodCharger andriodCharger) {
        this.andriodCharger = andriodCharger;
    }

    @Override
    public void chargePhone() {
        andriodCharger.chargePhone();
        System.out.println("your iphone is charhing using Adaptor");
    }
        
}
