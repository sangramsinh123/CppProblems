class Demo{
    public static void main(String[] args) {
        AppleCharger lightingCable = new AdaptorCharger(new TypeCCable());
        ApplePhone iphone13 = new ApplePhone(lightingCable);
        iphone13.chargeIphone();
    }
}