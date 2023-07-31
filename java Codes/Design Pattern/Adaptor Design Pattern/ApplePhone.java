public class ApplePhone {
    
    private AppleCharger appleCharger;
    
    public ApplePhone(AppleCharger appleCharger) {
        this.appleCharger = appleCharger;
    }

    public void chargeIphone(){
        appleCharger.chargePhone();
    }
}
