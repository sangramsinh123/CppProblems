class Sieve{
    public static void sieveOfErathosis(int n){
        boolean[] isPrime = new boolean[n+1];
        Arrays.fill(isPrime, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for(int i = 2;i<=n;i++){
            if(isPrime[i] == true){
                for(int j = i*i;j<=n;j+=i){
                    isPrime[j] = false;
                }
            }
        }

        
    }
}
